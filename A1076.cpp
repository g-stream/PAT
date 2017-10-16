#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n,depth;
vector<vector<int> > follow;

int main() {
    cin >> n >> depth;
    follow.resize(n+1);
    for(int i = 0; i < n+1; i++){
        follow[i].resize(n+1);
    }
    int now = 1;
    while(n--) {
        int m;
        cin >> m;
        while(m--) {
            int to;
            cin >> to;
            follow[to][now] = 1;
        }
        now++;
    }
    int m;
    cin >> m;
    vector<int> q;
    while(m--){
        int i;
        cin >> i;
        q.push_back(i);
    }
    for(int i = 0; i< q.size();i++){
        vector<int> vis(follow.size(),0);
        vector<int> dep(follow.size(),0);
        queue<int> l;
        l.push(q[i]);
        dep[q[i]] = 1;
        vis[q[i]] = 1;
        int sum = 0;
        while(!l.empty()&&dep[l.front()]<=2+depth){
            int now = l.front();
           // cout << now<< "-" << dep[now]<<" ";
            if(dep[now]<=depth+1&&dep[now]>=2)sum++;
            l.pop();
            for(int j = 1;j<follow.size();j++){
                if(follow[now][j]&&!vis[j])
                {l.push(j);vis[j] = 1;
                dep[j]=dep[now]+1;
                }
            }
        }
        cout << sum << endl;
    }

    return 0;
}
