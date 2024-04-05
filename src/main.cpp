#include <boost/stacktrace.hpp>
#include <future>
#include <iostream>
#include <lwvid/lwvid.hpp>
#include <memory>

auto avformat_context_deleter(AVFormatContext* avfmt_ctx) -> void {
    avformat_free_context(avfmt_ctx);
}

auto main() -> int {
    auto avfmt_ctx = avformat_alloc_context();
    avformat_open_input(&avfmt_ctx, "../bunny_1080p_60fps.mp4", NULL, NULL);
    std::cout << boost::stacktrace::stacktrace();
    return 0;
}
