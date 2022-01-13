int countHelper(Node* root,int X,int &cnt){
    if(root==NULL){
        return 0;
    }
    
    int sm=root->data + countHelper(root->left,X,cnt)
          + countHelper(root->right,X,cnt);
          
    if(X==sm)
    cnt++;
    
    return sm;
}
int countSubtreesWithSumX(Node* root, int X)
{

	int cnt=0;
	countHelper(root,X,cnt);
	
	return cnt;
	
}

/*
subtree is all child nodes below that node + that node itself.

          1
        /  \
       5    4       so now   1->5 is not a subtree 1->5->2->-1 is a subtree or
      /             5->2->-1 is a subtree or 2->-1 is a subtree or -1 itself is a subtree
     2             
    /
   -1


*/