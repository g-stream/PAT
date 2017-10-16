#include<vector>
#include<iostream>
using namespace std;
int birds[10010];
int in[10010];
int find(int root){
    if(birds[root] == root)
        return root;
    int ans = find(birds[root]);
    birds[root] = ans;
    return ans;
}
void join(int i, int j)
{
    birds[find(i)] = find(j);
}
int main()
{
    for(int i = 0; i < 10010; i++){
        birds[i] = i;
        in[i]=0;
    }
    int maxn = 0;
    int n ;
    cin >> n;
    for(int i = 0; i < n; i++){
        int m;
        cin >> m;
        int now ;
        cin >> now;
        maxn = max(maxn,now);
        for(int j =1;j  < m;j++){
            int tmp;
            cin >> tmp;
            maxn = max(maxn,tmp);
            join(now,tmp);
        }
    }
    int cnt = 0;
    for(int i = 1; i<=maxn;i++){
        if(in[find(i)]==0){
            cnt++;
            in[find(i)] = 1;
        }
    }
    cout << cnt << " " << maxn << endl;
    cin >> n;
    while(n--){
        int n1,n2;
        cin >> n1 >> n2;
        if(find(n1)==find(n2)){
            cout << "Yes\n";
        }else {
            cout << "No\n";
        }
    }
}
