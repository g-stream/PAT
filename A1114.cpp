#include<vector>
#include<map>
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
struct fam
{
    int np;
    int ns;
    double area;
};
struct e
{
    int id;
    int num;
    double ps;
    double pa;
};
bool operator<(const e& e1, const e&e2)
{
    if(e1.pa!=e2.pa)
        return e1.pa>e2.pa;
    return e1.id<e2.id;
}
map<int,fam> record;
const int maxn = 100010;
int parent[maxn];
int find(int id){
    if(parent[id]==id)
        return id;
    int ans = find(parent[id]);
    parent[id] = ans;
    return ans;
}
void join(int id1,int id2)
{
    int root,mod;
    id1 = find(id1);
    id2 = find(id2);
    if(id1<id2){
        root = id1;
        mod = id2;
    } else {
        root = id2;
        mod = id1;
    }
    parent[mod] = root;
}
int main()
{
    for(int i = 0; i < maxn; i++) {
        parent[i] = i;
    }
    int n;
    cin >> n;
    vector<int> person;
    for(int i = 0; i < n; i++){
        int now,far,mon,n_c;
        cin >> now >> far >> mon >> n_c;
        if(far>=0){
            join(now,far);
            person.push_back(far);
        }
        if(mon>=0){
            person.push_back(mon);
            join(now,mon);
        }
        person.push_back(now);
        while(n_c--){
            int child;
            cin >> child;
            join(now,child);
            person.push_back(child);
        }
        cin >> record[now].ns >> record[now].area;
    }
    sort(person.begin(),person.end());
    vector<int>::iterator it = unique(person.begin(),person.end());
    person.erase(it,person.end());
    map<int,fam> ans;
    for(int i = 0; i < person.size();i++){
        int now = person[i];
        int rep = find(person[i]);
        ans[rep].np++;
        if(record.count(now)){
            ans[rep].area+=record[now].area;
            ans[rep].ns += record[now].ns;
        }
    }
    vector<e> vans;
    for(map<int,fam>::iterator it = ans.begin(); it!= ans.end();it++){
            e tmp;
            tmp.id = it->first;
            tmp.num = it->second.np;
            tmp.ps = (double)it->second.ns/tmp.num;
            tmp.pa = it->second.area/tmp.num;
            vans.push_back(tmp);
    }
    sort(vans.begin(),vans.end());
    cout<< vans.size()<<endl;
    for(int i =0; i < vans.size(); i++){
        printf("%04d %d %.3f %.3f\n",vans[i].id,vans[i].num,vans[i].ps,vans[i].pa);
    }
}
