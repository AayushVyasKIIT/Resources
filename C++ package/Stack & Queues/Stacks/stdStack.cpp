#include <bits/stdc++.h>

using namespace std;

class Stack_int{
    private:
        int *arr;
        int top;
        int n;
    public:
        Stack_int(int n){
            this->n = n;
            arr = new int[n];
            top =-1;
        }

        void push(int data){
            if(top==n){
                cout << "stack overflow" << endl;
            }
            top++;
            arr[top] = data;
        }
        void pop(){
            if(top==-1){
                cout << " Underflow" << endl;
            }
            cout << arr[top] <<" ";
            top --;
        }
        int topMost(){
            if(top==-1){
                cout << "No elements in stack" << endl;
                return -1;
            }
            return arr[top];
        }
        bool isEmpty(){
            if(top==-1){
                return true;
            }
            return false;
        }
        void printStack(){
            int i=0;
            while(i!=top+1){
                cout << arr[i] << " ";
                i++;
            }
            cout << "|" << endl;
        }
};

class Stack_char{
    private:
        char *arr;
        int top;
        int n;
    public:
        Stack_char(int n){
            this->n = n;
            arr = new char[n];
            top =-1;
        }

        void push(int data){
            if(top==n){
                cout << "stack overflow" << endl;
            }
            top++;
            arr[top] = data;
        }
        void pop(){
            if(top==-1){
                cout << " Underflow" << endl;
            }
            cout << arr[top] <<" ";
            top --;
        }
        int topMost(){
            if(top==-1){
                cout << "No elements in stack" << endl;
                return -1;
            }
            return arr[top];
        }
        bool isEmpty(){
            if(top==-1){
                return true;
            }
            return false;
        }
        void printStack(){
            int i=0;
            while(i!=top+1){
                cout << arr[i] << " ";
                i++;
            }
            cout << "|" << endl;
        }
};

