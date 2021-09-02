# Set & Multiset

Created: June 24, 2021 8:49 AM

- Set

    A set contains unique values only.

    all operations on multiset is applicable on set

    ```cpp
    set<int> st;
    ```

- Multiset

    A multiset is a set which may contain redundant values.

    ```cpp
    multiset<int,greater<int>> ms;
    ```

    if greater is sent then the greatest element will be at the begin() of the multiset.

    **[begin()](https://www.geeksforgeeks.org/multiset-begin-and-end-function-in-c-stl/)**

    – Returns an iterator to the first element in the multiset

    **[end()](https://www.geeksforgeeks.org/multiset-begin-and-end-function-in-c-stl/)**

    – Returns an iterator to the theoretical element that follows last element in the multiset

    **[size()](https://www.geeksforgeeks.org/multiset-size-in-c-stl-with-examples/)**

    – Returns the number of elements in the multiset

    **[max_size()](https://www.geeksforgeeks.org/multiset-max_size-in-c-stl/)**

    – Returns the maximum number of elements that the multiset can hold

    **[empty()](https://www.geeksforgeeks.org/multiset-empty-function-in-c-stl/)**

    – Returns whether the multiset is empty

    - a.erase() – Remove all instance of element from multiset having same value
    - a.erase(a.find()) – Remove only one instance of element from multiset having same value
    - **[begin()](https://www.geeksforgeeks.org/multiset-begin-and-end-function-in-c-stl/)** – Returns an iterator to the first element in the multiset.
    - **[end()](https://www.geeksforgeeks.org/multiset-begin-and-end-function-in-c-stl/)** – Returns an iterator to the theoretical element that follows last element in the multiset.
    - **[size()](https://www.geeksforgeeks.org/multiset-size-in-c-stl-with-examples/)** – Returns the number of elements in the multiset.
    - **[max_size()](https://www.geeksforgeeks.org/multiset-max_size-in-c-stl/)**– Returns the maximum number of elements that the multiset can hold.
    - **[empty()](https://www.geeksforgeeks.org/multiset-empty-function-in-c-stl/)** – Returns whether the multiset is empty.
    - **[pair insert(const g)](https://www.geeksforgeeks.org/multiset-insert-function-in-c-stl/)** – Adds a new element ‘g’ to the multiset.
    - **[iterator insert (iterator position,const g)](https://www.geeksforgeeks.org/multiset-insert-function-in-c-stl/)** – Adds a new element ‘g’ at the position pointed by iterator.
    - **[erase(iterator position)](https://www.geeksforgeeks.org/multiset-erase-in-c-stl/)**– Removes the element at the position pointed by the iterator.
    - **[erase(const g)](https://www.geeksforgeeks.org/multiset-erase-in-c-stl/)**– Removes the value ‘g’ from the multiset.
    - **[clear()](https://www.geeksforgeeks.org/multiset-clear-function-in-c-stl/)**– Removes all the elements from the multiset.
    - **[key_comp()](https://www.geeksforgeeks.org/multiset-key_comp-function-in-c-stl/)** / **[value_comp()](https://www.geeksforgeeks.org/multiset-value_comp-method-in-c-stl/)**– Returns the object that determines how the elements in the multiset are ordered (‘<‘ by default).
    - **[find(const g)](https://www.geeksforgeeks.org/multiset-find-function-in-c-stl/)**– Returns an iterator to the element ‘g’ in the multiset if found, else returns the iterator to end.
    - **[count(const g)](https://www.geeksforgeeks.org/multiset-count-function-in-c-stl/)**– Returns the number of matches to element ‘g’ in the multiset.
    - **[lower_bound(const g)](https://www.geeksforgeeks.org/multiset-lower_bound-in-cpp-stl-with-examples/)**– Returns an iterator to the first element that is equivalent to ‘g’ or definitely will not go before the element ‘g’ in the multiset if found, else returns the iterator to end.
    - **[upper_bound(const g)](https://www.geeksforgeeks.org/multiset-upper_bound-in-cpp-stl-with-examples/)**– Returns an iterator to the first element that is equivalent to ‘g’ or definitely will go after the element ‘g’ in the multiset if found, else returns the iterator to end.
    - **[multiset::swap()](https://www.geeksforgeeks.org/multisetswap-c-stl/)**– This function is used to exchange the contents of two multisets but the sets must be of same type, although sizes may differ.
    - **[multiset::operator=](https://www.geeksforgeeks.org/multisetoperator-c-stl/)**– This operator is used to assign new contents to the container by replacing the existing contents.
    - **[multiset::emplace()](https://www.geeksforgeeks.org/multisetemplace-c-stl/)**– This function is used to insert a new element into the multiset container.
    - **[multiset equal_range()](https://www.geeksforgeeks.org/multiset-equal_range-function-in-c-stl/)**– Returns an iterator of pairs. The pair refers to the range that includes all the elements in the container which have a key equivalent to k.
    - **[multiset::emplace_hint()](https://www.geeksforgeeks.org/multiset-emplace_hint-function-in-c-stl/)** – Inserts a new element in the multiset.
    - **[multiset::rbegin()](https://www.geeksforgeeks.org/multiset-rbegin-and-rend-function-in-c-stl/)**– Returns a reverse iterator pointing to the last element in the multiset container.
    - **[multiset::rend()](https://www.geeksforgeeks.org/multiset-rbegin-and-rend-function-in-c-stl/)**– Returns a reverse iterator pointing to the theoretical element right before the first element in the multiset container.
    - **[multiset::cbegin()](https://www.geeksforgeeks.org/multiset-cbegin-and-cend-function-in-c-stl/)**– Returns a constant iterator pointing to the first element in the container.
    - **[multiset::cend()](https://www.geeksforgeeks.org/multiset-cbegin-and-cend-function-in-c-stl/)**– Returns a constant iterator pointing to the position past the last element in the container.
    - **[multiset::crbegin()](https://www.geeksforgeeks.org/multiset-crbegin-and-crend-function-in-c-stl/)**– Returns a constant reverse iterator pointing to the last element in the container.
    - **[multiset::crend()](https://www.geeksforgeeks.org/multiset-crbegin-and-crend-function-in-c-stl/)**– Returns a constant reverse iterator pointing to the position just before the first element in the container.

- Maximum Sliding window

    T(n) = O(nlogn)

    ```cpp
    multiset<int,greater<int>> ms;
        vector<int> array = {-10,9,2,1,2,3,4,0,1};

        vector<int> MaxSlidingWindowAns;
        int k = 2;
        for(int i=0;i<k;i++){
            ms.insert(array[i]);
        }
        MaxSlidingWindowAns.push_back(*ms.begin());
        for(int i=k;i<array.size();i++){
            ms.erase(ms.lower_bound(array[i-k]));
            ms.insert(array[i]);
            MaxSlidingWindowAns.push_back(*ms.begin());
        }
        for(auto i:MaxSlidingWindowAns){
            cout << i << endl;
        }
    ```