#include <bits/stdc++.h>
using namespace std;
int repeat(vector<int>&ar){
	for(int i=0;i<ar.size();i++){
		int idx=abs(ar[i])-1;
		ar[idx]*=-1;
		if(ar[idx]>0)
			return abs(ar[i]);
	}
	return 0;
}
vector<int> missingAndRepeating(vector<int> &arr, int n)
{
	long long sum=0,expSum;
	for(int i:arr)	sum+=i;
	int repElement=repeat(arr);
	expSum=n*(n+1)/2;
	long long diff=expSum-sum;
	return {repElement+(int)diff , repElement};
}
int main(){
    int n;  cin>>n;
    vector<int>ar(n);
    for(auto &i:ar) cin>>i;
    vector<int>res=missingAndRepeating(ar,n);
    for(auto &i:res) cout<<i<<" ";
    return 0;
}
