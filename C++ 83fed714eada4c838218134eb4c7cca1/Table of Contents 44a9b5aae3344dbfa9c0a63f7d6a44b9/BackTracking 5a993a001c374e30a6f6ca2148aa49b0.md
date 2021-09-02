# BackTracking

Created: June 5, 2021 10:39 AM

- Introduction

    ![BackTracking%205a993a001c374e30a6f6ca2148aa49b0/Untitled.png](BackTracking%205a993a001c374e30a6f6ca2148aa49b0/Untitled.png)

    Rahul wants a girlfriend.

    He goes on a date with 3 different girls Sneha, Meha, Neha

    Case1 : Rahul & Sneha

    Rahul doesnot like Sneha because she eats too much ketchup

    FAILED

    **Backtracked.**

    Case 2:  Rahul & Meha

    Meha rejected Rahul as she doesnot like tattoos

    **Backtracked.**

    Case 3: Rahul & Neha

    Neha likes Rahul and Rahul also likes Neha.

    PASSED

    **Moved forward.**

    So, Rahul checked every possible soltion(girls), if she liked him and he also liked her, they proceeded further and became couples, else Rahul backtracked and looked for other solution or girl which matches his needs.

    ![BackTracking%205a993a001c374e30a6f6ca2148aa49b0/Untitled%201.png](BackTracking%205a993a001c374e30a6f6ca2148aa49b0/Untitled%201.png)

---

- Problems
    - Rat in a Maze

        ![BackTracking%205a993a001c374e30a6f6ca2148aa49b0/Untitled%202.png](BackTracking%205a993a001c374e30a6f6ca2148aa49b0/Untitled%202.png)

        **Problem** : In a nXn matrix(maze_) find the path for the rat to reach from starting(0,0) to ending (n-1,n-1).

        **Constraints** : here the dark coloured blocks are obstacles or barriers meaning he cannot step on those blocks.

        Approach: 

        - Suppose the rat moved further by some means and reached this point

            ![BackTracking%205a993a001c374e30a6f6ca2148aa49b0/Untitled%203.png](BackTracking%205a993a001c374e30a6f6ca2148aa49b0/Untitled%203.png)

            Now he cannot reach to the solution from this point.

        - So, he will revert back to his previous correct step, peechli position pr waaps chla jaayga, and look for different path. (Back Tracking)

            ![BackTracking%205a993a001c374e30a6f6ca2148aa49b0/Untitled%204.png](BackTracking%205a993a001c374e30a6f6ca2148aa49b0/Untitled%204.png)

            - Now suppos he reached here,  he found out that the maze is ended and he cannot move down, again he has to back track and look for different solution.

            ![BackTracking%205a993a001c374e30a6f6ca2148aa49b0/Untitled%205.png](BackTracking%205a993a001c374e30a6f6ca2148aa49b0/Untitled%205.png)

            And finally he will arrive at the end point.

        ### Solution

        ![BackTracking%205a993a001c374e30a6f6ca2148aa49b0/Untitled%206.png](BackTracking%205a993a001c374e30a6f6ca2148aa49b0/Untitled%206.png)

        Input matrix : A n*n matrix where elements signify 1 where the rat can go and 0 where he cannot go.

        Output: we have to output the path taken by rat, represented by 1.

        So, if the rat stepped on a position and moved forward it will be 1.

        Algorithm:

        1. make a function that will check , if we can go on a block or not.
        2. First Recursively call for right then for bottom.
        3. Now this recursive calls will return true or false stating that aage jaage iska solution milega toa true nhi toa false.
        4. Now if false return kiya kisi recursive call ne, toa we will back track and look for other directions recursive call.
        5. if True then we will add it to out matrix and move forward.

        ---

        logic:

        ```cpp
        bool isSafe(int** arr, int x,int y,int n){

            if(x<n && y<n && arr[x][y]==1){
                return true;
            }
            return false;
        }

        bool RatinMaze(int** arr,int x,int y,int n,int** path){

            //base case
            if(x==n-1 && y==n-1){
                path[x][y] =1;
                return true;
            }

            if(isSafe(arr,x,y,n)){
                path[x][y] = 1;

                //recursive call for right
                if(RatinMaze(arr,x+1,y,n,path)){
                    return true;
                }
                //recursive call for bottom
                if(RatinMaze(arr,x,y+1,n,path)){
                    return true;
                }

                //backtracking
                path[x][y] = 0;
                return false;
                //solution not possible
            }
            return false;
        }
        ```

        ---

        Driver code:

        ```cpp
        int main(){
            int n=5;
            int **maze = new int*[n];
            int m[5][5] = {{1,0,1,0,1},{1,1,1,1,1},{0,1,0,1,0},{1,0,0,1,1},{1,1,1,0,1}};

            for(int i=0;i<n;i++){
                maze[i] = new int[n];
                for(int j=0;j<n;j++){
                    maze[i][j] =  m[i][j];
                }
            }
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    cout << " " << maze[i][j];
                }
                cout << endl;
            }
            int **path = new int*[n];
            for(int i=0;i<n;i++){
                path[i] = new int[n];
                for(int j=0;j<n;j++){
                    path[i][j] = 0;
                }
            }
            cout << endl;
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    cout << " " << path[i][j];
                }
                cout << endl;
            }    
            cout << "\nPath :" << endl;

            RatinMaze(maze,0,0,n,path);
            cout << endl;
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    cout << " " << path[i][j];
                }
                cout << endl;
            }    
            cout << "\nPath :" << endl;
            
        }
        ```

    ---

    - N-Queen problem

        ![BackTracking%205a993a001c374e30a6f6ca2148aa49b0/Untitled%207.png](BackTracking%205a993a001c374e30a6f6ca2148aa49b0/Untitled%207.png)

        input n=4

        Remember we have to insert atleast 1 queen in a **row**.

        means n*n chess board , and n queens have to be placed such that they donot kill each other.

        Approach:

        Constraints st the queens donot kill each other:

        1. indices(i,j) of every queen should be unique

            meaning no queens should have same index for row or column otherwise they will kill each other. Horizontally or vertically.

        2. no queens should have same diagonals.

            nhi to cross mein maardegi ,diagonally.

        using recursion approach:

        suppose we placed a queen at 0,0.

        1. Then next queen has to be placed , so we find suitable place for it taking constraints in consideration.
            - We cannot place it in 1st and 0th column (vertically)
            - We cannot place it in 1st row and 1st column (diagonally)

            So, we place the queen on 1st row and 2nd column.

            ![BackTracking%205a993a001c374e30a6f6ca2148aa49b0/Untitled%208.png](BackTracking%205a993a001c374e30a6f6ca2148aa49b0/Untitled%208.png)

        2. Now look for suitable place to place the third queen.
            - We cannot place it in 2nd row 0th column.(vertically)
            - We cannot place it in  2nd row 1st column and 3rd column.(diagonally)
            - We cannot place it in 2nd column. (horizontally)

            This means that we cannot place a queen in the 3rd row, this is because we placed our previous queen incorrectly.

            So, we back track and change the position of previous queen.

            ![BackTracking%205a993a001c374e30a6f6ca2148aa49b0/Untitled%209.png](BackTracking%205a993a001c374e30a6f6ca2148aa49b0/Untitled%209.png)

            Now check again if this position of previous is queen yields suitable position for the current queen or not.

            **Yes!**

            It does, if we place a queen in 3rd row 1st column.

            ![BackTracking%205a993a001c374e30a6f6ca2148aa49b0/Untitled%2010.png](BackTracking%205a993a001c374e30a6f6ca2148aa49b0/Untitled%2010.png)

        3. Now when we try to place the last queen in the last row, we cannot place it anywhere. 

            So, **backtrack**

            - we back track and call the previous[2] queen to change its position : it can't cchange so **backtrack.**
            - the previous queen backtracks to its previous[1] and tells it to change its position : it can't change so **backtrack**.
            - finally previous[1[ backtracks to previous[0] and tells it to change its position : it can change **Yes!**

            Notice this step involved 3 backtracks.

            ![BackTracking%205a993a001c374e30a6f6ca2148aa49b0/Untitled%2011.png](BackTracking%205a993a001c374e30a6f6ca2148aa49b0/Untitled%2011.png)

            previous[0] with backtrack changed positon.

            Now all the queens has to be placed again.

        4. repeating above steps untill we arrive at the solution(recursively).

        ### Algorithm:

        1. make a constraint checker function that verifies the constraints are true.

            for constraint checking:

            ![BackTracking%205a993a001c374e30a6f6ca2148aa49b0/Untitled%2012.png](BackTracking%205a993a001c374e30a6f6ca2148aa49b0/Untitled%2012.png)

            - Check upper right and left?

                yes, we have to check for them, as we have placed a queen there.

            - Check in bottom left and right diagonals.

                As in the above picture we are checking for 2nd row ,So we wont check for the next row's left and right diagonals

                (bottom left and right diagonals)

                why?

                Because we haven't reached till there yet, and it will be empty obiviously.

            - Check in same row?

                No, because we have to place a queen here, there cannot be a queen already present.

            - Check in same column?

                yes, because we could have placed a queen in the previous rows in the same column.

            ```cpp

            bool constraintChecker(int** chessboard, int x,int y,int n){
                for(int row=0;row<n;row++){
                    if(chessboard[row][y]==1){
                        return false;
                    }
                }

                int row =x;
                int col =y;
                
                //upper left so row and col both decreases.
                while(row>=0 && col >= 0){
                    
                    if(chessboard[row][col]==1){
                        return false;
                    }

                    row--;
                    col--;
                    

                }
                row=0;
                col=0;
                //upper right so row will decrease and col will increase.
                while(row>=0 && col<n){
                    if(chessboard[row][col]==1){
                        return false;
                    }
                    row--;
                    col++;
                } 
                
                return true;
            }

            bool NQueens(int** chessboard, int x,int n){
                if(x>=n){ //this means we have placed our n queens
                    return true;
                }
                for(int col=0;col <n;col++){
                    if(constraintChecker(chessboard,x,col,n)){
                        chessboard[x][col] = 1;
                        if(NQueens(chessboard,x+1,n)){ //agr queens place hogai toa true return hoga
                            return true;
                        }
                        //nhi toa back tracking 
                        chessboard[x][col] =0; //backtracking
                    }       
                }
                return false;
            }

            int main(){

                int n = 4 ; //input the number of queens and the size of the chess board;
                int **chessboard = new int*[n];
                for(int i=0;i<n;i++){
                    chessboard[i] = new int[n];
                    for(int j=0;j<n;j++){
                        chessboard[i][j] =0;
                    }
                }
                if(NQueens(chessboard,0,n)){
                    for(int i=0;i<n;i++){
                        for(int j=0;j<n;j++){
                            cout << chessboard[i][j];
                        }
                        cout << endl;
                    }
                }else{
                    cout << "No" ;
                }
                
            }
            ```

            write explaination here when revising.