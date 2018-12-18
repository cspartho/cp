#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>adj;
int visit[123];
int level[123];
void dfs(int s)
{
    if(visit[s])
        return;
    visit[s]=1;
    for(auto u:adj[s])
    {
        if(!visit[u])
           {
            level[u]=level[s]+1;
        dfs(u);
           }
    }
}
int main()
{
    int nod,edj;
    cin>>nod>>edj;
    adj.resize(edj+5);
    for(int i=0; i<edj; i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(0);
    for(int i=0; i<nod; i++)
    {
        cout<<level[i]<<endl;
    }

}
