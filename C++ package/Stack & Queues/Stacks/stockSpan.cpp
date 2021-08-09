#include <bits/stdc++.h>

using namespace std;

int main(){
    

    vector<int> price = {100,90,80,70,60,70,75,85};
    stack<pair<int,int>> stock_span;
    for(int i=0;i<price.size();i++){
        int span = 1;
        
        while(!stock_span.empty() && stock_span.top().first <= price[i]){
            span += stock_span.top().second;
            stock_span.pop();
        }
        cout <<price[i] << ":" << span << " ";
        stock_span.push(make_pair(price[i],span));
    }


}