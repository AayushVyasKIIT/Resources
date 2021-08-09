#include <bits/stdc++.h>

using namespace std;


int main(){

    map<int,int> m;
    m.insert(pair<int,int>(1,20));
    m.insert(pair<int,int>(2,30));
    m.insert(pair<int,int>(3,40));
    m.insert(pair<int,int>(4,50));
    m.insert(pair<int,int>(5,60));


    /* 
    ?in the box[enter the key to know its value]
     */
    cout << m.at(1) << endl;

    //?
    cout << m[1] << endl;

    /* 
    ? **finding using key **
     */
    map<int,int>::iterator itr;
    itr = m.find(1); //returns an iterator to the found item using key.
    cout << itr->first;
    cout << (*itr).second;



}