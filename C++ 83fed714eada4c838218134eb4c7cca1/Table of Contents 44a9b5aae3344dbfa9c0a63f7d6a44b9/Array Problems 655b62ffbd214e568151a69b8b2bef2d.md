# Array Problems

Created: May 29, 2021 4:37 PM

- Maximum till i

    problem : an array [1,....i..n] ,convert this into an array containing maximum till ith index array[i] → max(array[i])

    note: here maxium of array[i] is required not the max of the whole array.

    The maximum till that index has to be filled at that position.

    ```cpp
    #include <bits/stdc++.h>

    using namespace std;

    void max_till_i(int arr[],int size){
        int current_max = *arr;
        for(int i=1;i<size;i++){
            if(current_max>*(arr+i)){
                *(arr+i) = current_max;
            }else{
                current_max = *(arr+i);
            }

        }
    }

    int main(){

        int arr[] = {0,-9,1,3,-4,5,0};
        max_till_i(arr,7);
        for(int i=0;i<7;i++){
            cout << arr[i];
        }
    }
    ```

- Subarray vs Subsequences

    ### Subarrays

    Continous part of the array: [1,2,3,4,5] → [2,3,4] (correct) |  [1,4,5](incorrect)

    > number of subarrays of an array of n elements = nC2 + n

                                                                                                    = n*(n+1)/2

    ### Subsequences

    A subsequence is  a sequence that can be derived in an array by select zero or more elements, without changing the order of the remaining elements.

    [1,2,3,4,5] → [1,3,5] (correct) | [1,5,3](incorrect, order changed)

    > number of subsequences of an array w n elements = $2^n$

    Every subarray is a subsequence but every subsequence is not a subarray.

    ![Array%20Problems%20655b62ffbd214e568151a69b8b2bef2d/Untitled.png](Array%20Problems%20655b62ffbd214e568151a69b8b2bef2d/Untitled.png)

    # Problems:

    - Q: Sum of all sub arrays

        logic : 

        for i to n:

        for j=i to n:

        calculate sum()

        visually: 

        [0,1,2,3,4] →{i=0,j=0}:[0] ,{i=0,j=1}: [0,1] ,{i=0,j=2}: [0,1,2] ,{i=0;j=4}:[0,1,2,3,4]

        [1,2,3,4] →{i=1,j=1}:[1] ,{i=1,j=2}: [1,2] ,{i=1,j=3}: [1,2,3] ,{i=1;j=4}:[1,2,3,4]

        ```cpp
        #include <bits/stdc++.h>

        using namespace std;

        void sumOfSubArrays(int *arr,int n){
            
            for(int i=0;i<n;i++){
                int current_sum = 0;
                for(int j=i;j<n;j++){
                    current_sum += arr[j];
                    cout <<"Subarray:"<<i << " "<<current_sum << endl;
                }
            }
        }

        int main(){
            int arr[] = {1,2,3,4,5};
            sumOfSubArrays(arr,5);

        }
        ```

    - Q: Longest Arithmetic Subarray

        ![Array%20Problems%20655b62ffbd214e568151a69b8b2bef2d/Untitled%201.png](Array%20Problems%20655b62ffbd214e568151a69b8b2bef2d/Untitled%201.png)

        ![Array%20Problems%20655b62ffbd214e568151a69b8b2bef2d/Untitled%202.png](Array%20Problems%20655b62ffbd214e568151a69b8b2bef2d/Untitled%202.png)

        ```cpp
        #include <bits/stdc++.h>

        using namespace std;

        int main(){

            int arr[] = {10,7,4,6,8,11};

            int pd = abs(arr[0]-arr[1]);
            int curr = 2;
            int mx = 2;
            int j=2; //because 0 and 1 are covered in pd
            while(j<7){
                if(abs(arr[j]-arr[j-1])==pd){
                    curr +=1;
                }else{
                    pd = arr[j] - arr[j-1];
                    curr = 2;
                }
                mx = max(mx,curr);
                j++;
            }
            cout << mx;
        }
        ```

    - Q: Record Breaker

        ![Array%20Problems%20655b62ffbd214e568151a69b8b2bef2d/Untitled%203.png](Array%20Problems%20655b62ffbd214e568151a69b8b2bef2d/Untitled%203.png)

        ![Array%20Problems%20655b62ffbd214e568151a69b8b2bef2d/Untitled%204.png](Array%20Problems%20655b62ffbd214e568151a69b8b2bef2d/Untitled%204.png)

- First repeating element

    ![Array%20Problems%20655b62ffbd214e568151a69b8b2bef2d/Untitled%205.png](Array%20Problems%20655b62ffbd214e568151a69b8b2bef2d/Untitled%205.png)

    ```cpp
    #include <bits/stdc++.h>
    #include "stdneeds.cpp"
    using namespace std;

    // r1 : the first repeating element r2: its index value must be the least.
    int first_repeating_element(int arr[],int size){

        int countidx[*max_element(arr,arr+size)+1];
        for(int i=0;i<*max_element(arr,arr+size)+1;i++){
            countidx[i] = -1;
        }
        int minidx=INT_MAX;
        for(int i=0;i<size;i++){
            if(countidx[arr[i]]==-1){
                countidx[arr[i]] = i;
            }else if(countidx[arr[i]]>=0){
                if(countidx[arr[i]]<minidx){
                    minidx = countidx[arr[i]];
                }
            }
        }
        return minidx;
    }

    int main(){
        int* arr = array1d(5);
        printArray(arr,5);
        cout <<"\nMin idx:" <<first_repeating_element(arr,5);
    }
    ```

    The logic here was to replace the count array with the index of the elements. Then if an element is repeated we check for min index and update accordingly.

- Subarray with given sum

    ![Array%20Problems%20655b62ffbd214e568151a69b8b2bef2d/Untitled%206.png](Array%20Problems%20655b62ffbd214e568151a69b8b2bef2d/Untitled%206.png)

      

    > T(n) should != O(n^2) : infered from the constraints.

    Approach:

    ![Array%20Problems%20655b62ffbd214e568151a69b8b2bef2d/Untitled%207.png](Array%20Problems%20655b62ffbd214e568151a69b8b2bef2d/Untitled%207.png)

    1. Keep 2 pointers both starting from 0.
    2. increment en untill : current sum + arr[en] ≥ sum na hojaay.
    3. jese hi (2) satisfy hui loop khtm hojaayga and en ki value stop hojaaygi.
    4. Now check if the currSum == S. if yes print st and en return 0;
    5. if not then : while(j<n)  {increase st →while(currSum ≥ S)}

    ```cpp
    #include <bits/stdc++.h>
    #include "stdneeds.cpp"

    using namespace std;

    int main(){
        int arr[] = {1,2,3,8};
        int n = 4;
        int S=5;

        int i=0,j=0,st=-1,en=-1,currSum=0;

        while(j<n && currSum<=S){
            currSum += arr[en+1];
            en++;
            j++;
        }
        if(currSum==S){
            cout << st << en << endl;
            return 0;
        }
        while(i<n){
            while(currSum >= S){
                currSum -= arr[st+1];
                st++;
            }
            i++;
        }
        cout << st+1 << en+1;

    }
    ```

- Smallest Possitive Missing number

    ![Array%20Problems%20655b62ffbd214e568151a69b8b2bef2d/Untitled%208.png](Array%20Problems%20655b62ffbd214e568151a69b8b2bef2d/Untitled%208.png)

    ![Array%20Problems%20655b62ffbd214e568151a69b8b2bef2d/Untitled%209.png](Array%20Problems%20655b62ffbd214e568151a69b8b2bef2d/Untitled%209.png)

    ```cpp
    #include <bits/stdc++.h>

    using namespace std;
    int smallestMissingPossitiveNumber(int *arr,int size){
        int smpi;
        int max_size = *max_element(arr,arr+size)+1;
        bool check[max_size];

        for(int i=0;i<max_size;i++){
            check[i]=false;
        }

        for(int i=0;i<size;i++){
            if(arr[i]>=0 && check[arr[i]]!=true){
                check[arr[i]] = true;
            }
        }

        for(int i=0;i<max_size;i++){
            if(check[i]==false){
                smpi = i;
                break;
            }
        }
        return smpi;
    }
    int main(){

        int arr[] = {0,-9,1,3,-4,5};
        cout << "Smallest possitive integer missing is : " << smallestMissingPossitiveNumber(arr,6);

    }
    ```

- All possible subarrays

    Approach:

    1. ek loop for starting point, ek loop for ending point and ek loop beech k elements print krwane k liye (starting and ending inclusive)
    2. for(i...n):
        1. for(j=i ...n):

            values it will iterate for:

            when i=0 **j=0** .... j=n

            for(k=i;k≤j;k++)

            when i=0; j=0

            it will print value at 0 index

        2. for(j=i ...n):

            values it will iterate for:

            when i=0 j=1 .... j=n

            ending point has changed.

            for(k=i;k≤j;k++)

            when i=0; j=1

            so it will print values from 0 to 1

            arr[0] arr[1]

        3. Similarily when j=2:

            i=0 j=2 

            for(k=i;k≤j;k++){

            arr[0] arr[1] arr[2]

            }

    3. This will continue untill the whole subarrays are printed.

    ```cpp
    #include <bits/stdc++.h>
    #include "stdneeds.cpp"

    using namespace std;

    int main(){

        int size;
        cin >> size;

        int *arr = cinarray1d(size);

        for(int i=0;i<size;i++){

            for(int j=i;j<size;j++){
                
                for(int k=i;k<=j;k++){
                    cout << arr[k];
                }
                cout <<endl;
            }
            
        }

        
    }
    ```

- Maximum sum subarray
    - Naive Approach

        T(n) = $O(n^3)$

        ```cpp
        #include <bits/stdc++.h>
        #include "stdneeds.cpp"

        using namespace std;

        int main(){

            int size;
            cin >> size;

            int *arr = cinarray1d(size);
            int sum =0;
            int mx = INT_MIN;
            for(int i=0;i<size;i++){
                
                for(int j=i;j<size;j++){
                    int sum=0;    
                    for(int k=i;k<=j;k++){
                        sum += arr[k];
                    }
                    mx = max(sum,mx);
                }
                
            }
            cout << "Maximum sum subarray:" << mx << endl;

            
        }
        ```

    - Optimized way
        - Cumulative sum approach

            T(n) = $O(n^2)$

            ![Array%20Problems%20655b62ffbd214e568151a69b8b2bef2d/Untitled%2010.png](Array%20Problems%20655b62ffbd214e568151a69b8b2bef2d/Untitled%2010.png)

            ```cpp
            #include <bits/stdc++.h>
            #include "C:\Resources\C++ package\Array\stdneeds.cpp"

            using namespace std;

            int main(){

                int size;
                cin >> size;

                int *arr = cinarray1d(size);
                int sum =0;
                int mx = INT_MIN;
                int cummulative[size+1];      
                cummulative[0] = 0;
                for(int i=1;i<size+1;i++){
                    cummulative[i] = cummulative[i-1] + arr[i-1];
                }
                cout << "Cummulative array is:" << endl;
                printArray(cummulative,size+1);
                for(int i=1;i<=size;i++){
                    sum=0;
                    for(int j=0;j<i;j++){
                        sum = cummulative[i] - cummulative[j];
                        mx = max(sum,mx);
                    }

                }
                cout << "Maximum Sum sub array is:" << mx;

                
            }
            ```

        - Kadane's algorithm

            if neg: sum =0 else : sum += arr[i]

            T(n) = $O(n)$

            ![Array%20Problems%20655b62ffbd214e568151a69b8b2bef2d/Untitled%2011.png](Array%20Problems%20655b62ffbd214e568151a69b8b2bef2d/Untitled%2011.png)

            ```cpp
            #include <bits/stdc++.h>
            #include "C:\Resources\C++ package\Array\stdneeds.cpp"
            using namespace std;

            int main(){

                int size;
                cin >> size;

                int *arr = cinarray1d(size);
                int currSum =0;
                int mx = INT_MIN;

                for(int i=0;i<size;i++){
                    if(arr[i]<0){
            						//if curremt mumber == -ve then currSum =0
                        currSum = 0;
                    }else{
                        currSum += arr[i];
                    }
                    mx = max(currSum,mx);
                    
                }
                cout << "Maximum Sum sub array is:" << mx;

            }
            ```

         

- Maximum Circular Subarray

    ![Array%20Problems%20655b62ffbd214e568151a69b8b2bef2d/Untitled%2012.png](Array%20Problems%20655b62ffbd214e568151a69b8b2bef2d/Untitled%2012.png)

    2 cases : 1st dont need wrapping 

     2nd needs wrapping

    ![Array%20Problems%20655b62ffbd214e568151a69b8b2bef2d/Untitled%2013.png](Array%20Problems%20655b62ffbd214e568151a69b8b2bef2d/Untitled%2013.png)

    Sum of non contributing elements = -kadane(reversed_sign_array)

    Approach:

    case1 : 

    normally kadane's algorithm lgao and answer paao

    case 2: 

    for (i=0....n):

    1.find total sum of array

    2. Reverse sign of each element in the array

    Max_wrap_sum = Total sum of the array - (-kadane(arr,size))

    The array passed to kadane is the array whose element's sign we reversed.

    final Case:

    compare non-wrap sum from case1 vs wrapped sum from case 2 and output the max of both of them.

    > maximumSum = max(case1,case2)

    ![Array%20Problems%20655b62ffbd214e568151a69b8b2bef2d/Untitled%2014.png](Array%20Problems%20655b62ffbd214e568151a69b8b2bef2d/Untitled%2014.png)

    ```cpp
    #include <bits/stdc++.h>
    #include "C:\Resources\C++ package\Array\stdneeds.cpp"
    using namespace std;

    int kadane(int* arr,int size){
        
        int currSum =0;
        int mx = INT_MIN;

        for(int i=0;i<size;i++){
            if(arr[i]<0){
                currSum=0;
            }else{
                currSum += arr[i];
            }
            mx = max(currSum,mx);

        }
        return mx;
    }

    int main(){
        int size;
        cin >> size ;
        int *arr = cinarray1d(size);

        //case1 : non-wrap around sum using kadane's algorithm.
        int nonwrap = kadane(arr,size);

        //case2 : wrap around sum
        int totalSum =0;
        int wrap;

        for(int i=0;i<size;i++){
            totalSum += arr[i];
            arr[i] *= -1;
        }

        wrap = totalSum + kadane(arr,size);

        //finalcase
        cout << "Maximum sum of circular Sub array is: " << max(wrap,nonwrap);

    }
    ```

- Pair Sum Problem

    ![Array%20Problems%20655b62ffbd214e568151a69b8b2bef2d/Untitled%2015.png](Array%20Problems%20655b62ffbd214e568151a69b8b2bef2d/Untitled%2015.png)

    Naive approach:

    1. find all the possible sums
    2. compare them with k 
    3. if == k then output i,j

    $T(n) = O(n^2)$

    High-low approach:

    $T(n) = O(n)$

    1. sort the array in min T(n)
    2. take 2 pointers low → arr[0] and high = arr[n]
    3. while low  < high
        1. Add them and check if low + high < or > k
        2. if low + high < k : then low ++
        3. if low + high > k : then high —
        4. if low + high == k : then output

    ```cpp
    #include <bits/stdc++.h>
    #include "stdneeds.cpp"

    using namespace std;

    bool pairequalsK(int* arr,int size,int k){
        int low = 0;
        int high = size-1;
        while(low<high){
            if(arr[low]+arr[high]<k){
                low++;
            }else if(arr[low]+arr[high] == k){
                return true;
            }else{
                high--;
            }
        }
        return false;
            

    }

    int main(){
        int k=4;
        int *arr = array1d(5);
        sort(arr,arr+5);
        printArray(arr,5);
        pairequalsK(arr,5, k)?cout<< "yes":cout<<"no";

    }
    ```