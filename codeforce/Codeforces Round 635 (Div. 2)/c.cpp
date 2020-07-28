#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

vector<int> pathv[202020], ans;
int n, k, parent[202020];

void fillp(int par, int depth, int state) {
	for (int i=0;i<pathv[state].size();i++) {
		if (pathv[state][i]!=par) {
			fillp(state, depth+1, pathv[state][i]);
			parent[state]+=parent[pathv[state][i]];
		}
	}
	ans.push_back(depth-parent[state]);
	parent[state]++;
}

int main() {
	int u, v;
	long long sum=0;
	scanf_s("%d%d", &n, &k);
	for (int i=0;i<n-1;i++) {
		scanf_s("%d%d", &u, &v);
		pathv[u].push_back(v);
		pathv[v].push_back(u);
	}
	fillp(0, 0, 1);
	sort(ans.begin(), ans.end(), greater<int>());
	for (int i=0;i<k;i++) {
		sum=sum+ans[i];
	}
	cout<<sum;
	return 0;
}