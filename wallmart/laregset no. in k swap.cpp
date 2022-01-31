 public:
    //Function to find the largest number after k swaps.
    void findMaxUtil(string str,string &max,int k,int pos){
        if(k==0)
          return;
        
        char maxm=str[pos];
        for(int i=pos+1;i<str.length();i++){
            if(maxm<str[i])
                maxm=str[i];
        }
        
        if(maxm !=str[pos])
           k--;
        
        for(int i=str.length()-1;i>=pos;i--){
            if(str[i]==maxm){
                swap(str[i],str[pos]);
                if(str.compare(max)>0)
                   max=str;
                
                findMaxUtil(str,max,k,pos+1);
                
                swap(str[i],str[pos]);
            }
        }
    }
    string findMaximumNum(string str, int k)
    {
       // code here.
       string max=str;
       findMaxUtil(str,max,k,0);
       return max;
    }

/*

we again swap in line 24
because there can be more than one occurence of maxm element in string
and we want the nearest from pos to get the maximum number
that's why we are resetting and move backward to see if there are more 
maxm element