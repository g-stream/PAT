#include <iostream>
#include <vector>
using namespace std;
int G[1010][1010];
bool vis[1010];
int n,m,k;
void dfs(int start)
{
    vis[start] = true;
    for(int i =1; i<=n;i++)
        if(!vis[i]&&G[start][i]){
            dfs(i);
    }
}
int main()
{
    cin >> n>>m>>k;
    for(int i = 0;i<m;i++){
        int r,l;
        cin >>r>>l;
        G[r][l] = true;
        G[l][r] = true;
    }
    for(int i = 0;i<k;i++){
        int check;
        int cnt=0;
        cin>>check;
        for(int j = 0;j<=n;j++){
            vis[j] = false;
        }
        vis[check] = true;
        for(int j = 1;j<=n;j++){
            if(vis[j]==false)
                {
                    dfs(j);
                    cnt++;
                }

        }
        cout << cnt-1<<endl;
    }
}
