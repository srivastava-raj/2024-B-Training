#include<iostream>
#include<queue>
using namespace std;

priority_queue<int,vector<int>> pqmax;
priority_queue<int,vector<int>,greater<int>> pqmin;

void insert(int x){
    if(pqmax.size()==0){
        pqmax.push(x);
        return;
        if(x < pqmax.top())
        {
        pqmin.push(x);
        }
        else
        pqmax.push(x);
    }
    else{
        if(pqmax.size() > pqmin.size()){
            if(x > pqmax.top()){
                pqmin.push(x);
            }
            else{
                int temp = pqmax.top();
                pqmax.pop();
                pqmin.push(temp);
                pqmax.push(x);
            }        
        }
        else{
            if(x < pqmin.top())
                pqmax.push(x);
            else{
                int temp = pqmin.top();
                pqmin.pop();
                pqmax.push(temp);
                pqmin.push(x);
            }
        }

    }
    
}

double findMedian(){
    if(pqmax.size() == pqmin.size()){
        return ((pqmax.top()+pqmin.top())/2);
    }
    else if(pqmax.size() > pqmin.size())
        return pqmax.top();
    else
        return pqmin.top();
}


int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<endl;
        int x;
        cin>>x;
        insert(x);
        cout<<"Median: "<<(double)findMedian();
    }
}
