#include <bits/stdc++.h>

using namespace std;


int prec(char op){
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
string InfixToPostFix(string Infix){
    string PostFix = "";
    stack <char> stack;
    for(int i=0;i<Infix.length();i++){
        if((Infix[i]>='a' && Infix[i]<='z') || (Infix[i]>='A' && Infix[i]<='Z')){
            PostFix += Infix[i];
        }else if(Infix[i] == '('){
            stack.push('(');
        }else if(Infix[i] == ')'){
            while(!stack.empty() && stack.top()!='('){
                PostFix += stack.top();
                stack.pop();
            }
            if(!stack.empty())
                stack.pop();
        }else{
            while(!stack.empty() && (prec(Infix[i]) < prec(stack.top()))){
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
    return PostFix;
}
int main(){
    cout << InfixToPostFix("(a-b/c)*(a/k-l)");

}