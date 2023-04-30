#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

//defines
#define int long long
#define debug(x) cerr << "(" << #x << "=" << x << "," << __LINE__ << ")\n";
#define sz(x) ((int)x.size());
#define all(x) (x).begin(),(x).end();

//constants
const int dx[4]{1, 0, -1, 0}, dy[4]{0, 1, 0, -1}; 
const char dir[4]{'D','R','U','L'};
const int mod=1e9+7;
const int maxn=2e5+5;
const double eps=1e-9;

//typedefs
typedef vector<vector<int>> vii;
typedef vector<int> vi;
typedef pair<int,int> pii;

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
    int n;
    cin >> n;
    vector<int> a(n),b(n);
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    for(int i=0;i<n;i++)
    {
        cin >> b[i];
    }
    int q;
    cin >> q;
    while(q--)
    {
        char c,c2;
        int x,y;
        cin >> c >> x >> c2 >> y;
        x--,y--;
        if(c=='B' and c2=='A')
        {
            swap(a[y],b[x]);
        }
        else if(c=='A' and c2=='B')
        {
            swap(a[x],b[y]);
        }        
        else if(c=='A' and c2=='A')
        {
            swap(a[x],a[y]);
        }
        else
        {
            swap(b[x],b[y]);
        }
    }
    for(auto i:a)
    {
        cout << i << ' ';
    }
    cout << '\n';
    for(auto i:b)
    {
        cout << i << ' ';
    }
    cout << '\n';
    
    return 0;
}