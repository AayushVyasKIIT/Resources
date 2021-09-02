# Binary Search Tree

Created: July 3, 2021 10:42 AM

![Binary%20Search%20Tree%20ff13de6e350e419aaba45e71e922a684/Untitled.png](Binary%20Search%20Tree%20ff13de6e350e419aaba45e71e922a684/Untitled.png)

![Binary%20Search%20Tree%20ff13de6e350e419aaba45e71e922a684/Untitled%201.png](Binary%20Search%20Tree%20ff13de6e350e419aaba45e71e922a684/Untitled%201.png)

![Binary%20Search%20Tree%20ff13de6e350e419aaba45e71e922a684/Untitled%202.png](Binary%20Search%20Tree%20ff13de6e350e419aaba45e71e922a684/Untitled%202.png)

- Building a Binary Search Tree

    ## Building a BST from an array

    Algorithm:

    1. check if root==NULL:

        return new node(val);

    2. check if root→data > val :

        proceed to root's left

        else:

        proceed to root's right

    3. recursively call untill root == NULL 
    4. then on the callbacks it will be assigned to roots-left or roots→right.

    ```cpp
    node* BuildBST(node* root,int val){
        if(root==NULL){
            return new node(val);
        }
        if(root->data>val){
            root->left = BuildBST(root->left,val);
        }else{
            root->right = BuildBST(root->right,val);
        }
        return root;
    }
    void InOrder(node* root){
        if(root==NULL){
            return;
        }
        InOrder(root->left);
        cout << root->data << " ";
        InOrder(root->right);
        
    }
    int main(){
        vector<int> arr = {5,2,1,3,4,0};
        node* n = new node(arr[0]);
        for(int i=1;i<arr.size();i++){
            BuildBST(n,arr[i]);
        }
        InOrder(n);
        
    }
    ```

    The inorder traversal of the BST will always be in sorted order.

- Search in BST

    ![Binary%20Search%20Tree%20ff13de6e350e419aaba45e71e922a684/Untitled%203.png](Binary%20Search%20Tree%20ff13de6e350e419aaba45e71e922a684/Untitled%203.png)

    T(n) = O(logn) in BST

    T(n) = O(n) in BT because there we have to see each and every node.

    here we know the value to left of the tree will be smaller and the value to the right of the tree will be greater.

    So, we looking the subtrees where the possibility of the node is more.

    ```cpp
    bool SearchBST(node* root,int key){
        if(root==NULL){
            return false;
        }

        if(root->data == key){
            return true;
        }
        if(root->data > key){
            return SearchBST(root->left,key);
    //search in left
        }else{
            return SearchBST(root->right,key);
    //search in right
        }
        return false;
    }
    ```

- Delete in BST

    Algorithm:

    There will be total of 3 cases for deleting a node

    1. if the node is the leaf node
    2. if the node has only 1 child(either left or right)
    3. if the node has both childs

    case1 : if the node is leaf node 

    delete or free the node

    case2 : if the node has only 1 child

    ![Binary%20Search%20Tree%20ff13de6e350e419aaba45e71e922a684/Untitled%204.png](Binary%20Search%20Tree%20ff13de6e350e419aaba45e71e922a684/Untitled%204.png)

    replace parent with child.

    case3: if the node has 2 childs

    ![Binary%20Search%20Tree%20ff13de6e350e419aaba45e71e922a684/Untitled%205.png](Binary%20Search%20Tree%20ff13de6e350e419aaba45e71e922a684/Untitled%205.png)

    find the inOrder successor of current node.

    inOrder successor means if we write the inOrder sequence of the tree the number next to the current node will be its successor.

    ![Binary%20Search%20Tree%20ff13de6e350e419aaba45e71e922a684/Untitled%206.png](Binary%20Search%20Tree%20ff13de6e350e419aaba45e71e922a684/Untitled%206.png)

    ![Binary%20Search%20Tree%20ff13de6e350e419aaba45e71e922a684/Untitled%207.png](Binary%20Search%20Tree%20ff13de6e350e419aaba45e71e922a684/Untitled%207.png)

    [Binary%20Search%20Tree%20ff13de6e350e419aaba45e71e922a684/deleting__a_node_in_BST.mkv](Binary%20Search%20Tree%20ff13de6e350e419aaba45e71e922a684/deleting__a_node_in_BST.mkv)

    ```cpp
    node* InOrderSuccessor(node* rootRight,int key){
        node* curr = rootRight;
        // we will be looking in the left of the current node because
        // our current node is root->right which means if we look for the values in the curr->right, the values will be greater than
        // root->right->data
        // but we want to replace the parent with value < root->right->data in order to preserve the binary tree property,
        // this can be done by looking in the left subtree for smaller value that fits just correctly. and its value will be < root->right
        //thus curr->left->data will always be < root->right->data.
        while(curr && curr->left!=NULL){
            curr = curr->left;
        }
        return curr;
    }
    node* deleteInBST(node* root,int key){
        if(root==NULL){
            return NULL;
        }
        if(root->data > key){
            root->left = deleteInBST(root->left,key);
        }
        else if(root->data < key){
            root->right = deleteInBST(root->right,key);
        }else{
            //case 2
            if(root->left==NULL){
                node* temp = root->right;
                free(root);
                return temp;
            }else if(root->right==NULL){
                node* temp = root->left;
                free(root);
                return temp;
            }
            //case 3
            node* temp = InOrderSuccessor(root->right,key);
            //we find the inOrderSuccessor and returns it
            root->data = temp->data;
            //we replace our current roots data with the inOrderSuccessor's data
            root->right = deleteInBST(root->right,temp->data);
            //we delete our inOrderSuccessor as it is now present at our root node.
        }
        return root;

    }
    ```

- Construct BST from preOrder

    [https://www.youtube.com/watch?v=vFW80O0NzBU&list=PLfqMhTWNBTe0b2nM6JHVCnAkhQRGiZMSJ&index=110](https://www.youtube.com/watch?v=vFW80O0NzBU&list=PLfqMhTWNBTe0b2nM6JHVCnAkhQRGiZMSJ&index=110)

    ```cpp
    node* BSTfromPreOrder(vector<int> preorder,int* preorderidx,int min,int max,int key,int n){
        if(*preorderidx >=n){
            return NULL;
        }
        node* root = NULL;
        if(key>min and key<max){ //if it follows BST
            root = new node(key);
            *preorderidx = *preorderidx + 1;
            if(*preorderidx<n){ //create bst for left
                root->left = BSTfromPreOrder(preorder,preorderidx,min,key,preorder[*preorderidx],n);
            }//min,max(NULL,key)
            if(*preorderidx<n){
                root->right = BSTfromPreOrder(preorder,preorderidx,key,max,preorder[*preorderidx],n);
            }//max,min(key,NULL)
        }
        return root;
    }
    ```

- check if BST or not

    check if the given tree is a BST or not

    Brute force  : just comparing root→data > root→left→data and root→data < root→right→data 

    But this will give wrong ❌ answer. As this will only compare the nodes current left and right not with the whole left and right subtree.

    **Correct Approach**:

    If we make sure that:

    1. our current node is greater than left subtree's max  

    2. our current node is lesser than right subtree's min  

    then we can say that it is BST.

    ```cpp
    bool check4BST(node* root,node* min = NULL,node* max = NULL){
        if(root==NULL){
            return true; //if no node then already in BST
        }
        if(min!=NULL and root->data <= min->data){
    		//if failed for left
            return false;

        }
        if(max!=NULL and root->data >= max->data){
    		//if failed for right
            return false;
        }	
    //for left min,max = min,root // for right min,max = root,max
        return check4BST(root->left,min,root)
    						 and check4BST(root->right,root,max);
    }
    ```

- make a balanced BST from sorted array

    ![Binary%20Search%20Tree%20ff13de6e350e419aaba45e71e922a684/Untitled%208.png](Binary%20Search%20Tree%20ff13de6e350e419aaba45e71e922a684/Untitled%208.png)

    ![Binary%20Search%20Tree%20ff13de6e350e419aaba45e71e922a684/Untitled%209.png](Binary%20Search%20Tree%20ff13de6e350e419aaba45e71e922a684/Untitled%209.png)

    ![Binary%20Search%20Tree%20ff13de6e350e419aaba45e71e922a684/Untitled%2010.png](Binary%20Search%20Tree%20ff13de6e350e419aaba45e71e922a684/Untitled%2010.png)

    balanced bst ka preorder print krwane s sorted order mein output aayga.

    ```cpp
    node* BBSTfromSortedArray(vector<int> sortedArray,int start,int end){
        if(start>end){
            return NULL;
        }
        int mid = (start+end)/2;
        node* root = new node(sortedArray[mid]);
        root->left = BBSTfromSortedArray(sortedArray,start,mid-1);
        root->right = BBSTfromSortedArray(sortedArray,mid+1,end);

        return root;
    }
    ```

- Catalan Numbers