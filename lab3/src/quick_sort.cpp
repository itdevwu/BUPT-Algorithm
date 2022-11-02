#include "quick_sort.hpp"

lab2::utils::SortInfo lab2::quick_sort::sort(std::vector<int> &vec)
{
    lab2::utils::SortInfo sort_info;

    const auto qsort_f = [&]()
    {
        std::function<void(int, int)> rec_f;
        rec_f = [&](int l, int r)
        {
            auto mid_val = vec[l];
            auto i = l, j = r;
            do
            {
                while (vec[i] < mid_val)
                {
                    sort_info.inc_cmp_cnt();
                    i++;
                }
                while (vec[j] > mid_val)
                {
                    sort_info.inc_cmp_cnt();
                    j--;
                }
                if (i <= j)
                {
                    sort_info.inc_cmp_cnt();
                    sort_info.inc_swap_cnt();
                    std::swap(vec[i], vec[j]);
                    i++;
                    j--;
                }
            } while (i <= j);
            if (l < j)
                rec_f(l, j);
            if (i < r)
                rec_f(i, r);
        };

        rec_f(0, vec.size());
    };

    qsort_f();

    return sort_info;
}