#include <string>
#include <iostream>
using namespace std;

int main()
{
    string s;
    getline(cin,s);
    int mm = 1;
    for(int i = 0;i<s.size();i++) {
        int num = 0;
        while(i-num>=0&&i+num<s.size()) {
            if(s[i-num]!=s[i+num])break;
            num++;
        }
        int tmp = (num-1)*2+1;
        if(tmp>mm)mm=tmp;
        num = 0;
        while(i-num>=0&&i+num+1<s.size()) {
            if(s[i-num]!=s[i+num+1])break;
            num++;
        }
        tmp = 2*num;
        if(tmp>mm)mm=tmp;
    }
    cout << mm;
}
