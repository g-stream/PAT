#include <iostream>
#include <string>
using namespace std;
bool flag[256] = {false};

int main()
{
    string s1,s2;
    getline(cin,s1);
    getline(cin,s2);
    string ans;
   // cout << s1;cout<<s2;
    for(int i = 0; i < s2.size();i++){
        flag[s2[i]] = true;
    }
    for(int i = 0; i< s1.size();i++) {
        if(flag[s1[i]]==false)
            ans.push_back(s1[i]);
    }
    cout << ans;
    //while(1);
}

