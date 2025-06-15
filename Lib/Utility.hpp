#pragma once
#include <random>
// #include <functional>
// #include <iostream>

// inline float RandomFloat(float min = 0.0f, float max = 1.0f) 
// {
//     static std::mt19937 mt(std::random_device{}());
//     float normalized = mt() * 1.0f / mt.max();
//     return min + normalized * (max - min);
// }

inline float RandomFloat(float min = 0.0f, float max = 1.0f)
{
    static std::mt19937 mt(std::random_device{}());
    std::uniform_real_distribution<float> dist(min, max);
    return dist(mt);
}

inline int RandomInt(int min, int max)
{
    static std::mt19937 mt(std::random_device{}());
    std::uniform_int_distribution<int> dist(min, max);
    return dist(mt);
}

// template <typename Func>
// void Measure(Func func, int iterations = 10000)
// {
//     auto start = std::chrono::high_resolution_clock::now();

//     for (int i = 0; i < iterations; ++i)
//         func();

//     auto end = std::chrono::high_resolution_clock::now();
//     std::chrono::duration<double, std::milli> duration = end - start;

//     std::cout << "Elapsed time: " << duration.count() << " ms" 
//         << " (" << (duration.count() / iterations) << " ms per call)\n";
// }