// Copyright (c) 2022 Zhenglong WU.

#include "brute_force.hpp"
#include "divide_conque.hpp"
#include "dp.hpp"

#include <chrono>
#include <fstream>

using namespace lab1;

int main(int argc, char *argv[])
{
    if (argc != 2)
        return 0;

    std::cout << "\t\t\tTIME(ns)\n";
    std::cout << "Scale\t"
              << "O(n^3)\t"
              << "O(n^2)\t"
              << "O(nlogn)\t"
              << "O(n)\n";

    int data_scales[] = {10, 100, 1000, 10000, 100000};
    for (auto data_scale : data_scales)
    {
        std::cout << data_scale << "\t\t";

        std::vector<int> vec;
        std::string path = argv[1];
        if (*path.end() != '/')
            path += '/';
        path += ("/" + std::to_string(data_scale) + ".txt");
        std::ifstream in_file(path.c_str());
        int n;
        in_file >> n;
        for (auto i = 1; i <= n; ++i)
        {
            int tmp;
            in_file >> tmp;
            vec.push_back(tmp);
        }

        int res_n3, res_n2, res_nlogn, res_n;

        if (data_scale <= 1000)
        {
            auto start = std::chrono::system_clock::now();
            res_n3 = brute_force::n3::maximum_subarray(vec);
            auto end = std::chrono::system_clock::now();
            auto elapsed =
                std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
            std::cout << elapsed.count() << "\t\t";
        }
        else
        {
            std::cout << "N/A\t\t";
        }

        {
            auto start = std::chrono::system_clock::now();
            res_n2 = brute_force::n2::maximum_subarray(vec);
            auto end = std::chrono::system_clock::now();
            auto elapsed =
                std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
            std::cout << elapsed.count() << "\t\t";
        }

        {
            auto start = std::chrono::system_clock::now();
            res_nlogn = divide_conque::maximum_subarray(vec);
            auto end = std::chrono::system_clock::now();
            auto elapsed =
                std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
            std::cout << elapsed.count() << "\t\t";
        }

        {
            auto start = std::chrono::system_clock::now();
            res_n = dp::maximum_subarray(vec);
            auto end = std::chrono::system_clock::now();
            auto elapsed =
                std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
            std::cout << elapsed.count() << "\t\t";
        }

        std::cout << "\n";
    }
    return 0;
}
