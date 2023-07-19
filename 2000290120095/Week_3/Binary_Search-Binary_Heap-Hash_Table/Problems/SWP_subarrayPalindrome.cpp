#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

bool isPalindrome(int num){
    int temp = num;
    int ans = 0;

    while(temp){
        ans= ans*10+temp%10;
        temp/=10;
    }
    if(num ==ans)
        return true;
    else
        return false;
}

int findPalindromicSubarray(vector<int> arr, int k){
    int num=0;
    for(int i=0;i<k;i++){
        num= num*10+arr[i];
    }
    if(isPalindrome(num)){
        return 0;
    }

    for(int j=k; j<arr.size();j++)
    {
        num= num%(int)pow(10,k-1)*10+arr[j];
        if(isPalindrome(num)){
            return j-k+1;
        }
    }
    return -1;
}

int main(){
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(3);
    arr.push_back(2);
    arr.push_back(5);
    arr.push_back(6);
    cout<<findPalindromicSubarray(arr,4);
}