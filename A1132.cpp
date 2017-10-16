#include<iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    while(n--){
        int tmp;
        cin >> tmp;
        int k = tmp;
        int cnt = 0;
        while(tmp){
            tmp/=10;
            cnt++;
        }
        cnt/=2;
        int num = 1;
        while(cnt--)num*=10;
        int n1 = k/num;
        int n2 = k%num;
        if(n1*n2==0){cout << "No\n";continue;}
        if((long long)k%((long long)n1*n2)==0){
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
}
