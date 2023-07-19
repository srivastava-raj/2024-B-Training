#include<bits/stdc++.h>
using namespace std;

int main()
{
    map<string,int> mpp;
  //mpp[Key value]=value
    mpp["aaj"]=27;
    mpp["bime"]=31;
    mpp["cank"]=47;

    for (auto it=mpp.begin(); it!=mpp.end();it++)
    {
    cout<<it->first<<" "<<it->second<<endl;

    }


    return 0;
}