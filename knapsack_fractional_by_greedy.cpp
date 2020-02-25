#include<bits/stdc++.h>
#define ll long long
#define loop(i,n) for(int i=0;i<n;i++)
#define fors(i,n) for(int i=1;i<=n;i++)

using namespace std;
vector<pair<double,int>> p;

bool cmp(const pair<double,int> &a,const pair<double,int> &b)
{
    return ((double(a.first)/a.second)>(double(b.first)/b.second));
}

double fractionalKnapsack(int w,int n)
{
    ll weight_sum=0; double profit_sum=0;
    sort(p.begin(),p.end(),cmp);
    loop(i,n)
    {
        if(weight_sum+p[i].second<=w)
        {
            weight_sum+=p[i].second;
            profit_sum+=p[i].first;

        }
        else{
            profit_sum+=(double(w-weight_sum)/p[i].second)*p[i].first;

            weight_sum+=(w-weight_sum);
            break;
        }
    }
    return profit_sum;
}

int main()
{  ll n,a,b,w;
   cout<<"enter the number of items:";
   cin>>n;
    cout<<"enter the capacity of knapsack:";
    cin>>w;
    loop(i,n)
    {
        cout<<"enter the value and weight of each item:";
        cin>>a>>b;
        p.push_back(make_pair(a,b));
    }
    cout<<"total maximum profit:"<<fractionalKnapsack(w,n);
}

