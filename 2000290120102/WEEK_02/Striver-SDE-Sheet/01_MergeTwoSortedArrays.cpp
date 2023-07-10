#include <bits/stdc++.h>
using namespace std;
vector<int> SortedArrays(vector<int>& nums1, vector<int>& nums2, int m, int n) {
	int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;
        while (j >= 0) {
            if (i >= 0 && nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }
		return nums1;
}
int main(){
    int n,m;    cin>>n>>m;
    vector<int>a(m+n),b(m);
    for(int i=0;i<n+m;i++)    cin>>a[i];
    for(int i=0;i<m;i++)    cin>>b[i];
    vector<int>res=SortedArrays(a,b,n,m);
    for(auto &i:res)    cout<<i<<" ";
    cout<<"\n";
}