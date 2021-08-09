#include <bits/stdc++.h>

using namespace std;

bool palindrome(char *arr,int size){
    int start = 0;
    int end = size-1;
    while(start<end){
        cout << arr[start] << arr[end];
        if(arr[start]==arr[end]){
            start++;
            end--;
        }else{
            return 0;
        }
    }
    return 1;
}

int main(){

    int size;
    cin >> size; 
    char arr[100];
    cin >> arr;

    palindrome(arr,size)?cout<<"Palindrome:True":cout<<"Palindrome:False";


}