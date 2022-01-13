void rotate(vector<vector<int> >& matrix)
{
    // Your code goes here
    int n=matrix.size();
    for(int i=0;i<n;i++){
        reverse(matrix[i].begin(),matrix[i].end());
    }
    
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            swap(matrix[i][j],matrix[j][i]);
        }
    }
    
    
}

/*
[1,2,3]                                  [1,4,7]
[4,5,6]   transpose of this matrix is    [2,5,8]
[7,8,9]                                  [3,6,9]

but we have to rotate 90 degree so first reverse the matrix row wise
and then transpose it
               
*/