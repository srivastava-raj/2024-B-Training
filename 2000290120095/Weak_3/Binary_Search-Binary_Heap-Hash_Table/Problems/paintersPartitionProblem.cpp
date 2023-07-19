#include<iostream>
using namespace std;

int possible(int arr[],int n,int limit)
{
    int sum=0, painters =1;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        if(sum>limit){
            sum+=arr[i];
            painters++;
        }
    }
    return painters;
}

int paintersPartition(int arr[],int n,int m){
    int totalLength =0, k=0;
    for(int i=0;i<n;i++){
        totalLength+=arr[i];
        k = min (arr[i],k);

    }
    int low =k, high= totalLength;
    while (low<high)           
    {
        int mid = (low+high)/2;
        int painter = possible(arr, n,mid);
        if(painter <= m)
            high = mid;
        else 
            low = mid+1;
    }

    return low;
    
    
}

int main(){
    int arr[]={10,20,30,40};
    int n=4;    //no of boards
    int m=2;    //no of painters
    cout<<paintersPartition(arr,n,m);

}