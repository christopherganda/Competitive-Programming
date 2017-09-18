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

int main(){
    #ifdef chris
    freopen(freinput);
    freopen(freoutput);
    #endif // chris
    int tc;
    cin>>tc;
    for(int i = 0;i<tc;i++){
        long long c;
        string n;

        vector<long long> a;
        getchar();
        getchar();
        getline(cin,n);
        istringstream iss(n);
        while(iss>>c){
            a.push_back(c);
        }
        pair<long long,string> d;
        vector<pair<long long,string> > b;
        for(long long j = 0;j<a.size();j++){
            string kata;
            cin>>kata;
            d = make_pair(a[j],kata);
            b.push_back(d);
        }
        sort(b.begin(),b.end());
        for(long long j = 0;j<a.size();j++){
            if((a.size()==1 && i==tc-1) || (a.size()!=1 && i==tc-1 && j==a.size()-1))cout<<b[j].second;
            else cout<<b[j].second<<endl;
        }
        cout<<endl;
    }
}
