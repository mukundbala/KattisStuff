//A0200081A
//Mukund Bala
//B07
//Walter Kong
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<vector<ll>>AL; //adjacency list --> most common used for unweighted

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    ll N; cin>>N; //number of people
    ll D; cin>>D; //number of days
    
    AL.assign(N,vector<ll>());
    vector<bool> infected(N,false);
    queue<ll> infectedq;
    ll C; cin>>C; //number of infected people;
    for (int i=0 ; i<C;++i){
        ll infectedIdx; cin>>infectedIdx;infectedIdx-=1;
        infectedq.push(infectedIdx);
        infected[infectedIdx]=true; 
    }
    //cout<<"hello"<<endl;
    vector<pair<ll,ll>>times(N,pair<ll,ll>());
    for (int i=0 ;i<N;++i){
        ll s,t; cin>>s>>t;
        times[i]={s,t};
    }

    for (int i=0;i<N;++i){
        ll currentIdx=i;
        auto [c_entry,c_exit]=times[i];
        for (int j=0;j<N;++j){
            if (j==i){continue;} //we dont want duplicates
            else{
                ll checkIdx=j;
                auto [j_entry,j_exit]=times[checkIdx];
                if (max(c_entry,j_entry) <= min(c_exit,j_exit)){
                    AL[i].push_back(j);
                }
            }
        }
    }
/*
    for (int i=0;i<AL.size();++i){
        cout<<"IDX: "<<i<<endl;
        for (auto& a:AL[i]){
            cout<<a<<" ";
        }
        cout<<endl;
    }
*/
    //graph has been set up, with everyone connected to everyone who came at the same time

    //run bfs
    //Queue has been set up earlier
    //Visited is the list of infected people
    set<ll> allInfected;
    for (int i=0;i<D;++i){
        //repeat D times
        //cout<<"DAY: "<<D<<endl;
        vector<ll>infectedToday;
        while(!infectedq.empty()){
            ll infector=infectedq.front(); //o index of the infected guy
            //cout<<"INFECTED GUY IS INDEX: "<<infector<<endl;
            infectedq.pop();
            infected[infector]=1;
            allInfected.insert(infector);
            for (auto& a:AL[infector]){
               // cout<<"Person Infected: "<<a<<endl;
                //if our guy is already infected
                if (infected[a]==false){
                    infected[a]=true;
                    infectedToday.push_back(a);
                    allInfected.insert(a);
                }
                else continue;
            }
        }
        for (auto& person:infectedToday){
            infectedq.push(person);
        }
    }
    //cout<<"ALL INFECTED PEOPLE: "<<endl;
    for (auto it=allInfected.begin();it!=allInfected.end();++it){
        cout<<*it+1<<" ";
    }
    cout<<endl;

    return 0;
}