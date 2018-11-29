#include<iostream>
#include<cstdio>
#include<algorithm>
#define ll long long

using namespace std;

struct data{

    int v;
    int f;
}ara[50005*2];

bool cmp(data a, data b){

    if(a.v == b.v && a.f < b.f) return 1;
    if(a.v < b.v) return 1;
    else return 0;
}

int main(){

    int cas=0,t,c=0,i,j,k,x,y,n,tmp1,tmp2,mx,l;
    scanf("%d",&t);
    while(++cas<=t){

        scanf("%d",&n);
        l = 0;
        mx = 0;
        for(i=1;i<=n;i++){
            scanf("%d %d",&x,&y);
            ara[++l].v = x;
            ara[++l].v = y;
            ara[l].f = 1 , ara[l-1].f = 0;
            //cout<<ara[l].v<<" "<<ara[l].f<<endl;
           // cout<<ara[l-1].v<<" "<<ara[l-1].f<<endl;
        }
        sort(ara+1,ara+l+1,cmp);

        for(i=1;i<=l;i++){
            //cout<<ara[i].v<<" "<<ara[i].f<<endl;
            if(ara[i].f == 0) c++;
            else c--;

            if(c>mx) mx = c;
        }

        printf("Case %d: %d\n",cas,mx);
    }
    return 0;
}
