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

int hasil;

int main(){
    #ifdef chris
    freopen(freinput);
    freopen(freoutput);
    #endif // chris
    int tc;
    cin>>tc;
    for(int i = 0;i<tc;i++){
        int m,n;
        getchar();
        getchar();
        cin>>m>>n;
        string arr;
        pair<pair<int,int>,string> p;
        vector<pair<pair<int,int>,string> > v;
        for(int j = 0;j<n;j++){
            cin>>arr;
            p = make_pair(make_pair(0,j),arr);
            v.push_back(p);
        }
        for(int j = 0;j<n;j++){
            arr = v[j].second;
            hasil = 0;
            for(int k = 0;k<m-1;k++){
                for(int l = k+1;l<m;l++){
                    if(arr[k]>arr[l])hasil++;
                }
            }
            v[j].first.first = hasil;
        }
        sort(v.begin(),v.end());
        for(int j = 0;j<n;j++){
            cout<<v[j].second<<endl;
        }
        if(i!=tc-1)cout<<endl;
    }
}
