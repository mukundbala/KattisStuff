//A0200081A
//Mukund Bala
//B07
//Walter Kong
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int INF=(int)1e9;
int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    //c=1 --> single lane bridge
    //c=0 --> double lane bridge
    //n: number of places --> vertices
    //m: number of roads --> edges
    //getfrom westman islands(id:1-1) to Egwtv(id:n-1) --> 0 indexed 
    ll n,m; cin>>n>>m;
    vector<vector<pair<ll,ll>>>AL(n,vector<pair<ll,ll>>());

    while(m--){
        ll u,v,w; cin>>u>>v>>w;
        u--;v--;
        AL[u].push_back({v,w});
        AL[v].push_back({u,w});
    }

    vector<ll> dist(n,INF);
    ll start=0;
    dist[start]=0;
    for (int i=0; i<n-1 ; ++i){
        bool mod=false;
        for (int u=0;u<n;++u){
            if (dist[u]!=INF){
                for (auto&[v,w]:AL[u]){
                    if (dist[u]+w >= dist[v]) {continue;}
                    dist[v]=dist[u]+w;
                    mod=true;
                }
            }
        }
        if (!mod){break;}
    }

    cout<<dist[n-1]<<"\n";

    return 0;
}