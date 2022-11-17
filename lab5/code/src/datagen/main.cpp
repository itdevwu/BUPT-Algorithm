// Copyright (c) 2022 Zhenglong WU.

// C++20 required!

#include <iostream>
#include <cstdio>
#include <random>
#include <vector>

int qpow(int a, int n)
{
    int res = 1;
    while (n)
    {
        if (n & 1)
            res *= a;
        n >>= 1;
        a *= a;
    }
    return res;
}

int main(int argc, char *argv[])
{
    std::random_device r_d;
    std::mt19937 r_g(r_d());

    double p = 0.8;

    system("pwd");
    if (argc == 2)
    {
        sscanf(argv[1], "%lf", &p);
        if (!(p >= 0 && p <= 1))
        {
            printf("WRONG PROBABILITY! RESETING...\n");
            p = 0.8;
        }
    }
    else if (argc != 1)
    {
        printf("WRONG FORMAT OF ARGUMENTS! RESETING...\n");
    }
    printf("PROBABILITY: %g\n\n", argc, p);

    for (auto data_set = 1; data_set <= 4; ++data_set)
    {
        printf("TEST SET No. %d\n", data_set);

        auto fp = fopen(("./data/" + std::to_string(data_set) + ".txt").c_str(), "w+");

        auto depth = (data_set == 1 ? 5 : qpow(10, data_set - 1));
        auto total_node = (int)(depth * (depth + 1) * 0.5);
        printf("DEPTH: %d\n", depth);
        printf("TOTAL NODE: %d\n", total_node);
        fprintf(fp, "%d\n", depth);

        std::vector<int> data(total_node);
        std::vector<std::pair<int, int> > masks;
        for (auto i = 1; i <= total_node; ++i)
        {
            if ((double)i / (double)total_node <= p)
            {
                data[i - 1] = std::rand() % 9 + 1;
            }
            else
            {
                data[i - 1] = -1;
            }
        }

        // C++20 required!
        std::shuffle(data.begin(), data.end(), r_g);

        for (auto i = 1; i <= depth; ++i)
        {
            for (auto j = 1; j <= i; ++j)
            {
                auto index = j + (int)(i * (i - 1) * 0.5) - 1;
                printf("%d ", data[index]);
                fprintf(fp, "%d ", (data[index] == -1) ? (std::rand() % 9 + 1) : data[index]);
                if (data[index] == -1)
                {
                    masks.push_back(std::make_pair(i, j));
                }
            }
            printf("\n");
            fprintf(fp, "\n");
        }
        for (auto mask : masks)
        {
            fprintf(fp, "%d %d\n", mask.first, mask.second);
        }
        printf("\n");

        fclose(fp);
    }
}