#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
    int n;	cin>>n;
	ll capacity=0;
	vector<ll>h(n),pre(n,0),suf(n,0);
	for(int i=0;i<n;i++)	cin>>h[i];
	pre[0]=h[0];
	for(int i=1;i<n;i++)	pre[i]=max(pre[i-1],h[i]);
	suf[n-1]=h[n-1];
	for(int i=n-2;i>=0;i--)	suf[i]=max(suf[i+1],h[i]);
	for(int i=1;i<n-1;i++){
		if(min(pre[i-1],suf[i+1])>h[i])
			capacity+=min(pre[i-1],suf[i+1])-h[i];
	}
	cout<<capacity;
    return 0;
}
