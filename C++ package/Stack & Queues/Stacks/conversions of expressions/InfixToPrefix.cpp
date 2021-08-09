#include <bits/stdc++.h>

using namespace std;

int precedence(char op){
    if(op=='^'){
        return 3;
    }else if(op == '*' || op == '/'){
        return 2;
    }else if(op == '+' || op == '-'){
        return 1;
    }else{
        return -1;
    }
    return -1;
}
string InfixToPrefix(string Infix){
    //step1: reverse string
    reverse(Infix.begin(),Infix.end());
    //step2: reverse paranthesis.
    for(int i=0;i<Infix.length();i++){
        if(Infix[i]=='('){
            Infix[i] = ')';
        }else if(Infix[i]==')'){
            Infix[i] = '(';
        }else{
            continue;
        }
    }
    //step 3:
    //Infix to PostFix.
    string PostFix = "";
    stack <char> stack;
    for(int i=0;i<Infix.length();i++){
        if((Infix[i]>='a' && Infix[i]<='z') || (Infix[i]<='A' && Infix[i]>='Z')){
            PostFix+=Infix[i];
        }else if(Infix[i]=='('){
            stack.push(Infix[i]);
        }else if(Infix[i]==')'){
            while(!stack.empty() && stack.top()!='('){
                PostFix+=stack.top();
                stack.pop();
            }
            if(!stack.empty()){
                stack.pop();
            }
        }else{
            while(!stack.empty() && precedence(Infix[i])<precedence(stack.top())){
                PostFix+=stack.top();
                stack.pop();
            }
            stack.push(Infix[i]);
        }
    }
    while(!stack.empty()){
        PostFix += stack.top();
        stack.pop();
    }
    //step 4: reverse Postfix result to get prefix.
    reverse(PostFix.begin(),PostFix.end());
    return PostFix;
}

int main(){
    cout << "(a-b/c)*(a/k-l)" << endl;
    cout << InfixToPrefix("(a-b/c)*(a/k-l)");


}