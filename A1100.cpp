#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <sstream>
using namespace std;

string tab1[13] = {"tret","jan","feb","mar","apr","may","jun","jly","aug","sep","oct","nov","dec"};
string tab2[13] = {"tret","tam","hel","maa","huh","tou","kes","hei","elo","syy","lok","mer","jou"};
int s2i(string s)
{
    stringstream sm ;
    sm << s;
    int ans=0;
    vector<string> v;
    while(sm >> s){
        v.push_back(s);
    }
    if(v.size()==2){
        int i = 0;
        while(tab2[i]!=v[0])i++;
        ans+=i*13;
        i=0;
        while(tab1[i]!=v[1])i++;
        ans+=i;
    } else {
        for(int k=0;k<13;k++){
            if(tab2[k]==v[0])
                return k*13;
        }
        int i=0;
        while(tab1[i]!=v[0])i++;
        ans+=i;
    }
    return ans;
}
string i2s(int i)
{
    int s1 = i/13;
    int s2 = i%13;
    if(s1&&s2){
        return tab2[s1]+" "+tab1[s2];
    } else if(s1){
        return tab2[s1];
    } else {
        return tab1[s2];
    }
}
int main()
{
    int n;
    cin >> n;
    stringstream sm;
    cin.ignore();
    while(n--){
        string s;

        getline(cin,s);
        if('0'<=s[0]&&s[0]<='9'){
            int num=0;
            for(int i = 0; i < s.size(); i++){
                num = num*10+s[i]-'0';
            }
            cout << i2s(num) << endl;
        } else {
            cout << s2i(s) << endl;
        }
    }
}
