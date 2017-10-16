#include <vector>
#include <iostream>
using namespace std;
int num,m;
const int maxn=110;
vector<int> fam[maxn];
int has[maxn]={0};
void dfs(int root ,int depth)
{
    if(fam[root].size()==0){
        has[depth]++;
        return;
    }
    has[depth]++;
    for(int i = 0;i<fam[root].size();i++){
        dfs(fam[root][i],depth+1);
    }
}
int main()
{
    cin >> num >>m;
    while(m--){
        int root,k;
        cin >> root >> k;
        while(k--){
            int child;
            cin >> child;
            fam[root].push_back(child);
        }
    }
    dfs(1,1);
    int max_g=0,ans_i;
    for(int i=1;i<=num;i++){
        if(has[i]>max_g){
            max_g = has[i];
            ans_i =i;
        }
    }
    cout << has[ans_i] << " " << ans_i;
}

