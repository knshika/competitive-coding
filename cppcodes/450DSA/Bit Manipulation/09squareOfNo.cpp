// sq(0)=0;
// If n is even, it can be written as
//   n = 2*x
//   n2 = (2*x)2 = 4*x2
// If n is odd, it can be written as
//   n = 2*x + 1
//   n2 = (2*x + 1)2 = 4*x2 + 4*x + 1

//=================
// square(num) = 15 * 15
//                           = 15 * (8 + 4 + 2 + 1) = (15 * 8) + (15 * 4) + (15 * 2) + (15 * 1)

// Square of a number using bitwise operators
#include <bits/stdc++.h>
using namespace std;

int square(int n)
{

    int setbitPos = 0, res = 0, mask = 1, temp = n, s;
    while (temp)
    {
        s = mask & n;
        if ((mask & n) != 0)
        {

            res += n << setbitPos;
        }
        setbitPos++;
        mask = mask << 1;
        temp = temp >> 1;
    }
    return res;
}

// Driver Code
int main()
{
    // Function calls
    for (int n = 1; n <= 5; n++)
        cout << "n = " << n << ", n^2 = " << square(n)
             << endl;
    return 0;
}

// if (n < 0)
//         n = -n;

//     // Initialize result
//     int res = n;

//     // Add n to res n-1 times
//     for (int i = 1; i < n; i++)
//         res += n;

//     return res;
//===========================

// // Base case
// if (n == 0)
// 	return 0;

// // Handle negative number
// if (n < 0)
// 	n = -n;

// // Get floor(n/2) using right shift
// int x = n >> 1;

// // If n is odd
// if (n & 1)
// 	return ((square(x) << 2) + (x << 2) + 1);
// else // If n is even
// 	return (square(x) << 2);
//==============================
