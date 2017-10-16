#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;
int n,m,l,farest;
const int maxn = 1020;
const int INF = 0x3fffffff;
int d[maxn];
int vis[maxn] = {false};
int s2i(string s)
{
    if(s[0]=='G'){
        return atoi(s.substr(1,s.size()-1).c_str())+n;
    }
    return atoi(s.c_str());
}
int G[maxn][maxn];
vector<int> adj[maxn];
void dij(int root)
{
    fill(d,d+maxn,INF);
    fill(vis,vis+maxn,false);
    d[root] = 0;
    for(int i = 0; i< n+m;i++){
        int u=-1,min_d=INF;
        for(int j = 1;j<=n+m;j++){
            if(!vis[j]&&d[j]<min_d){
                u = j;
                min_d = d[j];
            }
        }

        if(u == -1) return;
        root = u;//cout << "now:" << root <<endl;
        vis[root] = true;
        for(int j = 1;j<=n+m;j++){
            if(!vis[j]&&G[root][j]!=INF&&d[j]>d[root]+G[root][j]){
                d[j] = d[root]+G[root][j];
              // cout << j<<"jlkdjf "<<d[j]<<endl;
            }
        }
    }
}

int main()
{
    fill(G[0],G[0]+maxn*maxn,INF);
    fill(d,d+maxn,INF);
    cin >> n>>m>>l>>farest;
    while(l--) {
        string s_i,s_j;
        cin >> s_i>>s_j;
        int _i,_j;
        _i = s2i(s_i);
        _j = s2i(s_j);
     //   cout << _i << " " << _j <<endl;
        cin >> G[_i][_j];
        G[_j][_i] = G[_i][_j];
    }
    double ansDis = -1,ansAvg=INF;
    int ansID=-1;
    for(int i=n+1;i<=n+m;i++){
        double minDis = INF,avg=0;
        dij(i);
        for(int j=1;j<=n;j++){
            if(d[j]>farest){
                minDis=-1;
                break;
            }
            if(d[j]<minDis)minDis=d[j];
            avg+=1.0*d[j]/n;
        }
        if(minDis==-1)continue;
        if(minDis>ansDis){
            ansID =i;
            ansAvg=avg;
            ansDis = minDis;
        }else if(minDis == ansDis && avg< ansAvg) {
        ansID = i;
        ansAvg = avg;
        }
    }
    if(ansID == -1) cout<< "No Solution\n";
    else{
        cout << "G" << ansID-n<<endl;
        printf("%.1f %.1f\n", ansDis,ansAvg);
    }
}
