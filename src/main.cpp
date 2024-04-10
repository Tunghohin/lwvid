#include <boost/stacktrace.hpp>
#include <future>
#include <iostream>
#include <lwvid/lwvid.hpp>
#include <memory>
#include <spdlog/spdlog.h>

auto main() -> int {
    fmt::println("{}", 2333);
    spdlog::info("fff");
    return 0;
}
