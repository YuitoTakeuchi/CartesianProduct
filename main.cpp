#include "CartesianProduct.hpp"

#include <iostream>
#include <iomanip>
#include <chrono>

int main() {
    std::chrono::system_clock::time_point  start, end;
    start = std::chrono::system_clock::now();

    int64_t sum = 0;
    CartesianProductIndex<200, 200, 200, 200> gen;
    for(int i = 0; i < gen.size(); ++i) {
        const auto& set = gen.next();
        for(int i = 0; i < 4; ++i) sum += set[i];
    }

    end = std::chrono::system_clock::now();
    double elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count();

    std::cout << "Result of Static ver -----------------\n";
    std::cout << "Time Elapsed: " << std::setprecision(10) << elapsed << " ms\n";
    std::cout << "sum: " << sum << "\n";

    start = std::chrono::system_clock::now();

    int64_t sum2 = 0;
    // std::vector<int> sizes(4, 200);
    CartesianProductIndex<> gen2(4, 200);
    for(int i = 0; i < gen2.size(); ++i) {
        const auto& set = gen2.next();
        // for(auto& e: set) sum2 += e;
        for(int i = 0; i < 4; ++i) sum2 += set[i];
    }

    end = std::chrono::system_clock::now();
    double elapsed2 = std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count();

    std::cout << "Result of Dynamic ver -----------------\n";
    std::cout << "Time Elapsed: " << std::setprecision(10) << elapsed2 << " ms\n";
    std::cout << "sum: " << sum2 << "\n";
}