#include<vector>
#include<iostream>
#include<queue>
#include<cmath>
#include<cstdio>
#include<string>
#include<sstream>
using namespace std;
double sum = 0;
int cnt = 0;
int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        string str;
        cin >> str;
        int co = 1;
        if(str[0]=='-'){str.erase(str.begin());co = -1;}
        stringstream sm;
        bool is_num = true;
        int index = -1;
        bool has_dot = false;
        for(int i = 0; i < str.size(); i++){
            if(str[i]<='9'&&str[i]>='0')continue;
            index = i;
            if(has_dot){is_num = false;}
            has_dot = true;
            if(str[i]!='.')
            {
                is_num = false;break;
            }
        }
        if(index>=0&&str.size()-index>3)is_num = false;
        if(!is_num){
            cout << "ERROR: " ;
            if(co==-1)cout<<'-';
            cout << str << " is not a legal number"<<endl;
            continue;
        }
        sm << str;
        double tmp;
        sm >> tmp;
        tmp *= co;
        if(tmp>1000||tmp<-1000){
            cout << "ERROR: " ;
            if(co==-1)cout<<'-';
            cout << str << " is not a legal number"<<endl;
            continue;
        }
        cnt++;
        sum += tmp;
    }
    cout << "The average of "<<cnt;
    if(cnt == 0) cout << " numbers is Undefined";
    else if(cnt == 1){ cout<< " number is ";printf("%.2f",sum);}
    else {cout << " numbers is " ;printf("%.2f",sum/cnt);}
}
