#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstdio>
using namespace std;
int l,r;
struct R
{
    string name;
    int age;
    int value;
};
bool cmp(const R& r1,const R& r2)
{
    if(r1.age<=r&&r1.age>=l&&(r2.age>r||r2.age<l))
        return true;
    else if(r2.age<=r&&r2.age>=l&&(r1.age>r||r1.age<l))
        return false;
    else if(r1.value!=r2.value)
        return r1.value>r2.value;
    else if(r1.age != r2.age)
        return r1.age < r2.age;
    else return r1.name < r2.name;
}
int main()
{
    int n,m;
    cin >> n >> m;
    vector<R> v;
    while(n--) {
        R tmp;
        cin >> tmp.name >> tmp.age >> tmp.value;
        v.push_back(tmp);
    }
    int mm;
    int num = 0;
    while(m--) {
        num++;
        cin >> mm >> l >> r;
        sort(v.begin(),v.end(),cmp);
        int index = v.size();
        for(int i = 0; i < v.size(); i++) {
            if(v[i].age>r||v[i].age<l){
                index = i;
                break;
            }
        }

        printf("Case #%d:\n",num);
        if(min(index,mm)==0) cout << "None" << endl;
        else {
            for(int i = 0; i < min(index,mm); i++)
            {
                printf("%s %d %d\n",v[i].name.c_str(),v[i].age,v[i].value);
            }
        }
    }
    return 0;
}
