#include <iostream>
#include <algorithm>
using namespace std;

int ops(int a) { return a==2 ? 1 : 2; }
int t, w, jadu[1010], dp[31][3][1010];

int dfs(int nowloc, int switchtree, int depth) {
	if (depth==t) { 
		return 0;
	}
	if (dp[switchtree][nowloc][depth]) return dp[switchtree][nowloc][depth];
	
	if (switchtree<w) {
		if (nowloc==jadu[depth]) {
			dp[switchtree][nowloc][depth]=max(dfs(nowloc, switchtree, depth+1), dfs(ops(nowloc), switchtree+1, depth+1))+1;
			return dp[switchtree][nowloc][depth];
		}
		else if (nowloc==0) {
			dp[0][0][0]=max(dfs(1, 0, 0), dfs(2, 1, 0));
			return dp[0][0][0];
		}
		else {
			dp[switchtree][nowloc][depth]=max(dfs(nowloc, switchtree, depth+1), dfs(ops(nowloc), switchtree+1, depth+1));
			return dp[switchtree][nowloc][depth];
		}
	}
	else {
		if (nowloc==jadu[depth]) {
			dp[switchtree][nowloc][depth]=dfs(nowloc, switchtree, depth+1)+1;
			return dp[switchtree][nowloc][depth];
		}
		else {
			dp[switchtree][nowloc][depth]=dfs(nowloc, switchtree, depth+1);
			return dp[switchtree][nowloc][depth];
		}
	}
}
int main() {
	scanf_s("%d%d", &t, &w);
	for (int i=0; i<t; i++) {
		scanf_s("%d", &jadu[i]);
	}
	printf("%d", dfs(0, 0, 0));
	return 0;
}