#include<bits/stdc++.h>
using namespace std;

#define MX 1000005
int lps[MX];

void lps_calc(char key[]){
    int i = 1,j = 0;
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

int ans[MX],in;

int match(char txt[],char key[],int key_ln){
    int i=0,j=0,cn=0;
    in=0;
    while(txt[i]){
        if(txt[i]==key[j]){
            i++;
            j++;
            if(j==key_ln){
                ans[++in] = i-j+1;
                j=lps[j-1];
            }
        }
        else{
            if(j) j = lps[j-1];
            else i++;
        }
    }
    return in;
}

char txt[MX],key[MX];

int main(){
    int x,i,j,k,ts,cas=0,cn;
    //freopen("NAJPF.txt","r",stdin);
    cin>>ts;
    while(++cas<=ts){
        scanf("%s %s",txt,key);
        //memset(lps,0,sizeof lps);
        k = strlen(key);
        lps_calc(key);
        cn = match(txt,key,k);
        if(cn){
            printf("%d\n",cn);
            for(i=1;i<=cn;i++){
                if(i==cn) printf("%d\n",ans[i]);
                else printf("%d ",ans[i]);
            }
        }
        else printf("Not Found\n");
        if(cas!=ts) puts("");
    }
    return 0;
}
