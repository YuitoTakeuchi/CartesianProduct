#pragma once

#include <array>
#include <vector>
#include <cmath>

#include <numeric>
#include <functional>

#include <random>

template<int... N>
class CartesianProductIndex {
    static constexpr int dimension = sizeof...(N);
    static constexpr int sizes[dimension] = {N...};
    static constexpr long prod = std::accumulate(std::begin(sizes), std::end(sizes), 1UL, std::multiplies<long>{});
    std::array<int, dimension> product_set{};
    std::array<int, dimension> _product_set{}; // for random get

    std::random_device seed_gen;
    std::mt19937 engine = std::mt19937(seed_gen());
    std::uniform_int_distribution<> dist = std::uniform_int_distribution<> (0, prod);

public:
    CartesianProductIndex() {
        product_set[0] = -1;
    }
    const std::array<int, dimension>& next() {
        for(int idx = 0; idx < dimension; ++idx) {
            if(++product_set[idx] < sizes[idx]) break;
            product_set[idx] = 0;
        }
        return product_set;
    }

    const std::vector<int>& random() {
        long idx = dist(engine);
        for(int i = 0; i < dimension; ++i) {
            _product_set[i] = idx % sizes[i];
        }
        return _product_set;
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
    std::vector<int> _product_set; // for random get
    std::random_device seed_gen;
    std::mt19937 engine = std::mt19937(seed_gen());
    std::uniform_int_distribution<> dist;

public:
    CartesianProductIndex(int size, int dimension) {
        dist = std::uniform_int_distribution<> (0, prod);
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

    const std::vector<int>& random() {
        long idx = dist(engine);
        for(int i = 0; i < dimension; ++i) {
            _product_set[i] = idx % sizes[i];
        }
        return _product_set;
    }

    long size() {return prod;}
};