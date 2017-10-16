
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
        farest.push_back(now);
        depth = d;
    }else if(d==depth){
        farest.push_back(now);
    }
//    cout<< "now"<<now<<endl;
 //   cout << "dep"<<depth<<endl;
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
    if(n==1){cout << 1;return 0;}
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
    vector<int> tmp = farest;//farest拷贝到tmp中，不能用farest作为遍历的控制参数，因为farest会在遍历时改变，会造成死循环。
    for(int i =0;i<tmp.size();i++){
        fill(vis,vis+maxn,false);
        dfs(tmp[i],0,tmp[i]);
    }
    for(int i =0;i<tmp.size();i++){farest.push_back(tmp[i]);}//加入第一次的点
    sort(farest.begin(),farest.end());
    vector<int>::iterator e = unique(farest.begin(),farest.end());
    for(vector<int>::iterator it = farest.begin();it!=e;it++){
        cout<<  *it<<endl;
    }
}
