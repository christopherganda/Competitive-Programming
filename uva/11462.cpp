#include <bits/stdc++.h>
using namespace std;
#define freinput "input.txt","r",stdin
#define freoutput "output.txt","w",stdout
#define mp make_pair
#define fi first
#define sc second
#define pb push_back
#define ellapse printf("Time : %0.3lf\n",clock()*1.0/CLOCKS_PER_SEC);
typedef long long ll;
typedef unsigned long int uld;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int,int> pii;
struct comp {
       bool operator() (int a,int b) {
            return a>b;
       }
};

int main(){
    #ifdef chris
    freopen(freinput);
    freopen(freoutput);
    #endif // chris
    ios::sync_with_stdio(false);
    ll n;
    cin>>n;
    vector<ll> v;
    for(ll i = 0;i<n;i++){
        ll a;
        cin>>a;
        v.pb(a);
    }
    sort(v.begin,v.end,operator);
}
