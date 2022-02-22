#include <bits/stdc++.h>
using namespace std;



int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N,Q; cin>>N>>Q; //N:nuumber of people, Q:number of events
    unordered_map<int,int> ppl;
    int globalUpdate=0; 

    while(Q--){
        string cmd; cin>>cmd;
        if (cmd=="PRINT"){
            int idx; cin>>idx;
            if (ppl.find(idx)==ppl.end()){cout<<globalUpdate<<"\n";}
            else{
                cout<<ppl[idx]<<"\n";
            }
            
        }
        else if (cmd=="SET"){
            int idx,val; cin>>idx>>val;
            ppl[idx]=val;
        }
        else if (cmd=="RESTART"){
            int val; cin>>val;
            globalUpdate=val;
            ppl.clear();
        }
    }
    return 0;
}