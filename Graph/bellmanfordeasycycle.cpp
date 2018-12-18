#include<bits/stdc++.h>
using namespace std;
vector<tuple<int,int,int>>g;

bool bford(int n)
{
    vector<int>d(n+1,INT_MAX);
    d[0]=0;
    for(int i=1; i<n; i++)
    {
        bool any=false;//to check any node changes
        for(auto b:g)
        {
            int x,y,w;
            tie(x,y,w)=b; //tuple to variable
            if(d[x]!=INT_MAX && d[x]+w<d[y])
            {
                d[y]=d[x]+w;
                any=true;
            }
        }
        if(!any) break;
    }
    for(int i=1; i<n; i++)
    {

        for(auto b:g)
        {
            int x,y,w;
            tie(x,y,w)=b;
            if(d[x]!=INT_MAX && d[x]+w<d[y])
            {
                return true;
            }
        }
    }
    return false;

}

int main()
{
        int n,m;
        cin>>n>>m;
        g.resize(m+1);
        int x,y,w;
        for(int i=0; i<m; i++)
        {
            cin>>x>>y>>w;
            g.push_back(make_tuple(x,y,w));
        }
        if(bford(n))
            cout<<"Cycle Found"<<endl;
        else
            cout<<"No Cycle"<<endl;


        g.clear();


    return 0;
}
