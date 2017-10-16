#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<functional>
#include<map>
#include<set>
#include<algorithm>
using namespace std;
const int maxn = 1010;
int parent[maxn];
vector<int> v[maxn];
int find(int node)
{
    if(parent[node]==node)
        return node;
    int ans = find(parent[node]);
    parent[node] = ans;
    return ans;
}
int main()
{
    for(int i = 0; i < maxn; i++) {
        parent[i] = i;
    }
    int n;
    scanf("%d",&n);
    for(int i = 0; i < n; i++){
        int m;
        scanf("%d: ",&m);
        for(int j = 0; j < m; j++) {
            int k;
            scanf("%d",&k);
            if(!v[k].empty()){
                parent[find(i)] = find(v[k][0]);
            }
            v[k].push_back(i);
        }
    }
    set<int> s;
    map<int,int> m;
    for(int i = 0; i<n;i++){
            m[find(i)]++;
    }
    cout<<m.size();
    vector<int> v;
    for(map<int,int>::iterator it = m.begin();it!=m.end();it++){
        v.push_back(it->second);
    }
    sort(v.rbegin(),v.rend());
    cout<<endl;
    for(int i = 0; i < v.size(); i++) {
        if(i>0)cout<<" ";
        cout<< v[i];
    }
    cout<<endl;


}
