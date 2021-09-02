# Patterns

Created: June 27, 2021 3:24 PM

- Triangle Star 1

    ![Patterns%208ebfd38abc374faebf7440384787b161/Untitled.png](Patterns%208ebfd38abc374faebf7440384787b161/Untitled.png)

    ```python
    #include <iostream>

    int main() {
        // Write C++ code here
        std::cout << "Hello world!";
        int counter = 0;
        for(int i =0;i<5;i++){
            for(int j=0;j<5-i;j++){
                std::cout << "_"; 
            }
            for(int j=0;j<i;j++){
                std::cout << "* ";
            }
            std::cout << std::endl;
        }
        return 0;
    }
    ```

- Triangle Star 1

    ![Patterns%208ebfd38abc374faebf7440384787b161/Untitled.png](Patterns%208ebfd38abc374faebf7440384787b161/Untitled.png)

    ```python
    #include <iostream>

    int main() {
        // Write C++ code here
        std::cout << "Hello world!";
        int counter = 0;
        for(int i =0;i<5;i++){
            for(int j=0;j<5-i;j++){
                std::cout << "_"; 
            }
            for(int j=0;j<i;j++){
                std::cout << "* ";
            }
            std::cout << std::endl;
        }
        return 0;
    }
    ```

- Odd Triangle Star 2

    ![Patterns%208ebfd38abc374faebf7440384787b161/Untitled%201.png](Patterns%208ebfd38abc374faebf7440384787b161/Untitled%201.png)

    ```cpp

    #include <iostream>

    int main() {
        // Write C++ code here
        std::cout << "Hello world!";
        int counter = 0;
        for(int i =0;i<5;i++){
            for(int j=0;j<5-i;j++){
                std::cout << "_"; 
            }
            for(int j=0;j<2*i-1;j++){
                std::cout << "*";
            }
            std::cout << std::endl;
        }
        return 0;
    }
    ```

- reversed Odd Triangle Star 2

    ![Patterns%208ebfd38abc374faebf7440384787b161/Untitled%202.png](Patterns%208ebfd38abc374faebf7440384787b161/Untitled%202.png)

    ```cpp
    #include <iostream>

    int main() {
        // Write C++ code here
        int counter = 0;
        for(int i =5;i>0;i--){
            for(int j=0;j<5-i;j++){
                std::cout << "_"; 
            }
            for(int j=0;j<2*i-1;j++){
                std::cout << "*";
            }
            std::cout << std::endl;
        }
        return 0;
    }
    ```

- diamond

    ![Patterns%208ebfd38abc374faebf7440384787b161/Untitled%203.png](Patterns%208ebfd38abc374faebf7440384787b161/Untitled%203.png)

    ```cpp
    #include <iostream>

    using namespace std;

    int main()
    {   
        int n = 5;
        for(int i = 1 ; i<=n ;i++){
            for(int j=0; j<=n-i;j++){
                cout << "/" ;
            }
            for(int j=1;j<=2*i-1;j++){
                cout << "*" ;
            }
            cout <<endl;
            
        }
        for(int i = n-1 ; i>=1 ;i--){
            for(int j=0; j<=n-i;j++){
                cout << "/" ;
            }
            for(int j=1;j<=2*i-1;j++){
                cout << "*" ;
            }
            cout <<endl;
            
        }

        return 0;
    }
    ```

- 90* pyramid

    ![Patterns%208ebfd38abc374faebf7440384787b161/Untitled%204.png](Patterns%208ebfd38abc374faebf7440384787b161/Untitled%204.png)

    int main()
    {
    int n = 5;
    for(int i = 1 ; i<=n ;i++){
    for(int j=0; j<=n;j++){
    cout << " " ;
    }
    for(int j=1;j<=i;j++){
    cout << "*" ;
    }
    cout <<endl;

    ```
    }
    for(int i = n-1 ; i>=1 ;i--){
        for(int j=0; j<=n;j++){
            cout << " " ;
        }
        for(int j=1;j<=i;j++){
            cout << "*" ;
        }
        cout <<endl;

    }

    return 0;

    ```

    }