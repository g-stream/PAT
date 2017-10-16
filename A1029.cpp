#include <vector>
#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
    int n,m;
    vector<int> v1,v2;
    scanf("%d",&n);
    while(n--){
        int k;
        scanf("%d",&k);
        v1.push_back(k);
    }
    scanf("%d",&m);
    while(m--){
        int k;
        scanf("%d",&k);
        v2.push_back(k);
    }
    int index = (v1.size()+v2.size()-1)/2;
    int ans;
    m=n=0;
    while(index--){
       // cout<<"n:m-"<<n<<" "<<m<<endl;
        if(n==v1.size()){
            m++;
        }else if(m==v2.size()){
            n++;
        }else if(v1[n]<=v2[m]){
            n++;
        }else{m++;}
    }
        if(n==v1.size()){
            ans=v2[m];printf("%d",ans);return 0;
        }else if(m==v2.size()){
            ans=v1[n];printf("%d",ans);return 0;
        }else if(v1[n]<=v2[m]){
            ans=v1[n];printf("%d",ans);return 0;
        }else{printf("%d",v2[m]);}


}
