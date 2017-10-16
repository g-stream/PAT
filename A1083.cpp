#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
struct R
{
    string name;
    string id;
    int score;
};
int l,r;
bool in(const R& _r)
{
    if(_r.score<=r&&_r.score>=l)
        return true;
    return false;
}
bool cmp(const R& r1,const R& r2)
{
    if(in(r1)&&!in(r2))
        return true;
    else if(!in(r1)&&in(r2))
        return false;
    return r1.score>r2.score;
}
int main()
{
    int n;
    int cnt=0;
    vector<R> v;
    cin >> n;
    while(n--) {
        R tmp;
        cin >> tmp.name >> tmp.id >> tmp.score;
        v.push_back(tmp);
    }
    cin >> l >> r;

    sort(v.begin(),v.end(),cmp);
    for(int i = 0; i< v.size();i++)
        if(in(v[i])) cnt++;
    if(cnt) {
        for(int i = 0;i<cnt;i++)
            cout << v[i].name << " " << v[i].id << endl;
    } else cout << "NONE" << endl;

}

