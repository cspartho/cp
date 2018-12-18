#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
vector<int>indegree;
list <int>s;

set<int>st;
int c=0;

void toposort(int n)
{
    for(int i=1; i<=n; i++)
    {
        if(indegree[i]==0)
        {
            s.push_back(i);

        }
    }
    while (!s.empty())
    {
        int k=s.back();
        s.pop_back();

        st.insert(k);
        //l.push_back(k);
        for(int u:adj[k])
        {
            indegree[u]--;
            if(!indegree[u])
            {
                s.push_back(u);
            }
        }
        c++;
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    indegree.assign(n+1,0);
    adj.resize(m+n);
    for (int i = 0; i < m; i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        indegree[y]++;
    }
    toposort(n);
    if(c!=n || st.size()==0)
    {
        cout<<"Sandro fails."<<endl;
    }
    else
    {
        for(int i:st)
        {
            cout<<i<<" ";
        }
    }
    return 0;
}
