#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr1;
    vector<int> arr2;
    int n, ele;
    cin>>n;

    for (int i = 0; i < n; i++)
    {
        cin >> ele;
        arr1.push_back(ele);
    }
    int k = 0;
    arr2.push_back(arr1[k]);
    for (int i = 1; i < n; i++)
    {
        if (arr1[i] != arr2[k])
        {
            k++;
            arr2.push_back(arr1[i]);
        }
    }
    cout << arr2.size() << endl;
    return 0;
}