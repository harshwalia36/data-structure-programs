#include<bits/stdc++.h>
#define ll long long
#define loop(i,n) for(int i=0;i<n;i++)
#define fors(i,n) for(int i=1;i<=n;i++)

using namespace std;

bool cmp(const tuple<int,int,int> &a,const tuple<int,int,int> &b)
{
    return (get<1>(a)<get<1>(b));
}
int main()
{
    vector <tuple<int,int,int>> v;
    int n,a,b,c;
    cout<<"enter the no. of processes";
    cin>>n;
    float s1=0,s2=0;
    loop(i,n)
    {
        cout<<"enter the P_ID, A.T and B.T respectively";
        cin>>a>>b>>c;
        v.push_back(make_tuple(a,b,c));
    }
    sort(v.begin(),v.end(),cmp);

    int tat[n],wt[n],ct[n],idle_time=0;
    wt[0]=0;
    //completion time
    loop(i,n)
    {
        if(i==0)
            ct[0]=get<2>(v[i]);
        else{
            if(ct[i-1]<get<1>(v[i]))
            {
                idle_time+=get<1>(v[i])-ct[i-1];
                ct[i]=ct[i-1]+get<2>(v[i])+idle_time;
            }
            else{
                ct[i]=ct[i-1]+get<2>(v[i]);
            }

        }
    }
    //turn around time
    loop(i,n)
    {
        tat[i]=ct[i]-get<1>(v[i]);
    }
    loop(i,n)
    {
        wt[i]=tat[i]-get<2>(v[i]);
    }
    s1=accumulate(tat,tat+n,s1);
    s2=accumulate(wt,wt+n,s2);
    s1=s1/n;
    s2=s2/n;

cout<<"\nAverage Turn around time="<<s1<<endl;
cout<<"\nAverage Waiting time="<<s2<<endl;
}


