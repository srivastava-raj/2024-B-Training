#include <bits/stdc++.h> 
using namespace std;
int maximumProfit(vector<int> &prices){
        int maxpro = 0, minpri = INT_MAX;
        for(int &i:prices){
            int newmaxpro=max(maxpro,i-minpri);
            int newminpro=min(minpri,i);
            minpri=newminpro;
            maxpro=newmaxpro;
        }
        return maxpro;
}
int main(){
    int n;  cin>>n;
    vector<int>prices(n);
    for(auto &i:prices) cin>>i;
    cout<<maximumProfit(prices);
    return 0;
}
