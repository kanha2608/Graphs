// Karya ko arrambh karo to uska ant krne par hi viraam lo
// Anyatha karya hi tumhara Ant kar dega.  ~Guru Brishpati

#pragma GCC optimize("O3")
#pragma GCC target("sse4")
#include<bits/stdc++.h>
#include<vector>
#include<string>
#include<deque>
#include<set>
#include<stack>

// Some type Def
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<vector<int>> VVI;
typedef vector<int> VI;
typedef vector<string> VS;
#define PB push_back
#define MP make_pair
#define ff first
#define ss second
#define two(w) (1<<(w))
#define test(x,w) (x&two(w))
#define sz(v) (int)v.size()
#define all(c) c.begin(),c.end() 
#define clr(buf,val) memset(buf,val,sizeof(buf))
#define rep(i,l,r) for(int i=(l); i<(r) ; i++)
#define repv(i,v)  for(int i=0;i<(int)v.size();i++)
#define repi(it,c) for(typeof(c.begin()) it=c.begin();it!=c.end();++it)
#define inf INT_MAX
#define nl "\n"
#define debug(v)  for(int i = 0 ; i < v.size() ; i++){cout<<v[i]<<" ";} cout<<"\n";
#define inparr(arr,n) int arr[n] ; for(int i = 0 ; i < n ; i++){cin>>arr[i];}

bool sortbysec(const pair<int,int> &a, const pair<int,int> &b){
    return a.ss < b.ss;
}

void dvpii(vector<PII> v){
    rep(i , 0 , v.size()) cout<<i+1<<" "<<v[i].ff<<" "<<v[i].ss<<nl;
}
int  gcd(int a, int b){
    if(a == 0)  return b;
    return gcd(b%a , a);
}

bool isprime(int n){
    if(n == 2 || n == 3)
        return true;
    if(n % 2  == 0 || n% 3 == 0)
        return false;
    int i = 5;
    while(i * i <= n){
        if(n% (i ) == 0 || n%(i+2) == 0)
            return false;
        i += 6;
    }
    return true;
}
long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
void canonical(int n , vector<int>& ans){
    for(int i = 2; i*i <= n ; i++){
        int cnt= 0;
        while(n%i == 0){
            cnt++;
            n /= i;
        }
        if(cnt > 0){
            ans.PB(i);
        }
    }
    if(n > 1 ) ans.PB(n);
}
int divisors(int a){
    int cnt = 1;
    for(int i = 2; i <= sqrt(a) ; i++){
        if(a%i == 0){
            if(a/i ==i) cnt++;
            else cnt += 2;
        }
    }
    return cnt;
}

// VI adj[100001] , vis(100001) , in(100001);

int dx[8] = {-2, -1, 1 , 2 , 2, 1, -1, -2};
int dy[8] = {1, 2, 2, 1 , -1 ,-2, -2, -1};
int dis[9][9] , vis[9][9];
int sx, sy , ex ,ey , n;
bool isvalid(int x , int y){
    if(x < 1 || x > 8 || y < 1 || y > 8 || vis[x][y])   return false;
    return true;
}
void bfs(int x ,int y){
    vis[x][y] = 1;
    dis[x][y] = 0;
    queue<PII> q;
    q.push({x,y});
    while(!q.empty()){
        x = q.front().ff;
        y = q.front().ss;
        q.pop();
        for(int i = 0 ; i < 8 ; i++){
            if(isvalid(x + dx[i] , y + dy[i])){
                int nx = x + dx[i] ;
                int ny = y + dy[i];
                dis[nx][ny] = dis[x][y] + 1;
                vis[nx][ny] =1;
                q.push({nx, ny});
            }
        }
    }
    cout<<dis[ex][ey]<<nl;
}
void solve(){
    for(int i = 0 ; i<= 8 ; i++){
        for(int j = 0 ; j <= 8 ; j++){
            dis[i][j] = vis[i][j] = 0;
        }
    }
    string s ,e;
    cin>>s>>e;
    if(s == e){
        cout<<0<<nl;
        return;
    }
    sx = s[0] - 'a'  +1;
    sy = s[1] -'0';
    ex = e[0] - 'a'  +1;
    ey = e[1] -'0';
    bfs(sx ,sy);
}
int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    solve();   
}
