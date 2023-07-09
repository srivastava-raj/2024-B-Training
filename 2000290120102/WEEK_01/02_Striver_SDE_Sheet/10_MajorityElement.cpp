#include <bits/stdc++.h>
using namespace std;
int findMajorityElement(int arr[], int n) {
	int c=0,e,c1=0;
	for(int i=0;i<n;i++){
		if(c==0)	e=arr[i];
		c+=(e==arr[i])?1:-1;
	}
	for(int i=0;i<n;i++){
		if(arr[i]==e)
			c1++;
	}
	return (c1>n/2)?e:-1;
}
int main(){
    int n;  cin>>n;
    int ar[n];
    for(int i=0;i<n;i++)    cin>>ar[i];
    cout<<findMajorityElement(ar,n);
    return 0;
}