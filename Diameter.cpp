//Bharti Nema
#include<bits/stdc++.h>
using namespace std;
vector<vector<pair<int,int>>> vc;
vector<int> vis;
long long int temp[3];
long long int ans=0;
vector<vector<long long>> answers;
long long int dfs(int);
int main() {
	int n,a,b,c;
	long long int sum=0;
	cin>>n;
	//vector<pair<int,int>> vc[n+1];
	vc.clear();
	vc.resize(n+1);
    vis.resize(n+1,0);
    answers.resize(n+1,vector<long long>(2,0));
	for(int i=0;i<n-1;i++) {
		cin>>a>>b>>c;
		sum+=c;
		vc[a].push_back({b,c});
		vc[b].push_back({a,c});
	}
	vis[1]=1;
	dfs(1);
	if(ans==sum)
	cout<<sum;
	else
	cout<<ans+2*(sum-ans);
}

long long int dfs(int node) {
	if(vc[node].size()==1 && vis[vc[node][0].first]==1)
		return 0;
	long long int value=-1,returned;
	for(auto &x:vc[node]) {
		if(vis[x.first]==0) {
			vis[x.first]=1;
			returned=x.second+dfs(x.first);
			temp[0]=returned;
			temp[1]=answers[node][0];
			temp[2]=answers[node][1];
			sort(temp,temp+3);
			answers[node][0]=temp[1];
			answers[node][1]=temp[2];
			if(answers[node][0]+answers[node][1]>ans)
				ans=answers[node][0]+answers[node][1];
			value=max(value,returned);
		}
	}

	return value;
}