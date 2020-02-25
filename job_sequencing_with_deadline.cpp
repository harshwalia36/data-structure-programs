#include<bits/stdc++.h>
#define ll long long
#define loop(i,n) for(int i=0;i<n;i++)
#define fors(i,n) for(int i=1;i<=n;i++)

using namespace std;

bool cmp(const tuple<int,double,int> &a,const tuple<int,double,int> &b)
{

    return (get<1>(a)>get<1>(b));
}

int main()
{   ll n;
    cout<<"enter the no. of jobs:";
    cin>>n;
    vector <tuple<int,double,int>> vect;
    ll a,c,max=0;double b;
    loop(i,n)
    {   cout<<"enter the job no., profits and deadlines respectively:";
        cin>>a>>b>>c;
        vect.push_back(make_tuple(a,b,c));
        if(max<c)
            max=c;
    }
    sort(vect.begin(),vect.end(),cmp);

   /* loop(i,n)
    {
        cout<<get<0>(vect[i])<<" "<<get<1>(vect[i])<<" "<<get<2>(vect[i])<<endl;
    } */

   int size=max;
    int slot[size]={0},total_profit=0;
    for(auto i=vect.begin();i<vect.end();i++)
    {
        for(int j=get<2>(*i)-1;j>=0;j--)
        {
            if(slot[j]==0)
            {
                slot[j]=get<0>(*i);
                total_profit+=get<1>(*i);
                break;
            }
        }
    }
    cout<<"total profit:"<<total_profit;

}

