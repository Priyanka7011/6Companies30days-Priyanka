string tobinary(int i){
    string s="";
    while(i>0){
         s=to_string(i%2)+s;
         i=i/2;
    }
    
    return s;
}

vector<string> generate(int N)
{
	// Your code here
	vector<string> ans;
	int i=1;
	string s="";
	while(i<=N){
	   
	   s=tobinary(i); 
	   //cout<<s;
	   i++;
	   ans.push_back(s);
	   
	}
	
	return ans;
	
}