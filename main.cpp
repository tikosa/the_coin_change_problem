#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

// https://www.hackerrank.com/challenges/coin-change

// Write a program that, given
//
// The amount N to make change for and the number of types M of infinitely available coins
// A list of  coins - C = {C1, C2, ... , CM}
// Prints out how many different ways you can make change from the coins to STDOUT.
//
// Sample Input 
//
// 10 4
// 2 5 3 6
// Sample Output 
//
// 5
// {2,2,2,2,2}, {2,2,3,3}, {2,2,6}, {2,3,5}, {5,5}

struct Problem
{
    int amount;
    std::vector<int> coins;

    void input()
    {
        std::cin >> amount;
        int N = 0;
        int coin = 0;
        std::cin >> N;
        ++N;
        while(--N && std::cin >> coin)
        {
            coins.push_back(coin);
        }
    }

    void solve()
    {
        std::vector<int> m(amount+1);
        std::fill(m.begin(), m.end(), 0);
        m[0] = 1;

        for(int i = 0; i < coins.size(); ++i)
        {
            for(int j = 0; j <= amount; ++j)
            {
                if(j - coins[i] >= 0)
                {
                    m[j] += m[j - coins[i] ];
                }
            }
        }

        std::cout << m[amount] << std::endl;
    }
};

int main()
{
    Problem p;
    p.input();

    p.solve();

    return 0;
}
