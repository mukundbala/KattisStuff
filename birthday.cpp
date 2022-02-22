#include <bits/stdc++.h>
using namespace std ;

auto friendComparator=[](auto& a, auto& b)
{
    return (tuple(get<2>(a) ,get<3>(a), get<1>(b)) < tuple(get<2>(b) ,get<3>(b) , get<1>(a))) ;
};

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N ; cin >> N ;
    vector <tuple<string,int,int,int>> friends;
    vector <string> bestfriends;
    for (int i=0 ; i<N ;++i)
    {
        string name,ddmm;
        int like,day,month ;
        cin >> name >> like >>ddmm ;
        
        if (ddmm[0]=='0')
        {
            day=ddmm[1]-48 ;
        }
        else
        {
            string daystr=ddmm.substr(0,2);
            day=stoi(daystr);
        }
        if (ddmm[3]=='0')
        {
            month=ddmm[4]-48;
        }
        else
        {
            string montstr=ddmm.substr(3,2);
            month = stoi(montstr);
        }
        tuple <string,int,int,int> myFriend ;
        myFriend=make_tuple(name,like,day,month);
        friends.push_back(myFriend);
    }
    sort(friends.begin(),friends.end(),friendComparator);

    int currentDay=0;
    int currentMonth=0;

    for (int i=0 ; i<friends.size() ; ++i)
    {
        string friendName=get<0>(friends[i]);
        int like=get<1>(friends[i]);
        int day=get<2>(friends[i]);
        int month=get<3>(friends[i]);
        
        if (currentDay==day && currentMonth==month) continue ;
        else
        {
            currentDay=day;
            currentMonth=month;
            bestfriends.push_back(friendName);
        }
    }
    sort(bestfriends.begin(),bestfriends.end());
    cout << bestfriends.size() << endl ;
    for (int i=0 ; i<bestfriends.size() ; ++i)
    {
        cout << bestfriends[i] << endl;
    }
    return 0;
}