// Josephus Problem | Game of Death in a circle | Execution in Circle

// There are n people standing in a circle (numbered clockwise 1 to n) waiting to be executed. The counting begins at point 1 in the circle and proceeds around the circle in a fixed direction (clockwise). In each step, a certain number of people are skipped and the next person is executed. The elimination proceeds around the circle (which is becoming smaller and smaller as the executed people are removed), until only the last person remains, who is given freedom.
// Given the total number of persons n and a number k which indicates that k-1 persons are skipped and kth person is killed in circle. The task is to choose the place in the initial circle so that you are the last one remaining and so survive.
// Consider if n = 5 and k = 2, then the safe position is 3.
// Firstly, the person at position 2 is killed, then person at position 4 is killed, then person at position 1 is killed. Finally, the person at position 5 is killed. So the person at position 3 survives.

// n=40, k=7 then ans=24

// recursive problem on its own , input originally depends on previous output

// https://www.youtube.com/watch?v=ULUNeD0N9yI&list=PL_z_8CaSLPWeT1ffjiImo0sYTcnLzo-wY&index=19 start from 20 min ig

// hypothesis : array/vector with initially value == index ,
// then find the index of man to be killed using n and k (since array starts with0 we take k=k-1) index = (index + k-1)%n (for circular)
// also we have to remove this element so that elements can move forward

// base : obv when v.size==1 we got our last man , so print v[0]

// induction : since we dont need deleted index again there wont be any induction step , just pass v and index of prev output

#include <bits/stdc++.h>
using namespace std;

void josephus(vector<int> v, int index, int k, int &ans)
{
    if (v.size() == 1)
    {
        ans = v[0];
        cout << v[0];
        return;
    }
    index = (index + k) % v.size();
    v.erase(v.begin() + index);
    josephus(v, index, k, ans);
    /* The position returned by josephus(n - 1, k)
    is adjusted because the recursive call
    josephus(n - 1, k) considers the
    original position k % n + 1 as position 1 */
}

// Driver Program to test above function
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> v;
    int ans = -1, index = 0;
    k--;
    for (int i = 1; i <= n; i++)
    {
        v.push_back(i);
    }

    josephus(v, index, k, ans);
    cout << ans;
    return 0;
}
