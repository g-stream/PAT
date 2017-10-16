#include<iostream>
#include<queue>
#include <cmath>
#include<vector>
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
    cin>>n>>m;
    vector<S> v;
    for(int i = 0;i<n;i++){
        S s;
        cin >>s.w;
        s.id=i;
        v.push_back(s);
    }
    queue<S> q;
    for(int i = 0; i< n;i++){
        int tmp;
        cin>>tmp;
        q.push(v[tmp]);
    }
    while(q.size()!=1){
        queue<S> tmp_q;
        int out = ceil(q.size()/(double)m);
        while(q.size()){
            vector<S> group;
            int max_w = 0;
            int max_i;
            for(int i = 0;i<m&&q.size();i++){
                group.push_back(q.front());
                q.pop();
            }
            for(int i = 0;i<group.size();i++){
                if(max_w<group[i].w){
                    max_w = group[i].w;
                    max_i = group[i].id;
                }
            }
            tmp_q.push(v[max_i]);
            for(int i = 0;i<group.size();i++){
                if(group[i].w!=max_w){
                    v[group[i].id].r=out+1;
                }
            }
        }
        q = tmp_q;
    }
    v[q.front().id].r = 1;
    for(int i = 0;i<v.size();i++){
        cout << v[i].r;
        if(i<v.size()-1)cout<< " ";
    }
}
