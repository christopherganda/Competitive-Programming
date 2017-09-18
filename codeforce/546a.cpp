#include <bits/stdc++.h>
using namespace std;
int main(){
    long long int n,k,w;
    cin>>n>>k>>w;
    long long int cost  = w* (n + (n + (w-1)*n)) / 2;
    cout<<(cost-k >0?cost-k:0)<<endl;
}
