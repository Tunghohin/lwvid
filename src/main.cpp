#include <boost/stacktrace.hpp>
#include <future>
#include <iostream>
#include <lwvid/lwvid.hpp>
#include <memory>

auto main() -> int {
    auto avfmt_context = avformat_alloc_context();
    avformat_free_context(avfmt_context);
    std::cout << boost::stacktrace::stacktrace();
    return 0;
}
