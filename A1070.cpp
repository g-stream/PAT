#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
struct e
{
    double t,p;
};
bool cmp(const e& e1, const e& e2)
{
    return e1.p/e1.t>e2.p/e2.t;
}
int main ()
{
    int n,m;
    cin >> n>>m;
    vector<e> v;
    int cnt = n;
    while(n--) {
        e tmp;
        cin >> tmp.t;
        v.push_back(tmp);
    }
    int i = 0;
    while(cnt--) {
        cin >> v[i].p;
        i++;
    }
    sort(v.begin(),v.end(),cmp);
    i = 0;double sum=0;
    while(m&&i<v.size()){
        if(v[i].t<=m){

            sum+=v[i].p;
            m -= v[i].t;
            i++;
        } else {
            sum += m/v[i].t*v[i].p;
            break;
        }
    }
    printf("%0.2lf",sum);
}
