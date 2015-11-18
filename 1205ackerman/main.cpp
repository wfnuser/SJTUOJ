#include<iostream>
#include<cstdlib>
#include<cstdio>
 
using namespace std;
int a(int x,int y)
{
    if(x==0) return y+1;
    else
    {
        if(y==0) return a(x-1,1);
        else return  a(x-1,a(x,y-1));
    }
}
 
 
int main()
{
    int n,m;
    cin>>m>>n;
    cout<<a(m,n);
    
 
}
