#pragma once

#include <iostream>
#include <array>
#include <vector>
#include <cmath>

#include <numeric>
#include <functional>

template<int... N>
class CartesianProductIndex {
    static constexpr int dimension = sizeof...(N);
    static constexpr int sizes[dimension] = {N...};
    static constexpr long prod = std::accumulate(std::begin(sizes), std::end(sizes), 1UL, std::multiplies<long>{});
    std::vector<int> product_set{-1};

public:
    const std::vector<int>& next() {
        for(int idx = 0; idx < dimension; ++idx) {
            if(++product_set[idx] < sizes[idx]) break;
            product_set[idx] = 0;
        }
        return product_set;
    }

    long size() {return prod;}
};

// Dynamic
template<>
class CartesianProductIndex<> {
    int dimension;
    long prod;
    std::vector<int> sizes;
    std::vector<int> product_set;

public:
    CartesianProductIndex(int size, int dimension) {
        this->dimension = dimension;
        sizes = std::vector<int> (dimension, size);
        prod = pow(size, dimension);
        product_set = std::vector<int>(dimension, 0);
        product_set[0] = -1;
    }
    const std::vector<int>& next() {
        for(int idx = 0; idx < dimension; ++idx) {
            if(++product_set[idx] < sizes[idx]) break;
            product_set[idx] = 0;
        }
        return product_set;
    }
    long size() {return prod;}
};