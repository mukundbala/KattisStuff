//A0200081A
//Mukund Bala
//B07
//Walter Kong

#include <bits/stdc++.h>
using namespace std;

void spliceList(list <char> &fwd, list <char> &bwd) //function that takes in (homeList,endList) and splices them --> Home become empty
{
    auto it=bwd.begin();
    bwd.splice(it,fwd);
}

void backSpace (list <char> &charList,long long &count) //function that takes in a char list and pops back a value. Also reduces the character count
{
    if (charList.empty()){
        return;
        } //safe guard in case list being passed in is empty
    charList.pop_back();
    count-=1;
}

int main()
{
    string inpT; getline(cin,inpT);
    int T=stoi(inpT);

    int bint=int('<') ; int hint=int('[') ; int eint=int(']'); // converting the special characters to int
    while (T--) //iterating through each test case
    {
        string line; getline(cin,line); //getting each line input
        long long sizeLine=line.size(); // getting the size of the input line

        list <char> home; //list to store post Home entries
        list <char> end; //list to store End entries
        int listTrack=1; //0 --> home, 1--> end;

        long long numChar=0; //counter to keep track of the number of characters

        for (int i=0 ; i<sizeLine;++i) //iterating through each character --> O(n)
        {
            char letter=line[i]; int letterint=int(letter);

            if (end.empty() && home.empty())
            {
                if (letterint==bint || letterint==hint || letterint==eint)
                {
                    continue; // do nothing and just continue to the next character if the first letter is a special symbol
                } 
                else //case where an alphabet is inserted
                {
                    end.push_back(letter);++numChar; //push back letter into end list;
                    continue; //isolate this case using continue to go to the next char
                }
            }

            if (letterint==eint)
            {
                if (listTrack==1) // end is called when in end list;
                {
                    continue; //just continue
                }
                else if (listTrack==0)//if end was called after home
                {
                    spliceList(home,end);
                    listTrack=1; // set to end
                }
            }
            else if (letterint==hint)
            {
                if (listTrack==1) //home was called when cursor was in end list;
                {
                    listTrack=0; // exit end list and switch to home list
                }

                else if (listTrack==0) //home was called when the cursor was adding to home list;
                {
                    spliceList(home,end);
                    //list track alreayd 1
                }
            }
            else if (letterint==bint)
            {
                if (listTrack==0) //cursor was adding to home
                {
                    backSpace(home,numChar);
                    //ListTrack position remains
                }
                else if (listTrack==1)
                {
                    backSpace(end,numChar);
                    //ListTrack position remains
                }
            }
            else
            {
                if (listTrack==0) // cursor adding to home
                {
                    home.push_back(letter);
                    numChar+=1;
                }
                else if (listTrack==1) // cursor adding to end
                {
                    end.push_back(letter);
                    numChar+=1;
                }
            }

        }
        if (!home.empty()){spliceList(home,end);}
        while (!end.empty())
        {
            char x=end.front();
            end.pop_front();
            cout << x;
        }
        cout << "\n";
    }    

}


