#include <nanobench.h>

#include <array>
#include <cstdint>

using u32 = std::uint32_t;

constexpr std::size_t size = 1024;

u32 get_value(u32 index){
    static constexpr std::array<char, size> values
      = {'0','1','2','3','4','5','6','7','8','9'};

    return values[index];
}

int main() {
    ankerl::nanobench::Bench().run("static", []{ 
        volatile int result = get_value(7); 
    });
}