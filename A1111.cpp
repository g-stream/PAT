#include<vector>
#include<map>
#include<cstdio>
#include<algorithm>
using namespace std;
struct fam
{
    int np;
    int ns;
    double area;
};
map<int,fam> record;
const int maxn = 100010;
int parent[maxn];
int find(int id){
    if(parent[id]==id)
        return id;
    ans = find(parent[id]);
    parent[id] = ans;
    return ans;
}
void join(int id1,int id2)
{
    if(id1<id2){
        int root = find(id1);
        int mod = find(id2);
    } else {
        int root = find(id2);
        int mod = find(id1);
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
        join(now,far);
        join(now,mon);
        person.push_back(now);
        person.push_back(far);
        person.push_back(mon);
        while(n_c--){
            int child;
            cin >> child;
            join(now,child);
            person.push_back(child);
        }
        int k,double a;
        cin >> record[now].ns >> record[now].area;
    }
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

}
