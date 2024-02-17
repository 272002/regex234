#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s)
{
    string t;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            t.push_back(s[i]);
        }
        else if (s[i] >= 'A' && s[i] <= 'Z')
        {
            t.push_back(tolower(s[i]));
        }
        else if (s[i] >= '0' && s[i] <= '9')
        {
            t.push_back(s[i]);
        }
        
    }
    s = t;
    reverse(t.begin(), t.end());
    if (s == t)
    {
        return true;
    }
    return false;
}

int main()
{
    string s = "0P";
    cout << isPalindrome(s);
    return 0;
}