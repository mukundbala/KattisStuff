#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


vector<vector<int>>AL;
vector<int>visited;
void dfs(int u){
    visited[u]=1;
    for (auto&v:AL[u]){
        if (!visited[v]){
            dfs(v);
        }
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);

    int n,m; cin>>n>>m;
    AL.assign(n,vector<int>());
    visited.assign(n,0);

    while(m--){
        int u,v; cin>>u>>v;
        AL[u-1].push_back(v-1);
        AL[v-1].push_back(u-1); //input taken in and added
    }
    /*
    for (int i=0 ; i<n ; ++i){
        cout<<"HOUSE: "<<i<<endl;
        for (auto&a:AL[i]){
            cout<< a << endl;
        }
    }
    */
    set<int> unconnected;
    for (int i=0 ; i<n; ++i){
        if (!visited[i]){
            if (i==0){
                dfs(i);
            }
            else{
                unconnected.insert(i);
            }
        }
    }
    if (unconnected.empty()){cout<<"Connected"<<endl; return 0;}
    for (auto&a:unconnected){
        cout<<a+1<<endl;
    }
    
    
    
    

    return 0;
}