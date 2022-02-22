#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    ll n,k; cin>>n>>k;
    deque<pair<ll,ll>> ppl;

    while(n--){
        ll in,out; cin>>in>>out;
        ppl.push_back({in,out});
    }
    sort(ppl.begin(),ppl.end());
    //cout<<"people:"<<endl;
    //for (auto&[i,o]:ppl){cout<<i<<" "<<o<<endl;}

    multiset<ll> bar;
    ll timeNow;
    ll maxFriends=0;
    while (!ppl.empty()||!bar.empty()){ 
        if (!ppl.empty()){ //case where ppl is empty
            timeNow=ppl.front().first;
            bar.insert(ppl.front().second);
            ppl.pop_front();
        }
        else{
            timeNow=*bar.begin();
        }
        ll entry=*bar.begin();
        ll exit=entry+k;
        ll possibleFriends=0;
        for (auto it=bar.begin();it!=bar.end();++it){
            if (*it<=exit){
                possibleFriends++;
            }
        }
        maxFriends=max(possibleFriends,maxFriends);

        if (*bar.begin()<=timeNow){
            while(!bar.empty()){
                if (*bar.begin()<=timeNow){
                    bar.erase(bar.begin());
                    continue;
                }
                else{
                    break;// we cannot erase anymore
                }
            }
        }
        else{
            continue;
        }
    }
    cout<<maxFriends<<endl;

    
}