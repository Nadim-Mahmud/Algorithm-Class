

///        Dynamic Programming

///   *** Subset Sum [m*n]

ll n,k,ara[105],dp[10005];

ll ways()
{
    ll i,j;
    memset(dp,0,sizeof dp);
    dp[0] = 1;
    for(j=1;j<=n;j++){
        for(i=1;i<=k;i++){
            if(i>=ara[j]){
                dp[i] = dp[i] + dp[i-ara[j]];
            }
        }
    }
    return dp[k];
}



///              String Mathcing


///    **** Knuth–Morris–Pratt(KMP) [n+k]

#define MX 1000005
///Largest possible suffix-prefix upto this index
int lps[MX];

/// prefix size is (j+1) as key i 0 based index

void lps_calc(char key[]){
    int i = 1,j = 0;
    while(key[i]){
        //cout<<"ff\n";
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
/**
*   @return -1 if no match found else return staring position of match
*/
int match(char txt[],char key[],int key_ln){
    int i=0,j=0,cn=0;
    while(txt[i]){
        if(txt[i]==key[j]){
            i++;
            j++;
            if(j==key_ln){
                return i - key_ln;
                //cn++;
                //j=lps[j-1];
            }
        }
        else{
            if(j) j = lps[j-1];
            else i++;
            /// j = 0 and pos are not equal then skipping this position
        }
    }
    return cn;
}

char txt[MX],key[MX];

