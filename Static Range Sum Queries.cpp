#include <bits/stdc++.h>

#define ll long long int
#define pii pair<int, int>
#define pll pair<ll, ll>
#define rep(b) for(ll i = 0; i<b; i++)
#define repn(a, b) for(ll b = 0; i<a; i++)
#define LSOne(S) (S & -(S))
#define mem(a, b) memset(a, b, sizeof(a))
#define MAXN 200010

using namespace std;

// Using BIT.

ll ft[MAXN], n;

void update(ll j, ll val){
    for(; j<=n; j+=LSOne(j)){
        ft[j] += val;
    }
}

ll rmq(ll j){
    ll sum = 0;
    for(; j; j-=LSOne(j)){
        sum += ft[j];
    }
    return sum;
}

ll rmq(ll a, ll b){
    return rmq(b) - rmq(a-1);
}

void solve(){
    ll q, a, b; cin>>n>>q;
    rep(n){
        cin>>a;
        update(i+1, a);
    }
    rep(q){
        cin>>a>>b;
        cout<<rmq(a, b)<<'\n';
    }
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll t = 1;
    //cin>>t;
    while(t--){
        solve();
    }
}