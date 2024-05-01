//
// Created by hajlektalan on 2024-05-01.
//

#include "header/commons.h"
#include <random>


int commons::randGen(const int low, const int high) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(low, high);
    return distr(gen);
}

void commons::fillVector(std::vector<int> &vec,int size, int low, int high) {
    for (int i = 0; i < size; ++i) {
        vec.push_back(randGen(low, high));
    }
}
