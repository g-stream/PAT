#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
struct record
{
    string name;
    int h;
};
bool operator<(const record & r1, const record & r2)
{
    if(r1.h!=r2.h)
    {
        return r1.h<r2.h;
    } else return r1.name>r2.name;
}
void fun( vector<record> & v){
    if(v.size()==1)return;
    int m = v.size();
    int center = m/2;
    vector<record> tmp(v.size() );
    int i = m-2;
    int step = -1;
    tmp[center] = v[m-1];
    while(1){
        tmp[center+step] = v[i--];
        if(i==-1)break;
        step*=-1;
        tmp[center+step] = v[i--];
        if(i==-1)break;
        step*=-1;
        step--;
    }
    v=tmp;
}
void print(const vector<record> & v)
{
    for(int i = 0; i < v.size(); i++){
        if(i>0) cout << " ";
        cout << v[i].name;
    }
    cout << endl;
}
int main()
{
    int n,m;
    cin >> n >> m;
    vector<record> v;
    for(int i = 0; i < n; i++){
        record tmp;
        cin >> tmp.name>> tmp.h;
        v.push_back(tmp);
    }
    int num = n/m;
    sort(v.begin(),v.end());

    vector<vector<record>> ans(m);
    for(int i = 0; i < m; i++){
        if(i!=m-1){
            for(int j = num*i; j < num*(i+1); j++) {
                ans[i].push_back(v[j]);
            }
        } else
        for(int j = num*i; j < n; j++ ){
            ans[i].push_back(v[j]);
        }
    }
    for(int i = m-1; i >=0; i--){
        fun(ans[i]);
        print(ans[i]);
    }


}
