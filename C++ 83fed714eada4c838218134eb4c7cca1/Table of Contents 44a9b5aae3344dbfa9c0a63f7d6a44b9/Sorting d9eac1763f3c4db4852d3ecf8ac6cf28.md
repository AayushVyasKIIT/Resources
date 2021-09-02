# Sorting

Created: May 27, 2021 7:40 AM

- Selection Sort

    Criteria : Select the minimum element in the unsorted array and replace it with the first element and increment the sorted array by 1.

    T(n) : $O(n^2)$

    ```cpp
    #include <bits/stdc++.h>

    using namespace std;

    int* selectionSort(int arr[],int n){
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(arr[j]<arr[i]){
                    swap(arr[i],arr[j]);
                }
            }
        }
        return arr;
    }
    int main(){
        int arr[] = {2,3,1,5,0,6,4};
        int *a = selectionSort(arr,7);
        for(int i=0;i<7;i++){
            cout << a[i] ;
        }
    }
    ```

- Bubble Sort
    - Criteria : Swap two adjacent elements if in wrong order(L>R)
    - Result after 1 iteration : the largest element will be obtained at the last position. resulting in a sorted array.
    - n → n-1 ; traverse the array again and repeat the same untill the whole array turns into a sorted one.

    ```cpp
    #include <bits/stdc++.h>

    using namespace std;
    int* bubblesort(int arr[],int n){
        for(int i=0;i<n;i++){
            for(int j=0;j<n-i;j++){
                if(arr[j+1]<arr[j]){
                    swap(arr[j],arr[j+1]);          
                }
            }
        }
        return arr;
    }

    int main(){
        int arr[] = {3,4,15,1,6};
        int *r = bubblesort(arr,5);
        for(int i=0;i<5;i++){
            cout << "|"<<r[i];
        }
           
    }
    ```

- Insertion Sort

    Criteria: select an element and insert it at its correct position in a sorted array.

    logic: select an element and compare where its correct position should be, move rest of the elements 1 place to right and insert the element at the correct  position.

    ```cpp
    int* insertionSort(int arr[],int n){
        for(int i=1;i<n;i++){
            int current = arr[i];
            int j=i-1;
            while(current<arr[j] && j>=0){
                arr[j+1] = arr[j];
                j--;
            }
            arr[j+1] = current;
        }
        return arr;
    }

    int main(){
        int a[] = {5,3,2,4,1};
        int *r = insertionSort(a,5);
        for(int i=0;i<5;i++){
            cout << a[i];
        }

    }
    ```

- Merge Sort

    Based on Divide and Conquer Approach

    Divide the array into atomic units and then compare and place.

    Approach:

    **Working of mergeSort**

    ![Sorting%20d9eac1763f3c4db4852d3ecf8ac6cf28/Untitled.png](Sorting%20d9eac1763f3c4db4852d3ecf8ac6cf28/Untitled.png)

    Working of merge

    ![Sorting%20d9eac1763f3c4db4852d3ecf8ac6cf28/Untitled%201.png](Sorting%20d9eac1763f3c4db4852d3ecf8ac6cf28/Untitled%201.png)

    Algorithm:

    1. Take 3 pointers one for each array at the start and 1 for final array at l.
    2. create 2 temporary arrays of sizes size1 = mid-l+1 size2 = r-mid.
    3. Compare the values of the pointers and based on it fill the new array.
    4. Increment the pointer of the array whose value you filled.
    5. Repeat this untill ptr1≤size1 and ptr2≤size2.

    ```cpp

    void merge(int arr[],int l,int mid,int r){
        int n1 = mid-l+1;
        int n2 = r-mid;

        int a[n1];
        int b[n2];

        for(int i=0;i<n1;i++){
            a[i] = arr[l+i];
        }
        for(int j=0;j<n2;j++){
            b[j] = arr[mid+1+j];
        }
        
        int i=0;
        int j=0;
        int k=l;

        while(i<n1 && j<n2){
            if(a[i]<b[j]){
                arr[k] = a[i];
                k++;
                i++;
            }else{
                arr[k] = b[j];
                k++;
                j++;
            }
        }
        while(i<n1){
            arr[k] = a[i];
            k++;
            i++;
        }
        while(j<n2){
            arr[k] = b[j];
            k++;
            j++;
        }

    }

    void mergeSort(int arr[],int l,int r){

        if(l<r){
            int mid = (l+r)/2;
            mergeSort(arr,l,mid);
            mergeSort(arr,mid+1,r);
            merge(arr,l,mid,r);
        }

    }

    int main(){

        int arr[7] = {4,5,2,3,4,1,2};
        for(int i=0;i<7;i++){
            cout << arr[i];
        }
        cout << endl;
        mergeSort(arr,0,7);
        for(int i=0;i<7;i++){
            cout << arr[i];
        }
    }
    ```

    Explaination:

    `void mergeSort(int arr[],int l,int r){`
        `if(l<r){`
            `int mid = (l+r)/2;
            mergeSort(arr,l,mid);
            mergeSort(arr,mid+1,r);
            merge(arr,l,mid,r);
        }`
    `}`

    1. select the middle element
    2. send left array and right array to recursive calls.
    3. merge the results that comes back from the recursive calls.

        `void merge(int arr[],int l,int mid,int r){
            int n1 = mid-l+1;` //suppose mid = 4 & l=2 then size = 4-2+1 = 1 
            `int n2 = r-mid;` //7-4 = 3

            `int a[n1];
            int b[n2];

            for(int i=0;i<n1;i++){` //iterate over the temporary array
               `a[i] = arr[l+i];` //for iterating over the main array add i to l.
            `}
            for(int j=0;j<n2;j++){
                b[j] = arr[mid+1+j];` //mid is covered above start from mid +1
            `}
            
            int i=0;
            int j=0;
            int k=l;` k should point to the starting point till where sorted.

            `while(i<n1 && j<n2){
                if(a[i]<b[j]){
                    arr[k] = a[i];
                    k++;
                    i++;
                }else{
                    arr[k] = b[j];
                    k++;
                    j++;
                }
            }`

        //if one of the array is left.
            `while(i<n1){
                arr[k] = a[i];
                k++;
                i++;
            }
            while(j<n2){
                arr[k] = b[j];
                k++;
                j++;
            }

        }`

- Quick Sort

    we will select a pivot element and place it on its correct position.

    This pivot element can be the first element, mean, mode, median, last depends on us.

    ![Sorting%20d9eac1763f3c4db4852d3ecf8ac6cf28/Untitled%202.png](Sorting%20d9eac1763f3c4db4852d3ecf8ac6cf28/Untitled%202.png)

    ![Sorting%20d9eac1763f3c4db4852d3ecf8ac6cf28/Untitled%203.png](Sorting%20d9eac1763f3c4db4852d3ecf8ac6cf28/Untitled%203.png)

    Algorithm for Quick Sort:

    1. Use partition() to  partition the array around a pivot element and place it at its correct position.
    2. Tell recursion to do this for the left and right side of the pivot element's index.

    Partition(){

    ![Sorting%20d9eac1763f3c4db4852d3ecf8ac6cf28/Untitled%204.png](Sorting%20d9eac1763f3c4db4852d3ecf8ac6cf28/Untitled%204.png)

    }

    ![Sorting%20d9eac1763f3c4db4852d3ecf8ac6cf28/Untitled%205.png](Sorting%20d9eac1763f3c4db4852d3ecf8ac6cf28/Untitled%205.png)

    what is i doin?

    - Answer:

        i is the index of the last element that is <pivot element.

        It is used to swap the pivot element with the first element that is greater than pivot.

        ![Sorting%20d9eac1763f3c4db4852d3ecf8ac6cf28/Untitled%206.png](Sorting%20d9eac1763f3c4db4852d3ecf8ac6cf28/Untitled%206.png)

    ---

    Algorithm for Partition():

    1. Select a pivot element, in the above case we chose last element

        `pivot = arr[r];`

    2. Set a pointer that will point to the last element that is less than the pivot element.

        `int i= l-1;`

    3. from start(l) to end(r-1) iterate over the array:

        `if(arr[j] < pivot){`

        `i++;`

        `swap(arr[i],arr[j]);`

        `}`

    4. Atlast swap with 1 index + the last element that was smaller than pivot element to place the pivot element at its right position.

        `swap(arr[i+1],arr[pivot_index]);` or in above case `swap(i+1,r)`

    ```cpp
    int partition(int arr[],int l,int r){
        int pivot = arr[r];
        int p =r;
        int i = l-1;
        for(int j=l;j<r;j++){
            if(arr[j]<pivot){
                i++;
                swap(arr[j],arr[i]);
            }
        }
        swap(arr[i+1],arr[p]);
        return i+1;

    }

    void QuickSort(int arr[],int l,int r){
        if(l<r){
            int pi = partition(arr,l,r);
            QuickSort(arr,l,pi-1);
            QuickSort(arr,pi+1,r);
        }
    }

    int main(){

        int arr[7] = {4,5,2,3,4,1,2};
        for(int i=0;i<7;i++){
            cout << arr[i];
        }
        cout << endl;
        QuickSort(arr,0,6);
        for(int i=0;i<7;i++){
            cout << arr[i];
        }
    }
    ```

    `for(int j=l;j<r;j++)` this will iterate over the partitioned array and will always run from start(l) to end(r) irrespective of the pivot element.

    incase of pivot = arr[r] , j<r else j≤r (as r is the index of right most element).

- Count Sort

    T(n) = O(max(Ai)) + O(n) + O(max(Ai))

    ![Sorting%20d9eac1763f3c4db4852d3ecf8ac6cf28/Untitled%207.png](Sorting%20d9eac1763f3c4db4852d3ecf8ac6cf28/Untitled%207.png)

    Algorithm:

    1. create a count array storing the frequence of occurence of an element.
    2. modify this array by replacing each element with:

        count_arr[i] = count_arr[i-1] + count_arr[i]

    3. Traverse the main array from backward
    4. map arr[i] → count[arr[i]] 
    5. replace arr[i] = count[arr[i]]-1 // value of count_arr decremented by 1
    6. repeat this n-1 times and get the sorted array.

- DNF sort

    ![Sorting%20d9eac1763f3c4db4852d3ecf8ac6cf28/Untitled%208.png](Sorting%20d9eac1763f3c4db4852d3ecf8ac6cf28/Untitled%208.png)

    ![Sorting%20d9eac1763f3c4db4852d3ecf8ac6cf28/Untitled%209.png](Sorting%20d9eac1763f3c4db4852d3ecf8ac6cf28/Untitled%209.png)

    ```cpp
    void DNFSort(int arr[],int n){
        int low= 0;
        int mid = 0;
        int high = n-1;

        while(mid<=high){
            if(mid==0){
                swap(arr[low],arr[mid]);
                low++;
                mid++;
            }else if(mid==1){
                mid++;
            }else{
                swap(arr[mid],arr[high]);
                high--;
            }
        }
    }
    ```

- Wave sort

    ![Sorting%20d9eac1763f3c4db4852d3ecf8ac6cf28/Untitled%2010.png](Sorting%20d9eac1763f3c4db4852d3ecf8ac6cf28/Untitled%2010.png)

    bada chota bada chota bada

    ```cpp
    void WaveSort(int arr[],int n){

        for(int i=1;i<=n;i+=2){
            if(arr[i]>arr[i-1]){
                swap(arr[i-1],arr[i]);
            }else if(arr[i]>arr[i+1] && i<=n-2){
                swap(arr[i],arr[i+1]);
            }
        }

    }
    ```

    `else if(arr[i]>arr[i+1] && **i<=n-2**)` This is because if we are taking steps of i+=2, then we have to stop doing this before n-2 else we wont be able to check correctly for n-1 and n.

- Count inversions

    ![Sorting%20d9eac1763f3c4db4852d3ecf8ac6cf28/Untitled%2011.png](Sorting%20d9eac1763f3c4db4852d3ecf8ac6cf28/Untitled%2011.png)

    we cant take help of merge sort and solve this problem.

    when we merge in we cant look for inversions and add them.

    ![Sorting%20d9eac1763f3c4db4852d3ecf8ac6cf28/Untitled%2012.png](Sorting%20d9eac1763f3c4db4852d3ecf8ac6cf28/Untitled%2012.png)

    Suppose while merging if a[i] > b[j] : then inversion

    [IMP] : But if a[i] > b[j] then a[i+1] > b[j] and a[i+2] also till a[i+n], so we have n-i inversions here.

    ```cpp
    long long merge(int arr[],int l,int mid,int r){
        long long inv= 0;
        int n1 = mid-l+1;
        int n2 = r-mid;

        int a[n1];
        int b[n2];

        for(int i=0;i<n1;i++){
            a[i] = arr[l+i];
        }
        for(int i=0;i<n2;i++){
            b[i] = arr[mid+1+i];
        }
        int i=0;
        int j=0;
        int k=l;

        while(i<n1 && j<n2){
            if(a[i]<=b[j]){
                arr[k] = a[i];
                k++;
                i++;
            }else{
                arr[k] = b[j];
                inv+=n1-i; //jitna tak chota tha i un point ko hatake inversions
                k++;
                j++;
            }
        }
        while(i<n1){
            arr[k] = a[i];
            k++;
            i++;
        }
        while(j<n2){
            arr[k] = b[j];
            k++;
            j++;

        }
        return inv;
    }

    long long mergeSort(int arr[],int l,int r){
        long long inv = 0;
        if(l<r){
            int mid = (l+r)/2;
            inv+= mergeSort(arr,l,mid);
            inv+= mergeSort(arr,mid+1,r);
            inv+= merge(arr,l,mid,r);
        }
        return inv;
    }

    int main(){

        int arr[3] = {3,2,1};
        long long inv = mergeSort(arr,0,2);
        cout << inv;

    }
    ```