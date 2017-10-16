#include <vector>
#include <string>
#include <iostream>
#include <queue>
#include <algorithm>
#include <cstdio>
#include <functional>
using namespace std;
int timeconvert(string s)
{
    int hh,mm,ss;
    hh = 10*(s[0]-'0')+s[1]-'0';
    mm = 10*s[3] + s[4]-'0'*11;
    ss = 10*s[6] + s[7]-'0'*11;
    return 3600*hh+60*mm+ss;
}
struct e
{
    int t;
    string s;
    int p;
};
bool cmp(const e& e1,const e& e2)
{
    return e1.t<e2.t;
}
int main()
{

    int n,m;
    cin >> n >> m;
    vector<e> v;
    for(int i = 0; i < n; i++){
        e tmp;
        string s;
        cin >> tmp.s >> tmp.p;
        tmp.t = timeconvert(tmp.s);
        tmp.p *= 60;
        v.push_back(tmp);
    }
    sort(v.begin(),v.end(),cmp);
    priority_queue<int,vector<int>, greater<int> > q;
    int sum=0;
    for(int i = 0; i < m; i++){
        q.push(8*3600);
    }
    int i;
    for(i = 0; i < v.size()&&v[i].t<=3600*17; i++){
     //   cout << "in :" << v[i].s<<endl;
        while(!q.empty()&&q.top()<=v[i].t){
            q.pop();
        }
        if(q.size()<m) {q.push(v[i].t+(v[i].p>3600?3600:v[i].p));}
        else {
            while(q.size()>m)q.pop();
            sum += q.top()-v[i].t;
            q.push(v[i].p+q.top());
        }
    }
    printf("%.1f",(double)sum/60/(i));
}
