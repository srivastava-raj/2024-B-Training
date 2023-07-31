#include <bits/stdc++.h> 
using namespace std;
long long maxSubarraySum(vector<int>&nums, int n)
{
    /*
        Don't write main().
        Don't read input, it is passed as function argument.    
        No need to print anything.
        Taking input and printing output is handled automatically.
    */
    long long max_so_far = INT_MIN, max_ending_here = 0,size=n;
    for (long long i = 0; i < size; i++) {
        max_ending_here += nums[i];
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;
        if (max_ending_here < 0)
            max_ending_here = 0;
        }
    return (max_so_far<=0)?0:max_so_far;
}
int main(){
    int n;  cin>>n;
    vector<int>nums(n);
    for(auto &i:nums)   cin>>i;
    long long res=maxSubarraySum(nums,n);
    cout<<res;
    return 0;
}