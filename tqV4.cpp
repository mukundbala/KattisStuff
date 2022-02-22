//A0200081A
//Mukund Bala
//B07
//Walter Kong
#include <bits/stdc++.h>
using namespace std ;

//V4 using 2 deques to sim --> push front to left deque, push back to right deque

int cmdParser(string& inpCmd)
{
    if (inpCmd=="push_back") {return 1;}
    else if (inpCmd=="push_front"){return 2;}
    else if (inpCmd=="push_middle"){return 3;}
    else if (inpCmd=="get"){return 4;}
    return 0;
};

void Balancer(deque <long long>& leftDq, deque <long long>& rightDq,long long& ldqSize,long long& rdqSize)
{
    if (rdqSize>ldqSize) //pop front from right and push back to left
    {
        long long x=rightDq.front();
        rightDq.pop_front();
        rdqSize-=1;
        leftDq.push_back(x);
        ldqSize+=1;
    }

    if ((ldqSize-rdqSize)>1)
    {
        long long y=leftDq.back();
        leftDq.pop_back();
        ldqSize-=1;
        rightDq.push_front(y);
        rdqSize+=1;
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    string Ninp; getline(cin,Ninp);
    long long N=stoll(Ninp);
    deque <long long> ld,rd;
    long long ldSize=0;
    long long rdSize=0;
    for (int i=0;i<N;++i)
    {
        
        string inp; getline(cin,inp);
        stringstream ss(inp); string separated;
        int cmd=0;
        long long teqVal;
        int cnt=0;
        while (getline(ss,separated,' '))
        {
            if (cnt==0)
            {
                cmd=cmdParser(separated);cnt+=1;
            }
            else {teqVal=stoll(separated);}
        }
        //push_back --> 1
        //push_front --> 2
        //push_middle --> 3
        //get --> 4
        
        if (cmd==1) //PUSHBACK
        {
            rd.push_back(teqVal);
            rdSize+=1;
            cout << "AFTER PUSHBACK: " << " L --> "<<ldSize << " R--> " <<rdSize<<endl; 
            Balancer(ld,rd,ldSize,rdSize);
            cout << "LEFT SIZE: " << ldSize << endl;
            cout << "RIGHT SIZE: " << rdSize << endl;
        }
        else if (cmd==2) //PUSHFRONT
        {
            ld.push_front(teqVal);
            ldSize+=1;
            cout << "AFTER PUSHFRONT: " << " L --> "<<ldSize << " R--> " <<rdSize<<endl;
            Balancer(ld,rd,ldSize,rdSize);
            cout << "LEFT SIZE: " << ldSize << endl;
            cout << "RIGHT SIZE: " << rdSize << endl;
        }
        else if (cmd==3) //PUSHMIDDLE
        {
            ld.push_back(teqVal);
            ldSize+=1;
            cout << "AFTER PUSHMIDDLE: " << " L --> "<<ldSize << " R--> " <<rdSize<<endl;
            Balancer(ld,rd,ldSize,rdSize);
            cout << "LEFT SIZE: " << ldSize << endl;
            cout << "RIGHT SIZE: " << rdSize << endl;
        }
        else if (cmd==4)
        {
            if (teqVal<ldSize)
            {
                cout<< ld[teqVal]<<endl;
            }
            else if (teqVal>=ldSize)
            {
                cout<< rd[abs(ldSize-teqVal)]<<endl;
            }
        }

    }
}