#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
using namespace std;

int t, n,arr[2][101010], dp[2][101010],sum;

int main() {
	scanf("%d", &t);
	while (t--){
		scanf("%d", &n);
		for (int i=0;i<2;i++) {
			for (int j=0;j<n;j++) {
				scanf("%d", &arr[i][j]);
			}
		}
		dp[0][0]=arr[0][0];
		dp[0][1]=arr[1][0]+arr[0][1];
		dp[1][0]=arr[1][0];
		dp[1][1]=arr[0][0]+arr[1][1];
		for (int i=2;i<n;i++) {
			dp[0][i]=max(dp[1][i-1], dp[1][i-2])+arr[0][i];
			dp[1][i]=max(dp[0][i-1], dp[0][i-2])+arr[1][i];
		}
		printf("%d\n", max(dp[0][n-1],dp[1][n-1]));
	}
	return 0;
}
