#include<bits/stdc++.h>
using namespace std;

#define MX 1000005
int lps[MX];

string txt,key;

void lps_calc(){
    int i = 1,j = 0;
    while(i<key.size()){
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

void match(int key_ln){
    int i=0,j=0,cn=0;
    while(i<txt.size()){
        if(txt[i]==key[j]){
            i++;
            j++;
            if(j==key_ln){
                printf("%d\n",i-j);
                cn++;
                j=lps[j-1];
            }
        }
        else{
            if(j) j = lps[j-1];
            else i++;
        }
    }
}

//char txt[MX],key[MX];

int main(){
    int x,i,j,k,ts,cas=0,cn;
    //freopen("NHAY.txt","r",stdin);

    while((scanf("%d",&x))==1){
        cin>>key>>txt;
        k = key.size();
        lps_calc();
        match(k);
        if(cas!=ts) puts("");
    }
    return 0;
}
