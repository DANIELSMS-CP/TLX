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

vector<int> gen(1005);
vector<bool> used(1005);
void generate(int depth,int n,int k)
{
    if(depth==k)
    {
        int flag=0;
        for(int i=1;i<k;i++)
        {
            if(gen[i]<gen[i-1])
            {
                flag=1;
            }
        }
        if(flag)
        {
            return;
        }
        for(int i=0;i<k;i++)
        {
            cout << gen[i] << ' ';
        }
        cout << '\n';
        return;
    }
    else
    {
        for(int i=1;i<=n;i++)
        {
            if(not used[i])
            {
                used[i]=1;
                gen[depth]=i;
                generate(depth+1,n,k);
                used[i]=0;
            }
        }
    }
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;
    cin >> n >> k;
    generate(0,n,k);
    
    return 0;
}