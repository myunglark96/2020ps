#include <iostream>
using namespace std;

int dp[101][101][2];
int t, n, k;

int main() {
	scanf_s("%d", &t);
	dp[1][0][0]=1;
	dp[1][0][1]=1;
	for (int i=2;i<=100;i++) {
		for (int j=0;j<i;j++) {
			dp[i][j][0]=dp[i-1][j][0]+dp[i-1][j][1];
			dp[i][j][1]=(j?dp[i-1][j-1][1]:0)+dp[i-1][j][0];
		}
	}
	while (t--) {
		scanf_s("%d%d", &n, &k);
		cout<<dp[n][k][0]+dp[n][k][1]<<endl;
	}
	return 0;
}