#include<bits/stdc++.h>
#define ll long long
#define loop(i,n) for(int i=0;i<n;i++)
#define fors(i,n) for(int i=1;i<=n;i++)

using namespace std;
int *a,w=1;

int  partion(int low,int high,int pivot)
{
    int i=low-1;
    if(w)
       {
           swap(a[pivot],a[high]); w=0;
           pivot=high;
       }
    else
     pivot=high;
     for(int j=low;j<=high;j++)
     {
         if(a[j]<a[pivot])
         {
             i++;
             swap(a[i],a[j]);
         }
     }
     swap(a[i+1],a[pivot]);
     return i+1;
}
void quicksort(int low,int high,int pivot)
{
    if(low<high)
    {
        int p=partion(low,high,pivot);
        quicksort(low,p-1,pivot);
        quicksort(p+1,high,pivot);
    }
}
int main()
{
int n;
cout<<"\nenter the size of array=";
cin>>n;
int pivot;
a=new int[n+1];
loop(i,n)
{
    cin>>a[i];
}
cout<<"enter the pivot index: ";
cin>>pivot;
cout<<"array before sorting :";
loop(i,n)
{
 cout<<a[i]<<" ";
}cout<<endl;
quicksort(0,n-1,pivot);
cout<<"array after sorting :";
loop(i,n)
{
    cout<<a[i]<<" ";
}


}


