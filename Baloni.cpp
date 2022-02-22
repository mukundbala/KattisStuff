//Baloni
# include <bits/stdc++.h>
using namespace std;

int main()
{
    vector <int> popcount(1000001,0); //sacrifice 0
    int N; cin >> N ; //number of balloons
    
    for (int i=0 ; i<N ; ++i)
    {
        int height; cin>>height;
        if (popcount[height]==0) //unpopped
        {
            popcount[height] +=1;
        }
        else
        {
            popcount[height] -=1;
            popcount[height-1]+=1;
        } 
    }
    int arrows=0 ;

    for (int i=0 ; i<popcount.size()-1 ; ++i)
    {
        arrows+=popcount[i];
    }

    cout << arrows << endl;
}