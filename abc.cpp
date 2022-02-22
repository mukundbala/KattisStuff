#include <bits/stdc++.h>
using namespace std ;

int main()
{
    int n1,n2,n3 ; cin >> n1 >> n2 >> n3 ;
    string order;cin>>order;
    int o1,o2,o3 ; o1=order[0] ; o2=order[1] ; o3=order[2];
    vector <int> myvec; myvec.push_back(n1);myvec.push_back(n2);myvec.push_back(n3);
    int C=0; //C
    int A=101; //A
    int B;
    for (int i=0 ; i<3 ; ++i)
    {   
        if (myvec[i]>C) C=myvec[i];
        if (myvec[i]<A) A=myvec[i];
    }
    for (int i=0 ; i<3 ; ++i)
    {
        if (myvec[i]!=A || myvec[i]!=C) B=myvec[i];
    }

    
}