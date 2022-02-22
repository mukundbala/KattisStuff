#include <bits/stdc++.h>
using namespace std ;

/*
here's a small exercise:
there are N rectangles. on the follow N lines, 
contains the width and height of rectangles number 1, 2 ... N, sort the rectangles based on the area, 
tie broken by smaller widths first, then by smaller height, 
and then by the rectangle number (as in the input order), 
and print out the sorted rectangle's numbers


auto RectComparator=[](auto& a, auto& b) 
{
    return tuple( get<0>(a), get<1>(a) , get<2>(a), get<3>(a) ) < tuple(get<0>(b) , get<1>(b) , get<2>(b) , get<3>(b)) ;
};

int main()
{
    int N ; cin >> N ;
    vector <tuple<int,int,int,int>> rectArray ; //array that contains (area,width,height,index+1)
    for (int i=0 ; i<N ; ++i)
    {
        int width,height ; cin >> width >> height; 
        int area=width*height ;
        tuple <int,int,int,int> rect;
        rect=make_tuple(area,width,height,i+1);
        rectArray.push_back(rect);
    }
    cout << endl ;
    sort(rectArray.begin() , rectArray.end()) ;

    for (int i=0 ; i<N ; ++i )
    {
        cout << get<3>(rectArray[i]) << endl ;
    }
}
*/

int main()
{
    int n ; cin>>n;
    vector<tuple<int,int,int,int>> a(n);
    for (int i = 0; i < n; ++i) {
  auto &[area, width, height, idx] = a[i];
  cin >> width >> height;
  area = width * height;
  idx = i + 1;
}
sort(a.begin(), a.end());
for (auto &[area, width, height, idx] : a) 
  cout << idx << "\n";
    

}
