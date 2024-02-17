#include <bits/stdc++.h>
using namespace std;
bool isAnagram(string s, string t)
{

    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    if (s == t)
    {
        return true;
    }
    return false;
}
int main()
{
    string s, t;
    cin >> s >> t;
    cout<<isAnagram(s, t);

    return 0;
}