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
#define MD 1000000009
using namespace std;

ll pm=31,powr[MX],hs[MX];

void powCalc(){
    powr[0] = 1;
    for(int i=1;i<MX;i++){
        powr[i] = (powr[i-1]*pm)%MD;
    }
}

vector<int> ans;

void rabin_karp(char txt[],char ptt[]){
    int P = strlen(ptt),T=strlen(txt),i,crr;

    memset(hs,0,sizeof hs);

    for(i=0; i<T; i++){
        hs[i+1] = (hs[i]+(txt[i]-'a'+1)*powr[i])%MD;
    }
    ll hss = 0;
    for(i=0; i<P; i++){
        hss = (hss+(ptt[i]-'a'+1)*powr[i])%MD;
    }

    for(i=0;i+P-1<T;i++){
        crr = (hs[i+P] - hs[i] + MD)%MD;

        if(crr == hss*powr[i]%MD){
            ans.push_back(i+1);
        }
    }
}


int main()
{
    ll i,j,a,b,ts,cn=0,cas=0,n,m,x,y,in,sum=0,mn=INT_MAX,mx=0;
    //freopen("test.txt","r",stdin);
    powCalc();
    char str[MX],s[MX];
    cin>>ts;
    while(++cas<=ts){
        in = 0;
        scanf("%s %s",str,s);
        ///P("sss")
        rabin_karp(str,s);
        if(!ans.empty()){
            in = ans.size();
            printf("%d\n",in);
            for(i=0;i<in;i++){
                if(i==in-1) printf("%d\n",ans[i]);
                else printf("%d ",ans[i]);
            }
        }
        else{
            printf("Not Found\n");
        }
        if(cas!=ts) puts("");
        ans.clear();
    }
    return 0;
}

