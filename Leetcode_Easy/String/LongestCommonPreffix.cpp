#include <bits/stdc++.h>
using namespace std;

string longestCommonPrefix(vector<string> &strs)
{
    string ans = "";
    int n = strs.size();
    for (int i = 0; i < strs[0].size(); i++)
    {
        char ch = strs[0][i];
        bool flag = true;
        for (int j = 1; j < n; j++)
        {
            if (strs[j].size() < i || strs[j][i] != ch)
            {
                flag = false;
            }
        }
        if (flag == false)
        {
            break;
        }
        ans.push_back(ch);
    }
    return ans;
}

int main()
{
    vector<string> strs = {"flower","flow","flight"};
    cout<<longestCommonPrefix(strs);
    return 0;
}