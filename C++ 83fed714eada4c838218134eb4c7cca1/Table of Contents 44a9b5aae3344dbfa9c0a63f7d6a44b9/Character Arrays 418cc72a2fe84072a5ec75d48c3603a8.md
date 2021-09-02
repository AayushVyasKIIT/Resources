# Character Arrays

Created: June 1, 2021 5:21 PM

has n+1th  characters = "/0"

while(arr[i] ≠ '/0')

dont need loop for inputting characters;

cin >> arr;

- Palindrome

    Anna = annA

    ```cpp
    #include <bits/stdc++.h>

    using namespace std;

    bool palindrome(char *arr,int size){
        int start = 0;
        int end = size-1;
        while(start<end){
            cout << arr[start] << arr[end];
            if(arr[start]==arr[end]){
                start++;
                end--;
            }else{
                return 0;
            }
        }
        return 1;
    }

    int main(){

        int size;
        cin >> size; 
        char arr[100];
        cin >> arr;

        palindrome(arr,size)?cout<<"Palindrome:True":cout<<"Palindrome:False";

    }
    ```

- Largest word in a sentence

    ![Character%20Arrays%20418cc72a2fe84072a5ec75d48c3603a8/Untitled.png](Character%20Arrays%20418cc72a2fe84072a5ec75d48c3603a8/Untitled.png)

    ```cpp
    #include <bits/stdc++.h>

    using namespace std;

    int main(){
        int size;
        cin >> size;
        cin.ignore();

        char sentence[size];
        cin.getline(sentence,size);
        cin.ignore();

        int curr_len = 0;
        int len_mx = 0;
        int start = 0,start_mx = 0;
        for(int i=0;i<size+1;i++){
            cout << sentence[i] << endl;
            if(sentence[i]==' ' || sentence[i]== '\0'){
                if(curr_len>len_mx){
                    len_mx = curr_len;
                    start_mx = start;
                }
                start = i+1;
                curr_len=0;
            }else{
                curr_len ++;
                
            }

        }
        cout << "Maximum Length of word:" << len_mx;
        
        for(int i=0;i<len_mx;i++){
        
            cout << sentence[i+start_mx];
        }

    }
    ```

-