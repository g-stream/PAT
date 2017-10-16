
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
int r[100010] = {0};
int pi(int i)
{
    if(r[i]) return r[i];
    int ans=i;
    while(i--)
        ans+=i;
    r[i] = ans;
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<double> v;
    double tmp;
    for(int i = 0; i < n; i++){
        cin >> tmp;
        v.push_back(tmp);
    }
    double sum=0;
    for(int i = 0; i < n; i++) {
        long long co = (i+1)*(v.size()-i);
        sum += co*v[i];
    }
    printf("%.2f\n",sum);
}
