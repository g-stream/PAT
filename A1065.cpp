#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;
int main()
{
    ifstream cin("in.txt");
    vector<bool> v;
    int n;
    long long a,b,c;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a >> b >> c;
        long long ans = a+b;
        if(a>0&&b>0&&ans<0) v.push_back(true);
        else if(a<0&&b<0&&ans>=0) v.push_back(false);
        else if(ans>c) v.push_back(true);
        else v.push_back(false);
    }
    for(int i = 0; i < v.size(); i++) {
        if(v[i]) cout << "Case #" << i+1 << ": true" << endl;
        else cout << "Case #" << i+1 << ": false" << endl;
    }
    return 0;
}
