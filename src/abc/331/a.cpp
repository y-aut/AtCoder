#include <iostream>
using namespace std;
int main() {
    int M,D,y,m,d;
    cin>>M>>D>>y>>m>>d;
    if(++d>D)d=1,m++;
    if(m>M)m=1,y++;
    cout<<y<<" "<<m<<" "<<d<<endl;
}
