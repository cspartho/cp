#include<bits/stdc++.h>
using namespace std;
vector<int>adj[123];
vector<int>visit(10),p(10);
queue<int>q;

void bfs(int s)
{
    visit[s]=true;
    q.push(s);
    p[s]= -1;
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        visit[x]=true;
        for(int u:adj[x])
        {
            if(visit[u])
                continue;
            visit[u]=true;
            p[u]=x;
            q.push(u);
        }
    }
}

void path(int u)
{
    if(!visit[u])
    {
        cout<<"NO Path"<<endl;
    }
    else
    {
        vector<int>v;
        for(int i=u; i!=-1; i=p[i])
        {
            v.push_back(i);
        }
        reverse(v.begin(),v.end());
        for(int i:v)
        {
            cout<<i<<" ";
        }
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0; i<m; i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
    }
    visit.assign(n+5,false);
    bfs(0);
    path(7);

    return 0;
}
