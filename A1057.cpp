#include<vector>
#include <iostream>
#include<string>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
char op[15];
int main()
{
    vector<int> v;
    vector<int> vs;
    int n;
    cin >>n;
    while(n--){
        int num;
        scanf("%s",op);
        if(strcmp(op,"Push")==0){
            scanf("%d",&num);
            v.push_back(num);
            vs = v;
            sort(vs.begin(),vs.end());
        }else if(strcmp(op,"PeekMedian")==0) {
            if(v.size()){
                printf("%d\n",vs[(v.size()-1)/2]);
            }else{
                printf("%s\n","Invalid");
            }

        }else{
            if(v.size()){printf("%d\n",v.back());
            v.pop_back();
            vs = v;
            sort(vs.begin(),vs.end());
            }
            else printf("%s\n","Invalid");}

    }

}
