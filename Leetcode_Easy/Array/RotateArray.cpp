#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums = {-1, -100, 3, 99};
    int k = 2;
    int n = nums.size();
    k = k % n;
    reverse(nums.begin(), nums.begin() + (n - k));

    reverse(nums.begin() + (n - k), nums.end());

    reverse(nums.begin(), nums.end());

    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << " ";
    }

    return 0;
}