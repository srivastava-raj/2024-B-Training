#include<iostream>
using namespace std;

int smallestSubarray(int arr[],int n,int x)
{
    int sum =0;
    int minLength =n+1;
    int start = 0;
    int end = 0;
    while(end < n){
        while(sum<=x && end < n){
            sum+=arr[end++];
        }
        while (sum>x && start < n)  
        {
            if((end - start) < minLength)
                minLength = (end-start);
            sum-=arr[start++];
        }
        
    }
    return minLength;
}

int main()
{
    int arr[]={1,4,45,6,10,19};
    int n = 6;  //size
    int x = 51; //min limit
    cout<<smallestSubarray(arr,n,x);
}