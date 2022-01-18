string nextPalin(string N) { 
        //complete the function here
        int n=N.size();
        if(n<=3) return "-1";
        string half=N.substr(0,n/2);
        
        if(next_permutation(half.begin(),half.end())){
            string ans=half;
            if(n&1){
                ans+=N[n/2];
            }
            
            reverse(half.begin(),half.end());
            
            ans+=half;
            
            return ans;
        }
        
        return "-1";
        
        
        
        
    }

    /*
    It is used to rearrange the elements in the range [first, last) into the next lexicographically
     greater permutation. A permutation is each one of the N! possible arrangements the
     elements can take (where N is the number of elements in the range)

     The complexity of the code is O(n*n!) which also includes printing all the permutations


     return value: 
true : if the function could rearrange 
the object as a lexicographically greater permutation.
    
    */