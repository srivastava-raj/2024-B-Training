#include <bits/stdc++.h> 
using namespace std;
int count_z(int *arr, int n){
   int c=0;
   for(int i=0;i<n;i++){
      if(arr[i]==0)
         c++;
   }
   return c;
}
int count_o(int *arr, int n){
   int c=0;
   for(int i=0;i<n;i++){
      if(arr[i]==1)
         c++;
   }
   return c;
}
int count_t(int *arr, int n){
   int c=0;
   for(int i=0;i<n;i++){
      if(arr[i]==2)
         c++;
   }
   return c;
}
void sort012(int *arr, int n)
{
   int cz=count_z(arr,n);
   int co=count_o(arr,n);
   int ct=count_t(arr,n),i;
   for(i=0;i<cz;i++) arr[i]=0;
   for(i=cz;i<cz+co;i++) arr[i]=1;
   for(i=cz+co;i<cz+co+ct;i++) arr[i]=2;
}
int main(){
    int n;  cin>>n;
    int ar[n];
    for(int i=0;i<n;i++)    cin>>ar[i];
    sort012(ar,n);
    for(int i=0;i<n;i++)    cout<<ar[i]<<" ";
    return 0;
}