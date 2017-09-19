#include <bits/stdc++.h>
using namespace std;
#define freinput "input.txt","r",stdin
#define freoutput "output.txt","w",stdout
#define mp make_pair
#define fi first
#define sc second
#define pb push_back
#define max_N 1125
#define max_K 20
#define max_Prime 200 //1 to 1120 has 188 prime numbers.
#define ellapse printf("Time : %0.3lf\n",clock()*1.0/CLOCKS_PER_SEC);
typedef long long ll;
typedef unsigned long int uld;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int,int> pii;
bool arr[max_N];
int dp[max_N][max_K][max_Prime];
void sieve(){
    for(int i = 2;i*i<=1120;i++){
        if(arr[i]==1){
            for(int j = i*2;j<=1120;j+=i)arr[j]=0;
        }
    }
}
int ks(int n, int k, int i){
    cout<<n<<" "<<k<<" "<<i<<" "<<dp[n][k][i]<<endl;
    if(n>0 && k==0)return 0;
    if(i>n)return 0;
    if(n==0 && k==0)return 1;
    if(arr[i]==0)return ks(n,k,i+1);
    if(dp[n][k][i]!=-1)return dp[n][k][i];
    return dp[n][k][i] = ks(n-arr[i],k-1,i+1) + ks(n,k,i+1);
}
int main(){
//    #ifdef chris
//    freopen(freinput);
//    freopen(freoutput);
//    #endif // chris
    memset(arr,true,sizeof(arr));
    sieve();
    int n,k;
    while(scanf("%d %d",&n,&k),(n||k)){
        memset(dp,-1,sizeof(dp));
        int hasil =0;
        hasil+=ks(n,k,0);
        cout<<hasil<<endl;
    }
}

