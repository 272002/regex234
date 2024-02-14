#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums1 = {4, 7, 9, 7, 6, 7};
    vector<int> nums2 = {5, 0, 0, 6, 1, 6, 2, 2, 4};
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    vector<int> ans;
    int s1 = nums1.size();
    int s2 = nums2.size();
    if (s1 < s2)
    {
        int j = 0;
        for (int i = 0; i < s1;)
        {
            if (nums1[i] == nums2[j] && j < s2)
            {
                ans.push_back(nums2[j]);
                j++;
                i++;
            }
            else if (nums1[i] > nums2[j] && j < s2)
            {
                j++;
            }
            else if (j < s2)
            {
                i++;
            }
            else
            {
                break;
            }
        }
    }
    else
    {
        int j = 0;
        for (int i = 0; i < s2;)
        {
            if (nums2[i] == nums1[j] && j < s1)
            {
                ans.push_back(nums1[j]);
                j++;
                i++;
            }
            else if (nums2[i] > nums1[j] && j < s1)
            {
                j++;
            }
            else if (j < s1)
            {
                i++;
            }
            else
            {
                break;
            }
        }
    }

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}

// [4,7,9,7,6,7]
// [5,0,0,6,1,6,2,2,4]