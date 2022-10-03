// Copyright (c) 2022 Zhenglong WU.

#include "dp.hpp"

int lab1::dp::maximum_subarray(std::vector<int> &vec)
{
    int res = 0;

    int len = vec.size();
    int *f = new int[len];
    std::fill(f, f + len, 0);
    for (auto i = 0; i < len; ++i)
    {
        f[i] = std::max(f[i - 1] + vec[i], vec[i]);
        res = std::max(res, f[i]);
    }

    delete f;

    return res;
}
