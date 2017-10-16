#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
using namespace std;
const int maxn = 100010;
int num;
double p,r;
int root;
vector<int> chain[maxn];
int max_d=0;
int max_n=0;
double price;
void dfs(int root,int depth)
{
    if(chain[root].empth()) {
        if(depth>max_d){
            max_d=depth;
            max_n = 1;
        } else if(depth==max_d){
            max_n++;
        }
            return;}
    for(int i = 0; i < chain[root].size(); i++){
        dfs(chain[root][i],depth+1);
    }
}
int main ()
{
    cin >> num >> p >> r;
    r/=100;
    for(int i = 0; i < num; i++){
        int sp;
        cin >> sp;
        if(sp!=-1){
            chain[sp].push_back(i);
        } else root = i;
    }

    dfs(root,0);
    printf("%.2f %d",pow(1+r,max_d)*p,max_n);
}
