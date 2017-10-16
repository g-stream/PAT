#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int vp[100010],vi[100010];
struct node
{
    int v;
    node* l;
    node* r;
};
node * create(int pl,int pr,int il,int ir) {
    if(pl>pr) return NULL;
    node * tmp = new node;
    tmp->v = vp[pr];
    int n;
    for(int i = il;i<=ir;i++)
    {
        if(vi[i]==vp[pr]){
            n = i;break;
        }
    }
    tmp->l = create(pl,pl+n-il-1,il,n-1);
    tmp->r = create(pl+n-il,pr-1,n+1,ir);
    return tmp;
}
int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> vp[i];
    }
    for(int i = 0; i < n; i++){
        cin >> vi[i];
    }
    node* t = create(0,n-1,0,n-1);
    queue<node*> q;
    q.push(t);
    vector<int> v;
    while(!q.empty())
    {
        if(q.front()->l){q.push(q.front()->l);}
        if(q.front()->r){q.push(q.front()->r);}
        v.push_back(q.front()->v);
        q.pop();
    }
    for(int i = 0;i<v.size();i++)
    {
        if(i==0)
            cout << v[i];
        else cout << " " << v[i];
    }

}
