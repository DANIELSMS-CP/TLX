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

vector<vector<int>> grid(1500,vector<int>(1500));
string store="1";
vector<string> ans; 
void f(int r1,int c1,int r2,int c2)
{
    bool flag=0;
    for(int i=r1;i<=r2;i++)
    {
        for(int j=c1;j<=c2;j++)
        {
            if(grid[i][j]==0)
            {
                flag=1;
            }
        }
    }
    if(not flag)
    {
        ans.push_back(store);
        return;
    }
    else
    {
        if(r1==r2 and c1==c2)
        {
            return;
        }
        store.push_back('0');
        f(r1,c1,(r1+r2)/2,(c1+c2)/2);
        store.pop_back();
        store.push_back('2');
        f((r1+r2)/2+1,c1,r2,(c1+c2)/2);
        store.pop_back();
        store.push_back('1');
        f(r1,(c1+c2)/2+1,(r1+r2)/2,c2);
        store.pop_back();
        store.push_back('3');
        f((r1+r2)/2+1,(c1+c2)/2+1,r2,c2);
        store.pop_back();
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin >> n >> m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin >> grid[i][j];
        }
    }
    int x=1,y=1;
    for(int i=0;i<=10;i++)
    {
        if((1LL<<i)>=n)
        {
            x=(1LL<<i);
            break;
        }
    }
    for(int i=0;i<=10;i++)
    {
        if((1LL<<i)>=m)
        {
            y=(1LL<<i);
            break;
        }
    }
    f(1,1,max(x,y),max(x,y));
    sort(ans.begin(),ans.end());
    cout << sz(ans) << '\n';
    for(auto i:ans)
    {
        cout << i << '\n';
    }
    
    return 0;
}