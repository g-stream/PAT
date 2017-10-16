#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
using namespace std;
struct E
{
    vector<int> child;
    double supply;
};
    int n;
    double danjia,r;
E tab[100010];
double sum=0;
void dfs(int root, int depth)
{
    if(tab[root].child.empty()){
        sum+=tab[root].supply*pow(r+1,depth);return;
    }
    for(int i =0;i<tab[root].child.size();i++){
        dfs(tab[root].child[i],depth+1);
    }
}
int main()
{

    cin >> n >> danjia>>r;
    r/=100.0;
    for(int i = 0;i<n;i++){
        int num;
        cin >> num;
        if(num){
            while(num--){
                int cd;
                cin >> cd;
                tab[i].child.push_back(cd);
            }
        }else{
            cin >> tab[i].supply;
        }
    }
    dfs(0,0);
    printf("%.1f\n",sum*danjia);
}
