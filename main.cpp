#include <iostream>
#include <ranges>
#include <vector>
#include <thread>
#include "header/commons.h"

const unsigned int NUM_THREADS = std::thread::hardware_concurrency();

void createThreads(const std::vector<int> &vec, std::vector<int> &res_partialSums, int chunkSize);

void sumPartial(const std::vector<int> &vec, int start, int end, int &result);

void avgPartial(const std::vector<int> &vec, int start, int end, int &result);

int sumMThread(const std::vector<int> &vec, int chunkSize);

int sumSThread(std::vector<int> &vec);

int main(int argc, char *argv[]) {
    std::vector<int> aVec;

    commons::fillVector(aVec, 100, 0, 2);
    int chunkSize = aVec.size() / NUM_THREADS;

    std::cout << "Sum of our vector calculated by a single thread: " << sumSThread(aVec) << std::endl;
    std::cout << "Sum of our vector calculated with many threads: " << sumMThread(aVec, chunkSize) << std::endl;
    return 0;
}

void createThreads(const std::vector<int> &vec, std::vector<int> &res_partialSums, int chunkSize) {
    std::vector<int> loc_partialSums(NUM_THREADS);

    std::vector<std::thread> threads;

    for (int i = 0; i < NUM_THREADS; ++i) {
        int start = i * chunkSize;
        int end = (i == NUM_THREADS - 1) ? vec.size() : (i + 1) * chunkSize;
        threads.emplace_back(sumPartial, std::ref(vec), start, end, std::ref(loc_partialSums[i]));
    }

    for (auto &thread: threads) {
        thread.join();
    }

    for (int loc_partial_sum: loc_partialSums) {
        res_partialSums.push_back(loc_partial_sum);
    }

}

void sumPartial(const std::vector<int> &vec, int start, int end, int &result) {
    int partialSum = 0;
    for (int i = start; i < end; ++i) {
        partialSum += vec[i];
    }
    result = partialSum;
}

void avgPartial(const std::vector<int> &vec, int start, int end, int &result) {
    int partialAvg = 0;
    int divisor = end - start;
    for (int i = start; i < end; ++i) {
        partialAvg += vec[i];
    }
    partialAvg = partialAvg / divisor;
    result = partialAvg;
}

int sumSThread(std::vector<int> &vec) {
    int sum = 0;
    for (auto vechelp: vec) {
        sum += vechelp;
    }
    return sum;
}



int sumMThread(const std::vector<int> &vec, int chunkSize) {
    std::vector<int> partialSums;
    int totalSum = 0;

    createThreads(vec, partialSums, chunkSize);
    for (int partial_sum: partialSums) {
        totalSum+= partial_sum;
    }

    return totalSum;
}

int avgMThread

