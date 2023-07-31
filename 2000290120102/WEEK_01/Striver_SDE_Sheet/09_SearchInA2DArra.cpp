#include <bits/stdc++.h>
using namespace std;
bool searchMatrix(vector<vector<int>>& mat, int target) {
    int m=mat.size(),n=mat[0].size();
    int i=0,j=n-1;
    while(i<m and j>=0){
        if(mat[i][j]==target)
            return true;
        else if(mat[i][j]<target)
            i++;
        else
            j--;
    }
    return false;
}
int main(){
    int n,m,target;    cin>>n>>m>>target;
    vector<vector<int>>ar(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)    
            cin>>ar[i][j];
    }
    cout<<searchMatrix(ar,target);
    return 0;
}