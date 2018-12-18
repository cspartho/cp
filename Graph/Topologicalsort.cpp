#include<bits/stdc++.h>
using namespace std;

vector<int> adj[120];
bool visited[120];
//stack<int> ans;
vector<int>ans;

void dfs(int v)
{
    visited[v] = true;
    for (int u : adj[v])
    {
        if (!visited[u])
            dfs(u);
    }
    ans.push_back(v);
}

void topological_sort(int n)
{
    memset(visited,n+1, false);
    ans.clear();
    for (int i = 1; i <= n; ++i)
    {
        if (!visited[i])
            dfs(i);
    }
    reverse(ans.begin(),ans.end());
}
int main()
{

    int edj,nod;
    while(scanf("%d %d",&nod,&edj)==2 && (nod>0 || edj>0))
    {

        for(int i=0; i<nod; i++)
            adj[i].clear();
        for(int i=0; i<edj; i++)
        {
            int x,y;
            cin>>x;
            cin>>y;
            adj[x--].push_back(y--);

        }
        topological_sort(nod);

        for(auto it=ans.begin(); it!=ans.end(); it++)
        {
            cout<<*it<<" ";
        }

    }
    cout<<endl;


    return 0;
}
