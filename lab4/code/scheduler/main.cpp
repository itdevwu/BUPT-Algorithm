// Copyright (c) 2022 Zhenglong WU.
// All rights reserved.

#include "lab4_core.hpp"

int main(int argc, char **argv)
{
    printf("Round-robin Tournament Scheduler\n\n");

    printf("Amount of players is: ");
    unsigned int n;
    scanf("%u", &n);

    auto calender = new lab4::Calender(n);

    calender->print_info();

    delete calender;

    return 0;
}
