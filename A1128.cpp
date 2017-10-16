#include<vector>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<set>
using namespace std;
struct e
{
    int i,j;
    e(int m,int n):i(m),j(n){}
};
bool operator==(const e& e1,const e&e2)
{
    return abs(e1.i-e2.i)==abs(e1.j-e2.j);
}
int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int m;
        cin >> m;
        vector<e> v;
        set<int> in;
        for(int k = 0; k < m; k++){

            int tmp;
            cin >> tmp;
            in.insert(tmp);
            e pos(k,tmp);
            v.push_back(pos);
        }
        if(in.size()!=m){cout<<"NO\n";continue;}

        bool ok = true;
        for(int k = 0; k < m-1; k++){
            for(int j = k+1; j < m; j++){
                if(v[k]==v[j]){
                    ok = false;
                    break;
                }
            }
            if(!ok)break;
        }
        if(ok)cout << "YES\n";
            else cout << "NO\n";

    }
}
