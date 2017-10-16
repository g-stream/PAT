#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 10010;
vector<int> adj[maxn];
int n;
bool vis[maxn]={false};
int depth=0;
vector<int> farest;
void dfs(int now,int d,int root)
{
    if(d>depth){
        farest.clear();
        farest.push_back(root);
        depth = d;
    }
    vis[now]=true;
    for(int i=0;i<adj[now].size();i++){
        if(!vis[adj[now][i]]){
            dfs(adj[now][i],d+1,root);
        }
    }
}
int main()
{
    cin >> n;
    for(int i =0; i < n-1; i++){
        int _i,_j;
        cin >> _i >> _j;
        adj[_i].push_back(_j);
        adj[_j].push_back(_i);
    }
    int comp = 0;
    for(int i = 1; i<=n;i++){
        if(!vis[i]){
            comp++;
            dfs(i,0,i);
        }
    }
    if(comp>1){ cout <<  "Error: "<<comp<<" components";return 0;}
    cout << farest.size();
    for(int i =0;i<farest.size();i++){
        fill(vis,vis+maxn,false);
        dfs(farest[i],0,farest[i]);
    }
    sort(farest.begin(),farest.end());
    for(int i = 0; i<farest.size();i++){
        cout<<  farest[i]<<endl;
    }
}
