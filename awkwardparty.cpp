#include <bits/stdc++.h> //solved. lame qn
using namespace std;
typedef long long ll;


int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    map<ll,vector<ll>> guests; //map to store the language, vector to store the list of position of these people, with last know at the back
    ll n; cin>>n;
    ll total=n;
    ll pos=0;
    ll awk=0;
    
    
    while(n--){
        ll g; cin>>g;
        guests[g].push_back(pos);
        pos+=1;
    }
    ll max=total;
    for (auto[lang,arr]:guests){
        if (arr.size()==1){continue;}
        else{
            for (int i=1;i<arr.size();++i){
                if (arr[i]-arr[i-1] <max){
                    max=arr[i]-arr[i-1];
                }
            }
        }
    }
    cout<<max<<endl;
    return 0;
}