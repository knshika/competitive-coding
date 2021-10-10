//  C++ program to check if two given strings
// are rotations of  each other
#include <bits/stdc++.h>
using namespace std;

/* Function checks if passed strings (str1
   and str2) are rotations of each other */
bool areRotations(string str1, string str2)
{

    if (str1.length() != str2.length())
    {
        return 0;
    }
    int n = str1.length();

    queue<char> q1;
    for (int i = 0; i < n; i++)
    {
        q1.push(str1[i]);
    }
    queue<char> q2;
    for (int i = 0; i < n; i++)
    {
        q2.push(str2[i]);
    }

    while (n--)
    {
        char ch = q2.front();
        q2.pop();
        q2.push(ch);
        //check if at any iteration they are equal
        if (q2 == q1)
            return 1;
    }

    return 0;
}

/* Driver program to test areRotations */
int main()
{
    // string str1 = "AACD", str2 = "ACDA";
    // string str1 = "AABCD", str2 = "DCBAA";
    string str1 = "ABACD", str2 = "CDABA";

    if (areRotations(str1, str2))
        printf("Strings are rotations of each other");
    else
        printf("Strings are not rotations of each other");
    return 0;
}