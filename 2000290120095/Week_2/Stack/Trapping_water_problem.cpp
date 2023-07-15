#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int rainwater(vector<int> a)
{
    int n=a.size();
    stack<int> st;
    int ans=0;
    for(int i=0;i<n;i++){
        while(!st.empty() and a[st.top()] < a[i]){
            int cur=a[st.top()];
            st.pop();
            if(st.empty()){
                break;
            }
            int diff = i-st.top()-1;
            ans+=(min(a[st.top()],a[i])-a[cur])*diff;
        }
        st.push(i);
    }
    return ans;
}



int main()
{
    int n;
    cin>>n;
    vector<int> a(n);
    for(auto &i:a)
    cin>>i;
    cout<<"total water store will be"<<rainwater(a);
}