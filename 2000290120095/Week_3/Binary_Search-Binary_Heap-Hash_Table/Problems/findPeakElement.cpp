#include<iostream>
using namespace std;

int findPeak(int arr[],int low, int high, int n){
    int mid = low+(low+high)/2;
    if((mid==0 || arr[mid-1] <= arr[mid]) && (mid == n-1 || arr[mid+1] <= arr[mid]))
        return mid;
    else if(mid >0 && arr[mid-1]> arr[mid]){
        return findPeak(arr,low,mid-1,n);
    }
    else{
        return findPeak(arr,mid+1,high,n);
    }
}

int main(){
    int arr[]={1,3,20,4,1,0};
    cout<<findPeak(arr,0,5,6);
}