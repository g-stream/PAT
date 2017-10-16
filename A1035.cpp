#include <string>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <utility>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<pair<string,string> > v;
    int num = 0;
    for(int i = 0; i < n; i++){
        string s1,s2;
        cin >> s1 >> s2;
        bool flag = false;
        for(int j = 0; j< s2.size();j++){
            if(s2[j]=='1'){
                s2[j] = '@';
                flag = true;
            }
            if(s2[j]=='0'){
                s2[j] = '%';
                flag = true;
            }
            if(s2[j] == 'l'){
                s2[j] = 'L';
                flag = true;
            }
            if(s2[j] == 'O'){
                s2[j] = 'o';
                flag = true;
            }
        }
        if(flag){
            num++;
            v.push_back(make_pair(s1,s2));
        }
    }
    if(v.size()==0){
        if(n==1){cout << "There is 1 account and no account is modified";return 0;}
        else {
            cout << "There are "<<n<<" accounts and no account is modified";
            return 0;
        }
    } else {
        cout << num << endl;
        for (int i = 0; i<v.size(); i++){
            cout << v[i].first << " " << v[i].second<<endl;
        }
    }
}
