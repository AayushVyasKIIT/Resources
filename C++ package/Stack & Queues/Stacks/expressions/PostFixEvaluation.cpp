#include <bits/stdc++.h>

using namespace std;

int PostFixEvaluation(string expression){
    stack <int> stack;
    for(int i=0;i<expression.length();i++){
        if(expression[i]>='0' && expression[i]<='9'){
            stack.push(expression[i]-'0');
        }else{
            int op2 = stack.top();
            stack.pop();
            int op1 = stack.top();
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
    cout << PostFixEvaluation("46+2/5*7+");
    return 0;
}
