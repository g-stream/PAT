#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
struct R
{
    long long id;
    int score;
    int r;
    int rl;
    int l;
};
bool cmp(const R& r1,const R&r2)
{
    if(r1.score!=r2.score) {
        return r1.score>r2.score;
    }
    else return r1.id<r2.id;

}
int main()
{
    int sum=0,n,m;
    vector<R> v;
    cin >> n;
    int l = 1;
    while(n--) {
        cin >> m;
        for(int i =0;i<m;i++) {
            R tmp;
            cin >> tmp.id>>tmp.score;
            tmp.l = l;
            v.push_back(tmp);
        }
        sort(v.begin()+sum,v.end(),cmp);
        for(int i = sum;i<v.size();i++) {
            if(i==sum)v[i].rl = 1;
            else {
                if(v[i].score == v[i-1].score) v[i].rl = v[i-1].rl;
                else v[i].rl = i-sum+1;
            }
        }
        sum += m;l++;
    }
    sort(v.begin(),v.end(),cmp);
        for(int i = 0;i<v.size();i++) {
            if(i==0)v[i].r = 1;
            else {
                if(v[i].score == v[i-1].score) v[i].r = v[i-1].r;
                else v[i].r = i+1;
            }
        }
    cout << sum << endl;
    for(int i = 0; i < v.size(); i++)
    {
        printf("%013lld %d %d %d\n",v[i].id,v[i].r,v[i].l,v[i].rl);
    }
    return 0;
}
