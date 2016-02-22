#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define N 99999

using namespace std;

void input(int &n, int* numb, int &m)
{
    cout<<"Please write the numbers of integers"<<endl;
    cin>>n;
    cout<<"Please write integers"<<endl;
    for(int i=0; i<n; i++)
    {
        cin>>numb[i];
    }
    cout<<"Please write the final number"<<endl;
    cin>>m;
}

void fillArr(int* weight, int* way, bool* setnumb, int m)
{
    for(int i=0; i<=m; ++i)
    {
        weight[i]=INFINITY;
        way[i]=INFINITY;
        setnumb[i]=false;
    }
    weight[0]=0;
    way[0]=0;
}

void searñhSum(int* weight, bool* setnumb, int* number, int* way, int n, int m)
{
    int i,j,pos,minimum,temp;
    int flag[N];
    for(i=0;i<N;++i)
    {
        flag[i]=0;
    }
    while((weight[m]!=m) && (flag[pos]<2))
    {
        minimum=INFINITY;
        for(i=0; i<=m; ++i)
        {
            if((weight[i]<minimum) && (setnumb[i]==false))
            {
                minimum=weight[i];
                pos=i;
            }
        }
        setnumb[pos]=true;
        flag[pos]+=1;
        for(j=0; j<n; ++j)
        {
            temp=pos+number[j];
            if(((weight[pos]+number[j])< weight[temp]) && way[pos]<way[temp])
            {
                weight[temp]=weight[pos]+number[j];
                way[temp]=pos;
            }
        }

    }
}

void output(int* way, int m)
{
    int i=m;
    int max_int=INFINITY;
    bool flag=true;
    if (way[i]==max_int) cout<<"No amount of data numbers";
    else
    {
        cout<<m<<" = ";
        while(flag)
        {
            if (way[i]!=0) cout<<i-way[i]<<" + ";
            else
            {
                cout<<i-way[i];
                flag=false;
            }
            i=way[i];
        }
    }
}

int main()
{
    int n;
    int numb[N];
    int weight[N];
    bool setnumb[N];
    int way[N];
    int m;
    input(n,numb,m);
    fillArr(weight,way,setnumb,m);
    searñhSum(weight,setnumb,numb,way,n,m);
    output(way,m);
    return 0;
}
