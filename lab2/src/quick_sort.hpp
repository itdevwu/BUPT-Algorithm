#ifndef _QUICK_SORT_HPP_
#define _QUICK_SORT_HPP_

#include "utils.hpp"

#include <vector>
#include <functional>

namespace lab2::quick_sort
{
    /// @brief 快速排序，指定参考值为区间第一个数
    /// @param vec 引用目标序列
    /// @return 返回排序信息（交换次数和比较次数）
    lab2::utils::SortInfo sort(std::vector<int> &vec);
}

#endif // _QUICK_SORT_HPP_