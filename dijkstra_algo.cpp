#include<bits/stdc++.h>
#define ll long long
#define loop(i,n) for(int i=0;i<n;i++)
#define fors(i,n) for(int i=1;i<=n;i++)
#define PII pair<long long ,int>

using namespace std;

bool relaxed[100005]={false};
vector <PII> *adj;
int *dist;
int nodes,edges,x,y,weight;

ll dijkstra(int u)
{
    priority_queue <PII,vector<PII>,greater<PII>> q;   //min priority queue
    int y;
    int v,cost;
    PII p;
    q.push(make_pair(0,u));   //(w,v) in priority queue
    while(!q.empty())
    {
        p=q.top();
        q.pop();
        u=p.second;

    if(relaxed[u]==true)  //already relaxed vertex
    {
        continue;
    }
    relaxed[u]=true;
    for(int i=0;i<adj[u].size();i++)
    {
        v=adj[u][i].second;      //adjacent vertex to u
        cost=adj[u][i].first;
                    //do not push already visited vertex
         if(dist[v]>dist[u]+cost)
            {
               dist[v]=dist[u]+cost;
               q.push(make_pair(dist[v],v));
            }
    }
    }
    printf("Vertex Distance from Source\n");
    for (int i = 1; i <=nodes; ++i)
        printf("%d \t\t %d\n", i, dist[i]);


}

int main()
{

    cout<<"enter the number of nodes:";
    cin>>nodes;
    cout<<"enter the number of edges:";
    cin>>edges;
    adj=new vector<PII>[nodes+1];
    dist=new int[nodes+1];
    loop(i,nodes+1)
    {
        dist[i]=INT_MAX;
    }
    dist[1]=0;
    cout<<"enter the connecting nodes with weight:";
    loop(i,edges)
    {
        cin>>x>>y>>weight;
        adj[x].push_back(make_pair(weight,y));
    }
   dijkstra(1);


}

