#include<bits/stdc++.h>
using namespace std;
int longestSubSeg(vector<int> &nums , int n, int k){
    int zeroCount = 0;
    int longestWindow = 0;
    int start = 0;
    for (int i = 0; i < n; i++) {
        zeroCount += (nums[i] == 0);
        while (zeroCount > k) {
            zeroCount -= (nums[start] == 0);
            start++;
        }
        longestWindow = max(longestWindow, i - start);
    }
    return longestWindow+1;
}
int main(){
    int n,k;    cin>>n>>k;
    vector<int>ar(n);
    for(auto &i:ar) cin>>i;
    cout<<longestSubSeg(ar,n,k);
}