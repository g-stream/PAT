#include <string>
#include <iostream>
using namespace std;
int main()
{
    string s;
    cin >> s;
    bool fu=false,fue=false;
    int index = 0;
    while(s[index]!='E')index++;
    if(s[0]=='-') fu = true;
    if(s[index+1] == '-') fue = true;
    string s1 = s.substr(1,index-1);
    string s2 = s.substr(index+2,s.size()-2);
    int e=0;
    for(int i = 0; i < s2.size(); i++)
    {
        e = 10*e + s2[i]-'0';
    }
    if(fu)
    cout << s[0];
    if(e==0){
        cout << s1;return 0;
    }
    s1.erase(s1.begin()+1);
    if(fue){
        s1 = "0."+s1;
        for(int i = 1; i<e;i++){
            s1.insert(s1.begin()+2,'0');
        }
        cout << s1 << endl;
        return 0;
    } else {
        int num = s1.size();
        if(num-1>e){
            s1.insert(s1.begin()+e+1,'.');
        } else {
            int n = e-num+1;
            while(n--)
            s1.insert(s1.end(),'0');
        }
        cout << s1;
    }

}
