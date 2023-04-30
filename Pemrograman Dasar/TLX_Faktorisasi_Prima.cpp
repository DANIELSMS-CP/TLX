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

vector<int> primes;
vector<bool> flag(2000005,1);
void sieve()
{
    for(int i=2;i<=2000000;i++)
    {
        if(flag[i])
        {
            primes.push_back(i);
            for(int j=2*i;j<=2000000;j+=i)
            {
                flag[j]=0;
            }
        }
    }
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    sieve();
    int n;
    cin >> n;
    map<int,int> mp;
    for(int i=0;i<primes.size();i++)
    {
        while(n%primes[i]==0)
        {
            mp[primes[i]]++;
            n/=primes[i];
        }
    }
    int f=0;
    for(auto [key,val]:mp)
    {
        if(mp[key]>0)
        {
            if(f==0)
            {
                f++;
            }
            else
            {
                cout << "x ";
            }
            if(mp[key]==1)
            {
                cout << key << ' ';
            }
            else
            {
                cout << key << "^" << val << ' ';
            }
        }
    }
    
    return 0;
}