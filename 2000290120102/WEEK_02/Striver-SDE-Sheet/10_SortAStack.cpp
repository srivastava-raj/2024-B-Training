#include <bits/stdc++.h> 
using namespace std;
void insertSorted(stack<int>&s,int num){
    if(s.empty() || (s.top() < num)){
        s.push(num);
        return;
    }
    int n=s.top();
    s.pop();
    insertSorted(s,num);
    s.push(n);
}
void sortStack(stack<int> &stack)
{
	if(stack.empty())
        return;
    int num=stack.top();
    stack.pop();
    sortStack(stack);
    insertSorted(stack,num);
}
int main(){
    int n;  cin>>n;
    vector<int>ar(n);
    for(auto &i:ar) cin>>i;
    stack<int>s;
    for(auto &i:ar)
        s.push(i);
    sortStack(s);
    while(!s.empty()){
        int e=s.top();
        cout<<e<<" ";
        s.pop();
    }
    return 0;
}