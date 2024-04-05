cmake_minimum_required(VERSION 3.14)

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE RelWithDebInfo)
endif()

if (WIN32)
    add_definitions(-DNOMINMAX -D_USE_MATH_DEFINES)
endif()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_CREATE_STATIC_LIBRARY ON)

project(lwvid LANGUAGES CXX VERSION 0.0.1)
message("-- Project version: ${PROJECT_VERSION}")

find_package(PkgConfig REQUIRED)
pkg_check_modules(LIBAV REQUIRED IMPORTED_TARGET
    libavdevice
    libavfilter
    libavformat
    libavcodec
    libswresample
    libswscale
    libavutil
)

find_package(Boost 1.82.0 REQUIRED COMPONENTS
    stacktrace_basic
    stacktrace_backtrace
    stacktrace_addr2line
    stacktrace_noop
)

file(GLOB_RECURSE deps CONFIGURE_DEPENDS ./src/*.cpp)
add_subdirectory(include)
add_executable(lwvid ${deps})

target_link_libraries(lwvid PRIVATE
    include
    PkgConfig::LIBAV
    Boost::stacktrace_addr2line
)
target_include_directories(lwvid PRIVATE
    include
    PkgConfig::LIBAV
    Boost::stacktrace_addr2line
)
