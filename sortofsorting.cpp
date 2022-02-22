#include <bits/stdc++.h> 
using namespace std;

auto nameComparator=[](auto& a, auto& b)
{
    if (a[0]!=b[0])
    {
        return a[0]<b[0];
    }
    else return a[1]<b[1];
};

int main()
{
    int n=201;
    while (true)
    {

        cin >> n;
        if (n==0) break;
        vector <string> names;
        for (int i=0 ; i<n ; ++i)
        {
            string input;cin>>input;names.push_back(input);
        }
        stable_sort(names.begin(),names.end(),nameComparator);

        for (int i=0; i<n ; ++i)
        {
            cout << names[i] << "\n" ;
        }
        n=201;
        cout << "\n";
        continue;
    }
}