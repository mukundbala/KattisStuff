//A0200081A
//Mukund Bala
//B07
//Walter Kong

#include <bits/stdc++.h>
#include <iomanip>
using namespace std;
typedef long long ll;


int tupval (const tuple<ll,ll,ll>& a,int idx){
    //auto x=tie(get<0>(a),get<1>(a),get<2>(a));
    if (idx==0){return get<0>(a);} //time of entry
    else if (idx==1){return get<1>(a);} //type
    else {return get<2>(a);} //timetofinish
}

//function that find the {minTime,minTimeIdx} in an array of technicians
pair<ll,ll> freeTechnician(vector<ll>& a){
    vector<ll> ::iterator it_small=min_element(a.begin(),a.end());
    pair<ll,ll> data{*it_small,it_small-a.begin()}; //{first:min_time,second:minIDx}
    return data;
}


int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    ll cases,numTech; cin>>cases>>numTech;
    long long Snum=0;long long Rnum=0;
    vector<long long> presTime(2,0); //Index S=0, Index R=1; Array containing the cumulative time of each prescription
    vector<ll> Tech(numTech,0); //vector containing the time availabilities of numTech technicians
    pair<ll,ll> minTechData; //{vector containing the smallest techncian's timep and his corresponding index in a pair} first: time , second: index
    priority_queue<tuple<ll,ll,ll>,vector<tuple<ll,ll,ll>>,greater<tuple<ll,ll,ll>>> PQ; //main queue
    deque<tuple<ll,ll,ll>> Rwait,Swait; //waiting queues for R and S each. No sorting required. Insertions will be push_back, Extraction will be pop_front (FIFO)
   
    while (cases--){ //sending input into main priority queue PQ1
        ll time,timetaken;char presType;
        cin>>time>>presType>>timetaken;
        tuple<ll,ll,ll> presData;
        if (presType=='R'){presData=make_tuple(time,1,timetaken);Rnum++;}
        else {presData=make_tuple(time,0,timetaken);Snum++;}
        PQ.push(presData);
    }
    //while(!PQ.empty()){cout<<tupval(PQ.top(),0)<<" "<<tupval(PQ.top(),1)<<" "<<tupval(PQ.top(),2)<<endl;PQ.pop();}
    //cout<<Snum<<endl;
    //cout<<Rnum<<endl;
    //return 0;
    ll timeNow=0; //keep track of time
    while (!PQ.empty() || !Rwait.empty() || !Swait.empty()) //while PQ is full or Rwait is full or Swait is full
    {
        timeNow=tupval(PQ.top(),0); //timeNow set to the top of the heap, ok
        minTechData=freeTechnician(Tech); //calculate minTechData ,ok
        //cout << "Main LOOP : " <<minTechData.first<<" " << minTechData.second<<endl;
        //cout << "Main LOOP TIME: "<<timeNow<<endl; 
        if (timeNow>=minTechData.first){
            Tech[minTechData.second]=tupval(PQ.top(),0) + tupval(PQ.top(),2); //ok
            presTime[tupval(PQ.top(),1)]+=tupval(PQ.top(),2); //ok
            //cout << tupval(PQ.top(),0)<<" "<<tupval(PQ.top(),1)<<" "<<tupval(PQ.top(),2)<<" popped!"<<endl;
            PQ.pop(); //ok
            continue;
        }
        else{
            if (tupval(PQ.top(),1)==1){Rwait.push_back(PQ.top());timeNow=tupval(PQ.top(),0);PQ.pop();}
            else {Swait.push_back(PQ.top());timeNow=tupval(PQ.top(),0);PQ.pop();}
        }
        
        while (!Rwait.empty() || !Swait.empty()){
            minTechData=freeTechnician(Tech);
            //cout << "Secondary LOOP: " <<minTechData.first<<" " << minTechData.second<<endl;
            //cout <<"Secondary LOOP TIME: "<<timeNow<<endl;
            if (timeNow<minTechData.first){
                if (PQ.empty()){timeNow=minTechData.first;continue;}
                else{
                    timeNow=tupval(PQ.top(),0); //update TimeNow
                    //cout << tupval(PQ.top(),0)<<" "<<tupval(PQ.top(),1)<<" "<<tupval(PQ.top(),2)<<" popped to DEQUE!"<<endl;
                    if (tupval(PQ.top(),1)==1){Rwait.push_back(PQ.top());PQ.pop();}
                    else{Swait.push_back(PQ.top());PQ.pop();}
                    continue;
                }
            }
            else{
                if (!Rwait.empty() && !Swait.empty()){
                    //cout<<"EXPOSED R HEAD: "<<"["<<tupval(Rwait.front(),0)<<","<<tupval(Rwait.front(),1)<<","<<tupval(Rwait.front(),2)<<"]"<<endl;
                    //cout<<"EXPOSED S HEAD: "<<"["<<tupval(Swait.front(),0)<<","<<tupval(Swait.front(),1)<<","<<tupval(Swait.front(),2)<<"]"<<endl;
                    if (tupval(Rwait.front(),0)<=minTechData.first && tupval(Swait.front(),0)>minTechData.first){ //Pop from R bucket
                        Tech[minTechData.second]=minTechData.first+tupval(Rwait.front(),2);
                        presTime[1]+= minTechData.first - tupval(Rwait.front(),0) + tupval(Rwait.front(),2);
                        Rwait.pop_front(); //pop from the front
                        //cout <<"case 1a: "<<"POPPED FROM RWAIT"<<endl;
                        continue; //ok
                        
                    }
                    else if (tupval(Swait.front(),0)<=minTechData.first && tupval(Rwait.front(),0)>=minTechData.first){ //Pop from S bucket
                        Tech[minTechData.second]=minTechData.first+tupval(Swait.front(),2);
                        presTime[0]+= minTechData.first - tupval(Swait.front(),0) + tupval(Swait.front(),2);
                        Swait.pop_front();
                        //cout <<"case 1b: "<< "POPPED FROM SWAIT"<<endl;
                        continue;//ok
                    }
                    else if (tupval(Swait.front(),0)<=minTechData.first && tupval(Rwait.front(),0)<=minTechData.first){ //if both are less than the minTech, just pop fron S Bucker
                        Tech[minTechData.second]=minTechData.first+tupval(Swait.front(),2);
                        presTime[0]+= minTechData.first - tupval(Swait.front(),0) + tupval(Swait.front(),2);
                        Swait.pop_front();
                        //cout <<"case 1c: "<< "POPPED FROM SWAIT"<<endl; //ok!
                        continue; //if both are less than or equal to minTechTime, Technician will choose from Swait
                    }//ok
                    //cout<<"none of the choices in case 1"<<endl;
                }
                else if (Swait.empty() && !Rwait.empty()){ //Swait empty
                    //cout<<"EXPOSED R HEAD: "<<"["<<tupval(Rwait.front(),0)<<","<<tupval(Rwait.front(),1)<<","<<tupval(Rwait.front(),2)<<"]"<<endl;
                    //if (Swait.empty()){cout<<"Swait is Empty"<<endl;}
                    if ((tupval(PQ.top(),0)==timeNow) && tupval(PQ.top(),1)==0){
                        timeNow=tupval(PQ.top(),0);//will be the same
                        minTechData=freeTechnician(Tech);//will be the same
                        Swait.push_back(PQ.top());
                        PQ.pop();
                        continue;
                    }
                    else{
                        if (tupval(Rwait.front(),0) <= minTechData.first){
                            Tech[minTechData.second]=minTechData.first+tupval(Rwait.front(),2);
                            presTime[1]+= (minTechData.first - tupval(Rwait.front(),0) + tupval(Rwait.front(),2));
                            Rwait.pop_front(); //pop from the front
                            //cout<<"case 2a: "<<"POPPED FROM RWAIT"<<endl;
                            continue;
                        }
                        else{
                            Tech[minTechData.second]=tupval(Rwait.front(),0)+tupval(Rwait.front(),2);
                            presTime[1]+=tupval(Rwait.front(),2);
                            Rwait.pop_front();
                            //cout<<"case 2b: "<<"POPPED FROM RWAIT"<<endl;
                            continue;
                        }
                    }
                    //cout<<"none of the choices in case 2"<<endl;
                }
                else if (Rwait.empty() && !Swait.empty()){ //pop stuff from S
                    //cout<<"EXPOSED S HEAD: "<<"["<<tupval(Swait.front(),0)<<","<<tupval(Swait.front(),1)<<","<<tupval(Swait.front(),2)<<"]"<<endl;
                    //if (Rwait.empty()){cout<<"Rwait is Empty"<<endl;}
                    if (tupval(Swait.front(),0) <= minTechData.first){
                        Tech[minTechData.second]=minTechData.first+tupval(Swait.front(),2);
                        presTime[0]+= minTechData.first - tupval(Swait.front(),0) + tupval(Swait.front(),2);
                        Swait.pop_front(); //pop from the front
                        //cout<<"case 3a: "<<"POPPED FROM SWAIT"<<endl;
                        continue;
                    }
                    else{
                        Tech[minTechData.second]=tupval(Swait.front(),0)+tupval(Swait.front(),2);
                        presTime[0]+=tupval(Swait.front(),2);
                        Swait.pop_front();
                        //cout<<"case 3b: "<<"POPPED FROM SWAIT"<<endl;
                        continue;
                    }
                }
                else if (Rwait.empty() && Swait.empty()){
                    //cout<< "Rwait and Swait Empty. Proceed to main loop"<<endl;
                    break;

                }
            }
        }
    }
    if (Snum==0){
        cout << 0 << " ";
    }
    else{
        cout<<fixed;
        cout << setprecision(6)<<(double)presTime[0]/(double)Snum << " ";
    }
    if (Rnum==0){
        cout << 0 <<endl;
    }
    else{
        cout<<fixed;
        cout << setprecision(6)<<(double)presTime[1]/(double)Rnum <<endl;
    }

}