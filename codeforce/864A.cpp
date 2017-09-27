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
int cnt[107];
int main(){
    int n;
    cin>>n;
    memset(cnt,0,sizeof(cnt));
    vi arr;
    for(int i = 0;i<n;i++){
        int a;cin>>a;
        if(cnt[a]==0){
            arr.pb(a);
        }
        cnt[a]++;
    }
    if(arr.size()== 1 || arr.size()>2)cout<<"NO"<<endl;
    else if(arr.size()==2 && cnt[arr[0]]==cnt[arr[1]])printf("YES\n%d %d\n",arr[0],arr[1]);
    else cout<<"NO"<<endl;
}
