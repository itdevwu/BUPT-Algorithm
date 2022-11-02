#include "lab4_core.hpp"

void lab4::Calender::_divide_conquer(unsigned int n)
{
    if (n == 2)
    {
        _calender[1][1] = 1;
        _calender[1][2] = 2;
        _calender[2][1] = 2;
        _calender[2][2] = 1;
    }
    else
    {
        _divide_conquer(n / 2);
        auto bias = n / 2;
        for (auto i = 1; i <= bias; ++i)
        {
            for (auto j = 1; j <= bias; ++j)
            {
                _calender[i][j + bias] = _calender[i][j] + bias;
                _calender[i + bias][j + bias] = _calender[i][j];
                _calender[i + bias][j] = _calender[i][j + bias];
            }
        }
    }
}

unsigned int pos_in_day(unsigned int n, unsigned int pos, unsigned int day, unsigned int anchor)
{
    if (pos == anchor)
        return anchor;
    if ((pos + day) > n)
    {
        if ((pos + day) % n >= anchor)
            return ((pos + day) % n) + 1;
        else
            return (pos + day) % n;
    }
    else
        return pos + day;
}

void lab4::Calender::_circle_table_even()
{
    int anchor = 1;
    // OR: 1 <= day <= _player_amount - 1
    for (auto day = 1; day <= _player_amount - 1; ++day)
    {
        for (auto pos = 0; pos <= _player_amount / 2; ++pos)
        {
            _calender[pos_in_day(
                _player_amount,
                pos,
                day,
                anchor)]
                     [day] =
                         pos_in_day(_player_amount,
                                    _player_amount - pos + 1,
                                    day,
                                    anchor);
            _calender[pos_in_day(
                _player_amount,
                _player_amount - pos + 1,
                day,
                anchor)]
                     [day] =
                         pos_in_day(_player_amount,
                                    pos,
                                    day,
                                    anchor);
        }
    }
}

void lab4::Calender::_circle_table_odd()
{
    ++_player_amount;
    _circle_table_even();
    --_player_amount;
}

bool lab4::Calender::is_pow_of_two()
{
    auto amount = _player_amount;
    while (amount && !(amount & 1))
        amount >>= 1;
    return (amount == 1);
}

bool lab4::Calender::is_even()
{
    return !(_player_amount & 1);
}

bool lab4::Calender::is_odd()
{
    return (_player_amount & 1);
}

void lab4::Calender::schedule()
{
    if (is_pow_of_two())
    {
        _divide_conquer(_player_amount);
    }
    else if (is_even())
    {
        _circle_table_even();
    }
    else if (is_odd())
    {
        _circle_table_odd();
    }
    else
    {
        printf("\nERROR: Failed to classify type of this problem!\n");
        exit(0);
    }
}

void lab4::Calender::print_info()
{
    printf("\n=== Schedule Result ===\n\n");
    printf("Amount of players: %u\n", _player_amount);
    printf("Amount is power of 2: %s\n", is_pow_of_two() ? "true" : "false");
    printf("Amount is even: %s\n", is_even() ? "true" : "false");
    printf("Amount is odd: %s\n\n", is_odd() ? "true" : "false");
    printf("Scheduled Calender:\n");
    if (is_pow_of_two())
    {
        printf("\nScheduling Algorithm: Divide and Conquer\n");
        for (auto i = 1; i <= _player_amount; ++i)
        {
            printf("Player ");
            for (auto j = 1; j <= _player_amount; ++j)
            {
                printf("%u%s", (_calender[i][j] <= _player_amount ? _calender[i][j] : 0), (j == 1 ? ": " : " "));
            }
            printf("\n");
        }
    }
    else if (is_even())
    {
        printf("\nScheduling Algorithm: Circle Method\n");
        for (auto i = 1; i <= _player_amount; ++i)
        {
            printf("Player %u: ", i);
            for (auto j = 1; j < _player_amount; ++j)
            {
                printf("%u ", _calender[i][j]);
            }
            printf("\n");
        }
    }
    else if (is_odd())
    {
        printf("\nScheduling Algorithm: Circle Method with A Virtual Participant\n");
        // +1 for player V
        for (auto i = 1; i <= _player_amount + 1; ++i)
        {
            printf(
                "Player %s: ",
                (i <= _player_amount ? std::to_string(i).c_str() : "V"));
            for (auto j = 1; j < _player_amount + 1; ++j)
            {
                printf(
                    "%s ",
                    (_calender[i][j] <= _player_amount
                         ? std::to_string(_calender[i][j]).c_str()
                         : "V"));
            }
            printf("\n");
        }
        printf("NOTE: Player V is a virtual player, whose match is a bye match.\n\n");
    }
    else
    {
        printf("ERROR: Failed to classify type of this problem!\n");
        exit(0);
    }
    printf("\n========= End =========\n\n");
    printf("\n");
}

lab4::Calender::Calender(unsigned int player_amount)
{
    _player_amount = player_amount;
    _calender.resize(_player_amount + 2, std::vector<unsigned int>(_player_amount + 2));
    schedule();
}

lab4::Calender::~Calender()
{
    _calender.clear();
}