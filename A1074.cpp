#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;
struct NODE
{
    int add;
    int nex;
    int val;
};
int main()
{
    int n,index,start;
    cin >> start>>n>>index;
    map<int,NODE> re;
    for(int i =0;i<n;i++){
        NODE tmp;
        cin >> tmp.add>>tmp.val>>tmp.nex;
        re[tmp.add]=tmp;
    }
    vector<NODE> v;
    while(start!=-1){
        v.push_back(re[start]);
        start = re[start].nex;
    }
    int i = 0;
    while(index+i<=v.size()){
    reverse(v.begin()+i,v.begin()+index+i);
    i+=index;
    }
    for(int i = 0;i<v.size();i++){
        if(i==v.size()-1)printf("%05d %d %d\n",v[i].add,v[i].val,-1);
        else printf("%05d %d %05d\n",v[i].add,v[i].val,v[i+1].add);
    }
}
