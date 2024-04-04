#include <future>
#include <iostream>
#include <lwvid/lwvid.h>

auto func(int x) -> void { std::cout << x << std::endl; }

auto main() -> int {
    auto f = std::async(std::launch::async, func, 2);
    f.wait();
    return 0;
}
