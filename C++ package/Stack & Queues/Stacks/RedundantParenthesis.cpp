#include<bits/stdc++.h>

using namespace std;

bool redundantParenthesis(string exp){
    stack<char> stack;
    for(int i=0;i<exp.size();i++){
        if(exp[i]=='(' || exp[i]=='+'){
            stack.push(exp[i]);
        }else if(exp[i]==')'){
            if(stack.top()!='+'){
                return true;
            }
            while(!stack.empty() and stack.top()!='('){
                cout << stack.top();
                stack.pop();
            }
            stack.pop();
        }else{
            continue;
        }
    }
    cout << stack.size() << endl;
    if(stack.empty()){
        return false;
    }
    return false;
}

int main(){
    string exp = "(a+b*(a+b))";
    redundantParenthesis(exp)?cout << "Redundancy" : cout << "No redundancy";



}