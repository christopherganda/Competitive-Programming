#include <bits/stdc++.h>
using namespace std;
#define freinput "input.txt","r",stdin
#define freoutput "output.txt","w",stdout
#define mp make_pair
#define fi first
#define sc second
#define ellapse printf("Time : %0.3lf\n",clock()*1.0/CLOCKS_PER_SEC);
typedef long long ll;
typedef unsigned long int uld;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int,int> pii;
int main(){
//    #ifdef chris
//    freopen(freinput);
//    freopen(freoutput);
//    #endif // chris
    int a;
    while(cin>>a && a!=0){
        double b,c,d;
        cin>>b>>c>>d;
        d = d / 100 * b;
        double hasil = 0;
        int day = 0;
        while(hasil>=0 && hasil< a){
            if(b>0)hasil += (b);
            day++;
            if(hasil>a)break;
            hasil-=c;
            b = b-d;
        }
        if(hasil<0)cout<<"failure on day "<<day<<endl;
        else{
            cout<<"success on day "<<day<<endl;
        }
    }
}
