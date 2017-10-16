#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <cstdio>
#include <string>
#include <fstream>
using namespace std;
struct Record
{
    int month,day,hh,mm;
    int mmA;
    string flag;
};
bool cmp(const Record & r1,const Record & r2)
{
    if(r1.month!=r2.month)
        return r1.month<r2.month;
    else if(r1.day != r2.day)
        return r1.day < r2.day;
    else if(r1.hh != r2.hh)
        return r1.hh < r2.hh;
    else return r1.mm<r2.mm;
}
int price[24];
int main()
{
    //ifstream cin("in.txt");
    int n = 24;
    while(n--) {
        cin >> price[23-n];
    }
    cin >> n;
    map<string,vector<Record> >m;
    while(n--) {
        Record tmp;string str;
        cin >> str;
        scanf("%d:%d:%d:%d ",&tmp.month,&tmp.day,&tmp.hh,&tmp.mm);
        cin >> tmp.flag;
        tmp.mmA = 24*60*tmp.day+60*tmp.hh+tmp.mm;
        m[str].push_back(tmp);
    }
    for(map<string,vector<Record> >::iterator it = m.begin();it!=m.end();it++)
    {
        sort(it->second.begin(),it->second.end(),cmp);
        vector<Record> v;
        int on=-1;
        for(int i = 0; i < it->second.size();i++) {
            if(it->second[i].flag == "on-line") {
                on = i;
            }
            else if(it->second[i].flag == "off-line"&&on>=0) {
                v.push_back(it->second[on]);
                v.push_back(it->second[i]);
                on = -1;
            }
        }
        it->second = v;

        double sumA = 0;
        if(it->second.size()==0)continue;
        cout << it->first;
        printf(" %02d\n",it->second[0].month);
        for(int i = 0; i < v.size();i++) {
            double sum=0;
            printf("%02d:%02d:%02d ",v[i].day,v[i].hh,v[i].mm);
            if(i%2) {
                int time = v[i].mmA-v[i-1].mmA;
                Record tmp = v[i-1];
                while(tmp.day<v[i].day||tmp.hh<v[i].hh||tmp.mm<v[i].mm) {
                    sum+=price[tmp.hh];
                    tmp.mm++;
                    if(tmp.mm==60) {tmp.mm=0;tmp.hh++;}
                    if(tmp.hh==24) {tmp.hh=0;tmp.day++;}
                }


                cout << time << " $";
                printf("%0.2lf\n",sum/100);
                sumA+=sum;
            }
        }
        cout << "Total amount: $" ;
        printf("%0.2lf\n",sumA/100);
    }


    return 0;
}
