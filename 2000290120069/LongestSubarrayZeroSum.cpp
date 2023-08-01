#include <bits/stdc++.h>
using namespace std;
int LongestSubsetWithZeroSum(vector<int>&ar) {
    int k=0;
    unordered_map<int,int>m;
	  int psum=0,ans=0;
	  m[0]=-1;
	  for(int i=0;i<ar.size();i++){
	  	psum+=ar[i];
		  if(m.find(psum-k)!=m.end())
			  ans=max(ans,i-m[psum-k]);
		  else
			  m[psum]=i;
	  }
	  return ans;
}
int main(){
    int n;  cin>>n;
    vector<int>ar(n);
    for(auto &i:ar) cin>>i;
    cout<<LongestSubsetWithZeroSum(ar);
    return 0;
}
