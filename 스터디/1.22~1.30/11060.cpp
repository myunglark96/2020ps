#include <iostream>
#include <algorithm>
using namespace std;

int n, miro[1010], ans=99999999, dp[1010];

void dfs(int start, int jump) {
	if (start+miro[start]>=n-1) {
		ans=min(ans, jump+1);
		return;
	}
	dp[start]=jump;
	for (int i=1; i<=miro[start]; i++) {
		if(ans>jump+1&&dp[start+i]>jump+1) dfs(start+i, jump+1);
	}
	return;
}

int main() {
	scanf_s("%d", &n);
	for (int i=0; i<n; i++) {
		scanf_s("%d", &miro[i]);
		dp[i]=999999;
	}
	dfs(0, 0);

	if (n==1) cout<<0<<endl;
	else if (ans!=99999999) cout<<ans<<endl;
	else cout<<-1<<endl;
	return 0;
}