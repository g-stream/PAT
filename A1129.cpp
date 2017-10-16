#include<algorithm>
#include<functional>
#include<iostream>
#include<vector>
using namespace std;
const int maxn = 100010;
int mark[maxn] = {0};
bool cmp(int i, int j)
{
    if(mark[i]!=mark[j]){
        return mark[i]>mark[j];
    }
    return i<j;
}
int main()
{
    int n,m;
    cin >> n >> m;
    vector<int> v;
    for(int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    vector<int> ans;
    for(int i = 0; i < n; i++){
        if(i>0){
            cout<<v[i]<<":";
            sort(ans.begin(),ans.end(),cmp);
            for(int i = 0; i < min((int)ans.size(),m); i++){
                cout << " " << ans[i];
            }
            cout<<endl;
        }
        mark[v[i]]++;
        if(mark[v[i]]==1){
            ans.push_back(v[i]);
        }
    }
}
