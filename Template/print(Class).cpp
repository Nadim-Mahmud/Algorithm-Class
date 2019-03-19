#include<bits/stdc++.h>
#define ll long long
using namespace std;


        /// SORTING ALGORITHMS


///  *** Bubble sort [n*n]

void bubbleSort(ll ara[],ll n){
    ll i,j;
    for(i = 1; i <= n; i++){
        for(j = 1; j < n-i; j++){
            if(ara[j+1] < ara[j]){
                swap(ara[j+1],ara[j]);
            }
        }
    }
}


///  *** Selection sort  [n*n]

void selectionSort(ll ara[],ll n){
    for(int i = 1; i<=n; i++){
        for(int j = i+1; j<=n; j++){
            if(ara[i]>ara[j]){
                swap(ara[i],ara[j]);
            }
        }
    }
}

///  *** Insertion Sort  [n*n]

void insertionSort(ll ara[],ll n){
    ll i,j,tmp;
    for(i = 1; i<=n; i++){
        tmp = ara[i];
        j = i-1;
        while(j >= 1 && ara[j] > tmp){
            ara[j+1] = ara[j];
            j--;
        }
        ara[j+1] = tmp;
    }
}



///   *** merge sort  [nlog(n)]

#define MX 1000000

ll tmp[MX];

void mergeSort(ll ara[],ll l,ll r){
    if(l==r) return;
    ll i,j,k,md;
    md = (l+r)/2;
    mergeSort(ara,l,md);
    mergeSort(ara,md+1,r);
    for(i=l,j=md+1,k=l;k<=r;k++){
        if(i>md) tmp[k] = ara[j++];
        else if(j>r) tmp[k] = ara[i++];
        else if(ara[i]<ara[j]) tmp[k] = ara[i++];
        else tmp[k] = ara[j++];
    }
    for(i=l;i<=r;i++){
        ara[i] = tmp[i];
    }
}

///   *** Quick Sort  [nlogn]

ll partition(ll ara[],int lw,int hi){
    ll pivot = ara[hi],i,j;
    for(i=lw,j=lw;j<=hi;j++){
        if(ara[j]<pivot){
            swap(ara[i++],ara[j]);
        }
    }
    swap(ara[i],ara[hi]);
    return i;
}


void Quicksort(ll ara[],ll lw,ll hi){
    if(lw>=hi) return;
    ll pivot = partition(ara,lw,hi);
    Quicksort(ara,lw,pivot-1);
    Quicksort(ara,pivot+1,hi);
}







        /// SEARCHING ALGORITHMS

///   *** Binary Search [nlog(n)]

int binarySearh(int n,int lw,int hi){
    int mid;
    while(lw<hi){
        mid = (lw+hi)/2;
        if(ara[mid]>n) hi = mid-1;
        else if(ara[mid]<n) lw = mid+1;
        else break;
    }
    return mid;
}

ll ara[MX];




///    GRAPH ALGORITHMS



///  *** BFS [ total(node + edge) ]

vector <int> ed[MX];
int lev[MX],ms,par[MX];
bool vs[MX];
int bfs(int s){
    int i,j,d,f,v;
    queue <int> q;
    q.push(s);
    lev[s]=0;
    vs[s]=1;
    while(!q.empty()){
        f=q.front();
        q.pop();
        for(i=0;i<ed[f].size();i++){
            v=ed[f][i];
            if(!vs[v]){
                vs[v]=1;
                q.push(v);
                lev[v]=lev[f]+1;
            }
        }
    }
    return lev[destinition];
}

/// *** BFS in 2D Grid [edge + node]

int lev[MX][MX],m,n;
bool vs[MX][MX];
char st[MX][MX];
int dx[]={1,-1,0, 0, 1,1,};
int dy[]={0, 0,1,-1,-1, };

int bfs(int fx,int fy) // starting position
{
    int i,v,x,y,md=0;
    queue <pii> q;
    pii pr;
    vs[fx][fy]=1;
    lev[fx][fy]=0;
    q.push(pii(fx,fy));
    while(!q.empty()){
        pr=q.front();
        fx=pr.first;
        fy=pr.second;
        q.pop();
        for(i=0;i<4;i++){
            x=fx+dx[i];
            y=fy+dy[i];
            if(x<0||x>=n||y<0||y>=m)continue; // for zero based index
            if(!vs[x][y]&&st[x][y]!='#'){ // # is blocked
                q.push(pii(x,y));
                vs[x][y]=1;
                lev[x][y]=lev[fx][fy]+1;
                if(st[x][y]=='d'){ // d is destinition
                    md=max(md,lev[x][y]);
                }

            }
        }

    }
    return md;//max distance of d

}

/// *** DFS [E+V]

vector<int>ed[MX];
bool vs[MX];
int lev[MX];

void dfs(int n)
{
    if(vs[n]) return;
    vs[n] = 1;
    int i,v;
    for(i=0;i<ed[n].size();i++){
        v = ed[n][i];
        dfs(v);
    }
}

///  *** IDDFS [v+E]

vector<int>ed[MX];
int vs[MX],pr[MX];

bool dfs(int f){
    stack<int>st;
    st.push(f);
    while(!st.empty()){
        f = st.top();
        st.pop();
        if(vs[f]) return 1;
        vs[f] = 1;
        for(int i=0;i<ed[f].size();i++){
            int v = ed[f][i];
            if(!vs[v]){
                st.push(v);
            }
        }
    }
    return 0;
}


///  *** Dijkstra [edge log (node)]

struct node{
    int id,cost;
    node(){}
    node(int nid,int ncost)
    {
        id=nid;
        cost=ncost;
    }
    bool operator < (const node&x)const{
        return  cost>x.cost;
    }
};

vector <int> ed[MX],ec[MX];
int ds[MX];
void dxt(int s){
    priority_queue <node> q;
    q.push(node(s,0));
    ds[s]=0;
    node fn;
    int i,u,v;
    while(!q.empty()){
        fn=q.top();
        q.pop();
        u=fn.id;
        if(fn.cost!=ds[u])continue;
        for(i=0;i<ed[u].size();i++){
            v=ed[u][i];
            if(ds[v]>ds[u]+ec[u][i]){
                ds[v]=ds[u]+ec[u][i];
                q.push(node(v,ds[v]));
            }
        }
    }
}































///     DATA STRUCTURE



/// *** Segment Tree [log(total array size)*Query]

/** [ulow,uhigh] Query Range
*   [low,high] total range of root
*   Currrent position = pos
*   0 based Index And Root is also 0
*/


///   Seg Tree Without Lazy

int ara[MX],seg[4*MX],lazy[4*MX];

void creat(int low,int high,int pos)
{
    if(low==high){
        seg[pos] = ara[low]; // reached leaf and update
        return ;
    }
    int mid = (high+low)/2;
    creat(low,mid,pos*2+1);
    creat(mid+1,high,pos*2+2);
    seg[pos] += seg[pos*2+1] + seg[pos*2+2];
}

int query(int low,int high,int ulow,int uhigh,int pos)
{
    if(low>high) return 0;
    if(ulow>high||uhigh<low) return 0;
    if(ulow<=low&&uhigh>=high) return seg[pos];
    int mid = (high+low)/2;
    return query(low,mid,ulow,uhigh,pos*2+1) + query(mid+1,high,ulow,uhigh,pos*2+2);
}

/// *** Segment tree with lazy

int ara[MX],seg[4*MX],lazy[4*MX];

void creat(int low,int high,int pos)
{
    if(low==high){
        seg[pos] = ara[low]; // reached leaf and update
        return ;
    }
    int mid = (high+low)/2;
    creat(low,mid,pos*2+1);
    creat(mid+1,high,pos*2+2);
    seg[pos] += seg[pos*2+1] + seg[pos*2+2];
}

void update(int low,int high,int ulow,int uhigh,int val,int pos)
{
    if(low>high) return ;
    if(lazy[pos]!=0){ /// is not propagated yet
        seg[pos] = 0;
        if(low!=high){  ///if not leaf node
            lazy[pos*2+1] += lazy[pos];
            lazy[pos*2+2] += lazy[pos];
        }
        lazy[pos] = 0;
    }

    if(ulow>high||uhigh<low) return; ///No overlap
    if(ulow<=low&&uhigh>=high){ /// Total Overlap
        seg[pos] += val;
        if(low!=high){
            lazy[pos*2+1] += val;
            lazy[pos*2+2] += val;
        }
        return;
    }
    /// Partial overlap
    int mid = (high+low)/2;

    update(low,mid,ulow,uhigh,val,pos*2+1);
    update(mid+1,high,ulow,uhigh,val,pos*2+2);
    /// Updating the intermediate node
    seg[pos] = seg[pos*2+1] + seg[pos*2+2];
}

int query(int low,int high,int ulow,int uhigh,int pos)
{
    if(low>high) return 0;
    if(lazy[pos]!=0){
        seg[pos] += lazy[pos];
        if(low!=high){
            lazy[pos*2+1] += lazy[pos];
            lazy[pos*2+2] += lazy[pos];
        }
        lazy[pos] = 0;
    }

    if(ulow>high||uhigh<low) return 0;

    if(ulow<=low&&uhigh>=high)
        return seg[pos];

    int mid = (high+low)/2;

    return query(low,mid,ulow,uhigh,pos*2+1)
    + query(mid+1,high,ulow,uhigh,pos*2+2);
}


///   *** Merge Sort Tree [nlog(n) + query*log(n)*log(n)]


int ara[MX];
vector<int>vc[MX*4];
/// 1 based index

int bns(int n,int val){
    /// lower bound 1 2 2 2 3 4
    /// then returns 2
    int mid,i,j,low=0,high = vc[n].size()-1;
    while((high-low)>4){
        mid = (low+high)/2;
        if(vc[n][mid]<=val) low = mid;
        else high = mid - 1;
    }
    for(low;low<=high&&low<vc[n].size();low++){
        if(vc[n][low]>val) break;
    }
    return vc[n].size()-low; /// numbers greater than value
}

void mergee(int x,int y,int z){ /// merging 2 vector x and y to Z in sorted order
    int i,j,k,md,sz;
    sz = vc[x].size() + vc[y].size();
    for(i=0,j=0,k=0;k<sz;k++){
        if(i>=vc[x].size()) vc[z].push_back(vc[y][j++]);
        else if(j>=vc[y].size()) vc[z].push_back(vc[x][i++]);
        else if(vc[x][i]<vc[y][j]) vc[z].push_back(vc[x][i++]);
        else vc[z].push_back(vc[y][j++]);
    }
}

/** [low,high]  total range :: variable range
*   [qlow,qhigh] query range
*   pos = current position
*/

void creat(int low,int high,int pos){ /// creating merge sort tree
    if(low==high){
        vc[pos].push_back(ara[low]);
        return ;
    }
    int mid = (low+high)/2;
    creat(low,mid,pos*2);
    creat(mid+1,high,pos*2+1);
    mergee(pos*2,pos*2+1,pos);
    /// merge with stl ->
    /// merge(seg[pos*2].begin() , seg[pos*2].end(), seg[pos*2].begin(), seg[pos*2].end(),back_inserter(seg[pos]));
}

int query(int low,int high,int qlow,int qhigh,int pos,int val){
    if(qlow>qhigh) return 0;
    if(qlow>high||qhigh<low) return 0;
    if(qlow<=low&&qhigh>=high){
        return bns(pos,val);
    }
    int mid = (low + high)/2;
    return query(low,mid,qlow,qhigh,pos*2,val) + query(mid+1,high,qlow,qhigh,pos*2+1,val);
}

///  *** Disjoint Set Union Find [n||1]

int parent(int n)
{
    if(rp[n]==n)return n;
    return rp[n]=parent(rp[n]);
}
void setUp(int a,int b){
    rp[parent(b)]=parent(a);
}


///        COMPUTATIONAL GEOMETRY


///   *** Convex Hull[Grahams Scan]  [nlog(n)]

#define ll long long
struct point{
    ll x,y;
}convex_points[MX],points[MX];;

/// global scope decraltion of min-left point of collcetion
point pivot;

///Distance calculation mathod
ll dist(point p1,point p2){
    return ((p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y));
}

/**
*   https://www.geeksforgeeks.org/orientation-3-ordered-points/
*   calculating orientation based on slope (yi-yj)/(xi-xj)
*   by compering slope of p-q and q-r;
*   if p-q<q-r then counter-clockwise
*   @return 0 if colinear
*   @return 1 if clockwise (Right rotetion)
*   @return 2 if counter-clockwise (left rotetion)
*/
int orientation(point p,point q,point r){
    ll val = ((q.y-p.y)*(r.x-q.x) - (r.y-q.y)*(q.x-p.x));
    if(val==0) return 0;
    if(val>0) return 1;
    return 2;
}

/**
*   sorting by polor angle in counterclockwise order around point0.
*   If polor angle of two points is same, then put the nearest point first.
*/
bool cmp(point p1,point p2){
    ll o = orientation(pivot,p1,p2);
    if(o==0){
        return dist(pivot,p1) < dist(pivot,p2);
    }
    return (o==2);
}

/// returning previous value of top element
inline point nextToTop(stack<point>&st){
    point p,res;
    p = st.top();
    st.pop();
    res = st.top();
    st.push(p);
    return res;
}

int total;

/**
*   This function will calculate convexHull points
*   All arrays are in 0 based indexing
*   @param n total numbers of points
*/
bool convexHull(int n){
    ll i,pos=0,in=0,miny = points[0].y,minx = points[0].x;
    stack<point>st;

    /// Finding bottom-left most point
    for(i=0;i<n;i++){
        if((miny==points[i].y&&minx>points[i].x)||miny>points[i].y){
            minx = points[i].x;
            miny = points[i].y;
            pos = i;
        }
    }

    ///sorting element according to the criteria
    swap(points[0],points[pos]);
    pivot = points[0];
    sort(points+1,points+n,cmp);

    ///Now removing same angle point
    for(i=1;i<n;i++){
        while(i<n-1&&orientation(pivot,points[i],points[i+1])==0){
            i++;
        }
        points[++in] = points[i];
    }
    if(in<2) return 0;

    st.push(points[0]);
    st.push(points[1]);
    st.push(points[2]);
    for(i=3;i<=in;i++){
        ///only valid sequence is anti-clockwise
        while(orientation(nextToTop(st),st.top(),points[i])!=2){
            st.pop();
        }
        st.push(points[i]);
    }

    in = total = st.size();
    point tmp;
    /// storing convex points
    while(!st.empty()){
        tmp = st.top();
        st.pop();
        convex_points[--in] = tmp;
    }
    return 1;
}


///     *** Jarvis Algorithm/Convex-Hull [n*n]


#define ll long long
struct point{
    ll x,y;
}convex_points[MX],points[MX];;

/// global scope decraltion of min-left point of collcetion
point pivot;

///Distance calculation mathod
ll dist(point p1,point p2){
    return ((p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y));
}

double distd(point p1,point p2){
    return sqrt((p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y));
}

/**
*   https://www.geeksforgeeks.org/orientation-3-ordered-points/
*   calculating orientation based on slope (yi-yj)/(xi-xj)
*   by compering slope of p-q and q-r;
*   if p-q<q-r then counter-clockwise
*   @return 0 if colinear
*   @return 1 if clockwise (Right rotetion)
*   @return 2 if counter-clockwise (left rotetion)
*/
int orientation(point p,point q,point r){
    ll val = ((q.y-p.y)*(r.x-q.x) - (r.y-q.y)*(q.x-p.x));
    if(val==0) return 0;
    if(val>0) return 1;
    return 2;
}

/**
*   sorting by polor angle in counterclockwise order around point0.
*   If polor angle of two points is same, then put the nearest point first.
*/
bool cmp(point p1,point p2){
    ll o = orientation(pivot,p1,p2);
    if(o==0){
        return dist(pivot,p1) < dist(pivot,p2);
    }
    return (o==2);
}

/// returning previous value of top element
inline point nextToTop(stack<point>&st){
    point p,res;
    p = st.top();
    st.pop();
    res = st.top();
    st.push(p);
    return res;
}

int total;

/**
*   This function will calculate convexHull points
*   All arrays are in 0 based indexing
*   @param n total numbers of points
*/
double convexHull(int n)
{
	vector<point> hull;
	int l = 0;
	for (int i = 1; i < n; i++)
		if (points[i].x < points[l].x)
			l = i;
	int p = l, q;
	do
	{
		hull.push_back(points[p]);
		q = (p+1)%n;
		for (int i = 0; i < n; i++)
		{
            if (orientation(points[p], points[i], points[q]) == 2)
			q = i;
		}
		p = q;

	} while (p != l);

    double ans = distd(hull[0],hull[hull.size()-1]);

	for (int i = 0; i<hull.size()-1; i++){
        ans += distd(hull[i],hull[i+1]);
        //cout<<hull[i].x<<" "<<hull[i].y<<endl;
	}
	return ans;
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


