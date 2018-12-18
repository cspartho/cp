#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>>adj;

int main()
{
    int node,edj;
    cin>>node>>edj;
    for(int i=0;i<edj;i++)
    {
        int x,y,w;
        cin>>x>>y>>w;
        adj[x].push_back({y,w});
    }


    return 0;
}
