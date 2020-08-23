#include <iostream>
#include<cstdlib>
#include<windows.h>
using namespace std;
int flag=0;
int a[81]={5,3,0,0,7,0,0,0,0,
           6,0,0,1,9,5,0,0,0,
           0,9,8,0,0,0,0,6,0,
           8,0,0,0,6,0,0,0,3,
           4,0,0,8,0,3,0,0,1,
           7,0,0,0,2,0,0,0,6,
           0,6,0,0,0,0,2,8,0,
           0,0,0,4,1,9,0,0,5,
           0,0,0,0,8,0,0,7,9,};
int b[82];
int search(int y)
{
    for(int i=0;b[i]!=-2;i++)
    {
        if(b[i]==y)
            return 0;
    }
    return 1;
}
int quad(int num)
{
    int q=num/9;
    int r=num%9;
    int i,k;
    for(i=0;i<2;i++)
    {
        if(q>=3*i && q<=3*i+2)
            break;
    }
    for(k=0;k<3;k++)
    {
        if(r>=3*k && r<=3*k+2)
            break;
    }
    return(i+3*k);

}
int isfull()
{
    for(int i=0;i<81;i++)
    {
        if(a[i]==0)
            return 0;
    }
    return 1;
}
int cond(int x)
{
    for(int i=0;i<81;i++)
    {
        if(i<x || search(i)==0)
        {
        if(i/9==x/9 || i%9==x%9 || quad(i)==quad(x))
        {
            if(i!=x && a[x]!=0)
            {
                if(a[i]==a[x])
                    return 0;
            }
        }}
    }
    if(isfull()==1)
        flag=1;
    return 1;
}
void sudoku(int t)
{
    int j=1;
    if(t<=0 || flag==1)
        return;
    for(int i=0;i<9;i++)
    {
        a[81-t]=i+1;
        if(cond(81-t)==1)
        {
            for(;search(81-t+j)==0;j++)
            {
                if(t-j==80)
                    flag=1;
            }
            if(flag==1)
                return;
            sudoku(t-j);
            if(flag==1)
                return;
        }
    }
}
int main()
{
    int j=0;
    for(int i=0;i<81;i++)
    {
        if(a[i]!=0)
        {
            b[j]=i;
            j++;
        }
    }
    b[j]=-2;
    int nn;
    for(nn=0;search(nn)==0;nn++);
    sudoku(81-nn);
    for(int i=0;i<81;i++)
    {
        if(a[i]/10==0)
            cout<<"0";
        cout<<a[i]<<" ";
        if(i%9==8)
            cout<<"\n";
    }
    return 0;
}
