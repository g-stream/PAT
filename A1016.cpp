
#include<vector>
#include<iostream>
#include<queue>
#include<cmath>
#include<cstdio>
using namespace std;
struct node
{
    int id;
    int p;
    int d;
    vector<int> c;
};
const int maxn = 100100;
node tree[maxn];
queue<int> q;
int main()
{
    double price,r;
    int n;
    cin >> n >> price >> r;
    for(int i = 0; i < n; i++) {
        int k;
        cin >> k;
        while(k--){
            int tmp;
            cin >> tmp;
            tree[i].c.push_back(tmp);
            tree[i].id = i;
            tree[tmp].p = i;
        }
    }
    tree[0].d = 0;
    q.push(0);
    int mind = 0xfffffff;
    int num = 0;
    while(!q.empty()) {
            int tmp = q.front();
        for(int i = 0; i < tree[tmp].c.size(); i++){
            q.push(tree[tmp].c[i]);
            tree[tree[tmp].c[i]].d = tree[tree[tree[tmp].c[i]].p].d+1;
        }
        if(tree[tmp].c.empty()){
            if(tree[tmp].d<mind){
                num = 1;
                mind = tree[tmp].d;
            }else if(tree[tmp].d==mind){
                num++;
            }
        }
        q.pop();
    }

    printf("%.4f %d",pow(1+r/100,mind)*price,num);
}
