class Solution{
  public:
    string decodedString(string s){
        // code here
       stack<char> st;
       for(int i=0;i<s.length();i++){
           if(s[i]!=']'){
               st.push(s[i]);
           }else{
               string ans="";
               while(st.top()!='['){
                   ans=st.top()+ans;
                   st.pop();
               }
               st.pop();
               string num="";
               
               while( (!st.empty()) && isdigit(st.top())){
                   
                   num+=st.top();
                   st.pop();
               }
               reverse(num.begin(),num.end());
               int rep=stoi(num);
               //cout<<ans<<rep<<"\n";
               while(rep--){
                   //cout<<ans;
                   for(int j=0;j<ans.length();j++){
                       //cout<<ans[j];
                       st.push(ans[j]);
                   }
               }
           }
       }
       
      string res="";
      while(!st.empty()){
          res=st.top()+res;
          st.pop();
      }
      //cout<<res;
      
      return res;
       
       
};

/*

if stack is _____________________
            _|_b__|_c_|_a__|_c__|
    
    to print bcac
    ans=ans+st.top()

    but to print cacb
    ans=st.top()+ans
    
*/