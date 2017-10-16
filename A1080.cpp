#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
struct R
{
    int e,i;
    int id;
    vector<int> g;
};
bool cmp(const R& r1,const R& r2)
{
    if(r1.e+r1.i!=r2.e+r2.i)
        return r1.e+r1.i>r2.e+r2.i;
    else if(r1.e!=r2.e)
        return r1.e>r2.e;
    else return true;
}
bool cp(const R& r1,const R& r2)
{
    return r1.id<r2.id;
}
vector<int> quota;
int n,m,k;

int main()
{
    cin >> n >> m>> k;
    vector<R> v;
    quota.resize(m+1);
    for(int i = 0; i < m; i++) {
        cin >> quota[i];
    }
    int id=0;
    while(n--) {
        R tmp;
        cin >> tmp.e >> tmp.i;
        tmp.id = id;id++;
        for(int i = 0; i < k; i++)
        {int t;cin >>t;
        tmp.g.push_back(t);}
        v.push_back(tmp);
    }
    vector<vector<R> > school(m);
    sort(v.begin(),v.end(),cmp);
    for(int i  = 0; i< v.size();i++) {
        for(int j = 0; j<k;j++) {
                int g = v[i].g[j];
            if(school[g].size()<quota[g]||(school[g].size()>0&&v[i].e==school[g].back().e&&v[i].i==school[g].back().i))
            {school[g].push_back(v[i]);break;}
        }
    }
    for(int i  = 0; i< school.size();i++) {
        sort(school[i].begin(),school[i].end(),cp);
        if(school[i].empty()) cout << endl;
        else{
        for(int j = 0; j < school[i].size(); j++) {
            if(j==0) cout << school[i][j].id;
            else cout << " " << school[i][j].id;
        }
        cout << endl;}
    }
}
