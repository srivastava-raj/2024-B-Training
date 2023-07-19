#include<iostream>
using namespace std;

bool possible(int arr[],int n,int m,int limit){
    int studentRequired =1,sum=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]>limit)
            return false;
        if(sum+arr[i]>limit)
        {
            studentRequired++;
            sum = arr[i];
            if(studentRequired > m)
                return false;
            
        }
        else
            sum+=arr[i];
    }
    return true;
}

int allocateMinimumPages(int arr[],int n, int m){
    int sum=0;
    if(n<m)
        return -1;
    for(int i=0;i<n;i++){
        sum+=sum+arr[i];
    }
    int start =arr[0],end = sum,ans = INT_MAX;
    while (start<=end)
    {
        int mid = (start+end)/2;
        if(possible(arr,n,m,mid)){
            ans = min(ans,mid);
            end = mid-1;
        }
        else
        {
            start = mid+1;
        }
    }
    return ans;
    
}

int main(){
    int arr[]={12,34,67,90};
    int n=4;
    int m=2;
    cout<<allocateMinimumPages(arr,n,m);
}