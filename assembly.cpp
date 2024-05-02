//
// Created by hajlektalan on 2024-05-02.
//
#include "header/assembly.h"

#include <vector>
int lowLevel::asmVecSum(std::vector<int> &vec) {
    int sum = 0;
    for (int vechelp: vec) {
        __asm__ __volatile__
        (
            "addl %%eax, %%ebx;"
            : "=b" (sum)
            : "a" (vechelp), "b" (sum)
        );
    }
    return sum;
}