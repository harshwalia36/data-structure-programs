#include<bits/stdc++.h>
#define ll long long
#define loop(i,n) for(int i=0;i<n;i++)
#define fors(i,n) for(int i=1;i<=n;i++)
using namespace std;

void merge(int l[],int r[],int a[],int nl,int nr)
{
    int i=0,j=0,k=0;
    while(i<nl&&j<nr)
    {
        if(l[i]<r[j])
        {
            a[k++]=l[i++];
        }
        else
        {
            a[k++]=r[j++];
        }

    }
    while(i<nl){
        a[k++]=l[i++];
    }
    while(j<nr)
    {
        a[k++]=r[j++];
    }

}
void mergesort(int a[],int size)
{
    int mid=size/2;
    int left[mid],right[size-mid];
    if(size>1)
    {
    loop(i,mid)
    {
        left[i]=a[i];
    }
    for(int j=mid;j<size;j++)
        right[j-mid]=a[j];
    mergesort(left,mid);
    mergesort(right,size-mid);
    merge(left,right,a,mid,size-mid);
    }

}

int main()
{
int n;
cout<<"\nenter the size of array=";
cin>>n;
int a[n];
loop(i,n)
{
    cin>>a[i];
}
cout<<"array before sorting :";
loop(i,n)
{
 cout<<a[i]<<" ";
}
cout<<endl;
mergesort(a,n);
cout<<"array after sorting :";
loop(i,n)
{
    cout<<a[i]<<" ";
}
}


