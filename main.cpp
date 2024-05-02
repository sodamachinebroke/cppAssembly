#include <iostream>
#include <vector>
#include "header/commons.h"
#include "header/multithreading.h"

int sumSThread(std::vector<int> &vec) {
    int sum = 0;
    for (auto vechelp: vec) {
        sum += vechelp;
    }
    return sum;
}

int asmVecSum(std::vector<int> &vec) {
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

/*void asmLoop() {                                                          //this doesn't work yet, shouldn't touch
    int result;
    int array[] = {1, 2, 3, 4, 5};
    int array_size = std::size(array);
    asm volatile
    (
    "xorl %[result], %[result] \n" // Initialize result to 0
    "xorl %%eax, %%eax \n" // Clear loop counter

    "loop_start: \n"
    "addl (%%ebx, %%eax, 4), %%ecx \n" // Add array element to result
    "addl %%ecx, %[result] \n"
    "incl %%eax \n" // Increment loop counter
    "cmpl %[size], %%eax \n" // Compare loop counter with array size
    "jl loop_start \n" // Jump back to loop_start if loop counter is less than array size
    : [result] "=r" (result) // Output operand
    : [array] "b" (array), [size] "r" (array_size) // Input operands
    : "%eax", "ecx" // Clobbered registers
    );

    std::cout << "Result:" << result << std::endl;
}*/

int main(int argc, char *argv[]) {
    /*std::vector<int> aVec;

    commons::fillVector(aVec, 10, 0, 1);
    int chunkSize = aVec.size() / NUM_THREADS;


    std::cout << "Inline assembly adds numbers 2 and 3: " << asmAdd(2, 3) << std::endl;
    std::cout << "Security summing algorithm: " << multithreading::sumMThread(aVec, chunkSize) << std::endl;
    std::cout << "Inline asssembly sum our vector's values: " << asmVecSum(aVec) << std::endl;*/

    //A loop with assembly
    /*int result;
    asm
    (
    "xorl %[result], %[result] \n" // Initialize result to 0
    "movl $0, %%eax \n" // Initialize loop counter to 0
    "movl $10, %%ebx \n" // Set loop count to 10

    "loop_start: \n"
    "addl %%eax, %[result] \n" // Add loop counter to result
    "incl %%eax \n" // Increment loop counter
    "cmpl %%ebx, %%eax \n" // Compare loop counter with loop count
    "jl loop_start \n" // Jump back to loop_start if loop counter is less than loop count
    : [result] "=r" (result) // Output operand
    : // No input operands
    : "%eax", "%ebx" // Clobbered registers
    );*/
    return 0;
}
