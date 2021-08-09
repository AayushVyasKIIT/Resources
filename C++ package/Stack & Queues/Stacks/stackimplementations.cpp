#include "stdStack.cpp"

using namespace std;

int main(){

    Stack_int s(10);
    for(int i=0;i<10;i++){
        s.push(i);
    }
    s.printStack();
    cout << s.topMost() << endl;
    s.printStack();
    s.pop();
    s.printStack();
    cout << s.topMost() << endl;
    s.isEmpty()?cout << "Empty" << endl: cout <<"Non-empty" <<endl;
    

}