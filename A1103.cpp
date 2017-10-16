#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<vector<int> > ans;
int p,n,num;
int mm(int v){
    int i = 1;
    while(pow(i,p)<=v)i++;
    return --i;
}
void solve(vector<int> v,int rem)
{
    if(v.size()==num&&rem!=0)return;
    if(v.size()==num&&rem==0){
        ans.push_back(v);
        return;
    }
    int i;
    if(v.empty())
        i = mm(rem);
    else
        i = min(mm(rem),v.back());
    for(;i>=1;i--) {
        v.push_back(i);
        solve(v,rem-pow(i,p));
        v.pop_back();
    }
}
int sum(const vector<int> & v)
{
    int ans  = 0;
    for(int i = 0; i < v.size(); i++) {
        ans+=v[i];
    }
    return ans;
}
bool cmp(const vector<int> & v1, const vector<int> & v2)
{
    if(sum(v1)!=sum(v2))
        return sum(v1)>sum(v2);
    return v1>v2;
}
int main()
{
    cin >> n >> num >> p;
    vector<int> v;
    solve(v,n);
    if(ans.empty()){
        cout<<"Impossible"<<endl;
        return 0;
    }
    for(int i = 1; i < ans.size(); i++) {
        if(cmp(ans[i],ans[0]))
            ans[0] = ans[i];
    }
    cout << n <<" = ";
    for(int i = 0; i < num; i++) {
        if(i>0){
                cout << "^" << p << " + ";}
        cout << ans[0][i];
    }
    cout<<"^"<<p<<endl;
}

