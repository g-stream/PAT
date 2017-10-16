#include<vector>
#include<iostream>
#include<queue>
using namespace std;
vector<int> G[510];
int cnt = 0;
bool vis[510] = {false};
int main()
{
    int n,m;
    cin >> n >> m;
    while(m--){
        int i,j;
        cin >> i >> j;
        G[i].push_back(j);
        G[j].push_back(i);
    }
    bool ok = true;
    queue<int> q;
    q.push(1);cnt++;
    vis[1] = true;
    while(!q.empty()){
        int now =  q.front();
        for(int i = 0; i < G[now].size();i++){
            if(!vis[G[now][i]]){
                q.push(G[now][i]);
                cnt++;
                vis[G[now][i]] = true;
            }

        }
        q.pop();
    }
    //cout << cnt;
    if(cnt!=n){ok = false;}
    vector<int> odd,ans;
    for(int i = 1; i <= n; i++){
        int num = G[i].size();
        ans.push_back(num);
        if(num%2){
            odd.push_back(i);
        }
    }
    if(n==1){
        cout<<0<<endl<<"Eulerian";return 0;
    }
    for(int i = 0; i < ans.size();i++){
        if(i>0)cout << " ";
        cout << ans[i];
    }
    cout << endl;
    if(!ok){cout<<"Non-Eulerian\n";return 0;}
    if(odd.size()==2)cout << "Semi-Eulerian\n";
    else if(odd.empty())cout << "Eulerian\n";
    else cout << "Non-Eulerian\n";
}
