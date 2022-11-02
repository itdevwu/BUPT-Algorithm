#ifndef _LAB4_CALENDER_HPP_
#define _LAB4_CALENDER_HPP_

#include "lab4_core.hpp"

namespace lab4
{
    class Calender
    {
        private:
            std::vector<std::vector<unsigned int> > _calender;
            unsigned int _player_amount;

            void _divide_conquer(unsigned int n);
            void _circle_table_even();
            void _circle_table_odd();

        public:
            bool is_pow_of_two();
            bool is_even();
            bool is_odd();

            void schedule();
            void print_info();

            Calender(unsigned int player_amount);
            ~Calender();
    };
}

#endif // _LAB4_CALENDER_HPP_