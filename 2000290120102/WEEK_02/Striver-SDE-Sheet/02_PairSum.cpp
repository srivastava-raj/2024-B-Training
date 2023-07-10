#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> pairSum(vector<int> &arr, int s){
   int n=arr.size();
   vector<vector<int>>ans;
   for(int i=0;i<n;i++){
      for(int j=i+1;j<n;j++){
         if((arr[i] + arr[j] == s) && i!= j){
            vector<int> temp;
            temp.push_back(min(arr[i],arr[j]));
            temp.push_back(max(arr[i],arr[j]));
            ans.push_back(temp);
         }
      }
   }
   sort(ans.begin(), ans.end());
   return ans;
}
int main(){
    int n,s;  cin>>n>>s;
    vector<int>ar(n);
    for(auto &i:ar) cin>>i;
    vector<vector<int>>res=pairSum(ar,s);  
    for(int i=0;i<res.size();i++){
        for(int j=0;j<res[0].size();j++)
            cout<<res[i][j]<<" ";
        cout<<"\n";
    }  
    return 0;
}