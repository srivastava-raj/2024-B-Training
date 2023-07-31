#include <bits/stdc++.h> 
using namespace std;
vector<int> nextPermutation(vector<int> &permutation, int n)
{
    int ind = -1; 
    for(int i = n-2; i>=0; i--){     
        if(permutation[i]<permutation[i+1]){           
            ind = i;            
            break;     
        }  
    }
    if(ind == -1){      
        reverse(permutation.begin(), permutation.end());       
        return permutation;  
    }
    for(int i = n-1; i>ind; i--){       
        if(permutation[i]>permutation[ind]){          
            swap(permutation[i], permutation[ind]);           
            break;      
        }  
    }
    reverse(permutation.begin()+ind+1, permutation.end());  
    return permutation; 
}
int main(){
    int n;    cin>>n;
    vector<int>ar(n);
    for(int i=0;i<n;i++)  
        cin>>ar[i];
    vector<int>res=nextPermutation(ar,n);
    for(auto &i:res)
        cout<<i<<" ";
    return 0;
}