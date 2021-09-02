# Permutations

Created: June 5, 2021 2:45 PM

A permutation is a rearrangement of members of a sequence into a new sequence.

T(n) = n!

- For Distinct Elements

    ## Problem:

    ![Permutations%20f8fcc0c97b74486aafc165de2c11fd16/Untitled.png](Permutations%20f8fcc0c97b74486aafc165de2c11fd16/Untitled.png)

    possible permutations = n!

    Recursive approach:

    [1,2,3,4,5] = swap(1,2) → 2,1,3,4,5 gives 1 permutation.

    swapping n times for all elements will give n! permutations.

    IMP : This method is only valid for distinct elements

    - If we are at i index then swapping arr[i] and arr[i+1] will result in permutations.

    ```cpp
    vector<vector <int>> ans;
    void permutation_rec(vector<int> &vec, int idx ){
        if(idx == vec.size()){
            ans.push_back(vec);
            return;
        }
        for(int i=idx;i<vec.size();i++){
            swap(vec[i],vec[idx]);
            permutation_rec(vec,idx+1);
            swap(vec[i],vec[idx]);
        }
        return;

    }
    ```

    Q: why 2 swaps?

    A:

    ![Permutations%20f8fcc0c97b74486aafc165de2c11fd16/Untitled%201.png](Permutations%20f8fcc0c97b74486aafc165de2c11fd16/Untitled%201.png)

    Without 2nd swap

    ![Permutations%20f8fcc0c97b74486aafc165de2c11fd16/Untitled%202.png](Permutations%20f8fcc0c97b74486aafc165de2c11fd16/Untitled%202.png)

    With swap

    > Current idx se i ko harr baar swap kro and idx+1 k liye recursion ko boldo.

- Using STL

    next_permutation(start,end)

    This will generate a permutation each time it is called.

    when all the permutation are generated it will return false.

    ```cpp
    int main(){

        vector<int> vec = {1,2,3};

        vector<vector<int>> ans;
        sort(vec.begin(),vec.end());
        do{
            ans.push_back(vec); //add it.
        }while(next_permutation(vec.begin(),vec.end()));//generate permutation

        
        for(auto i : ans){
            for(auto j:i){
                cout<< j;
            }
            cout << endl;
        }

    }
    ```

- May contain duplicate elements

    > If we used distinct elements approach here, it wont be able to understand the difference between duplicates, because it just swpas the element and return the result.

    It doesnot know the difference between 121 and 121, because there we worked on indices not values.

    ---

    so we have to avoid these duplicates in order to find permutations when duplicates are in our array.

    ![Permutations%20f8fcc0c97b74486aafc165de2c11fd16/Untitled%203.png](Permutations%20f8fcc0c97b74486aafc165de2c11fd16/Untitled%203.png)

    ![Permutations%20f8fcc0c97b74486aafc165de2c11fd16/Untitled%204.png](Permutations%20f8fcc0c97b74486aafc165de2c11fd16/Untitled%204.png)

    suppose we swapped here 12335 → 12335 , no changes! This type of swaps are resulting in duplicates.

    So, we need to avoid these swaps between same number.

    for this we state a if conition st:

    if(i ≠ idx and a[i] == a[idx])

    continue;

    ....

    Q: why i≠idx?

    - **Answer**

        because we want to swap once with the next unique element and for this.

        idx is the starting point and i is current, 

        if **i!=idx && a[i] == a[idx]** : mtln  idx → 3    i → 3 

        in array 123**(idx**)3(i)45 here idx≠i and arr[idx] = 3 == arr[i] =3

        thats why.

    ```cpp
    #include <bits/stdc++.h>

    using namespace std;

    vector<vector<int>> ans;

    void PermutationsOnDuplicateItems(vector<int> &vec,int idx){
        
        if(idx == vec.size()){
            ans.push_back(vec);
            return;
        }

        for(int i=idx;i<vec.size();i++){
            if(i!=idx && vec[i]==vec[idx])
                continue;
            swap(vec[i],vec[idx]);
            PermutationsOnDuplicateItems(vec,idx+1);
            swap(vec[i],vec[idx]);
        }
        return;

    }

    int main(){

        vector<int> vec = {1,2,1};
        PermutationsOnDuplicateItems(vec,0);

        for(auto i : ans){
            for(auto j:i){
                cout<< j;
            }
            cout << endl;
        }

    }
    ```