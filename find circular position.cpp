string printMinNumberForPattern(string S){
        // code here 
        stack<int> st;
        int count=1;
        string ans;
        
        for(int i=0;i<S.length();i++){
            if(S[i]=='D'){
                st.push(count);
                count++;
            }else{
                st.push(count);
                count++;
                
                while(!st.empty()){
                    ans+=to_string(st.top());
                    st.pop();
                }
            }
        }
        st.push(count);
        while(!st.empty()){
                    ans+=to_string(st.top());
                    st.pop();
                }
        
        cout<<ans;
        
    }