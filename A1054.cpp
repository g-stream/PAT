#include <cstdio>
#include<iostream>
#include <map>
using namespace std;

int main()
{
    map<int,int> a;
    int n,m,k;
    scanf("%d %d",&n,&m);
    k = n*m;
    while(k--) {
        scanf("%d",&n);
        a[n]++;
    }
    m = 0;
    int s=0;
    for(map<int,int>::iterator it=a.begin(); it!=a.end();it++)
    {
        if(it->second>s){
            m=it->first;
            s=it->second;
        }

    }
    printf("%d",m);
}
