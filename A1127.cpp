#include<vector>
#include<algorithm>
#include<queue>
#include<iostream>
using namespace std;
const int maxn = 100010;
struct node
{
    int l,r;
    node():l(-1),r(-1){}
};
node tree[maxn];
vector<int> in,post;
int build(int i,int j,int u,int v)
{
    if(i==j)return -1;
    int root = post[v-1];
    int index = 0;
    while(in[index]!=root)index++;
    tree[root].l = build(i,index,u,u+index-i);
    tree[root].r = build(index+1,j,u+index-i,v-1);
    return root;
}
void print(vector<int> & v)
{
    for(int i = 0; i < v.size(); i++){
        if(i>0) cout << " ";
        cout << v[i];
    }
    cout << endl;
}
int main()
{
    int n;
    cin >> n;
    for(int i=0;i < n; i++){
        int tmp;
        cin >> tmp;
        in.push_back(tmp);
    }
    for(int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        post.push_back(tmp);
    }
    vector<int> ans,v;
    queue<int> q;
    int root = build(0,n,0,n);
    int now = root;
    q.push(root);
    while(!q.empty()){
        int now = q.front();
        if(tree[now].l!=-1){
            q.push(tree[now].l);
        }
        if(tree[now].r!=-1){
            q.push(tree[now].r);
        }
        q.pop();
        ans.push_back(now);
    }
    while(1){
        int changed = false;
        vector<int>::iterator it = find(ans.begin(),ans.end(),now);
        for(;it!=ans.end();it++){
            int tmp = (tree[*it].l==-1)?tree[*it].r:tree[*it].l;
         //   cout << tmp<<endl;
            if(tmp!=-1){
                now = tmp;
                changed = true;
                break;
            }
        }
        if(!changed)break;
        v.push_back(now);
    }
   if(!v.empty())
    v.erase(v.begin());
    if(v.empty()){
        print(ans);
        return 0;
    }
    for(int i = 0; i < v.size(); i+=2){
        if(i==v.size()-1){
            reverse(find(ans.begin(),ans.end(),v[i]),ans.end());
        } else {
            reverse(find(ans.begin(),ans.end(),v[i]),find(ans.begin(),ans.end(),v[i+1]));
        }
    }
    print(ans);

}
