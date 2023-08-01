#include <bits/stdc++.h>
using namespace std;
int findDuplicate(vector<int> &arr, int n){
	set<int>s;
	for(auto &i:arr){
		if(s.count(i)==1)
			return i;
		s.insert(i);
	}
	return -1;
}
int main(){
    int n;  cin>>n;
    vector<int>ar(n);
    for(auto &i:ar) cin>>i;
    cout<<findDuplicate(ar,n);
    return 0;
}
