//A0200081A
//Mukund Bala
//B07
//Walter Kong

//set implementation, delete players who leave from all 3 sets, and do the necessary checks before each subsequent choosing/erasure


#include <bits/stdc++.h>
using namespace std;

auto comp1=[](const auto& a, const auto& b){
    if (get<0>(a.first)==get<0>(b.first)){
        return a.second<b.second;
    }
    return get<0>(a.first)>get<0>(b.first);
};

auto comp2=[](const auto& a, const auto& b){
    if (get<1>(a.first)==get<1>(b.first)){
        return a.second<b.second;
    }
    return get<1>(a.first)>get<1>(b.first);
};

auto comp3=[](const auto& a, const auto& b){
    if (get<2>(a.first)==get<2>(b.first)){
        return a.second<b.second;
    }
    return get<2>(a.first)>get<2>(b.first);
};


int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    set<pair<tuple<int,int,int>,string>,decltype(comp1)>skill1(comp1);
    set<pair<tuple<int,int,int>,string>,decltype(comp2)>skill2(comp2);
    set<pair<tuple<int,int,int>,string>,decltype(comp3)>skill3(comp3);
    

    int N; cin>>N;
    while(N--){
        string name; int sk1,sk2,sk3;
        cin>>name>>sk1>>sk2>>sk3;
        pair<tuple<int,int,int>,string>data{{sk1,sk2,sk3},name};
        skill1.insert(data);skill2.insert(data);skill3.insert(data);
    }
    
    while(!skill1.empty() && !skill2.empty() && !skill3.empty()){
        if (skill1.empty() || skill2.empty() || skill3.empty()){break;}
        auto[data1,name1]=*skill1.begin();auto first=make_pair(data1,name1);
        skill1.erase(first);skill2.erase(first);skill3.erase(first);

        if (skill1.empty() || skill2.empty() || skill3.empty()){break;}
        auto[data2,name2]=*skill2.begin();auto second=make_pair(data2,name2);
        skill1.erase(second);skill2.erase(second);skill3.erase(second);
        
        if (skill1.empty() || skill2.empty() || skill3.empty()){break;}
        auto[data3,name3]=*skill3.begin();auto third=make_pair(data3,name3);
        skill1.erase(third);skill2.erase(third);skill3.erase(third);

        vector<string> myTeam={name1,name2,name3};
        sort(myTeam.begin(),myTeam.end());
        for (auto&a:myTeam){cout<<a<<" ";}
        cout<<"\n";

    }
    
    return 0;
}