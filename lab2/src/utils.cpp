#include "utils.hpp"

lab2::utils::SortInfo::SortInfo()
{
    _swap_cnt = _cmp_cnt = 0;
}

void lab2::utils::SortInfo::inc_cmp_cnt()
{
    ++_cmp_cnt;
}

void lab2::utils::SortInfo::inc_swap_cnt()
{
    ++_swap_cnt;
}

void lab2::utils::SortInfo::set_cmp_cnt(unsigned int val)
{
    _cmp_cnt = val;
}

void lab2::utils::SortInfo::set_swap_cnt(unsigned int val)
{
    _swap_cnt = val;
}

unsigned int lab2::utils::SortInfo::get_cmp_cnt()
{
    return _cmp_cnt;
}

unsigned int lab2::utils::SortInfo::get_swap_cnt()
{
    return _swap_cnt;
}
