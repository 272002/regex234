#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums = {8, 9, 9, 2};
    int n = nums.size();
    int cry = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (nums[i] < 9)
        {
            nums[i] += 1;
            cry = 0;
            break;
        }
        else
        {
            nums[i] = 0;
            cry = 1;
        }
    }
    vector<int> ans;
    if (cry == 1)
    {
        ans.push_back(cry);
    }
    for (int i = 0; i < n; i++)
    {
        ans.push_back(nums[i]);
    }
    return 0;
}