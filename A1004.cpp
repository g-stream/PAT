#include <vector>
#include <iostream>
using namespace std;
int num,m;
const int maxn = 110;
int max_d=0;
vector<int> child[maxn];
int cnt[maxn];
void dfs(int root, int depth)
{
    if(child[root].empty()){
        if(depth>max_d)max_d=depth;
        cnt[depth]++;
        return;
    }
    for(int i = 0; i<child[root].size();i++){
        dfs(child[root][i],depth+1);
    }
}
int main()
{
    cin >> num >>m;
    while(m--){
        int p,k,cd;
        cin >> p >> k;
        while(k--){
            cin >> cd;
            child[p].push_back(cd);
        }
    }
    dfs(1,0);
    for(int i =0;i<=max_d;i++){
        if(i!=0)cout << " ";
        cout << cnt[i];
    }
}

