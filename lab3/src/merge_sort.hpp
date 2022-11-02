#ifndef _MERGE_SORT_HPP_
#define _MERGE_SORT_HPP_

#include "utils.hpp"

#include <vector>
#include <functional>

namespace lab2::merge_sort
{
    /// @brief 归并排序(借助辅助空间)
    /// @param vec 引用目标序列
    /// @return 返回排序信息（交换次数和比较次数）
    lab2::utils::SortInfo sort(std::vector<int> &vec);
}

#endif // _MERGE_SORT_HPP_