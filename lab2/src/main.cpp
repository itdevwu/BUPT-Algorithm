#include <iostream>
#include <cstdio>

#include "quick_sort.hpp"

int main(int argc, char *argv[])
{
    printf("快速排序:\n");

    std::vector<int> vec = {4, -3, 1, 6, 9, -7};

    lab2::quick_sort::sort(vec);

    for (auto x : vec)
    {
        printf("%d\n", x);
    }

    return 0;
}
