// C++ implementation to Divide two
// integers without using multiplication,
// division and mod operator
#include <bits/stdc++.h>
using namespace std;

// Function to divide a by b and
// return floor value it
int divide(long long _dividend, long long _divisor)
{
    if (_dividend == 1 << 31 || _divisor == -1)
        return INT32_MAX; // corner case
    // Calculate sign of divisor i.e.,
    // sign will be negative only iff
    // either one of them is negative
    // otherwise it will be positive
    int sign = ((_dividend < 0) ^ (_divisor < 0)) ? -1 : 1;

    // Update both divisor and
    // dividend positive
    int dividend = abs(_dividend);
    int divisor = abs(_divisor);

    //===================================
    // // Initialize the quotient
    // int quotient = 0;
    // while (dividend >= divisor)
    // {
    //     dividend -= divisor;
    //     quotient++;
    // }
    //====================================
    int quotient = 0;
    while (dividend - divisor >= 0)
    {

        int count = 0;
        while (dividend - (divisor << 1 << count) >= 0)
        {            // multiply divisor by 2with iterator;  10 - (3*2*count) (not 0 in case of left shift)
            count++; // kind of iterator
        }
        quotient += 1 << count; // count total subtraction (as we are doubling the divisor count will also double)

        dividend -= (divisor << count); // 10-> (10-6(highes 3 multiple))
    }

    // Return the value of quotient with the appropriate sign.

    return quotient * sign;
}

// Driver code
int main()
{
    int a = 10, b = 3;
    cout << divide(a, b) << "\n";

    a = 43, b = -8;
    cout << divide(a, b);

    return 0;
}
