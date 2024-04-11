#include <lwvid/lw_avreader.hpp>
#include <lwvid/lwvid.hpp>

lwvid::AVReaderPrivate::AVReaderPrivate() { fmtctx = avformat_alloc_context(); }

lwvid::AVReaderPrivate::~AVReaderPrivate() { avformat_free_context(fmtctx); }

lwvid::AVReader::AVReader() : inner_(std::make_unique<AVReaderPrivate>()) {}

auto lwvid::AVReader::open(std::string const& path) -> int {
    if (inner_ == nullptr)
        return -1;
    int ret =
        avformat_open_input(&inner_->fmtctx, path.c_str(), nullptr, nullptr);
    if (!ret) {
        avformat_find_stream_info(inner_->fmtctx, nullptr);
    }

    return ret;
}

auto lwvid::AVReader::close() -> int {
    if (inner_ == nullptr)
        return -1;
    avformat_close_input(&inner_->fmtctx);
    return 0;
}