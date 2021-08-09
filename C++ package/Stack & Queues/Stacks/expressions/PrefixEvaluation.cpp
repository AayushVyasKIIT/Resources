#include <bits/stdc++.h>

using namespace std;

int PrefixEvaluation(string expression){
    stack <int> stack;
    for(int i=expression.length()-1;i>=0;i--){
        if(expression[i] >= '0' && expression[i] <= '9'){
            stack.push(expression[i]-'0');
        }else{
            int op1 = stack.top();
            stack.pop();
            int op2 = stack.top();
            stack.pop();
            int ans;
            switch(expression[i]){
                case '+':
                    ans = op1+op2;
                    stack.push(ans);
                    break;
                case '-':
                    ans = op1-op2;
                    stack.push(ans);
                    break;
                case '*':
                    ans = op1*op2;
                    stack.push(ans);
                    break;
                case '/':
                    ans = op1/op2;
                    stack.push(ans);
                    break;
                case '^':
                    ans = pow(op1,op2);
                    stack.push(ans);
                    break;
                default:
                    break;
            }
        }
   
    }
    return stack.top();
}

int main(){
    cout << PrefixEvaluation("-+7*45+20");

}