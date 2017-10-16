#include <vector>
#include <iostream>
using namespace std;
int INF = 0x3fffffff;
int c[10010];
bool vis[1010];
int d[1010];

int main()
{
    int capacity,num,tar,m;
    cin >> capacity>>num>>tar>>m;
    for(int i = 1;i<=num;i++){
        cin >> c[i];
    }
    vector<vector<int> > G(num+1,vector<int>(num+1,INF));
    for(int i = 0; i < m; i++){
        int _i,_j;
        cin >> _i >> _j;
        cin >> G[_i][_j];
    }
    vector<vector<int> > pre(num+1);
    int now = 0;
    vis[now] = true;

    for(int i = 0;i<num+1;i++){
        d[i]=INF;
    }
    d[now] = 0;
    for(int i=0;i<num+1;i++){
        for(int j=0;j<num+1;j++){
            if(!vis[j]&&G[now][j]!=INF){
                    if(d[j]>G[now][j]+d[now]){
                        d[j]=G[now][j]+d[now];
                        pre[j].clear();
                        pre[j].push_back(now);
                    } else if(d[j]==G[now][j]+d[now]){
                        pre[j].push_back(now);
                    }
            }
        }
        int min_d=INF,min_i;
        for(int j=0;j<num+1;j++){
            if(!vis[j]){
                if(d[j]<min_d){
                    min_d = d[j];
                    min_i = j;
                }
            }
        }

        vis[min_i]=true;
        now = min_i;
    }


}

