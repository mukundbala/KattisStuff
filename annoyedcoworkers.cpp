#include <bits/stdc++.h> //Solved
using namespace std;
typedef long long ll;
typedef pair<ll, ll> ii;

auto comp=[](auto& a, auto& b){
    return tie(get<0>(a),get<1>(a),get<2>(a))<tie(get<0>(b),get<1>(b),get<2>(b));
};

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    ll h,c; cin>>h>>c; //h:number of help times c: number of coworkers

    multiset<tuple<ll,ll,ll>,decltype(comp)> pq(comp);

    while(c--){
        ll a,d; cin>>a>>d;
        //vector containing (potentialAnnoyed,currentAnnoyed,annoyMore)
        tuple<ll,ll,ll>worker;
        worker=make_tuple(a+d,a,d);
        pq.insert(worker);
    }
    for (int i=0 ; i<h ; ++i){
        auto [future,current,add]=*pq.begin();
        pq.erase(pq.begin());
        //cout<<future<<" "<<current<<" "<<add<<endl;
        tuple<ll,ll,ll> update; update=make_tuple(future+add,current+add,add);
        pq.insert(update);
    }
    //cout<<"___________"<<endl;
    ll maxAnnoy=0;
    for (auto&[a,b,c]:pq){
        //cout<<a<<" "<<b<<" "<<c<<endl;
        maxAnnoy=max(maxAnnoy,b);
        //cout<<pq.size()<<endl;
    }
    //cout<<get<2>(*pq.rbegin())<<endl;
    //cout<<"-------"<<endl;
    cout<<maxAnnoy<<endl;
}