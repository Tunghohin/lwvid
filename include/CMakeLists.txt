file(GLOB_RECURSE srcs CONFIGURE_DEPENDS ./*.h)

add_library(include SHARED ${srcs})

target_include_directories(include PUBLIC .)

set_target_properties(include PROPERTIES 
    LINKER_LANGUAGE CXX
    )
