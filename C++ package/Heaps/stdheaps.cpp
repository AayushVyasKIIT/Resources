#include <bits/stdc++.h>

using namespace std;

int parent(int i){
    return floor(i/2);
}

int right(int i){
    return 2*i+2;
}

int left(int i){
    return 2*i+1;
}

void max_heapify(vector<int> &arr,int i,int heap_size){
    int largest = i;
    int l = left(i);
    int r = right(i);
    if(l<heap_size and arr[l]>arr[largest]){
        largest = l;
    }
    if(r<heap_size and arr[r]>arr[largest]){
        largest = r;
    }
    if(largest!=i){
        swap(arr[largest],arr[i]);
        max_heapify(arr,largest,heap_size);
    }
}

void build_max_heap(vector<int> &arr,int heap_size){
    for(int i=heap_size/2;i>=0;i--){
        max_heapify(arr,i,heap_size);
    }
}

void heap_sort(vector<int> &arr){
    int heap_size = arr.size()-1;
    build_max_heap(arr,heap_size);
    for(int i=heap_size;i>0;i--){
        swap(arr[i],arr[0]);
        max_heapify(arr,0,i);
    }
}

int maximum(vector<int> arr){
    return arr[0];
}

int extract_max(vector<int> &arr){
    if(arr.size()<=0){
        return -1;
    }
    int max = arr[0];
    arr[0] = arr[arr.size()-1];
    arr.resize(arr.size()-1);
    max_heapify(arr,0,arr.size()-1);
    return max;
}
void heap_increase_key(vector<int> &arr,int i,int key){
    if(key<arr[i]){
        return;
    }
    arr[i] = key;
    while(i>0 and arr[parent(i)]<arr[i]){
        swap(arr[i],arr[parent(i)]);
        i = parent(i);
    }

}
void insert_max_heap(vector<int> &arr,int key){
    arr.push_back(INT_MIN);
    heap_increase_key(arr,arr.size()-1,key);
}
int main(){
    vector<int> arr = {4,5,2,3,1};

    build_max_heap(arr,arr.size());
    cout << extract_max(arr);

    heap_increase_key(arr,1,7);

    insert_max_heap(arr,0);

    cout << "\nsorted array is:" << endl;
    heap_sort(arr);
    for(auto i:arr){
        cout << i;
    }
    
}