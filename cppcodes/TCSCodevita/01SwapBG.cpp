#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int MinSwapsReq(string seats)
    {

        int n = seats.size();
        int countG = 0, countB = 0, res = 0;

        for (int i = 0; i < n; i++)
        {
            if (seats[i] == 'G')
                countG++;
            else
                countB++;
        }

        // when string length is even
        if (n % 2 == 0)
        {
            int oddG = 0, evenG = 0;
            for (int i = 0; i < n; i++)
            {
                if (seats[i] == 'G')
                {
                    if (i % 2 == 0)
                    {
                        evenG++;
                    }
                    else
                    {
                        oddG++;
                    }
                }
            }
            return min(n / 2 - oddG, n / 2 - evenG);
        }
        // when string length is odd
        else
        {
            int N = (n + 1) / 2;
            int evenG = 0, evenB = 0;
            for (int i = 0; i < n; i++)
            {
                if (i % 2 == 0)
                {
                    if (seats[i] == 'G')
                        evenG++;
                    else
                        evenB++;
                }
            }
            if (countG > countB)
                return N - evenG;
            else
                return N - evenB;
        }

        return res;
    }
};

int main()
{

    string seats;
    cin >> seats;
    Solution obj;
    int result = obj.MinSwapsReq(seats);
    cout << result;

    return 0;
}

// End 99 98 S(7) 96 95 94 93 92 91
// 81 82 L(99) 84 85 86 87 88 89 90
// 80 79 78 77 76 75 74 73 72 71
// 61 S(22) 63 64 65 66 67 68 69 70
// 60 59 58 S(14) 56 57 54 53 52 51
// 41 42 43 44 45 46 L(80) 48 49 50
// 40 39 38 37 36 35 34 33 32 31
// 21 22 23 L(63) 25 26 27 28 29 30
// 20 19 S(2) 17 16 15 14 13 12 11
// Start 2 3 4 5 6 7 8 9 10

// 6 6 6 5 4 3 6 6 6 5 6 4 3 1