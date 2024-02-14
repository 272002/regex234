#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums = {2,2};
    int target = 4;
    int n = nums.size();
    map<int, int> mp;
    for (int i = 0; i < nums.size(); i++)
    {
        mp[nums[i]] = i;
    }
    int cl = 0;
    vector<int> ans;
    for (int i = 0; i < nums.size(); i++)
    {
        if ((mp.find(target - nums[i]) != mp.end()) && mp[target - nums[i]] != i)
        {
            ans.push_back(i);
            ans.push_back(mp[target - nums[i]]);
            cl = 1;
            break;
        }
    }
    if (cl == 1)
    {
        for (int i = 0; i < ans.size(); i++)
        {
            cout<<ans[i]<<" ";
        }
        
    }
    else
    {
        cout<<-1<<" "<<-1;
    }

    return 0;
}