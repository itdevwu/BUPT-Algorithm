// Copyright (c) 2022 Zhenglong WU.

#include "brute_force.hpp"

int lab1::brute_force::n3::maximum_subarray(std::vector<int> &vec)
{
    int sum = 0, res = 0;

    for (auto i = vec.begin(); i != vec.end(); ++i)
    {
        for (auto j = vec.begin(); j != i; ++j)
        {
            sum = 0;
            for (auto k = j; k != i; ++k)
            {
                sum += *k, res = std::max(res, sum);
            }
        }
    }

    return res;
}

int lab1::brute_force::n2::maximum_subarray(std::vector<int> &vec)
{
    int res = 0;

    int len = vec.size();
    int *sum = new int[len + 1];
    std::fill(sum, sum + len + 1, 0);

    for (auto i = 1; i <= len; ++i)
    {
        sum[i] = sum[i - 1] + vec[i - 1];
        for (auto j = 1; j < i; ++j)
        {
            res = std::max(res, sum[i] - sum[j]);
        }
    }

    delete sum;

    return res;
}