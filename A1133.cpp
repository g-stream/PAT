#include<vector>
#include<algorithm>
#include<iostream>
#include<cstdio>
using namespace std;
struct node{
    int id;
    int pos;
    int next;
    int var;
};
node l[100000];
vector<node> v;
int k;
bool operator<(const node & n1,const node&n2){
    int n = n1.var,m=n2.var;
    if(n<0){
        if(m<0)return  l[n1.id].pos<l[n2.id].pos;
        return true;
    }
    if(n<=k){
        if(m<0)return false;
        if(m<=k)return l[n1.id].pos<l[n2.id].pos;
        return true;
    }
    if(m<=k)return false;
    return l[n1.id].pos<l[n2.id].pos;
}
int main()
{
    int root,n;
    cin >> root >> n >> k;
    for(int i = 0; i < n; i++){
        node tmp;
        cin >> tmp.id >> tmp.var >> tmp.next;
        l[tmp.id].id = tmp.id;
        l[tmp.id].var = tmp.var;
        l[tmp.id].next = tmp.next;
    }
    int now = root;
    int cnt = 0;
    while(now !=-1){
        v.push_back(l[now]);
        l[now].pos = cnt++;
        now = l[now].next;
    }
    sort(v.begin(),v.end());
    for(int i = 0; i < v.size(); i++){
        if(i==v.size()-1){
            printf("%05d %d %d\n", v[i].id,v[i].var,-1);
            break;
        }
        printf("%05d %d %05d\n", v[i].id,v[i].var,v[i+1].id);
    }
}
