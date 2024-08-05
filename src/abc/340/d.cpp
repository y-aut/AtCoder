#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N,A[2<<17],B[2<<17],X[2<<17];
long dist[2<<17];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>N;
	for(int i=0;i<N-1;i++){
		cin>>A[i]>>B[i]>>X[i];
		X[i]--;
	}
	for(int i=0;i<N;i++)dist[i]=(long)1e18;
	priority_queue<pair<long,long>,vector<pair<long,long>>,greater<pair<long,long>>>q;
	q.emplace(dist[0]=0,0);
	while(!q.empty()){
		auto [d,v]=q.top();
		q.pop();
		if(dist[v]<d)continue;
		if(v==N-1)continue;
		if(dist[v+1]>dist[v]+A[v]){
			q.emplace(dist[v+1]=dist[v]+A[v],v+1);
		}
		if(dist[X[v]]>dist[v]+B[v]){
			q.emplace(dist[X[v]]=dist[v]+B[v],X[v]);
		}
	}
	cout<<dist[N-1]<<endl;
}
