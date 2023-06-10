#include "CartesianProduct.hpp"

#include <iostream>

int main() {
    CartesianProductIndex<2, 3, 5, 2> gen;
    for(int i = 0; i < gen.size(); ++i) {
        auto set = gen.next();
        for(auto &e: set) std::cout << e << " ";
        std::cout << "\n";
    }

    CartesianProductIndex<> gen2(2, 4);

    for(int i = 0; i < gen2.size(); ++i) {
        auto set = gen2.next();
        for(auto &e: set) std::cout << e << " ";
        std::cout << "\n";
    }
}