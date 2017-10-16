#include<iostream>
#include<cstdio>
#include <vector>
using namespace std;
int main()
{
    int n,m;
    cin >> n>>m;
    vector<int> v(1);
    for(int i = 0; i<n;i++){
        int k;
        cin>>k;
        v.push_back(k);
    }
    vector<int> r;
    int mm = 0x7fffffff;
    for(int i =1;i<=n;i++){
        int sum = 0;
        int j=i;
        for(j=i;j<=n;j++){
            sum+=v[i];
            if(sum>=m)break;
        }
        if(sum==mm){r.push_back(i);r.push_back(j);cout<<i<<"|"<<j<<endl;}
        else if(sum<mm){r.clear();r.push_back(i);r.push_back(j);mm=sum;}
    }
    for(int i=0;i<n/2;i++){
        cout<<r[2*i]<<"-"<<r[2*i+1]<<endl;
    }
}
