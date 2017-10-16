#include <cmath>
#include <cstdio>
#include <queue>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int num;
struct node
{
    int r,l,val;
};
const int maxn = 1010;
node tree[maxn];

int build(int i,int j,int n)
{
    if(i==j)return -1;
    int level=1;
    while(pow(2,level)-1<=n)level++;
    level--;
    int remain = n-pow(2,level)+1;
    int half = pow(2,level-1);
    int index;
    if(remain<=half) index = pow(2,level-1)-1+remain+i;
    else index = pow(2,level)-1+i;
    tree[index].l = build(i,index,index-i);
    tree[index].r = build(index+1,j,j-index-1);
    return index;
}

int main()
{
    cin >>num;
    vector<int> v;
    for(int i =0;i<num;i++){
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(),v.end());
    for(int i=0;i<num;i++){
        tree[i].val = v[i];
    }
    int root = build(0,num,num);
    queue<node> q;
    q.push(tree[root]);
    vector<int> ans;
    while(!q.empty()){
        node tmp = q.front();
        ans.push_back(tmp.val);
        q.pop();
        if(tmp.l!=-1)q.push(tree[tmp.l]);
        if(tmp.r!=-1)q.push(tree[tmp.r]);
    }
    for(int i =0;i<num;i++){
        if(i!=0)cout << " ";
        cout << ans[i];
    }

}
