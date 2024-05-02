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

/*int ASMsumSThread(std::vector<int> &vec) {
    int sum;
    asm volatile(
        "xor %[sum], %[sum]\n"                      // Initialize sum to 0
        "mov %[vec], %[vec]\n"                      // Move the address of vec to a register
        "mov %[end], %[vec_end]\n"                  // Move the end address of vec to a register
        "loop_start:\n"
        "cmp %[vec], %[end]\n"                      // Compare the current address with the end address
        "je loop_end\n"                             // If they are equal, jump to the end of the loop
        "mov eax, dword ptr [%[vec]]\n"             // Load the current value of vec into EAX
        "add %[sum], eax\n"                         // Add the value to sum
        "add %[vec], 4\n"                           // Move to the next element of vec (assuming int is 4 bytes)
        "jmp loop_start\n"                          // Jump back to the start of the loop
        "loop_end:\n"
        : [sum] "=r" (sum),                         // Output: sum (register)
        [vec] "+r" (vec)                            // Input/Output: vec (register)
        : [vec_end] "r" (vec.data() + vec.size())   // Input: vec_end (register)
        : "eax", "cc"                               // Clobbered registers: EAX, condition codes
    );
    return sum;
}*/


int main(int argc, char *argv[]) {
    std::vector<int> aVec;

    commons::fillVector(aVec, 100000, 1, 200000);
    int chunkSize = aVec.size() / NUM_THREADS;

    std::cout << "Sum of our vector calculated by a single thread: " << sumSThread(aVec) << std::endl;
    //std::cout << "Sum of our vector calculated using inline assembly: " << ASMsumSThread(aVec) << std::endl;
    std::cout << "Sum of our vector calculated with many threads: " << multithreading::sumMThread(aVec, chunkSize) <<
            std::endl;
    return 0;
}
