#include <bits/stdc++.h> //done!
using namespace std;


int main()
{
    vector <int> control={0,0,0}; //infection rate
    double controlNum=0; // totaNumber in control
    vector <int> test={0,0,0}; //infection rate
    double testNum=0; // totaNumber in control

    int N; cin>>N;

    while (N--)
    {
        string data; cin >> data;

        if (data[0]=='N')
        {
            ++controlNum;
            for (int i=1 ; i<4;++i)
            {
                if (data[i]=='Y') {++control[i-1];}
            }
        }
        else if (data[0]=='Y')
        {
            ++testNum;
            for (int i=1 ; i<4;++i)
            {
                if (data[i]=='Y') {++test[i-1];}
            }
        }
    }

    for (int i=0 ; i<3 ; ++i)
    {
        double controlInfected=control[i];
        double testInfected=test[i];
        double controlRate=(controlInfected/controlNum)*100;
        double testRate=(testInfected/testNum)*100;

        if (controlRate<=testRate) {cout << "Not Effective"<<endl;}
        else
        {
            double decrease=((controlRate-testRate)/controlRate) *100;
            cout <<setprecision(6)<< decrease <<endl;
        }
    } 
}   