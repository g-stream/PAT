#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    string str;
    int n;
    cin >> n;
    cin.get();
    vector<string> v;
    for(int i = 0;i<n;i++) {
        getline(cin ,str);
        v.push_back(str);
    }
    int index = 0;
    int s=0x7fffffff;
    for(int i = 0; i< n;i++) {
        if(v[i].size()<s)s = v[i].size();
    }
    for(;index<s;index++) {
            bool flag = true;
        char c = v[0][v[0].size()-1-index];
        for(int j = 1;j<n;j++)
        {
            if(v[j][v[j].size()-1-index]!=c){flag = false;break;}
        }
        if(flag==false) {break;}
    }
    if(index==0)cout<<"nai";
    else cout<< v[0].substr(v[0].size()-index,index);
}
