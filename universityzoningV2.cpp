//A0200081A
//Mukund Bala
//B07
//Walter Kong
#include <bits/stdc++.h>
#define ll long long
using namespace std ;

//helper functions (remember to add citation)

auto RowColComparator=[](auto& a, auto& b)
{
    return (tie(get<0>(a) , get<1>(a))< tie(get<0>(b) , get<1>(b)));
};

bool sortIds(const tuple<ll int, ll int, ll int>& a, const tuple<ll int, ll int, ll int>& b)
{
    return (get<2>(a)<get<2>(b));
}

ll int stepsToMove(ll int ir,ll int ic, ll int ar,ll int ac)
    {
        ll int steps=abs(ar-ir) + abs(ac-ic) ;
        return steps;
    }


class Faculty

{
public:
    ll int spaceAvail; //number of spaces given to the faculty
    ll int Tval; //T value for the faculty
    vector <tuple<ll int,ll int>> posAvail; //vectors of array containing the sorted spaces available!
    vector<tuple<ll int , ll int,ll int>> posInitial; //initial state of the students
    vector <ll int> stepsArray;
    ll int minMoves;

    Faculty(ll int a) // constructor that is initialised with spaceAvail param
    {
        spaceAvail=a;
    }

    long long int getRow(long long int studentIndex,vector<tuple<long long int , long long int>> targetVector)
    {
        return get<0>(targetVector[studentIndex]);
    }
    long long int getCol(long long int studentIndex,vector<tuple<long long int , long long int>> targetVector)
    {
        return get<1>(targetVector[studentIndex]);
    }
    vector<tuple<ll int , ll int,ll int>> IDsort(vector<tuple<ll int , ll int,ll int>> targetVector)
    {
        sort(targetVector.begin(),targetVector.end(),sortIds);
        return targetVector;
    }
   

};


int main()
{
    //parsing the first line of input
    ll int rows,cols,facs,students,G;
    string line1; getline(cin,line1);
    string separated1; vector <ll int> line1Vec;
    stringstream ss1(line1);
    while (getline(ss1,separated1,' '))
    {
        ll int input=stoll(separated1);
        line1Vec.push_back(input);

    }

    rows=line1Vec[0];cols=line1Vec[1];
    facs=line1Vec[2];students=line1Vec[3];
    G=line1Vec[4];

    //creating a vector array of classes
    vector <Faculty> facArray; facArray.reserve(facs);
    //Parsing the next F lines of input

    for (int i=0 ; i<facs ; ++i)
    {
        string lineK; vector <ll int> lineKVec;
        string separatedK; 
        getline(cin,lineK) ; 
        stringstream ssk(lineK);
        while (getline(ssk,separatedK,' '))
        {
            ll int inputK=stoll(separatedK);
            lineKVec.push_back(inputK);
        }
        ll int cellsAssigned=lineKVec[0];
        facArray.push_back(Faculty(cellsAssigned));

        for (int j=1 ; j<=cellsAssigned*2 ; j+=2)
        {
            ll int facRow=lineKVec[j];
            ll int facCol=lineKVec[j+1];
            tuple <ll int,ll int> coordinates;
            coordinates=make_tuple(facRow,facCol);
            facArray.back().posAvail.push_back(coordinates);
        }
    }

    for (int i=0 ; i<facs ;++i)
    {
        sort(facArray[i].posAvail.begin(),facArray[i].posAvail.end(),RowColComparator);
        cout << "FACULTY: " << i+1 <<endl;
        for (int j=0 ; j<facArray[i].posAvail.size() ; ++j)
        {
            ll int checkRow=facArray[i].getRow(j,facArray[i].posAvail);
            ll int checkCol=facArray[i].getCol(j,facArray[i].posAvail);
            cout << "AVAILABLE POSITION: " << "(" << checkRow << "," <<checkCol << ")" << endl;
        } 
    }
    cout << "\nFirst F lines of faculty positions are sorted"<<endl;

    //Parsing the next S lines data
    //Reminder that faculty i is in index i-1 in facArray

    for (int i=0 ; i<students; ++i)
    {
        ll int rowStu,colStu,idStu,facStu;
        cin >> rowStu >> colStu >> idStu >>facStu ;
        tuple <ll int,ll int,ll int> studentInfo;
        studentInfo=make_tuple(rowStu,colStu,idStu);
        facArray[facStu-1].posInitial.push_back(studentInfo);
    }
    //Parsing last line + sorting student positions in their respective faculties w.r.t studenID
    for (int i=0 ; i<facs ; ++i)
    {
        facArray[i].posInitial=facArray[i].IDsort(facArray[i].posInitial);
        ll int TvalFac; cin >> TvalFac;
        facArray[i].Tval=TvalFac;
        cout<<"\nFACULTY: "<< i+1 << endl;
        cout <<"FACULTY: "<< i+1 << " HAS TVAL: "<<facArray[i].Tval<<endl;
        for (int j=0 ; j<facArray[i].posInitial.size();++j)
        {
            ll int checkerrow=get<0>(facArray[i].posInitial[j]);
            ll int checkercol=get<1>(facArray[i].posInitial[j]);
            ll int checkerID=get<2>(facArray[i].posInitial[j]);
            cout << "STUDENT ID: " << checkerID << " @ " <<"("<<checkerrow<<","<<checkercol<<")"<<endl; 
        }   
    }
    
    vector <ll int> FacultyTValues;

    for (int i=0 ; i<facs ; ++i)
    {   
        cout<<"\nFACULTY: "<< i+1 << endl;
        for (int j=0 ; j<facArray[i].posInitial.size();++j)
        {
            ll int initial_row=get<0>(facArray[i].posInitial[j]);
            ll int initial_col=get<1>(facArray[i].posInitial[j]);
            ll int ID=get<2>(facArray[i].posInitial[j]);

            ll int assigned_row=get<0>(facArray[i].posAvail[j]);
            ll int assigned_col=get<1>(facArray[i].posAvail[j]);
            ll int stepsMoved=stepsToMove(initial_row,initial_col,assigned_row,assigned_col);
            facArray[i].stepsArray.push_back(stepsMoved);
            cout<<"ID: " << ID << " MOVED "<<stepsMoved<<" STEPS FROM " << "(" << initial_row<<","<< initial_col<<")"<< " TO " <<"("<< assigned_row<<","<< assigned_col<< ")"<<endl;
        }
    sort(facArray[i].stepsArray.begin(),facArray[i].stepsArray.end());
    }

    for (int i=0 ; i<facs ; ++i)
    {
        vector <ll int> myArr=facArray[i].stepsArray;
        ll int limit=facArray[i].Tval;
        ll int minSteps=0;
        ll int counter_T=0;
        for (int j=0 ; j<myArr.size() ; ++j)
        {
            if (counter_T==limit) break;
            else
            {
                counter_T+=1;
                minSteps+=myArr[j];
            }
        }
        FacultyTValues.push_back(minSteps);
    }

    sort(FacultyTValues.begin(),FacultyTValues.end());
    ll int counterG=0;
    ll int minTotalSteps=0;
    cout << "G VALUE: " << G << endl ;
    for (int i=0 ; i<FacultyTValues.size();++i)
    {
        if (counterG==G) break ;
        else
        {
            counterG+=1;
            minTotalSteps+=FacultyTValues[i];
        }
    }
    cout << minTotalSteps << endl ;
}
