#include <iostream>
using namespace std;
int main() {
    int n,s,m,l;
    cin>>n>>s>>m>>l;
    int ans=(int)1e8;
    for(int i=0;i*6<n+6;i++)for(int j=0;i*6+j*8<n+14;j++){
        int k=(n-i*6-j*8+11)/12;
        ans=min(ans,i*s+j*m+k*l);
    }
    cout<<ans;
}
