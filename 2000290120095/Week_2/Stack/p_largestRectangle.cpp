#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int max(int a,int b)
{
    return a>b?a:b;
}

int get_max_area(vector<int> a)
{
    int n=a.size();
    int  ans=0;
    int  i=0;
    stack<int> st;
    while(i<n){
        while(!st.empty() and a[st.top()]>a[i]){
            int t = st.top();
            int h = a[t];
            st.pop();
            if(st.empty()){
                ans = max(ans,h*i);
            }
            else{
                int len=i-st.top()-1;
                ans = max(ans,h*len);
            }
            
        }
        st.push(i);
        i++;

    }
    return ans;


}

int main()
{
    int n;
    cin>>n;
    vector<int> a(n);
    for(auto &i:a)
    {
        cin>>i;
    }
    for(auto &i:a)
    cout<<i<<" ";
    cout<<get_max_area(a);

}