#include<string>
#include<iostream>
#include<vector>
using namespace std;
string ans;
struct node
{
    int r,l,p;
    string var;
    node():r(-1),l(-1),p(-1){}
};
const int maxn = 100010;
node tree[maxn];
void in(int root){
    if(tree[root].l==-1&&tree[root].r==-1){
        ans+=tree[root].var;
        return;
    }
    ans += "(";
    if(tree[root].l!=-1){
        in(tree[root].l);
    }
    ans+=tree[root].var;
    if(tree[root].r!=-1){
        in(tree[root].r);
    }
    ans+=")";
}
int main()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        string str;
        int l,r;
        cin >> str >> l >> r;
        tree[i].l = l;
        tree[i].r = r;
        tree[i].var = str;
        if(l!=-1)tree[l].p = i;
        if(r!=-1)tree[r].p = i;
    }
    int root = -1;
    for(int i = 1; i <= n; i++){
        if(tree[i].p == -1){
            root = i;
            break;
        }
    }
    in(root);
    if(ans.size()==1){cout << ans <<endl; return 0;}
    cout << ans.substr(1,ans.size()-2);
}
