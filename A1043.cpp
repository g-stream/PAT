#include <vector>
#include <iostream>
using namespace std;
const int maxn = 1010;
struct node
{
    int r,l,val;
};
node tree[maxn];
int n;
bool normal;
bool ok=true;
int checkAndBuild(int i, int j)
{
  //  cout << "building:"<<i<<":"<<j<<endl;
    if(i==j)return -1;
    int val_root = tree[i].val;
    if(normal){
        int index=i+1;
        while(tree[index].val<val_root&&index<j)index++;
        //cout << "index:"<<index<<endl;
        for(int i=index;i<j;i++){if(tree[i].val<val_root)ok=false;}
        tree[i].l = checkAndBuild(i+1,index);
        tree[i].r = checkAndBuild(index,j);
    }else{
        int index=i;
        while(tree[index].val>=val_root&&index<j)index++;
        for(int i=index;i<j;i++){if(tree[i].val>=val_root)ok=false;}
        tree[i].l = checkAndBuild(i+1,index);
        tree[i].r = checkAndBuild(index,j);
    }
    return i;
}
vector<int> ans;
void dfs(int root)
{
    if(tree[root].l!=-1)dfs(tree[root].l);
    if(tree[root].r!=-1)dfs(tree[root].r);
    ans.push_back(tree[root].val);
}

int main()
{
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> tree[i].val;
    }
    if(n==1) {cout<< "YES\n"<<tree[0].val;return 0;}
    if(tree[0].val>tree[1].val)normal = true;
    else normal = false;

    checkAndBuild(0,n);
    dfs(0);
    if(!ok){cout << "NO";return 0;}
    cout << "YES\n";
    for(int i = 0;i<n;i++)
    {
        if(i!=0)cout<< " ";
        cout << ans[i];
    }
}
