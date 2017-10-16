#include <queue>
#include <string>
#include <iostream>
#include <functional>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
struct s
{
    char name[5];
};
bool operator>(const s& s1, const s& s2){
    return strcmp(s1.name,s2.name)>0;
}
int main()
{
    int n,id,n_l,m;
    cin >> n >> n_l;

    priority_queue<s ,vector<s>, greater<s> > q[n_l+1];
    while(n--){
        s ss;
        scanf("%s %d",ss.name,&m);
        while(m--){
            scanf("%d",&id);
            q[id].push(ss);
        }
    }
    for(int i = 1; i <= n_l; i++){
        cout << i << " " << q[i].size() << endl;
        while(!q[i].empty()){
            printf("%s\n",q[i].top().name);
            q[i].pop();
        }
    }
}
