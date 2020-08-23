#include <iostream>
#include <windows.h>
using namespace std;
int a[20],n;
int cond(int a[],int m)
{
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(j!=i)
            {
                if(a[j]==a[i] || a[j]+j==a[i]+i || a[j]-j==a[i]-i)
                return 0;
            }
        }
    }
    if(m==n)
    {
       for(int o=0;o<n;o++)
        cout<<" _";
       cout<<"\n";
       for(int i=0;i<m;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(j==a[i])
                    cout<<"|X";
                else
                    cout<<"|_";
            }
            cout<<"|\n";
        }
        cout<<"\n";
    }
    return 1;
}
void queen(int t,int a[],int n)
{
    if(t==0)
        return;
    for(int i=0;i<n;i++)
    {
        a[n-t]=i;
        if(cond(a,n-t+1)==1)
        {
            queen(t-1,a,n);
        }
    }
}
int main()
{
    cout<<"enter no. of queens";
    cin>>n;
    for(int i=0;i<n;i++)
        a[i]=101;
    queen(n,a,n);
    /*for(int i=0;i<n;i++)
    {
        cout<<a[i];
        Sleep(100);
    }*/
    return 0;
}
