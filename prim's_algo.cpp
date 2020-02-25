#include<bits/stdc++.h>
#define ll long long
#define loop(i,n) for(int i=0;i<n;i++)
#define fors(i,n) for(int i=1;i<=n;i++)
#define PII pair<long long ,int>

using namespace std;

bool marked[100005]={false};
vector <PII> *adj;
ll prims(int x)
{
    priority_queue <PII,vector<PII>,greater<PII>> q;    //min priority queue
    int y;
    ll minimumCost=0;
    PII p;
    q.push(make_pair(0,x));
    while(!q.empty())
    {
        p=q.top();
        q.pop();
        x=p.second;

    //checking for cycle
    if(marked[x]==true)
    {
        continue;
    }
    minimumCost+=p.first;
    marked[x]=true;
    for(int i=0;i<adj[x].size();i++)
    {
        y=adj[x][i].second;
        if(marked[y]==false)             //do not push already visited vertex
        {
            q.push(adj[x][i]);
        }
    }
    }
    return minimumCost;

}

int main()
{
    int nodes,edges,x,y,weight;
    cout<<"enter the number of nodes:";
    cin>>nodes;
    cout<<"enter the number of edges:";
    cin>>edges;
    adj=new vector<PII>[nodes+1];
    cout<<"enter the connecting nodes with weight:";
    loop(i,edges)
    {
        cin>>x>>y>>weight;
        adj[x].push_back(make_pair(weight,y));
        adj[y].push_back(make_pair(weight,x));
    }
   ll minimumCost=prims(1);
   cout<<"minimum cost of tree is: "<<minimumCost;

}

