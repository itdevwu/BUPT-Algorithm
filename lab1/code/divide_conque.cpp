// Copyright (c) 2022 Zhenglong WU.

#include "divide_conque.hpp"

int lab1::divide_conque::maximum_subarray(std::vector<int> &vec)
{
    const auto &recursive = [](std::vector<int> &vec, int l, int r)
    {
        std::function<int(std::vector<int> &, int, int)> rec_f;
        rec_f = [&](std::vector<int> &vec, int l, int r)
        {
            if (l == r)
                return vec[l];

            int mid = (l + r) / 2;

            int res1 = rec_f(vec, l, mid);
            int res2 = rec_f(vec, mid + 1, r);
            int res3 = 0;

            int left_sum = 0, left_res = 0;
            for (auto i = mid; i >= l; --i)
            {
                left_sum += vec[i];
                left_res = std::max(left_res, left_sum);
            }

            int right_sum = 0, right_res = 0;
            for (auto i = mid + 1; i <= r; ++i)
            {
                right_sum += vec[i];
                right_res = std::max(right_res, right_sum);
            }

            res3 = left_res + right_res;

            return std::max(res1, std::max(res2, res3));
        };

        return rec_f(vec, l, r);
    };

    int len = vec.size();
    return recursive(vec, 0, len - 1);
}
