vector<int> tree_ar;
    //Function to serialize a tree and return a list containing nodes of tree.
    void helperserialise(Node* root){
        if(root==NULL){
            tree_ar.push_back(0);
            return;
        }
        tree_ar.push_back(root->data);
        helperserialise(root->left);
        helperserialise(root->right);
    }
    vector<int> serialize(Node *root) 
    {
        //Your code here
        helperserialise(root);
        
        return tree_ar;
        
        
    }
    
    //Function to deserialize a list and construct the tree.
    Node * deSerialize(vector<int> &A)
    {
       //Your code here
       Node* root;
       //root->data=A[0];
       root=helperDeserialise(A);
       
       return root;
    }
    int x=0;
    Node* helperDeserialise(vector<int>& A){
        if((A.size()-1)<x || A[x]==0){
            x++;
            return NULL ;
        }
        Node* root=new Node(A[x++]);
        root->left=helperDeserialise(A);
        root->right=helperDeserialise(A);
        
        return root;
    }
