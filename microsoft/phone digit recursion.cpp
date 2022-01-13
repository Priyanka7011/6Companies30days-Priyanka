vector<string> possibleWords(int a[], int N)
    {
        //Your code here
        string keypad[]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> ans;
        int index=0;
        string output="";
        solve(keypad,ans,index,output,a,N);
        
        return ans;
    }
    
    void solve(string keypad[],vector<string> &ans,int index,string output,int a[],int n){
        if(index>=n){
            ans.push_back(output);
            return;
        }
        
        
        for(int i=0;i<keypad[a[index]].length();i++){
            char c=keypad[a[index]][i];
            solve(keypad,ans,index+1,output+c,a,n);
        }
        
        
        return ;
        
        
    }