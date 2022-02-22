#include <bits/stdc++.h>
using namespace std ;


int main()
{
    int e,f,c ; cin >> e >> f >> c;
    int totalDrinks=0;
    int totalBottles=e+f ;

    while(totalBottles>=c)
    {
        int newBottles=totalBottles/c;
        int rem=totalBottles%c;
        totalBottles=newBottles + rem ;
        totalDrinks+=newBottles; 
    }
    cout << totalDrinks << endl ;
}