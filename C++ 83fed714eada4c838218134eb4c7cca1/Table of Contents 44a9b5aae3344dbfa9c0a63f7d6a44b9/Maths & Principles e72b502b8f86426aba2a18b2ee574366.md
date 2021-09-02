# Maths & Principles

Created: June 3, 2021 9:16 AM

- Sieve of Eratosthenes

    used to print prime numbers in a given range.

    concept: we traverse through an array containing numbers from the range and we mark each element as checked and unchecked.

    ![Maths%20&%20Principles%20e72b502b8f86426aba2a18b2ee574366/Untitled.png](Maths%20&%20Principles%20e72b502b8f86426aba2a18b2ee574366/Untitled.png)

    Approach:

    1. start traverse, check for first unmarked element, i.e 2.
    2. Mark all multiples of it till range_max
    3. Move to next unchecked element, i.e 3, now start checking from $i^2$ and mark all multiple's.

        Because, multiples < $i^2$ have already been marked by the previous number i.e 2.

        similarily for i=5 start checking from $i^2$.

    4. repeat untill i*2 ≤ range.
    5. all the unmarked elements left in the array will be prime numbers.

        ![Maths%20&%20Principles%20e72b502b8f86426aba2a18b2ee574366/Untitled%201.png](Maths%20&%20Principles%20e72b502b8f86426aba2a18b2ee574366/Untitled%201.png)

    ```cpp
    void sieveOfEratosthenes(int start,int end){
        int arr[end+1];
        for(int i=0;i<end+1;i++){
            arr[i] = 0;
        }
        for(int i=start;i*i <= end+1;i++){
            if(arr[i]==0){
            **    for(int j=i*2;j<end+1;j++){ j<sqrt(n)?
                    if(j%i==0)
                        arr[j]=1;
                }**
            }
            
        }
        for(int i=0;i<end+1;i++){
            if(arr[i]!=0){
                cout << " " << i;
            }
        }

    }
    ```

- Prime Factorization (using sieve of eratosthenes principle)

    prime factor: 20 = 2*2*5

    Approach :

    The key part is selecting an i and finding its multiple in second using j+=i , eg : if i=2 , spf[2] = 2 , now j+=i i.e 2+=2 → j=4 | spf[4] =2

    1.  create an array of size = number. intialize with i
    2. find the smallest prime factor, and store it on the index = number in spf array.

        {index,value} : {20,2}

    3. repeat this for all.
    4. Now use a while loop(n≠1):

        print(spf[n]) i.e 2

        n /=spf[n] i.e 20/2 = 10

        when n=10

        print(spf[10]) i.e 2

        n/=spf[n] i.e 10/2 = 5

        similarily for n=5

    5. And all our prime numbers will be printed untill n≠1.

    ```cpp

    void primeFactorization(int n){

        int spf[n+1];
        for(int i=0;i<n+1;i++){
            spf[i] = i;
        }
        for(int i=2;i<n/2;i++){
            if(spf[i]==i){
                for(int j=i*i;j<n+1;**j+=i**){ 
                    if(spf[j]==j){//checking 2nd time because it is possibe 
    														//we could have marked it earlier.
                        spf[j]=i; //spf[20] = 2;
                    }
                }
            }
        }
        while(n!=1){
            cout<< " " << spf[n] ;
            n/=spf[n];
        }
    }

    int main(){
        primeFactorization(20);
        

    }
    ```

- Inclusion - Exclusion Principle

    ---

    - Theory

        ![Maths%20&%20Principles%20e72b502b8f86426aba2a18b2ee574366/Untitled%202.png](Maths%20&%20Principles%20e72b502b8f86426aba2a18b2ee574366/Untitled%202.png)

        n1 : italian

        n2 : french

        n3 : both 

        Total = Italian + French - both

        ![Maths%20&%20Principles%20e72b502b8f86426aba2a18b2ee574366/Untitled%203.png](Maths%20&%20Principles%20e72b502b8f86426aba2a18b2ee574366/Untitled%203.png)

        div by 5 + div by 7 - div by both

    - problems
        - find the numbers divisible by 5 or 7

            a | b = a+b-a*b

            ```cpp
            int divisible(int number,int a,int b){
                int c1 = number/a;
                int c2 = number/b;
                int c3 = number/(a*b);

                return c1+c2-c3;

            }
            ```

        - euclid's algorithm to find GCD/HCF

            ![Maths%20&%20Principles%20e72b502b8f86426aba2a18b2ee574366/Untitled%204.png](Maths%20&%20Principles%20e72b502b8f86426aba2a18b2ee574366/Untitled%204.png)

            subtracting 2 numbers doesnot affect their GCD or HCF.

            ![Maths%20&%20Principles%20e72b502b8f86426aba2a18b2ee574366/Untitled%205.png](Maths%20&%20Principles%20e72b502b8f86426aba2a18b2ee574366/Untitled%205.png)

            ![Maths%20&%20Principles%20e72b502b8f86426aba2a18b2ee574366/Untitled%206.png](Maths%20&%20Principles%20e72b502b8f86426aba2a18b2ee574366/Untitled%206.png)

            above 2 approaches results in same result.

            ```cpp
            int gcd(int a,int b){

            		while(b!=0){
                    int rem = a%b;
                    a = b;
                    b = rem;
                }
                return a;
            }
            int main(){

                cout << gcd(42,24);

            }
            ```