#include<vector>
#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
void fun(vector<int> & v, int l,int r,int k)
{
    srand((unsigned)time(NULL));
    int pivot = v[l+(rand())%(r-l)];
    cout << pivot <<endl;
    int p1 =l,p2=r;

    while(p1<p2){
        for(int i =0;i<v.size();i++){
            cout<<v[i]<<" ";
        }
        cout<<endl;
        while(p1<p2&&v[p1]<pivot)p1++;
        while(p1<p2&&v[p2]>=pivot)p2--;
        cout<< p1 << ": " <<p2<<endl;
        swap(v[p1],v[p2]);
    }
    if(p1==k)return;
    if(p1<k)
        fun(v,p1,r,k);
    else
        fun(v,l,p1-1,k);
}
int main()
{
    int n;
    scanf("%d",&n);
    vector<int> v;
    for(int i = 0; i < n; i++){
        int tmp;
        scanf("%d",&tmp);
        v.push_back(tmp);
    }
    int m = n/2;
    printf("%d ",n%2);
    fun(v,0,v.size()-1,m);
    int sum = 0;
    for(int i = 0; i < n; i++){
        if(i<m){
            sum-=v[i];
        }else{
            sum+=v[i];
        }
    }
    printf("%d",sum);
}
