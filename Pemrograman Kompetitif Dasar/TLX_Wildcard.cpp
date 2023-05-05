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


signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    int n;
    cin >> n;
    vector<string> a(n);
    int pos=0;
    for(int i=0;i<sz(s);i++)
    {
        if(s[i]=='*')
        {
            pos=i;
            break;
        }
    }
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    for(int i=0;i<n;i++)
    {
        if(sz(a[i])<sz(s)-1)
        {
            continue;
        }
        int found=1;
        int p=0;
        for(int j=0;j<pos;j++)
        {
            if(a[i][p]!=s[j])
            {
                found=0;
            }
            p++;
        }
        p=sz(a[i])-1;
        for(int j=sz(s)-1;j>pos;j--)
        {
            if(a[i][p]!=s[j])
            {
                found=0;
            }
            p--;
        }
        if(found)
        {
            cout << a[i] << '\n';
        }
    }
   
    return 0;
}
