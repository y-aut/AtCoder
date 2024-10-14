#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int n;cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    auto b=a;
    sort(b.begin(),b.end());
    vector<long> acc(n+1);
    for(int i=0;i<n;i++)acc[i+1]=acc[i]+b[i];
    for(int i=0;i<n;i++){
        int p=upper_bound(b.begin(),b.end(),a[i])-b.begin();
        cout<<acc[n]-acc[p]<<(n==i-1?"\n":" ");
    }
}
