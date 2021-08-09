#include <bits/stdc++.h>

using namespace std;

int main(){
    int size;
    cin >> size;
    cin.ignore();

    char sentence[size];
    cin.getline(sentence,size);
    cin.ignore();

    int curr_len = 0;
    int len_mx = 0;
    int start = 0,start_mx = 0;
    for(int i=0;i<size+1;i++){
        if(sentence[i]==' ' || sentence[i]== '\0'){
            if(curr_len>len_mx){
                len_mx = curr_len;
                start_mx = start;
            }
            start = i+1;
            curr_len=0;
        }else{
            curr_len ++;
            
        }

    }
    cout << "Maximum Length of word:" << len_mx << endl;
    
    for(int i=0;i<len_mx;i++){
    
        cout << sentence[i+start_mx];
    }

}