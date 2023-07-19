#include<iostream>
#include<vector>
using namespace std;

void computeNumberFromSubarray(vector<int> v,int k)
{
    pair<int,int> ans;
    int sum =0;
    for(int i=0;i<k;i++)
    {
        sum+=v[i];
    }
    bool found = false;
    if(sum%3 == 0)
    {
        found = true;
        ans = make_pair(0,k-1);
    }
    for(int j = k;j<v.size();j++)
    {
        if(found)
            break;
        
        sum = (sum + v[j]) - v[j-k];
        

        if(sum%3==0)
        {
            ans = make_pair(j-k+1,j);
            found = true;
        }
    }

    if(!found)
        ans = make_pair(-1,0);
    
    else if(ans.first == -1)
        cout<<"No Subarray exist";
    else
    {
        for(int i=ans.first;i<= ans.second;i++)
            cout<<v[i]<<" ";
    }


    
}

int main()
{
    vector<int> v;
    v.push_back(0);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    int k=3;
    computeNumberFromSubarray(v,k);

}

