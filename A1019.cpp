#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n,r;
    vector<int> v;
    cin >> n>>r;
    while(n){
        v.push_back(n%r);
        n/=r;
    }
    bool flag = true;
    for(int i = 0,j = v.size()-1;i<j;i++,j--) {
        if(v[i]!=v[j]) {
            flag = false;
            break;
        }
    }
    if(flag) {
        cout << "Yes" <<endl;
        for(int i = 0; i < v.size();i++)
        {
            if(i==0) cout << v[v.size()-1];
            else cout << " " << v[v.size()-1-i];
        }
    }
    else {cout << "No"<<endl;        for(int i = 0; i < v.size();i++)
        {
            if(i==0) cout << v[v.size()-1];
            else cout << " " << v[v.size()-1-i];
        }}
        return 0;
}
