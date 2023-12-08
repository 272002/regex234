#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> &arr, int k, int point)
{
    sort(arr.begin(), arr.end());
    int mx = point;
    int ans = point;
    int l = 0, r = arr.size() - 1;
    while (l <= r)
    {
        if (k >= arr[l])
        {
            ans++;
            k = k - arr[l];
            l++;
        }
        else
        {
            k = k + arr[r];
            r--;
            ans--;
        }
        mx = max(mx, ans);
    }
    cout << mx << endl;
}

int main()
{
    string s;
    string a;
    int l, point = 1, k;
    getline(cin, s);
    cin >> k;
    vector<int> arr;
    string::size_type i = 0;
    for (i = 0; i < s.size(); i++)
    {
        if (s[i] == ' ')
        {
            l = stoi(a);
            arr.push_back(l);
            a.clear();
        }
        else
        {
            a += s[i];
        }
    }
    l = stoi(a);
    arr.push_back(l);
    solve(arr, k, point);
    return 0;
}
