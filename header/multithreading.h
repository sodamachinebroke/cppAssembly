//
// Created by hajlektalan on 2024-05-01.
//

#ifndef MULTITHREADING_H
#define MULTITHREADING_H
#include <vector>
#include <thread>
#include <functional>

const unsigned int NUM_THREADS = std::thread::hardware_concurrency();

using ProcessFunction = std::function<void(const std::vector<int> &, int, int, int &)>;

class multithreading {
public:
    static int sumMThread(const std::vector<int> &vec, int chunkSize);
};


#endif //MULTITHREADING_H
