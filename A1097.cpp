
#include<cstdio>
#include<set>
#include <map>
#include <iostream>
using namespace std;
struct l
{
    int add;
    int var;
};
int main()
{
    set<int> s;
    int root,r1,root2=-1,r2,n,r;
    bool f = false;
    cin >> root >> n;
    r1 = root;
    r = root;
    map<int,int> var,next;
    while(n--){
        int tmpvar,tmpnext,tmpadd;
        scanf("%d%d%d",&tmpadd,&tmpvar,&tmpnext);
        var[tmpadd] = tmpvar;
        next[tmpadd] = tmpnext;
    }
    bool f1 = false;
    while(r!=-1){
        if(!s.count(var[r])){
            s.insert(var[r]);
            s.insert(-var[r]);
            if(f1 == false){
                f1 = true;
            } else {
                next[r1] = r;
            }
            r1 = r;
        } else {
            if(f== false){
                root2 = r;
                r2 = r;
                f = true;
            } else {
                next[r2] = r;
                r2 = r;
            }
        }
        r = next[r];
    }
    next[r1] = -1;
    next[r2] = -1;
    while(root!=-1){
        printf("%05d %d ",root,var[root]);
        if(next[root]<0) cout<< -1<<endl;
        else printf("%05d\n",next[root]);
        root = next[root];
    }
    while(root2!=-1){
        printf("%05d %d ",root2,var[root2]);
        if(next[root2]<0) cout<< -1<<endl;
        else printf("%05d\n",next[root2]);
        root2 = next[root2];
    }
}
