//A0200081A
//Mukund Bala
//B07
//Walter Kong
#include <bits/stdc++.h>
using namespace std;

void moveCursor(int& mycursor,const int movetype)
{
    if (movetype==int('L') || movetype==int('B'))
    {
        mycursor-=1 ;
    }
    else if (movetype==int('R'))
    {
        mycursor +=1;
    }
    else
    {
        mycursor+=1;
    }
};


int main()
{
    string input; cin >> input;
    long long lenstr=input.size();
    vector <char> pwd;
    int left=int('L');
    int right=int('R');
    int backsp=int('B');
    int cursor=0;

    for (int i=0 ; i<lenstr; ++i) //O(size of string) --> O(n)
    {
        char currentChar=input[i];
        int charint=int(currentChar);

        if (currentChar=='L' || currentChar=='R') //O(1)
        {
            moveCursor(cursor,charint); //O(1)
        }
        
        else if (currentChar=='B') //O(1)
        {
            moveCursor(cursor,charint);//O(1)
            pwd.erase(pwd.begin()+cursor); //O(n)
        }
        else
        {
            pwd.insert(pwd.begin()+cursor,currentChar);//O(n)
            moveCursor(cursor,charint); //O(1)
        }
    }
    string opString;
    for (int j=0 ; j<pwd.size();++j) //O(n)
    {
        opString+=pwd[j];
    }
    cout << opString << endl;
}

//Inner loop O(2n)
//Outer loop O(n)
//Overall O(n^2)