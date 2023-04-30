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

int n;
vector<string> a;
vector<vector<int>> grid(500,vector<int>(500));
int r,c;
void create()
{
    for(int i=0;i<sz(a);i++)
    {
        int r1=1,c1=1,r2=r,c2=c;
        for(int j=1;j<sz(a[i]);j++)
        {
            if(a[i][j]=='0')
            {
                r2=(r1+r2)/2;
                c2=(c1+c2)/2;
            }
            else if(a[i][j]=='2')
            {
                r1=(r1+r2)/2+1;
                c2=(c1+c2)/2;
            }
            else if(a[i][j]=='1')
            {
                r2=(r1+r2)/2;
                c1=(c1+c2)/2+1;
            }
            else
            {
                r1=(r1+r2)/2+1;
                c1=(c1+c2)/2+1;
            }
        }
        for(int i=r1;i<=r2;i++)
        {
            for(int j=c1;j<=c2;j++)
            {
                grid[i][j]=1;
            }
        }
    }
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i=0;i<n;i++)
    {
        string s;
        cin >> s;
        a.push_back(s);
    }
    cin >> r >> c;
    int original_r=r,original_c=c;
    int pw2x=1,pw2y=1;
    for(int i=0;i<15;i++)
    {
        if((1LL<<i)>=r)
        {
            pw2x=(1LL<<i);
            break;
        }
    }
    for(int i=0;i<15;i++)
    {
        if((1LL<<i)>=c)
        {
            pw2y=(1LL<<i);
            break;
        }
    }
    r=max(pw2x,pw2y);
    c=max(pw2x,pw2y);
    create();
    for(int i=1;i<=original_r;i++)
    {
        for(int j=1;j<=original_c;j++)
        {
            cout << grid[i][j] << ' ';
        }
        cout << '\n';
    }
    
    return 0;
}