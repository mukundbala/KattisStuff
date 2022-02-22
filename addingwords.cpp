#include <bits/stdc++.h> //SOLVED. Use unordered map to map variable name to number. Just follow qn
using namespace std;
typedef long long ll;

int main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n;

    unordered_map<string,int> dict;
    while(true){
        string cmd; cin>>cmd;
        if (cmd=="clear"){
            dict.clear();
        }
        else if (cmd=="def"){
            string variable; cin>>variable;
            ll val; cin>>val;
            dict[variable]=val;
        }
        else{//case of calc
            string calc; //everything after calc
            cin.ignore();
            getline(cin,calc); stringstream ss(calc);string separated;
            queue<string> calcOrder;
            bool variableCheck=true;
            if (calc.empty()){break;}
            while (getline(ss,separated,' ')){
                string calcStr=separated;
                //cout<<calcStr << " ";
                if (calcStr=="+" || calcStr=="-"){
                    calcOrder.push(calcStr);
                }
                else if (calcStr=="=") break;
                else{
                    //check if variable names are ok
                    auto search=dict.find(calcStr);
                    if (search==dict.end()){variableCheck=!variableCheck;break;}
                    else{
                        calcOrder.push(calcStr);
                    }
                }
                
            }
            if (!variableCheck){cout<<calc<<" "<<"unknown"<<endl;continue;}
            else{
                bool negFlag=0; // 0 is +, 1 is -
                ll total=0;
                while(!calcOrder.empty()){
                    string front=calcOrder.front();
                    if (front=="+"){negFlag=0;}
                    else if (front=="-"){negFlag=1;}
                    else{
                        if (negFlag==0){total+=dict[front];}
                        else{total-=dict[front];}
                    }
                    calcOrder.pop();
                }
                //check if the total exists
                bool totalCheck=false;
                string totalVarName;
                for (auto& [var,num]:dict){
                    if (num==total){totalCheck=true;totalVarName=var;break;}
                }
                if (!totalCheck){cout<<calc<<" "<<"unknown"<<endl;continue;}
                else{
                    cout<<calc<<" "<<totalVarName<<endl;continue;
                }

            }

        }

    }
}