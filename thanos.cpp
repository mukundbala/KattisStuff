#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T; cin >> T;
    long long int yearsArray[T];

    for (int i=0 ; i<T ; ++i)
    {
        long long int P , R , F ; cin>>P>>R>>F; //P is pupulation, R is growth rate, F is food
        int years=0;

        while (P<=F)
        {
            P*=R ;
            years ++;
        }
        yearsArray[i]=years;
    }

    for (int i=0 ; i<T ; ++i)
    {
        cout << yearsArray[i] << endl ;
    }
}