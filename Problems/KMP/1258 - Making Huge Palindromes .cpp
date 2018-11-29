#include<bits/stdc++.h>
#define p(XX) cout<<"db1 "<<XX<<endl;
#define pp(XX,YY) cout<<"db1 "<<XX<<" "<<YY<<endl;
using namespace std;
#define MX 1000005

int lps[MX];

void lps_calc(char key[]){
    int i=1,j=0;
    while(key[i]){
        if(key[i]==key[j]){
            lps[i] = ++j;
            i++;
        }
        else{
            if(j) j = lps[j-1];
            else lps[i++] = 0;
        }
    }
}

int match(char txt[],char key[],int ln){
    int i=0,j=0;
    while(txt[i]){
        if(txt[i]==key[j]){
            i++;
            j++;
        }
        else{
            if(j) j = lps[j-1];
            else i++;
        }
    }
    return ln+ln-j;
}


char txt[MX],cp[MX];

int main(){
    int i,j,k,ts,cas=0,n,m;
    //freopen("1258.txt","r",stdin);
    cin>>ts;
    while(++cas<=ts){
        scanf("%s",txt);
        n = strlen(txt);
        for(i=n-1;i>=0;i--){
            cp[n-i-1] = txt[i];
        }
        cp[n] = '\0';
        //p(cp)
        lps_calc(cp);
        printf("Case %d: %d\n",cas,match(txt,cp,n));
    }
    return 0;
}
