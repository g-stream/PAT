#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int main ()
{
    int n,m;
    cin >> n>> m;
    vector<int> v;

    while(n--) {
            int tmp;
    cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(),v.end());
    int i = 0,j = v.size()-1;
    bool has = false;
    while(i<j){
        if(v[i]+v[j]>m)j--;
        else if(v[i]+v[j]<m)i++;
        else {cout << v[i] << " "<< v[j];return 0;}
    }
    cout << "No Solution";
    return 0;
}
