#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int q = (int)sqrt(n);
    if(n%2)
    {
        cout << 1<<endl;
        for(int i = 3;i<=n;i++)
            if(n%i==0){cout<<i;return 0;}
    }
    if(n==2||n==3||n==5){cout<<"1\n"<<n;return 0;}
    int num=1,index;
    for(int i =2;i<=q;i++)
    {
        int tmp = n;
        int nn=0;
        while(tmp%(i+nn)==0){
        //    cout << "in"<<i<<":"<<nn<<endl;
            tmp/=i+nn;
            nn++;
        }
        if(nn>num){
            index = i;
            num=nn;
        }
    }
    cout<<num<<endl;
    for(int i=0;i<num;i++){
        if(i>0)cout<<"*";
        cout<<index+i;
    }
}
