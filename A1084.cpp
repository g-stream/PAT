#include <iostream>
#include <vector>
#include <string>
using namespace std;
int flag[1000] = {0};
vector<char> v;
int main()
{
    string s1,s2;
    getline(cin ,s1);
    getline(cin, s2);
    for(int i = 0; i < s1.size();i++){
        char c1 = ('a'<=s1[i]&&s1[i]<='z')?s1[i]-32:s1[i];
        bool in;
        for(int j = 0; j< s2.size();j++) {
            in = false;
            char c2 = ('a'<=s2[j]&&s2[j]<='z')?s2[j]-32:s2[j];
            if(c1==c2) {in = true;break;}
        }
        if(!in&&!flag[c1])v.push_back(c1);
        if(!in)flag[c1]=1;
    }
    for(int i =0;i<v.size();i++) {
        cout <<v[i];
    }
    return 0;
}
