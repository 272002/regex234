#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> nums = {0,1,0,3,12};
    int n = nums.size();
    vector<int> ans;
    int cntzero = 0;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == 0)
        {
            cntzero++;
        }
        else
        {
            ans.push_back(nums[i]);
        }
    }
    for (int i = 0; i < cntzero; i++)
    {
        ans.push_back(0);
    }
    nums.clear();
    for (int i = 0; i < n; i++)
    {
        nums.push_back(ans[i]);
    }
    
    return 0;
}