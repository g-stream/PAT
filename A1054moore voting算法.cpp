#include<iostream>
#include <cstdio>
using namespace std;
int main()
{
    int n,m,k;
    cin >> n >> m;
    k = n*m;
    int c=0;
    while(k--){
        int now;
        scanf("%d",&now);
        if(c==0){m=now;}
        else if(m!=now)c++;
        else c--;

    }
    cout << m;
}
