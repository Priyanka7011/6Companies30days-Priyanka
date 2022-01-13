    vector <int> calculateSpan(int price[], int n)
    {
       // Your code here
       vector<int> v(n,1);
       stack<int> s;
       s.push(0);
       for(int i=1;i<n;i++){
           
           while(!s.empty() && price[s.top()]<=price[i]){
               s.pop();
           }
           int ans;
           if(!s.empty()){
               ans=i-s.top();
           }else{
               ans=i+1;
           }
           s.push(i);
           v[i]=ans;
       }
       return v;
    }
    
    
/*

we are only pushing i after popping elements because we are sure that elements between (i-1,i-2,i-k-1) 
to i-k are smaller. so only i and i-k in stack will give the span of stock .


*/