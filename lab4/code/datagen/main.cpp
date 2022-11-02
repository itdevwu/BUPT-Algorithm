#include <bits/stdc++.h>

/// @brief Data distribution: 40% are power of 2; 30% are even but not power of 2; 30% are odd. 
void datagen()
{
    srand(time(NULL));
    std::vector<int> data_vec;

    for (int i = 1; i <= 4; ++i)
    {
        std::array bias{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12}; // C++17
        std::random_shuffle(bias.begin(), bias.end());
        auto res = 1 << bias[rand() % bias.size()];
        while (!data_vec.empty() && std::find(data_vec.begin(), data_vec.end(), res) != data_vec.end())
        {
            std::random_shuffle(bias.begin(), bias.end());
            auto res = 1 << bias[rand() % bias.size()];
        }
        data_vec.push_back(res);

    }
    for (int i = 1; i <= 3; ++i)
    {
        int res = 0;
        for (int j = rand() % 9; (j >= 0) || (res & 1); --j)
        {
            if (rand() % 2)
                res |= 1;
            res <<= 1;
        }
        while (!data_vec.empty() && std::find(data_vec.begin(), data_vec.end(), res) != data_vec.end())
        {
            res <<= 1;
        }
        data_vec.push_back(res);
    }
    for (int i = 1; i <= 3; ++i)
    {
        int res = 0;
        for (int j = rand() % 9; (j >= 0); --j)
        {
            if (rand() % 2)
                res |= 1;
            res <<= 1;
        }
        res |= 1;
        while (!data_vec.empty() && std::find(data_vec.begin(), data_vec.end(), res) != data_vec.end())
        {
            res <<= 1;
            res |= 1;
        }
        data_vec.push_back(res);
    }

    for (auto i = 0; i < data_vec.size(); ++i) // ignore performance cost
    {
        freopen((std::to_string(i) + ".txt").c_str(), "w", stdout);
        printf("%d\n", data_vec[i]);
    }
}

int main(int argc, char *argv[])
{
    datagen();
}