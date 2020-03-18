#include <iostream>
#include <algorithm>
using namespace std;

int n, t[1500001], p[1500001], dp[1500001];

int sangdam(int d) {
	if (d>=n) return 0;
	if (dp[d]!=-1) return dp[d];

	if (d+t[d]<=n) return dp[d]=max(sangdam(d+1), sangdam(d+t[d])+p[d]);
	else return dp[d]=sangdam(d+1);
}

int main() {
	scanf_s("%d", &n);
	memset(dp, -1, sizeof(dp));
	for (int i=0;i<n;i++) {
		scanf_s("%d%d", &t[i], &p[i]);
	}

	cout<<sangdam(0);
	return 0;
}