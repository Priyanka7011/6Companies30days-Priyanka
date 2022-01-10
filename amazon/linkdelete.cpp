void linkdelete(struct Node  *head, int m, int n)
    {
        //Add code here   
        Node* temp = head;
        while(temp){
            
            int tempM=m;
            while( temp && --tempM){
                temp=temp->next;
            }
            
            int tempN=n;
            Node* prev=temp;
            while(temp && tempN--){
                temp=temp->next;
            }
            if(prev){
                if(temp!=NULL){
                    temp=temp->next;
                    prev->next=temp;
                }else{
                    temp=NULL;
                    prev->next=NULL;
                }
            }
            
            
        }
    }