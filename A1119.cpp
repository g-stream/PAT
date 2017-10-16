#include<vector>
#include<iostream>
#include<queue>
bool ok = true;
using namespace std;
vector<int> v1,v2;
struct node
{
    int r,l;
    node():r(-1),l(-1){}
};
node tree[31];
int fun(int i,int j,int u,int v)
{
    if(i==j)return v1[i];
    if(i>j)return -1;
    int index = u;
    for(;index<=v;index++){
        if(v2[index]==v1[i+1])
            break;
    }
    if(index==v-1)ok = false;
    int root = v1[i];
    tree[root].l = fun(i+1,i+index-u+1 ,u,index);
    tree[root].r = fun(i+index-u+2,j,index+1,v-1);
    return root;
}
bool is = true;
void fun2(int root)
{
    if(tree[root].l!=-1){
        fun2(tree[root].l);
    }
    if(!is) cout << " ";
    cout << root;
    is = false;
    if(tree[root].r!=-1){
    fun2(tree[root].r);}
}
int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        v1.push_back(tmp);
    }
    for(int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        v2.push_back(tmp);
    }
    int root = fun(0,v1.size()-1,0,v2.size()-1);
    if(ok){
        cout << "Yes\n";
    }else {
        cout <<"No\n";
    }
    fun2(root);
    cout << endl;
}
