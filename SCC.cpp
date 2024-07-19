//Bharti Nema
#include <bits/stdc++.h>
using namespace std;
vector<vector<long long>> vc,reverse_vc;
vector<long long> vis;
stack<long long> stk;
void dfs(int);
void dfs1(int);
int main() {
	long long int n,inp,top,count=0;
	cin>>n;
	vc.resize(n+1);
	reverse_vc.resize(n+1);
	vis.resize(n+1,0);
	for(int i=1;i<=n;i++) {
		cin>>inp;
		if(i!=inp)
		vc[i].push_back(inp);
	}

	for(int i=1;i<=n;i++) {
		if(vis[i]==0) {
			vis[i]=1;
			dfs(i);
			stk.push(i);
		}
	}

	for(int i=1;i<=n;i++) {
		if(vc[i].size()>0)
		reverse_vc[vc[i][0]].push_back(i);
	}

	vis.clear();
	vis.resize(n+1,0);
	top=stk.top();
	while(!stk.empty()) {
		top=stk.top();
		stk.pop();
		if(vis[top]==0) {
			vis[top]=1;
			count+=1;
			dfs1(top);
		}
	}

	cout<<count;

}

void dfs(int node) {
	//cout<<node<<endl;
	for(auto &x: vc[node]) {
		if(vis[x]==0) {
			vis[x]=1;
			dfs(x);
	        stk.push(x);
		}
	}
}

void dfs1(int node) {
	//cout<<node<<endl;
	for(auto &x: reverse_vc[node]) {
		if(vis[x]==0) {
			vis[x]=1;
			dfs1(x);
		}
	}
}