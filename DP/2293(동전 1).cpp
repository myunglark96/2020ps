#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
using namespace std;

int n, dong[101],k,dp[10101];

int main() {
	scanf("%d%d", &n,&k);
	for (int i=0;i<n;i++) {
		scanf("%d", &dong[i]);
	}
	sort(dong, dong+n);
	dp[0]=1;
	for (int i=0;i<n;i++) {
		for (int j=dong[i];j<=k;j++) {
			dp[j]+=dp[j-dong[i]];
		}
	}
	cout<<dp[k];
	return 0;
}