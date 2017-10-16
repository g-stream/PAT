#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct station
{
    double price;
    double distance;
};
bool cmp(const station& s1,const station & s2){
    return s1.distance<s2.distance;
}
int main()
{
    double capacity,distance,per;
    int n;
    cin >> capacity >> distance >> per >> n;
    vector<station> v;
    while(n--){
        station s;
        cin >> s.price>>s.distance;
        v.push_back(s);
    }
    sort(v.begin(),v.end(),cmp);
    if(v[0].distance!=0){
        cout << "The maxinum travel distance = 0.00";
        return 0;
    }
    double longest = per*capacity;
    int now = 0;
    double p=0;
    while(1){
        bool finded=false;
        double min_price = 1000000,c=0;
        int min_price_index;
        for(int i=now;i<v.size()&&v[i].distance<=v[now].distance+longest;i++)
        {
            if(v[i].price<v[now].price) {now = i;p+=((v[i].distance-v[now].distance)/per-c)*v[now].price;c=0;finded=true;break;}
            if(v[i].price<min_price){min_price = v[i].price;min_price_index=i;}
        }
        if(!finded){
            p+=(capacity-c)*v[now].price;
            now = min_price_index;

        }

    }
}

