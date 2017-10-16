#include<vector>
#include<iostream>
#include<queue>
#include<cstdio>
using namespace std;
struct node
{
    int var;
    node* l,*r,*p;
    int d;
    node():var(0),l(nullptr),r(nullptr),p(nullptr),d(0){}
};
int num[1010] = {0};
node* root = nullptr;
void dfs(node *root)
{
    if(root == nullptr)return;
    num[root->d]++;
    dfs(root->l);
    dfs(root->r);
}
int main()
{
    int n;
    cin >> n;
    bool first = true;
    for(int i = 0; i < n; i++)
    {
        int tmp ;
        cin >> tmp;
        node** now = &root;
        if(first){
            *now = new node;
            (*now)->var = tmp;
            first = false;
            continue;
        }
        while(1){
            if(tmp<=(*now)->var){
               if((*now)->l!=nullptr){
                    now = &((*now)->l);
               } else {
                    (*now)->l = new node;
                    (*now)->l->var = tmp;
                    (*now)->l->p = *now;
                    (*now)->l->d = (*now)->d+1;
                    break;
               }
            }else{
               if((*now)->r!=nullptr){
                    now = &((*now)->r);
               } else {
                    (*now)->r = new node;
                    (*now)->r->var = tmp;
                    (*now)->r->p = *now;
                    (*now)->r->d = (*now)->d+1;
                    break;
               }
            }
        }
    }
    dfs(root);
    if(n==0){printf("0 + 0 = 0");return 0;}
    if(n==1){
        printf("0 + 1 = 1\n");return 0;}
    int n1,n2;
    for(int i = 1 ; i < 1010; i++){
        if(num[i]){
            n1 = num[i];
            n2=num[i-1];
        }else break;
    }
    printf("%d + %d = %d",n1,n2,n1+n2);
}
