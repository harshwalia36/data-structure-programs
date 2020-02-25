#include<bits/stdc++.h>
#define ll long long
#define loop(i,n) for(int i=0;i<n;i++)
#define fors(i,n) for(int i=1;i<=n;i++)

using namespace std;

int main()
{int t=3;
while(t--)
{
    int n;
cout<<"\nenter the size of array=";
cin>>n;
int a[n],targ;
loop(i,n)
{
    cin>>a[i];
}
sort(a,a+n);
cout<<"sorted array is:";
loop(i,n)
{
    cout<<a[i]<<" ";
}cout<<endl;
cout<<"enter the no. to be searched in array=";
cin>>targ;
int h=n,l=0,m,flag=0;
m=(h-l)/2;

loop(i,logb(n)+1)
{
    if(a[m]==targ)
    {
        cout<<"index="<<m<<" in array";flag=1; break;
    }
    else if(a[m]>targ)
        h=m-1;
    else
        l=m+1;
        m=(h-l)/2+l;
}
if(flag==0)
{
    cout<<"\nElement is not present in array";
}
}
}


