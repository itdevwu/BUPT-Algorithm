// Copyright (c) 2022 Zhenglong WU.

#include <bits/stdc++.h>

int main(int argc, char *argv[])
{
    srand(time(nullptr));

    int count = 0;
    if (argc >= 2)
        count = atoi(argv[1]);

    std::cout << count << '\n';
    for (auto i = 1; i <= count; ++i)
    {
        int sign = ((rand() % 2 == 0) ? -1 : 1);
        int abs_val = rand() % 10;

        std::cout << sign * abs_val << ' ';
    }

    return 0;
}