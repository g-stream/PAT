#include <vector>
#include <string>
#include <iostream>
#include <cmath>
using namespace std;
bool isprime(int n){
    if(n==0||n==1)
        return false;
    else {
        for(int i = 2; i <= sqrt((double)n);i++){
            if(n%i==0)return false;
        }
    }
    return true;
}
int reverseit(int n, int r){
    int ans = 0;
    do{
        ans = r*ans + n%r;
        n /= r;
    }while(n!=0);
    return ans;
}
int main()
{
    while(1){
        int n,r;
        cin >> n;
        if(n<0)return 0;
        else cin>>r;
        int aa = reverseit(n,r);
        int bb = reverseit(aa,r);
        if(isprime(aa)&&isprime(bb))cout << "Yes"<<endl;
        else cout << "No" << endl;
    }
}
