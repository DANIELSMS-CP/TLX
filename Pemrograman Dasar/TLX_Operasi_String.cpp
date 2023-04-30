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
    string s,s2,s3,s4;
    cin >> s >> s2 >> s3 >> s4;
    s=s.erase(s.find(s2),s2.length());
    int pos=s.find(s3);
    for(int i=0;i<pos;i++)
    {
        cout << s[i];
    }
    cout << s3;
    cout << s4;
    for(int i=pos+s3.size();i<s.size();i++)
    {
        cout << s[i];
    }
    
    return 0;
}