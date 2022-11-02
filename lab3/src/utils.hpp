#ifndef _UTILS_HPP_
#define _UTILS_HPP_

namespace lab2::utils
{
    class SortInfo
    {
    private:
        unsigned int _cmp_cnt;
        unsigned int _swap_cnt;

    public:
        SortInfo();

        void inc_swap_cnt();
        void inc_cmp_cnt();

        void set_cmp_cnt(unsigned int val);
        void set_swap_cnt(unsigned int val);

        unsigned int get_cmp_cnt();
        unsigned int get_swap_cnt();
    };
}

#endif // _UTILS_HPP_