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
    int n,k;
    cin >> n >> k;
    vector<string> grid(n);
    for(int i=0;i<n;i++)
    {
        cin >> grid[i];
    }
    while(true)
    {
        int flag=0;
        vector<int> idx;
        for(int i=0;i<n;i++)
        {
            int flag2=1;
            for(int j=0;j<k;j++)
            {
                if(grid[i][j]=='0')
                {
                    flag2=0;
                }
            }
            if(flag2)
            {
                flag=1;
                idx.push_back(i);
                for(int j=0;j<k;j++)
                {
                    grid[i][j]='0';
                }
            }
        }
        if(not flag)
        {
            break;
        }
        for(int i=idx.back()-1;i>=0;i--)
        {
            for(int j=0;j<k;j++)
            {
                if(grid[i][j]=='1')
                {
                    int temp=i;
                    while(temp+1<n and grid[temp+1][j]=='0')
                    {
                        swap(grid[temp][j],grid[temp+1][j]);
                        temp++;
                    }
                }
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<k;j++)
        {
            cout << grid[i][j];
        }
        cout << '\n';
    }
    
    return 0;
}