#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
#define MX 1000000

pii ara[MX];

int main(){
    int cn=0,mx=0,i,j,k,l,m,n,ts,cas=0,en;
    freopen("interval.txt","r",stdin);
    cin>>ts;
    while(++cas<=ts){
        scanf("%d",&n);
        for(i=1;i<=n;i++){
            scanf("%d %d",&ara[i].second,&ara[i].first);
        }
        sort(ara+1,ara+n+1);
        cn=mx=0;
        en=-1;
        for(i=1;i<=n;i++){
            if(ara[i].second>=en){
                cn++;
                en = ara[i].first;
            }
        }
        for(i=1;i<=n;i++){
            if(i>=3){
                if(ara[i].first==ara[i-1].first&&ara[i-2].first==ara[i-1].first){
                    if(ara[i].second==ara[i-1].second&&ara[i-2].second==ara[i-1].second){
                        mx++;
                        while(ara[i].first==ara[i+1].first&&ara[i].second==ara[i+1].second) i++;
                        if(i>n) break;
                    }
                }
            }
        }
        printf("%d\n",cn);
    }
    return 0;
}

