#include <cassert>
#include <cstring>
#include <cmath> // nanf, isnan
#include <iostream>
#include <limits> // std::numeric_limits

#pragma STDC FENV_ACCESS ON

void print_float(float f) {
    std::uint32_t i;
    std::memcpy(&i, &f, sizeof f);
    std::cout << std::hex << i << std::endl;
}

int main() {
    static_assert(std::numeric_limits<float>::has_quiet_NaN, "");
    static_assert(std::numeric_limits<float>::has_signaling_NaN, "");
    static_assert(std::numeric_limits<float>::has_infinity, "");

    // Generate them.
    float qnan = std::numeric_limits<float>::quiet_NaN();
    float snan = std::numeric_limits<float>::signaling_NaN();
    float inf = std::numeric_limits<float>::infinity();
    float nan0 = std::nanf("0");
    float nan1 = std::nanf("1");
    float nan2 = std::nanf("2");
    float div_0_0 = 0.0f / 0.0f;
    float sqrt_negative = std::sqrt(-1.0f);

    // // Print their bytes.
    // std::cout << "qnan "; print_float(qnan);
    // std::cout << "snan "; print_float(snan);
    // std::cout << " inf "; print_float(inf);
    // std::cout << "-inf "; print_float(-inf);
    // std::cout << "nan0 "; print_float(nan0);
    // std::cout << "nan1 "; print_float(nan1);
    // std::cout << "nan2 "; print_float(nan2);
    // std::cout << " 0/0 "; print_float(div_0_0);
    // std::cout << "sqrt "; print_float(sqrt_negative);

    // // Assert if they are NaN or not.
    // assert(std::isnan(qnan));
    // assert(std::isnan(snan));
    // assert(!std::isnan(inf));
    // assert(!std::isnan(-inf));
    // assert(std::isnan(nan0));
    // assert(std::isnan(nan1));
    // assert(std::isnan(nan2));
    // assert(std::isnan(div_0_0));
    // assert(std::isnan(sqrt_negative));

    float zero = 0.0;
    float t;
    print_float(snan);
    asm(
        "fsub.s %0, %2, %1"
        : "=f"(t)               
        : "f"(zero), "f"(snan)
    );
    print_float(t);
}