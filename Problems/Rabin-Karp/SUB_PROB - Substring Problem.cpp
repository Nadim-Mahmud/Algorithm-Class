///Not AC

#include <bits/stdc++.h>
#define ll long long
#define P(X) cout<<"db "<<X<<endl;
#define P2(X,Y) cout<<"db2 "<<X<<" "<<Y<<endl;
#define rep(i,n) for(i=1;i<=n;i++)
#define FO freopen("t.txt","w",stdout);
#define MS(XX,YY) memset(XX,YY,sizeof(XX));
#define pii pair<int,int>
#define chk(n,i) (bool)(n&(1<<i))
#define on(n,i) (n|(1<<i))
#define off(n,i) n=n&(~(1<<i))
#define eps 10e-7
#define MX 1000005
#define MD 999721
using namespace std;

int ara[MX];
bool mr[MX];
char str[MX],s[MX];

int dohash(char *s){
    ll i,pm=937,pp=1,hv=0;
    for(i=0;s[i];i++){
        pp=(pp*pm)%MD;
        hv+=s[i]*pp;
        hv%=MD;
    }
    return hv;
}

void rabin(char str[]){
    ll i,pm=937,pp=1,hv=0;
    for(i=0;str[i];i++){

        hv =
    }
}

int main()
{
    ll i,j,a,b,ts,cn=0,cas=0,n,m,x,y,sum=0,mn=INT_MAX,mx=0;
    //freopen("test.txt","r",stdin);
    cin>>str;
    cin>>n;
    for(i=1;i<=n;i++){
        scanf("%s",s);
        ara[dohash(s)] = i;
    }

    return 0;
}

