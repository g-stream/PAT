#include<vector>
#include <queue>
#include <iostream>
#include <cmath>
using namespace std;
struct S
{
    int id;
    int w;
    int r;
};
int main()
{
    int n,m;
    cin >> n>>m;
    vector<S> v;
    for(int i = 0;i<n;i++){
        S s;s.id = 0;
        cin >> s.w;
        v.push_back(s);
    }
    queue<S>q;
    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        q.insert(v[tmp]);
    }

    queue<S> tmpq;
    while(1){
        int rl = ceil(q.size()/(double)m)+1;
        int fat = 0;
        for(int i = 0; q.size()&&i<m;i++)
            S tmp = q.front();
            q.pop();

    }
}
