#include <bits/stdc++.h>
using namespace std;
int main() {
	long long int n,a,b,c,curr=0;
	cin>>n;
	long long INF=LLONG_MAX;
	vector<vector<pair<long long,long long>>> graph(n+2);
	vector<long long> vis(n+2,0),dist(n+2,0);
	priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>> pq;
	pair<long long,long long> curr_node;
	for(int i=1;i<n;i++) {
		cin>>a>>b>>c;
		graph[i].push_back(make_pair(a,i+1));
		graph[i].push_back(make_pair(b,c));
		dist[i+1]=INF;
	}

	pq.push({0,1});
	dist[1]=0;

	while(!pq.empty()) {
		curr_node=pq.top();
		if(vis[curr_node.second]==1) {
			pq.pop();
			continue;
		}
		vis[curr_node.second]=1;
		curr=dist[curr_node.second];
		pq.pop();
		for(pair<long long,long long> val:graph[curr_node.second]) {
			if(vis[val.second]==0 && curr+val.first<dist[val.second]) {
				dist[val.second]=curr+val.first;
				pq.push({dist[val.second],val.second});
			}
		}
	}
	cout<<dist[n];
}