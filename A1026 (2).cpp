#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstdio>
using namespace std;
struct T
{
    int leave_time;
    int id;
};
inline operator<(const T& t1, const T& t2){
    return t1.leave_time>t2.leave_time;
}
priority_queue<T> q;
struct Consumer
{
    bool served;
    int arrive_time;
    int period;
    int vip;
};
inline operator<(const Consumer& c1, const Consumer& c2)
{
    return c1.arrive_time < c2.arrive_time;
}
void print_time(int t)
{
    printf("%02d:%02d:%02d",t/3600,t%3600/60,t%60);
}
int main()
{
    int num,num_table,num_vip_table,vip_table_id;
    vector<Consumer> v;
    cin >> num;
    for(int i = 0; i < num; i++){
        string s;
        cin >> s;
        Consumer tmp;
        tmp.served = false;
        tmp.arrive_time = 3600*((s[0]-'0')*10+(s[1]-'0')) + 60*((s[3]-'0')*10+s[4]-'0')+(s[6]-'0')*10+s[7]-'0';
        cin >> tmp.period >> tmp.vip;
        v.push_back(tmp);
    }
    sort(v.begin(),v.end());
    cin >> num_table;
    vector<int> zhaodai(num_table+1);
    vector<int> vip(num_table+1);
    cin >> num_vip_table;
    while(num_vip_table--){
        int i;
        cin >> i;
        vip[i] = 1;
    }
    for(int i = 1; i <= num_table; i++){
        T tmp;
        tmp.leave_time = 8*3600;
        tmp.id = i;
        q.push(tmp);
    }
    int index = 0;
    while(q.top().leave_time<=21*3600&&index<=num){
        T tmp = q.top();


    }

}
