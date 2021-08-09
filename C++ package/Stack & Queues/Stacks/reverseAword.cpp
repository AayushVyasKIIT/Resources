#include "stdstack.cpp"

void reverseSentence(string sentence){

    Stack_char s(sentence.length()+1);
    int i=0;
    while(sentence[i]!='\0'){
        s.push(sentence[i]);
        i++;
    }
    int top = sentence.length();
    while(top!=0){
        s.pop();
        top--;
    }
}



int main(){
    string sentence = "hello";
    reverseSentence(sentence);
}