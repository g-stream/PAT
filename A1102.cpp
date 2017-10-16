#include<iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
struct node
{
    int v;
    int p;
    int r;
    int l;
};
node a[10000];
int main()
{
    int n;
    cin>> n;
    for(int i = 0; i<n;i++){
        a[i].p = -1;
        a[i].l = -1;
        a[i].r = -1;
    }
    for(int i = 0; i < n; i++){
        char r,l;
        cin >> l >> r;
        if(l!='-'){
            a[i].l = l-'0';
            a[l-'0'].p = i;
        }
        if(r!='-'){
            a[i].r = r-'0';
            a[r-'0'].p = i;
        }
    }
    int root = 0;
    while(a[root].p!=-1) {
        root = a[root].p;
    }
    vector<int> in_order;
    vector<int> level_order;
    queue<int> q;
    q.push(root);
    while(!q.empty()){
        int now = q.front();
        level_order.push_back(now);
        q.pop();
        if(a[now].r>=0)q.push(a[now].r);
        if(a[now].l>=0)q.push(a[now].l);

    }


    for(int i = 0;i<n;i++){
        if(i==0)cout<<level_order[i];
        else cout<< " "<< level_order[i];
    }
}
