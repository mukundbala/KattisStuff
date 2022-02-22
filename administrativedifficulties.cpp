#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);

    ll tc; cin>>tc;

    while(tc--){
        ll timeNow=0;
        unordered_map<string,vector<ll>> carData;
        unordered_set<string> carIn; //checking to see if the car is in
        unordered_map<string,pair<string,ll>> carOut; //checking to see if the car is out
        unordered_map<string,pair<string,ll>> spies; //um containing spy name mapped to the car they took at what time;
        ll n,m; cin>>n>>m;
        map<string,ll>bill;
        while(n--){
            string carName; ll cat_price,pickup,rate; 
            cin>>carName>>cat_price>>pickup>>rate;
            carData[carName]={cat_price,pickup,rate};
            carIn.insert(carName);
        }

        while(m--){
            ll time;
            string spy,event;
            cin>>time>>spy>>event;
            timeNow=time;

            if (event=="p"){
                string car; cin>>car;
                //if (bill[spy]=-1){cout<<spy<<" is inconsisntent in p 34" <<endl;continue;}
                //check to see if the car has already been rented
                if (carIn.find(car)==carIn.end() && carOut.find(car)!=carOut.end()){
                    //case where spy borrows car, but the car is already out
                    //inconsistent case!
                    bill[spy]=-1; //if -1, means inconsistent
                    cout<<spy<<" is inconsisntent in p 40" <<endl;
                }
                else if (carIn.find(car)!=carIn.end() && carOut.find(car)==carOut.end()){
                    //case where the car is still in, but the spy actually has rented another car...
                    if (spies.find(spy)!=spies.end()){
                        //inconsistent
                        string borrowedCar=spies[spy].first;
                        if (carOut.find(borrowedCar)!=carOut.end()){
                            carOut.erase(borrowedCar);
                            carIn.insert(borrowedCar);
                        }
                        spies.erase(spy);
                        bill[spy]=-1; //inconsistent
                        cout<<spy<<" is inconsisntent in p 53" <<endl;
                    }
                    else{
                        //borrowing is valid
                        carIn.erase(car);
                        carOut[car]={spy,time};
                        spies[spy]={car,time};
                        cout<<spy<<" has borrwed the car"<<endl;
                        if (bill[spy]==-1){cout<<spy<<" is inconsisntent in p 60" <<endl;continue;}
                        else{ll spybill=bill[spy] += ceil(carData[car][1]);} //pickup cost is added to spies bill
                    }
                }
            }
            else if (event=="r"){
                ll distance; cin>>distance;
                //check to see that the car is indeed out
                //if (bill[spy]=-1){cout<<spy<<" is inconsisntent in r" <<endl;continue;}
                if (spies.find(spy)==spies.end()){
                    //inconsisntent, spy not found in a list of borrowed spies
                    bill[spy]=-1;
                    cout<<spy<<" is inconsisntent in r 72" <<endl;
                }
                else{
                    if (spies[spy].second < timeNow){
                        string borrowedCar=spies[spy].first;
                        if (carIn.find(borrowedCar)==carIn.end() && carOut.find(borrowedCar)!=carOut.end()){
                            if (carOut[borrowedCar].first==spy && carOut[borrowedCar].second == spies[spy].second){
                                //valid return.
                                ll spybill=ceil(distance * carData[borrowedCar][2]);
                                if (bill[spy]==-1){cout<<spy<<" is inconsisntent in r" <<endl;continue;}
                                else{bill[spy]+=spybill;}
                                carIn.insert(borrowedCar);
                                carOut.erase(borrowedCar);
                                spies.erase(spy);
                            }
                            else {bill[spy]=-1;cout<<spy<<" is inconsisntent in r" <<endl;}continue;
                        }
                        else {bill[spy]=-1;cout<<spy<<" is inconsisntent in r" <<endl;continue;}
                    }
                    else {bill[spy]=-1;cout<<spy<<" is inconsisntent in r" <<endl;continue;}
                }

            }
            else if (event=="a"){
                float percentage; cin>>percentage;
                percentage=percentage/100;
                //if (bill[spy]=-1){cout<<spy<<" is inconsisntent in a" <<endl;continue;}
                //check if spy has even borrowed a car
                if (spies.find(spy)==spies.end()){
                    bill[spy]=-1;
                    cout<<spy<<" is inconsisntent in a" <<endl;
                }
                else{
                    if (spies[spy].second<timeNow){
                        string borrowedCar=spies[spy].first;
                        if (carOut.find(borrowedCar)!=carOut.end() && carIn.find(borrowedCar)==carIn.end()){
                            if (carOut[borrowedCar].first == spy && carOut[borrowedCar].second<timeNow && carOut[borrowedCar].second==spies[spy].second){
                                //the borrowed car was borrowed by the spy, the time in the borrowed car is less than the current time, and equal to the time in the spy data base
                                //valid case
                                ll spyBill=ceil(carData[borrowedCar][0]*percentage);
                                if (bill[spy]==-1){cout<<spy<<" is inconsisntent in a" <<endl;continue;}
                                else{
                                    bill[spy]+=spyBill;
                                }
                            }
                        }
                    }
                }
            }

        }
        if (!spies.empty()){
            for (auto &[spyname,data]:spies){
                bill[spyname]=-1;
                cout<<spyname<<" did not return the car"<<endl;
            }
            spies.clear();
        }
        for (auto&[spyName,spyBill]:bill){
            if (spyBill==-1){
                cout<< spyName << " INCONSISTENT" <<endl;
            }
            else{
                cout<<spyName<<" "<<spyBill<<endl;
            }
        }
        
    }

    return 0;
}