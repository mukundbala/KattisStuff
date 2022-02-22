//A0200081A
//Mukund Bala
//B07
//Walter Kong

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
auto comp = [](auto& a , auto& b)
{
    if (a.first==b.first){return tie(a.first,a.second) > tie(a.first,b.second);}
    return tie(a.first,a.second) < tie(b.first,b.second);
};

ll Priority(ll& time, ll& sev, ll& kval){
    ll priority=(sev-(time*kval));
    return priority;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    ll cases,k; cin>>cases>>k;
    priority_queue<pair<ll,string> , vector<pair<ll,string>> , decltype(comp) > triage(comp);
    unordered_map<string,bool> deadMap;
    ll triageNum=0;
    while(cases--){
        //cout << triageNum<<endl;
        ll query; cin>>query;
        if (query==1){
            ll time,severity;string name;
            cin>>time>>name>>severity;
            pair <ll,string> patientData;
            ll patientPriority=Priority(time,severity,k);
            //cout << name << " " << patientPriority<<endl;
            patientData={patientPriority,name};
            triage.push(patientData);
            triageNum++;
        }
        else if(query==2){
            ll doctime;cin>>doctime;
            if (triageNum==0){cout<<"doctor takes a break"<<"\n";}
            else{
                bool popped=false;
                while (!popped){
                    if (triageNum==0){cout<<"doctor takes a break"<<"\n";break;}
                    string topName=triage.top().second;
                    if (deadMap.find(topName)!=deadMap.end()){
                        triage.pop();triageNum--;continue;//this means that the person on top is already dead
                    }
                    else{triage.pop();popped=!popped;triageNum--;}
                    if (popped){cout<<topName<<"\n";break;}
                }
            }
        }    
        else if (query==3){
            ll deadTime;string deadName;cin>>deadTime>>deadName; //get the inputs
            deadMap[deadName]=true; //push into the map
        }
    }
    return 0;
}