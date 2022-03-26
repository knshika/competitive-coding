#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void actionT(int &idx, string &nums)
    {
        if (nums[idx] != 9)
            nums[idx]++;
    }
    void actionD(int &idx, string &nums)
    {
        if (nums[idx] != 0)
            nums[idx]--;
    }
    void actionSn(int &idx, char n, string &nums)
    {
        int i = n - '0';
        swap(nums[idx], nums[i - 1]);
    }

    void encryptNums(string &nums, string actions)
    {
        int n = nums.size();
        int m = actions.size();
        int idx = 0, i = 0;
        while (i < m)
        {

            switch (actions[i])
            {
            case 'R':
                idx++;
                break;
            case 'L':
                idx--;
                break;
            case 'T':
                actionT(idx, nums);
                break;
            case 'D':
                actionD(idx, nums);
                break;

            default:
            {
                i++;
                actionSn(idx, actions[i], nums);
            }
            break;
            }
            i++;
        }
    }
};

int main()
{

    string nums, actions;
    cin >> nums;
    cin >> actions;

    Solution obj;
    obj.encryptNums(nums, actions);
    cout << nums;

    return 0;
}
// 123456
// RLTDRRTRS2S1