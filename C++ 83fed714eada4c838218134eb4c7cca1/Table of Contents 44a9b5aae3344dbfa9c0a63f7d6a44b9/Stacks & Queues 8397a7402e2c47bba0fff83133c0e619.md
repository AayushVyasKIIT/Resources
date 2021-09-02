# Stacks & Queues

Created: June 20, 2021 9:14 AM

- Stacks
    - Basic operations

        ```cpp
        #include <bits/stdc++.h>

        using namespace std;

        class Stack{
            private:
                int *arr;
                int top;
                int n;
            public:
                Stack(int n){
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
        ```

    - Problems
        - Reverse a word

            ```cpp
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
            ```

        - Reverse a sentence

            ```cpp
            int main(){

                string sentence = "Hey, how are you doing?";
                int i=0;
                string temp = " ";
                stack <string> s;
                while(i<sentence.length()+1){
                    if(sentence[i]==' ' or sentence[i]=='\0'){
                        s.push(temp);
                        temp = "";
                    }
                    temp = temp + sentence[i];
                    i++;
                }
                while(!s.empty()){
                    cout << s.top();
                    s.pop();
                }

            }
            ```

        - Reverse a stack

            ![Stacks%20&%20Queues%208397a7402e2c47bba0fff83133c0e619/Untitled.png](Stacks%20&%20Queues%208397a7402e2c47bba0fff83133c0e619/Untitled.png)

            ![Stacks%20&%20Queues%208397a7402e2c47bba0fff83133c0e619/Untitled%201.png](Stacks%20&%20Queues%208397a7402e2c47bba0fff83133c0e619/Untitled%201.png)

            [Stacks%20&%20Queues%208397a7402e2c47bba0fff83133c0e619/reverse_a_stack.mkv](Stacks%20&%20Queues%208397a7402e2c47bba0fff83133c0e619/reverse_a_stack.mkv)

            ```cpp
            #include <bits/stdc++.h>
            using namespace std;
            void insertAtbottom(stack<int> &st,int ele){
                //base condition
                if(st.empty()){
                    st.push(ele);
                    return;
                }
                int top_ele = st.top();
                st.pop();
                insertAtbottom(st,ele);
                st.push(top_ele); 
            // we are doing this because, we kept popping 
            //out all the elements in line 7.
            }

            void reverseStack(stack<int> &st){
                //base case
                if(st.empty()){
                    return;
                }

                int ele = st.top();
                st.pop();
                reverseStack(st);
                insertAtbottom(st,ele);
                
            }

            int main(){

                stack <int> st;
                st.push(1);
                st.push(2);
                st.push(3);
                st.push(4);
                st.push(5);
                reverseStack(st);
                while(st.empty()!=1){
                    cout << st.top();
                    st.pop();
                }

                //1 2 3 4 5  // 5 4 3 2 1
            }
            ```

        - Keeping track of max element

            we will maintain 2 stacks for this:

            1. mainStack - storing all the values
            2. maxStack - stores the max values top of which will have the maximum value of the stack.
    - expressions

        ### Infix Notation

        ![Stacks%20&%20Queues%208397a7402e2c47bba0fff83133c0e619/Untitled%202.png](Stacks%20&%20Queues%208397a7402e2c47bba0fff83133c0e619/Untitled%202.png)

        ![Stacks%20&%20Queues%208397a7402e2c47bba0fff83133c0e619/Untitled%203.png](Stacks%20&%20Queues%208397a7402e2c47bba0fff83133c0e619/Untitled%203.png)

        Infix notation are human understandable notations that we use in our day to day math.

        ### Prefix Notation

        polish notation

        ![Stacks%20&%20Queues%208397a7402e2c47bba0fff83133c0e619/Untitled%204.png](Stacks%20&%20Queues%208397a7402e2c47bba0fff83133c0e619/Untitled%204.png)

        ![Stacks%20&%20Queues%208397a7402e2c47bba0fff83133c0e619/Untitled%205.png](Stacks%20&%20Queues%208397a7402e2c47bba0fff83133c0e619/Untitled%205.png)

        evaluate from right to left.

        two operands then 1 operator.

        - Evaluatiing prefix expressions

            we will use the LIFO property of the stack here.

            if(current_element == operand):

            push(current_element)

            if(current_element == operator):

            pop() 2 times.

            operand 1 operator operand 2

            ![Stacks%20&%20Queues%208397a7402e2c47bba0fff83133c0e619/Untitled%206.png](Stacks%20&%20Queues%208397a7402e2c47bba0fff83133c0e619/Untitled%206.png)

            ![Stacks%20&%20Queues%208397a7402e2c47bba0fff83133c0e619/Untitled%207.png](Stacks%20&%20Queues%208397a7402e2c47bba0fff83133c0e619/Untitled%207.png)

            ![Stacks%20&%20Queues%208397a7402e2c47bba0fff83133c0e619/Untitled%208.png](Stacks%20&%20Queues%208397a7402e2c47bba0fff83133c0e619/Untitled%208.png)

            ```cpp
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
            ```

        [Stacks%20&%20Queues%208397a7402e2c47bba0fff83133c0e619/Evaluating_Prefix.mkv](Stacks%20&%20Queues%208397a7402e2c47bba0fff83133c0e619/Evaluating_Prefix.mkv)

        ### Postfix expression

        ![Stacks%20&%20Queues%208397a7402e2c47bba0fff83133c0e619/Untitled%209.png](Stacks%20&%20Queues%208397a7402e2c47bba0fff83133c0e619/Untitled%209.png)

        ![Stacks%20&%20Queues%208397a7402e2c47bba0fff83133c0e619/Untitled%2010.png](Stacks%20&%20Queues%208397a7402e2c47bba0fff83133c0e619/Untitled%2010.png)

        > Both postfix and prefix are computer understandable.

        - Evaluating Postfix expression

            points to remember

            operand 2 mein 1st pop

            operand 1 mein 2nd pop

            left → right traverse

            ```cpp

            ```

    - conversion of expressions
        - Infix to PostFix

            ![Stacks%20&%20Queues%208397a7402e2c47bba0fff83133c0e619/Untitled%2011.png](Stacks%20&%20Queues%208397a7402e2c47bba0fff83133c0e619/Untitled%2011.png)

            [Stacks%20&%20Queues%208397a7402e2c47bba0fff83133c0e619/InfixToPostfix.mkv](Stacks%20&%20Queues%208397a7402e2c47bba0fff83133c0e619/InfixToPostfix.mkv)

            ```cpp
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
            ```

        - Infix to PreFix

            Algorithm:

            1.Reverse string

            2.Reverse brackets

            3. apply Infix→PostFix

            4.Reverse Resulting expression to get Prefix.

            ```cpp
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
            ```

        - Largest Rectangle

            ![Stacks%20&%20Queues%208397a7402e2c47bba0fff83133c0e619/Untitled%2012.png](Stacks%20&%20Queues%208397a7402e2c47bba0fff83133c0e619/Untitled%2012.png)

            ![Stacks%20&%20Queues%208397a7402e2c47bba0fff83133c0e619/Untitled%2013.png](Stacks%20&%20Queues%208397a7402e2c47bba0fff83133c0e619/Untitled%2013.png)

            ![Stacks%20&%20Queues%208397a7402e2c47bba0fff83133c0e619/Untitled%2014.png](Stacks%20&%20Queues%208397a7402e2c47bba0fff83133c0e619/Untitled%2014.png)

            ![Stacks%20&%20Queues%208397a7402e2c47bba0fff83133c0e619/Untitled%2015.png](Stacks%20&%20Queues%208397a7402e2c47bba0fff83133c0e619/Untitled%2015.png)

            ![Stacks%20&%20Queues%208397a7402e2c47bba0fff83133c0e619/Untitled%2016.png](Stacks%20&%20Queues%208397a7402e2c47bba0fff83133c0e619/Untitled%2016.png)

            ```cpp
            #include <bits/stdc++.h>

            using namespace std;

            int main(){
                vector<int> arr = {2,1,5,6,2,3};
                stack<int> stack;
                stack.push(0);
                int ans=0;
                for(int i=0;i<arr.size();i++){
                    while(!stack.empty() and arr[stack.top()]>arr[i]){
                        int t=stack.top();
                        int h =arr[t];
                        stack.pop();
                        if(stack.empty()){
                            ans = max(ans,i*h);
                        }else{
                            int l = i-stack.top()-1;
                            ans = max(ans,l*h);
                        }
                        
                    }
                    stack.push(i);
                }
                cout << ans << endl;
            }
            ```

        ---

        - Rainwater harvesting

            ![Stacks%20&%20Queues%208397a7402e2c47bba0fff83133c0e619/Untitled%2017.png](Stacks%20&%20Queues%208397a7402e2c47bba0fff83133c0e619/Untitled%2017.png)

            ```cpp
            int rainwater(vector<int> pillars){
                int water = 0;
                stack<int> stack;
                for(int i=0;i<pillars.size();i++){
                    while(!stack.empty() && pillars[i]>pillars[stack.top()]){
                        int t = stack.top();
                        int height =pillars[stack.top()];
                        stack.pop();
                        if(stack.empty()){
                            break;
                        }
                        int l = i - stack.top() -1;
                        int h = min(pillars[i],pillars[stack.top()]/*this is the next element(from R->L))-pillars[t]//t is the current element*/)-pillars[t];
                        water+= l*h;
                    }
                    stack.push(i);
                }
                return water;
            }
            int main(){
                vector<int> pillars = {0,1,0,2,1,0,1,3,2,1,2,1};
                cout << rainwater(pillars);   
            }
            ```

        - Redundant Parenthesis

            ((a+b)) ❎

            (a+(a+b)) ✅

            Approach:

            1.keep pushing into stack untill a closing brace is encountered.

            2. Now pop until a opening brace is not encountered.

            with constraints that the top element should be an operator(+ - * /) 

            if not operator : redundant brackets

            else keep popping off.

            3. if atlast stack is empty then no redundant brackets.

            ```cpp
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
            ```

        - Stock Span

            ![Stacks%20&%20Queues%208397a7402e2c47bba0fff83133c0e619/Untitled%2018.png](Stacks%20&%20Queues%208397a7402e2c47bba0fff83133c0e619/Untitled%2018.png)

            ```cpp
            vector<int> price = {100,90,80,70,60,70,75,85};
                stack<pair<int,int>> stock_span;
                for(int i=0;i<price.size();i++){
                    int span = 1;
                    
                    while(!stock_span.empty() && stock_span.top().first <= price[i]){
                        span += stock_span.top().second;
                        stock_span.pop();
                    }
                    cout <<price[i] << ":" << span << " ";
                    stock_span.push(make_pair(price[i],span));
                }
            ```

        - 3 sum 2pointers

            ![Stacks%20&%20Queues%208397a7402e2c47bba0fff83133c0e619/Untitled%2019.png](Stacks%20&%20Queues%208397a7402e2c47bba0fff83133c0e619/Untitled%2019.png)

            ![Stacks%20&%20Queues%208397a7402e2c47bba0fff83133c0e619/Untitled%2020.png](Stacks%20&%20Queues%208397a7402e2c47bba0fff83133c0e619/Untitled%2020.png)

        - longest subarray w consecutive 1's

            ![Stacks%20&%20Queues%208397a7402e2c47bba0fff83133c0e619/Untitled%2021.png](Stacks%20&%20Queues%208397a7402e2c47bba0fff83133c0e619/Untitled%2021.png)

            ![Stacks%20&%20Queues%208397a7402e2c47bba0fff83133c0e619/Untitled%2022.png](Stacks%20&%20Queues%208397a7402e2c47bba0fff83133c0e619/Untitled%2022.png)

            ![Stacks%20&%20Queues%208397a7402e2c47bba0fff83133c0e619/Untitled%2023.png](Stacks%20&%20Queues%208397a7402e2c47bba0fff83133c0e619/Untitled%2023.png)

            ```cpp
            int longestConsecutive1(vector<int> arr,int k){
                int zerocount = 0;
                int ans = 0;
                int i=0;
                for(int j=0;j<arr.size();j++){
                    if(arr[j]==0){
                        zerocount++;
                    }
                    while(zerocount>k){
                        if(arr[i]==0){
                            zerocount--;
                        }
                        i++;
                    }
                    ans = max(ans,j-i+1);
                }
                return ans;

            }
            ```

        - longest substring with no repeat

            ![Stacks%20&%20Queues%208397a7402e2c47bba0fff83133c0e619/Untitled%2024.png](Stacks%20&%20Queues%208397a7402e2c47bba0fff83133c0e619/Untitled%2024.png)

            ![Stacks%20&%20Queues%208397a7402e2c47bba0fff83133c0e619/Untitled%2025.png](Stacks%20&%20Queues%208397a7402e2c47bba0fff83133c0e619/Untitled%2025.png)

            ![Stacks%20&%20Queues%208397a7402e2c47bba0fff83133c0e619/Untitled%2026.png](Stacks%20&%20Queues%208397a7402e2c47bba0fff83133c0e619/Untitled%2026.png)

            ![Stacks%20&%20Queues%208397a7402e2c47bba0fff83133c0e619/Untitled%2027.png](Stacks%20&%20Queues%208397a7402e2c47bba0fff83133c0e619/Untitled%2027.png)

            ```cpp
            int noOfLongestNonRepeatingSubstr(string str){
                vector<int> mp(256,-1);
                int mx_len = INT_MIN;
                int start=-1,count =0;
                for(int i=0;i<str.size();i++){
                    if(mp[str[i]]>start){
                        start = mp[str[i]];
                    }
                    mp[str[i]] = i;
                    mx_len = max(mx_len,i-start);
                    
                }
                cout << mx_len;
                return mx_len;
            }
            ```

- Queues

    FIFO

    ![Stacks%20&%20Queues%208397a7402e2c47bba0fff83133c0e619/Untitled%2028.png](Stacks%20&%20Queues%208397a7402e2c47bba0fff83133c0e619/Untitled%2028.png)

    enqueue() : push an element

    dequeue() : pop an element from 

    peek(): value of front()

    ## Array Implementation of Queue

    ![Stacks%20&%20Queues%208397a7402e2c47bba0fff83133c0e619/Untitled%2029.png](Stacks%20&%20Queues%208397a7402e2c47bba0fff83133c0e619/Untitled%2029.png)

    ![Stacks%20&%20Queues%208397a7402e2c47bba0fff83133c0e619/Untitled%2030.png](Stacks%20&%20Queues%208397a7402e2c47bba0fff83133c0e619/Untitled%2030.png)

    ![Stacks%20&%20Queues%208397a7402e2c47bba0fff83133c0e619/Untitled%2031.png](Stacks%20&%20Queues%208397a7402e2c47bba0fff83133c0e619/Untitled%2031.png)

    front++

    peek = queue.front

    empty = front > back || front==-1 

    ```cpp
    #include <bits/stdc++.h>

    using namespace std;

    class Queue{
        private:
            int* arr;
            int front;
            int back;
            int n;
        public:
            Queue(int n){
                arr = new int[n];
                front =-1;
                back = -1;
            }        
            void enqueue(int data){
                if(back==n){
                    cout << "Queue Overflow" << endl;
                    return; 
                }
                back++;
                arr[back] = data;

                if(front==-1){
                    front++;
                }
            }
            void dequeue(){
                if(front==-1){
                    cout << "Queue Empty" << endl;
                    return;
                }
                if(front>back){
                    cout << "Queue OverFlow" << endl;
                    return;
                }
                front++;
            }
            bool isEmpty(){
                if(front==-1 || front>back){
                    return 1;
                }
                return 0;
            }
            int peek(){
                if(front==-1 || front > back){
                    return -1;
                }
                return arr[front];

            }
    };

    int main(){

        Queue q(10);
        for(int i=0;i<10;i++)
            q.enqueue(i);
        
        cout << q.peek();
        for(int i=0;i<9;i++)
            q.dequeue();
        cout << q.peek();
        
        q.dequeue();
        cout << q.isEmpty() << endl;

    }
    ```

    ## Linked List Implementation of Queues

    Approach:

    1. make a node structure
    2. call that node structure while enqueing and dequeing and create links
    3. use front and back pointers.

    ```cpp
    class node{
        public:
            int data;
            node* next = NULL;
            node(int data):data(data){}
    }; 

    class Queue{
        private:
            node* front;
            node* back;
        public:
            Queue(){
                front = NULL;
                back = NULL;
            }
            void enqueue(int data){
                node* newNode = new node(data);
                if(front==NULL){
                    front = newNode;
                    back = newNode;
                }
                back->next = newNode;
                back = newNode;
            }   
            void dequeue(){
                if(front==NULL ||  front>back){
                    cout << "OverFlow or Underflow" << endl;
                }
                front = front->next;
            }  
            int peek(){
                if(front==NULL ||  front>back){
                    cout << "OverFlow or Underflow" << endl;
                }
                return front->data;
            }
            bool isEmpty(){
                if(front == NULL || front>back){
                    return 1;
                }
                return 0;
            }
    };
    ```

- Queues using stack

    Approach1: Using 2 stacks

    ![Stacks%20&%20Queues%208397a7402e2c47bba0fff83133c0e619/Untitled%2032.png](Stacks%20&%20Queues%208397a7402e2c47bba0fff83133c0e619/Untitled%2032.png)

    ![Stacks%20&%20Queues%208397a7402e2c47bba0fff83133c0e619/Untitled%2033.png](Stacks%20&%20Queues%208397a7402e2c47bba0fff83133c0e619/Untitled%2033.png)

    for enqueue : Push everything to stack 1 

    for dequeue : Push everything to stack 2 and return stack2.top()

    isEmpty() : if s1.empty() and s2.empty() 

    Approach 2: Function Call Stack

    for enqueue : push to stack 1

    for dequeue:

    ![Stacks%20&%20Queues%208397a7402e2c47bba0fff83133c0e619/Untitled%2034.png](Stacks%20&%20Queues%208397a7402e2c47bba0fff83133c0e619/Untitled%2034.png)

    ```cpp
    int dequeue(){
                if(stack1.empty()){
                    cout << "Queue is empty" << endl;
                    return -1;
                }
                int x = stack1.top();
                stack1.pop();
                if(stack1.empty()){
                    return x;
                }
                int item = dequeue();
                stack1.push(x);

                return item;
            }
    ```

- Stack using queue

    Method 1:

    ![Stacks%20&%20Queues%208397a7402e2c47bba0fff83133c0e619/Untitled%2035.png](Stacks%20&%20Queues%208397a7402e2c47bba0fff83133c0e619/Untitled%2035.png)

    q2 mein element ko insert krwao.

    q1 ko khaali kro q2 mein

    q2 ko swap kro q1 s.

- Deque

    A hybrid data structure of stack and queue

    push_front and push_back supported, similarily for pop.

    ![Stacks%20&%20Queues%208397a7402e2c47bba0fff83133c0e619/Untitled%2036.png](Stacks%20&%20Queues%208397a7402e2c47bba0fff83133c0e619/Untitled%2036.png)

    ## Sliding window maximum

    ![Stacks%20&%20Queues%208397a7402e2c47bba0fff83133c0e619/Untitled%2037.png](Stacks%20&%20Queues%208397a7402e2c47bba0fff83133c0e619/Untitled%2037.png)

    T(n) = O(n)

    Alternate method was using a multiset done in multiset section O(nlogn).

    [Stacks%20&%20Queues%208397a7402e2c47bba0fff83133c0e619/MaximumSlidingWindowUsingDeque.mkv](Stacks%20&%20Queues%208397a7402e2c47bba0fff83133c0e619/MaximumSlidingWindowUsingDeque.mkv)

    Explaination of the MaximumSlidingWindow using Deque.

    last part of the video contains explanation of the code written below

    ```cpp
    int main(){
        vector<int> arr = {-10,9,2,1,3,4,0,3};
        deque<int> q; //Remember : We will be adding the indices to the deque not the elements.
        int k = 3;
        vector <int> MaximumOfEachWindow;
        //for first k elements
        for(int i=0;i<k;i++){
            while(!q.empty() && arr[i]>=arr[q.back()/*remeber we are dealing with indices in q*/]){
                /*so the above line means, if the current element is greater than 
                the last index pushed to the deque*/
                q.pop_back();
                /*remove every element from the deque*/
            }
            /* add the index of the newly discovered maximum element*/
            q.push_back(i);
        }
        //push this to our answer but remember dont do q.front() as we are dealing with indices.
        MaximumOfEachWindow.push_back(arr[q.front()]);
        //for k -> n
        for(int i=k;i<arr.size();i++){
            /*first we need to remove the previous windows elements(indices)*/
            while(!q.empty() && q.front()<=i-k)
                q.pop_back();
            /*similarily to previous steps we'll do it for the next window k*/
            while(!q.empty() && arr[i]>=arr[q.back()]){
                q.pop_back();
            }
            /*push the maximum element(index) of the window*/
            q.push_back(i);
            //push all the maximums discovered but remember we are dealing with indices in deque.
            MaximumOfEachWindow.push_back(arr[q.front()]);
        }

        for(auto each: MaximumOfEachWindow){
            cout << each;
        }

    }
    ```

-