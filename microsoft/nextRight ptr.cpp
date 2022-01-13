void connect(Node *root)
    {
       // Your Code Here
       queue<Node *> q;
       q.push(root);
       
       while(!q.empty()){
           int size=q.size();
           Node* temp=q.front();
           q.pop();
           for(int i=0;i<size;i++){
               if(temp->left)
                  q.push(temp->left);
                  
               if(temp->right)
                  q.push(temp->right);
                  
               if(i==size-1){
                   temp->nextRight=NULL;
                   //q.pop();
               }else{
                   temp->nextRight=q.front();
                   temp=q.front();
                   q.pop();
               }
               
               
               
           }
       }
    }  