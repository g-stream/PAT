#include<cstdio>
#include<vector>
#include<iostream>
#include<cmath>
using namespace std;
const int maxn = 10010;
const int f = 4;
const int s = 5;
const int t = 6;
bool checked[maxn] = {false};
int in[maxn] = {0};
bool is_primer(int n)
{
    if(n==1) return false;
    if(n==2) return true;
    for(int i = 2;i<=sqrt((double)n);i++){
        if(n%i==0)return false;
    }
    return true;
}
int main()
{
    int n;
    cin >> n;
    for(int i =0; i<n;i++){
        int tmp ;
        cin >> tmp;
        if(i==0){in[tmp]=f;continue;}
        if(is_primer(i+1)){in[tmp]=s;continue;}
        in[tmp] = 1;
    }
    cin >> n;
    for(int i = 0; i < n; i++){
        int tmp ;
        cin >> tmp;
        printf("%04d: ",tmp);
        if(in[tmp]==0){
            cout << "Are you kidding?\n";
        }else{
            if(checked[tmp]){
                cout << "Checked\n";
                continue;
            }
            switch(in[tmp]){
            case f:
                cout << "Mystery Award\n";
                break;
            case s:
                cout << "Minion\n";
                break;
            default:
                cout << "Chocolate\n";
            }
            checked[tmp] = true;
        }
    }
}
