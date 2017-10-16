
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <string>
using namespace std;
const int maxn = 210;
const int INF = 0x3fffffff;
int G[maxn][maxn];
bool vis[maxn] = {false};
int d[maxn];
int happiness_now[maxn];
int passed[maxn];
int pre[maxn];
int happiness[maxn];
int num[maxn];
int index = 0;
int n,m;
map<string ,int> city_id;
string city_name[maxn];
int s2i(string s)
{
    if(!city_id.count(s)){
        city_id[s]=index;
        city_name[index] = s;
        return index++;
    }
    return city_id[s];
}
void dij(int root)
{
    fill(vis,vis+maxn,false);
    fill(d,d+maxn,INF);
    fill(passed,passed+maxn,INF);
    fill(pre,pre+maxn,-1);
    fill(happiness_now,happiness_now+maxn,0);
    d[root] = 0;
    happiness_now[root] = 0;
    num [root] =1;
    passed[root] = 0;
    for(int i = 0;i<n;i++){
        int u = -1,min_d=INF;
        for(int j = 0;j<n;j++){
            if(!vis[j]&&d[j]<min_d){
                u = j;
                min_d = d[j];
            }
        }
        if(u==-1) return;
        root = u;
        vis[root] = true;
        for(int j = 0;j<n;j++){
            if(!vis[j]&&G[root][j]!=INF){
              //  cout << j<< " pre: " << root << " d: " << d[root]+G[root][j] <<"|"<<happiness_now[j]<< " hap: "<< happiness_now[root]+happiness[j]<<endl;
                    if(d[j]>d[root]+G[root][j]){
                    pre[j] = root;
                    d[j] = d[root]+G[root][j];
                    happiness_now[j] = happiness_now[root]+happiness[j];
                    passed[j] = passed[root]+1;
                    num[j]=num[root];
                }else if(d[j]==d[root]+G[root][j]){
                    num[j]+=num[root];
                    if(happiness_now[j]<happiness_now[root]+happiness[j]){
                        pre[j] = root;
                        d[j] = d[root]+G[root][j];
                        happiness_now[j] = happiness_now[root]+happiness[j];
                        passed[j] = passed[root]+1;
                    }else if(happiness_now[j]==happiness_now[root]+happiness[j]&&passed[j]-1>passed[root]){
                        pre[j] = root;
                        d[j] = d[root]+G[root][j];
                        passed[j] = passed[root]+1;
                    }
                }
            }
        }
    }
}
int main()
{
    fill(G[0],G[0]+maxn*maxn,INF);
    string start;
    cin >> n >> m >> start;
    int start_id = s2i(start);
    string tmp;
    happiness[0] = 0;
    for(int i =0; i < n-1; i++){
        cin >> tmp;
        int id = s2i(tmp);
        cin >> happiness[id];
    }
    for(int i = 0; i<m;i++){
        string s1,s2;
        cin >> s1 >>s2;
        cin >> G[city_id[s1]][city_id[s2]];
        G[city_id[s2]][city_id[s1]]=G[city_id[s1]][city_id[s2]];
    }
    dij(start_id);
    int now = city_id["ROM"];
    vector<int> v;
    while(now!=-1){
        v.push_back(now);
        now = pre[now];
    }
    index = city_id["ROM"];
    cout << num[index] << " " << d[index] << " " <<  happiness_now[index] << " " << happiness_now[index]/passed[index]<<endl;
    for(int i=v.size()-1;i>=0;i--){
        if(i!=v.size()-1)cout<< "->";
        cout << city_name[v[i]];
    }
}
