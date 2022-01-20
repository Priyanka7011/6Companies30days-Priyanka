string amendSentence (string s)
    {
        // your code here
        string ans="";
        string temp="";
        for(int i=0;i<s.length();i++){
            
            if(i==0){
                temp+=tolower(s[0]);
            }
            else if(islower(s[i]))
              temp+=s[i];
            else{
                
                ans+=temp;
                ans+=" ";
                temp=tolower(s[i]);
                
                
            }
            //cout<<temp;
            
        }
        ans+=temp;
        
        //cout<<ans;
        return ans;
    }