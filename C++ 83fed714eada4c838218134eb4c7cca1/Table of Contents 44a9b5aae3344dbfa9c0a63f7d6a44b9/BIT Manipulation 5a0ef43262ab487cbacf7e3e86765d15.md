# BIT Manipulation

Created: June 2, 2021 4:34 PM

- Bit Manipulation Concepts
    - Get Bit

        ![BIT%20Manipulation%205a0ef43262ab487cbacf7e3e86765d15/Untitled.png](BIT%20Manipulation%205a0ef43262ab487cbacf7e3e86765d15/Untitled.png)

        ```cpp
        int getBit(int n,int pos){
            return (n& (1<<pos)!=0);
        }
        ```

        1<<pos will left-shift pos bits ,001 → 100

    - Set Bit

        ![BIT%20Manipulation%205a0ef43262ab487cbacf7e3e86765d15/Untitled%201.png](BIT%20Manipulation%205a0ef43262ab487cbacf7e3e86765d15/Untitled%201.png)

        **Difference from getBit:**

        here instead of getting a bit from on a particular position we have to set the bit.

        in getBit we took and(&) here we take or( | ).

        why or?

        if we have to set a bit that means replace 0→1

        so by left shifting we make a number whose bit is 1 where we want to insert.

        Now after taking or(|).

        if the number has 0 at the pos bit then it will get orred ( 0 | 1) → 1.

        else (1 | 1) → 1.

        Both the cases the bit will be set to 1.

        ```cpp
        int setBits(int n,int pos){
            return (n | (1<<pos)); //returns the new number 
        													//created after setting the bits
        }

        int main(){
            cout << setBits(5,1);
        }
        ```

    - Clear Bit

        ![BIT%20Manipulation%205a0ef43262ab487cbacf7e3e86765d15/Untitled%202.png](BIT%20Manipulation%205a0ef43262ab487cbacf7e3e86765d15/Untitled%202.png)

        Make the number whos posn bit you want to clear, using the left shift .

        take 1's compliment of it, so that akk bits except that posn becomes 1 and that posn becomes 0.

        Now take and(&) with the number , this will result in a number where the bit at posn will be zero because 0&0 = 0 and 1&0  =0.

        ```cpp
        int clearBits(int n,int pos){
            int mask = ~(1<<pos);
            return (n&mask);

        }
        int main(){

            cout << clearBits(5,2);

        }
        ```

    - Update Bit

        clear Bit + set bit

        ```cpp
        int updateBit(int n,int pos,int value){
            int mask = ~(1<<pos)
            n = (n&mask);//clear bit
            return (n|(value<<pos)); //set bit

        }
        ```

        value : value will be left shifted to pos bits. This means if we want to set 0 the value will be 000.

- Common generalized results
    - n-1 from n

        ![BIT%20Manipulation%205a0ef43262ab487cbacf7e3e86765d15/Untitled%203.png](BIT%20Manipulation%205a0ef43262ab487cbacf7e3e86765d15/Untitled%203.png)

        select the right most 1's bit and from here keep flipping every bit to the right.

    - n & n-1 has same bits as n except the rightmost set bit.

        (n&n-1) and n will have same bits except the rightmost set bit.

        if(n & n-1) == 0 :

        then it is a power of 2

        else:

        not a power of 2

        ![BIT%20Manipulation%205a0ef43262ab487cbacf7e3e86765d15/Untitled%204.png](BIT%20Manipulation%205a0ef43262ab487cbacf7e3e86765d15/Untitled%204.png)

    - power of 2

        1 << n

        will give nth power of 2.

- Problems
    - If power of 2?

        we will be using 2 generalized results from above section.

        if(n & n-1) == 0 :

        then it is a power of 2

        else:

        not a power of 2

        1000 & 0111 (8 & 7) = 0000

        ```cpp
        int power2(int n){
            return (n & n-1);
        }

        int main(){
            if(power2(8==0){
                cout << "yes" ;
            }else{
                cout << "no";
            }

        }
        ```

    ---

    - count the number of 1's in binary representation of a number.

        here we can use the second principle i.e (n&n-1) and n will have same bits except the rightmost set bit.

        ![BIT%20Manipulation%205a0ef43262ab487cbacf7e3e86765d15/Untitled%205.png](BIT%20Manipulation%205a0ef43262ab487cbacf7e3e86765d15/Untitled%205.png)

        ek baar yh process krne pr ek rightmost 1 bit 0 bn jaata h.

        we can do this process untill all the bits become zero and the number of repeatition of this process will be the number of 1's.

        ```cpp
        int noOf1(int n){
            int count1 = 0;
            while(n!=0){
                count1 ++;
                n = n&n-1;

            }
            return count1;
        }
        ```

    ---

    - generate all subsets of a set

        ![BIT%20Manipulation%205a0ef43262ab487cbacf7e3e86765d15/Untitled%206.png](BIT%20Manipulation%205a0ef43262ab487cbacf7e3e86765d15/Untitled%206.png)

        0 → $2^n-1$

    ---

    - Unique number (where each element is present twice)

        ![BIT%20Manipulation%205a0ef43262ab487cbacf7e3e86765d15/Untitled%207.png](BIT%20Manipulation%205a0ef43262ab487cbacf7e3e86765d15/Untitled%207.png)

        XOR Bitwise operator

        ![BIT%20Manipulation%205a0ef43262ab487cbacf7e3e86765d15/Untitled%208.png](BIT%20Manipulation%205a0ef43262ab487cbacf7e3e86765d15/Untitled%208.png)

        XOR : 1XOR1 =0  1^1 =0 ; any number ^ any number = 0

         

        ```cpp
        int Unique_elements(int arr[],int n){
            int xorsum =0;

            for(int i=0;i<n;i++){
                xorsum =xorsum^arr[i];
                cout << xorsum;
            }
            return xorsum;
        }

        int main(){
            int arr[5] = {1,2,3,2,1}; //each element is present twice ,Except one!
            cout << Unique_elements(arr,5);
        }
        ```

    ---

    - 2 Unique numbers (where each element is present twice)

        Approach :

        1. Using XOR we can find the xorsum which will give sum of the two unique elements(as in previous question)
        2. Now we will look at the sum of the two unique elements, and check for the rightmost set bit(1) position.
        3. Then iterate through the array and find all the elements having 1 at that position.

            ![BIT%20Manipulation%205a0ef43262ab487cbacf7e3e86765d15/Untitled%209.png](BIT%20Manipulation%205a0ef43262ab487cbacf7e3e86765d15/Untitled%209.png)

            4. Take xorsum of these elements, all duplicate elements will become 0, except the unique one.

            5. From the above process we got the element with setbit on ith position  as sum of the 2 unique numbers.

            ![BIT%20Manipulation%205a0ef43262ab487cbacf7e3e86765d15/Untitled%2010.png](BIT%20Manipulation%205a0ef43262ab487cbacf7e3e86765d15/Untitled%2010.png)

            6. From the sum calculate the 2nd unique number by subtracting the result. or take xor with the result.

            ```cpp
            int getBit(int n,int pos){
                return ((n&(1<<pos))!=0);
            }

            void Unique_elements(int arr[],int n){

                int xorsum =0;

                for(int i=0;i<n;i++){
                    xorsum = (xorsum^arr[i]);
                }
                int sumof2uniqueElements = xorsum;
                int setbit = 0;
                int pos = 0; //position where 1(setbit) is found
                while(setbit!=1){
                    setbit = xorsum & 1;
                    pos++;
                    xorsum = xorsum >> 1;
                }
                int setbitXorSum = 0;
                for(int i=0;i<n;i++){
                    if(getBit(arr[i],pos-1)){
                        setbitXorSum = setbitXorSum^arr[i];
                    }
                }
                cout << "1st unique element is:" << setbitXorSum << endl;
                cout << "2nd unique element is:" << (sumof2uniqueElements^setbitXorSum) << endl;

            } 
            ```

    ---

    - Unique number in a triplet

        ![BIT%20Manipulation%205a0ef43262ab487cbacf7e3e86765d15/Untitled%2011.png](BIT%20Manipulation%205a0ef43262ab487cbacf7e3e86765d15/Untitled%2011.png)

        Approach:

        1. create a new array where indices represents the positions where setBit is present in numbers.
        2. Iterate through every number and fill this array;

            if(getbit(arr[i],pos)==1)):

            countArray[pos]+=1l

            ![BIT%20Manipulation%205a0ef43262ab487cbacf7e3e86765d15/Untitled%2012.png](BIT%20Manipulation%205a0ef43262ab487cbacf7e3e86765d15/Untitled%2012.png)

        3. To find the number from the array, take modulo of every element with 3 

            `countArray[i] = countArray[i]%3.`

            ![BIT%20Manipulation%205a0ef43262ab487cbacf7e3e86765d15/Untitled%2013.png](BIT%20Manipulation%205a0ef43262ab487cbacf7e3e86765d15/Untitled%2013.png)

        4. The reverse of the  resultant elements  will be the unique element where triplets of numbe are present.
        5. Convert binary to decimal and get the number.

        ```cpp
        #include <bits/stdc++.h>

        using namespace std;
        int getbit(int n,int pos){
            return ((n&(1<<pos))!=0);
        }

        int unique_in_triplet(int arr[],int n){
            int countArray[64];
            for(int i=0;i<64;i++){
                countArray[i] = 0;
            } 
            for(int i=0;i<n;i++){
                int num = arr[i]; //get the number for which we have to
        													//calculate
                int pos = 0;
                int n = num;
                while(num!=0){ //iterate untill no 1's left in the represn.
                    if(getbit(n,pos)==1){
                        countArray[pos] +=1;
                    }
                    pos++; //iterating over all the positions.
                    num = num>>1;
                }
            }

        		//convert to decimal
            int dec = 0;
            for(int i=0;i<64;i++){
                if(countArray[i]%3==1){
                    dec += pow(2,i);
                }
            }

            return dec;
        }

        int main(){
            int arr[10] = {1,3,2,3,5,2,1,1,3,2};
            cout << unique_in_triplet(arr,10);

        }
        ```