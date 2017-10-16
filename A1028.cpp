#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
struct R
{
    int id;
    string name;
    int score;
};

bool cp1(const R& r1,const R& r2)
{
    return r1.id<r2.id;
}
bool cp2(const R& r1,const R& r2)
{
    if(r1.name!=r2.name)
    return r1.name<r2.name;
    else return r1.id<r2.id;
}
bool cp3(const R& r1,const R& r2)
{
    if(r1.score!=r2.score)
    return r1.score<r2.score;
    else return r1.id<r2.id;
}
bool (*cmp[4])(const R&,const R&);
int main()
{
    cmp[1] = cp1;
    cmp[2] = cp2;
    cmp[3] = cp3;
    int n,index;
    cin >> n >> index;
    vector<R> v;
    while(n--) {
        R tmp;
        cin >> tmp.id >> tmp.name >> tmp.score;
        v.push_back(tmp);
    }
    sort(v.begin(),v.end(),cmp[index]);
    for(int i = 0; i < v.size(); i++){
        printf("%06d %s %d\n",v[i].id,v[i].name.c_str(),v[i].score);
    }
    return 0;
}
