#include <iostream>
#include <string>
#include <cmath>
#include <cstdio>
#include <algorithm>

#define N 10000
using namespace std;
bool pq[ N ];
bool primer(int n)
{
    if(n==2) return true;
    for(int i = 2; i <= (int)sqrt(n);i++)
        if(n%i==0)return false;
    return true;
}
int main()
{
    int n;
    cin >> n;
    if(n==1){cout<<"1=1";return 0;}
    cout<<n<<"=";
    fill(pq,pq+N,true);
    bool has = false;
    for(int i =2;i<N;i++){
        if(pq[i]&&primer(i)){
                for(int j = 2; j*i<N;j++){
                    pq[j*i] = false;
                }
                int k = 0;
                while(n%i==0){
                    k++;
                    n /= i;

                }
                if(k>0){
                if(n==0)break;
                if(has==true)
                    cout<<"*";
                cout << i;
                if(k>=2)
                    cout<<"^"<<k;
                has = true;
        }}
    }
}

