//
// Created by hajlektalan on 2024-05-01.
//

#include "header/multithreading.h"
#include <vector>
#include <thread>
#include <functional>

using ProcessFunction = std::function<void(const std::vector<int> &, int, int, int &)>;

void createThreads(const std::vector<int> &vec, std::vector<int> &res_partialSums, int chunkSize,
                   const ProcessFunction &pfunc) {
    std::vector<int> loc_partialSums(NUM_THREADS);

    std::vector<std::thread> threads;

    for (int i = 0; i < NUM_THREADS; ++i) {
        int start = i * chunkSize;
        int end = (i == NUM_THREADS - 1) ? vec.size() : (i + 1) * chunkSize;
        threads.emplace_back(pfunc, std::ref(vec), start, end, std::ref(loc_partialSums[i]));
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

int multithreading::sumMThread(const std::vector<int> &vec, int chunkSize) {
    std::vector<int> partialSums;
    int totalSum = 0;

    createThreads(vec, partialSums, chunkSize, sumPartial);
    for (int partial_sum: partialSums) {
        totalSum += partial_sum;
    }

    return totalSum;
}
