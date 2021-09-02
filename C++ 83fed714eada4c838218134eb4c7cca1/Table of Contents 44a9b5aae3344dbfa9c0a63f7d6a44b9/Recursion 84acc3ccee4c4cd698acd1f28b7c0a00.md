# Recursion

Created: June 3, 2021 3:16 PM

Function Calling itself again and again to break the problem into smaller parts and solve it.

```cpp
int sum(int n){
	if(n==0){
		return 0;
	}
	int prevSum = sum(n-1);
	return n + prevSum;
}
```

Stack memory representation:

![Recursion%2084acc3ccee4c4cd698acd1f28b7c0a00/Untitled.png](Recursion%2084acc3ccee4c4cd698acd1f28b7c0a00/Untitled.png)

sum(0) will return to sum(1)

sum(1) will return to sum(2)

....

sum(4) will return to main()

![Recursion%2084acc3ccee4c4cd698acd1f28b7c0a00/Untitled%201.png](Recursion%2084acc3ccee4c4cd698acd1f28b7c0a00/Untitled%201.png)

- n to power p

    ```cpp
    int power(int n,int p){
    	if(p==0){
    		return 1;
    	}
    	
    	return n*power(n,p-1);;
    }
    ```

- Factorial

    ```cpp
    int factorial(int n){
    	if(n==1 or n==1){
    		return 1;
    	}
    	return n*factorial(n-1);
    }
    ```

- Fibonacci nth

    ![Recursion%2084acc3ccee4c4cd698acd1f28b7c0a00/Untitled%202.png](Recursion%2084acc3ccee4c4cd698acd1f28b7c0a00/Untitled%202.png)

    base case: fib(0) =0 fib(1) =1

    ```cpp
    int fib(int n){
    	if(n == 0 || n==1){
    		return n;
    	}
    	return fib(n-1) + fib(n-2);
    }
    ```

- is array sorted?

    ```cpp
    bool isSorted(int arr[],int n){
    		if(n==1){
    			return true;
    		}
    			
    		return arr[0] < arr[1] && isSorted(arr+1,n-1);
    }
    ```

    Here in (n-1) we are not actually decreasing the size , we are just using it as a stop condition to keep track of how many numbers are sorted.

- print 1 to n

    ```cpp
    void inc(int n){
        if(n==1){
            cout << 1;
            return;
        }
        inc(n-1);
        cout << n << endl;

    }
    ```

- print n to 1

    ```cpp
    void inc(int n){
        if(n==0){
            return;
        }
    		cout << n << endl;
        inc(n-1);

    }
    ```

difference between 1→n and n→1 is calling print after and before recursive call. 

- If print called before recursive call then n will be printed and (n-1) will be called.
- If print called after recursive call then first recursive call will be made to (n-1), untill the base condition is reached. After the base condition the callbacks happen and print statements are executed.

---

- Find the first occurence and last occurence of a number in an array

    ```cpp
    int first_occurence(int arr[],int n,int i,int key){
    	if(i==n){
    		return -1;
    	}

    	if(arr[i] ==key){
    		return i;
    	}
    	
    	return first_occurence(arr,n,i+1,key);

    }
    ```

    ```cpp
    int last_occurence(int arr[],int n,int i,int key){
        if(i==n){
            return -1;
        }
    	int restArray = last_occurence(arr,n,i+1,key);	
    	if(restArray!=-1){
    		return restArray; 
    		
    	} 
    	if(arr[i]==key){
    		return i; 
    		
    	}
    	return -1;
    }
    ```

    the difference here is, in first_occurence we iterate untill we get the desired key, in last_occurence we iterate untill -1 and then in callbacks we check for the key.

---

- Reverse a string using recursion

    ```cpp
    void reverseString(string str,int n){
        if(n==0){
            return;
        }
        reverseString(str.substr(1),n-1);
        cout << str[0];
    }
    int main(){
        reverseString("hello",5);

    }
    ```

---

- find replace pi with 3.14 in a string.

    ![Recursion%2084acc3ccee4c4cd698acd1f28b7c0a00/Untitled%203.png](Recursion%2084acc3ccee4c4cd698acd1f28b7c0a00/Untitled%203.png)

    ```cpp
    void replacePi(string str){

        if(str.length()==0){
            return;
        }
        if(str[0]=='p' && str[1]=='i'){
            cout << 3.14;
            replacePi(str.substr(2));
        }else{
            cout << str[0];
            replacePi(str.substr(1));
        }
    }

    int main(){
        replacePi("pippppppip");
    }
    ```

---

- Tower of hanoi

    ![Recursion%2084acc3ccee4c4cd698acd1f28b7c0a00/Untitled%204.png](Recursion%2084acc3ccee4c4cd698acd1f28b7c0a00/Untitled%204.png)

    ![Recursion%2084acc3ccee4c4cd698acd1f28b7c0a00/Untitled%205.png](Recursion%2084acc3ccee4c4cd698acd1f28b7c0a00/Untitled%205.png)

    ![Recursion%2084acc3ccee4c4cd698acd1f28b7c0a00/Untitled%206.png](Recursion%2084acc3ccee4c4cd698acd1f28b7c0a00/Untitled%206.png)

---

- Remove all duplicates

    ![Recursion%2084acc3ccee4c4cd698acd1f28b7c0a00/Untitled%207.png](Recursion%2084acc3ccee4c4cd698acd1f28b7c0a00/Untitled%207.png)

    take out a and send arr[n-1] to recursion.

    then compare a and arr[0] if equal return arr[0...n-1]

    ```cpp
    string removeDuplicates(string s){
    	if(s.length ==0){
    		return "";
    	}
    	char ch = s[0];
    	string ans = removeDuplicate(s.substr(1));
    	
    	if(ch==ans[0]){
    		return ans;
    	}
    	return (ch+ans);
    }
    ```

---

- Move all x to end of the string.

    ![Recursion%2084acc3ccee4c4cd698acd1f28b7c0a00/Untitled%208.png](Recursion%2084acc3ccee4c4cd698acd1f28b7c0a00/Untitled%208.png)

    ```cpp
    string moveAllx(string s){

        if(s.length()==0){
            return "";
        }
        char c = s[0];//select first element
        string ans = moveAllx(s.substr(1)); //rest of the array

        if(c=='x'){
            return ans+c;
        }
            
        return c + ans ;
    }

    int main(){

        cout << moveAllx("xx23435xx343");
    }
    ```

---

- Generate all substrings of a string

    ![Recursion%2084acc3ccee4c4cd698acd1f28b7c0a00/Untitled%209.png](Recursion%2084acc3ccee4c4cd698acd1f28b7c0a00/Untitled%209.png)

    ![Recursion%2084acc3ccee4c4cd698acd1f28b7c0a00/Untitled%2010.png](Recursion%2084acc3ccee4c4cd698acd1f28b7c0a00/Untitled%2010.png)

    Every step do 2 things, add something and dont add.

    > From the tree diagram, add A to "" and dont add anything,then add B to A and "" and continues.

    ```cpp
    void substrings(string s,string ans){

        if(s.length()==0){
            cout << ans << endl;
            return;
        }
        char c =  s[0];
        string ros = s.substr(1);

        substrings(ros,ans); //ek baar toa kch nhi add krengy
        substrings(ros,ans+c); // ek baar add ek add kreny.
    }
    ```

---

- Generate Substrings with ASCII codes.

    ![Recursion%2084acc3ccee4c4cd698acd1f28b7c0a00/Untitled%2011.png](Recursion%2084acc3ccee4c4cd698acd1f28b7c0a00/Untitled%2011.png)

    3 recursive calls:

    1. add nothing
    2. add alphabet.
    3. add ASCII code.

    ```cpp
    void substringsWascii(string s,string ans){

        if(s.length()==0){
            cout << ans << endl;
            return;
        }
        char c =  s[0];
        int ascii = c;
        string ros = s.substr(1);

        substringsWascii(s,ans); //ek baar toa kch nhi add krengy
        substringsWascii(s,ans+c); // ek baar add ek add kreny alphabet. 
        substringsWascii(s,ans+to_string(ascii)); // add krengy ascii.
    }
    ```

---

- Permutations of string

    ![Recursion%2084acc3ccee4c4cd698acd1f28b7c0a00/Untitled%2012.png](Recursion%2084acc3ccee4c4cd698acd1f28b7c0a00/Untitled%2012.png)

    fix one character and send rest of the string to recursion.

    ```cpp
    void permutations(string s,string ans){

        if(s.length()==0){
            cout << ans << endl;
            return;
        }

        for(int i=0;i<s.length();i++){
            char c = s[i];
            string ros = s.substr(0,i) + s.substr(i+1);

            permutations(ros,ans+c);
        }
        
    }
    ```

---

- Minimum number of possible paths from start to end

    ![Recursion%2084acc3ccee4c4cd698acd1f28b7c0a00/Untitled%2013.png](Recursion%2084acc3ccee4c4cd698acd1f28b7c0a00/Untitled%2013.png)

    dice has values from 1-6.

    for knowing all possible paths from  0 to 3 we have to first know all the possible paths from 1 to 3 , and for 1 to 3 we have to know 2-3 and then 3-3 i.e 1 path.

    ```cpp
    int countPath(int start,int end){

        if(start==end){
            return 1;
        }
        if(start>end){
            return 0;
        }

        int count =0;
        for(int i=1;i<=6;i++){
            count+=countPath(start+i,end);
        }
        return count;

    }
    ```

---

- Count paths in a maze(without obstacles)

    ![Recursion%2084acc3ccee4c4cd698acd1f28b7c0a00/Untitled%2014.png](Recursion%2084acc3ccee4c4cd698acd1f28b7c0a00/Untitled%2014.png)

    start = 0,0

    end = n-1,n-1

    you can move only in 2 directions top→bottom and left → right.

    ```cpp
    int countPathsMaze(int n,int i,int j){

        if(i==n-1 && j==n-1){
            return 1;
        }
        if(i>n || j>n){
            return 0;
        }

        return countPathsMaze(n,i+1,j) + countPathsMaze(n,i,j+1);

    }
    ```

---

- Tilling problem

    ![Recursion%2084acc3ccee4c4cd698acd1f28b7c0a00/Untitled%2015.png](Recursion%2084acc3ccee4c4cd698acd1f28b7c0a00/Untitled%2015.png)

    ![Recursion%2084acc3ccee4c4cd698acd1f28b7c0a00/Untitled%2016.png](Recursion%2084acc3ccee4c4cd698acd1f28b7c0a00/Untitled%2016.png)

    Basically if we place a tile horizontally then we reduce the size by 2. 

    And if we place vertically we reduce the size by 1.

    and some combinations of it will till the whole floor.

    ```cpp
    int TillingWays(int n){
        if(n==0){
            return 0;
        }
        if(n==1){
            return 1;
        }
        return TillingWays(n-1) + TillingWays(n-2);
    }
    ```

---

- Friends pairing problem

    ![Recursion%2084acc3ccee4c4cd698acd1f28b7c0a00/Untitled%2017.png](Recursion%2084acc3ccee4c4cd698acd1f28b7c0a00/Untitled%2017.png)

    1st friend can be paired with n-1 friends.

    if we paired with n-1 then friendPaired(n-1)

    if we paired with n-2 then friendPaired(n-2)*(n-1) ways.

    add both to get the total ways.

    Base case if n==0:return 0, if n==1 return 1(means single) if n==2: return 2(paired)

    ```cpp
    int firendsPaired(int n){

        if(n==0 || n==1 || n==2){
            return n;
        }

        return firendsPaired(n-1) + firendsPaired(n-2)*(n-1);
    }
    ```

---

- 0-1 knapsack problem

    ![Recursion%2084acc3ccee4c4cd698acd1f28b7c0a00/Untitled%2018.png](Recursion%2084acc3ccee4c4cd698acd1f28b7c0a00/Untitled%2018.png)

    - summation of values should be max.
    - weight should be less than capacity of knapsack.

    At every point we have 2 options, either add(1) or don't add(0).

    Approach:

    2 case:

    1. Consider the nth element and add it.
    2. Consider the nth element but dont add it.

    Check which one of this is more profitable or max(1,2).

    Base case:

    if(weight of n > Weight of knapsack){

    return 2 waala case. i.e (consider nth but dont add it).

    }

    if(n==0 || W==0){

    return 0;

    }

    Pseudo Code:

    case 1 : considering nth item and adding it

    knapsack(values,wt,n-1,W-wt[n-1])+value[n-1];

    case 2: considering nth item butnot adding it.

    knapsack(values,wt,n-1,W);

    ```cpp

    int knapsack(int values[],int wt[],int n,int W){

        if(n==0 || W==0){
            return 0;
        }
        if(wt[n-1]>W){
            return knapsack(values,wt,n-1,W);
        }
        return max(knapsack(values,wt,n-1,W-wt[n-1])+values[n-1],knapsack(values,wt,n-1,W));    

    }

    int main(){

        int wt[3] = {10,20,30};
        int values[3] = {100,50,150};

        int W = 50;
        cout << knapsack(values,wt,3,W);

    }
    ```