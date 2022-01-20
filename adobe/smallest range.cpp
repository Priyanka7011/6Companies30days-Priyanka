#define p pair<int,pair<int,int>>
    pair<int,int> findSmallestRange(int arr[][N], int n, int k)
    {
          //code here
          priority_queue<p,vector<p>,greater<p>>q;
           int mn=INT_MAX,mx=INT_MIN, range=INT_MAX;
            int low=0,high=0;
           for(int i=0;i<k;i++){
            q.push({arr[i][0],{i,0}});
            mn=min(arr[i][0],mn);
            mx=max(arr[i][0],mx);
            
           }
        while(true){
            p temp=q.top();
            q.pop();
            
           int min1=temp.first;
           
            if(range >mx-min1){
                
                mn=min1;
                low=mn;
                high=mx;
                range=mx-mn;
                
            }
          int i=temp.second.first;//array number
          int j=temp.second.second;// index
          
          if(j==n-1)//if fully traversed
          break;
          
          q.push({arr[i][j+1],{i,j+1}});
          
          if(mx <arr[i][j+1])
          {
              mx=arr[i][j+1];
          }
 
        }
        return {low,high};
          
    }
    /*
    
    we have to make a pririty queue to store the index ,row_number and element also.

travese the lists and keep on finding the min and max difference .
if range of previous difference is greater than current min max difference ,update range.
    
    */