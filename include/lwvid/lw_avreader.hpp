#ifndef _LW_AVREADER_HPP
#define _LW_AVREADER_HPP

#include <lwvid/lwvid.hpp>
#include <memory>
#include <string>

namespace lwvid {

class AVReaderPrivate {
    friend class AVReader;

public:
    AVReaderPrivate();
    ~AVReaderPrivate();

private:
    AVFormatContext* fmtctx = nullptr;
};

class AVReader {
public:
    AVReader();
    ~AVReader() = default;
    AVReader(AVReader const&) = delete;
    auto operator=(AVReader const&) noexcept -> AVReader& = delete;
    AVReader(AVReader&&) = default;
    auto operator=(AVReader&&) noexcept -> AVReader& = default;

    auto open(std::string const&) -> int;
    auto close() -> int;

private:
    std::unique_ptr<AVReaderPrivate> inner_;
};

} // namespace lwvid

#endif