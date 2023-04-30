#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

//defines
#define int long long
#define debug(x) cerr << "(" << #x << "=" << x << "," << __LINE__ << ")\n";
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)
#define rep(i,a,b) for(int i=a;i<(b);i++)

//constants
const int dx[4]{1, 0, -1, 0}, dy[4]{0, 1, 0, -1}; 
const char dir[4]{'D','R','U','L'};
const int mod=1e9+7;
const int maxn=2e5+5;
const double eps=1e-9;

//typedefs
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

//Template
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

//Mods
int mul(int a,int b,int MOD)
{
    return ((a%MOD)*(b%MOD))%MOD;
}
int add(int a,int b,int MOD)
{
    return (a+b)%MOD;
}
int sub(int a,int b,int MOD)
{
    return (MOD+a-b)%MOD;
}

int n,m;
vector<vector<bool>> vis(100,vector<bool>(100));
vector<vector<int>> grid(100,vector<int>(100));
int cnt;
void dfs(int x,int y)
{
    cnt++;
    vis[x][y]=1;    
    for(int i=0;i<4;i++)
    {
        if(x+dx[i]>=0 and x+dx[i]<n and y+dy[i]>=0 and y+dy[i]<m and not vis[x+dx[i]][y+dy[i]] and grid[x][y]==grid[x+dx[i]][y+dy[i]])
        {
            dfs(x+dx[i],y+dy[i]);
        }
    }
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin >> grid[i][j];
        }
    }
    int x,y;
    cin >> x >> y;
    dfs(x,y);
    cout << cnt*(cnt-1) << '\n';
    
    return 0;
}