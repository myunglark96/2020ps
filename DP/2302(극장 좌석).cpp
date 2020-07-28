#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

int n, m,dp[45],ans=1,lastfixed=0,fixseet;

int main() {
	dp[0]=1,dp[1]=1, dp[2]=2;
	for (int i=3;i<=40;i++) {
		dp[i]=dp[i-1]+dp[i-2];
	}
	scanf("%d%d", &n, &m);
	for (int i=0;i<m;i++) {
		scanf("%d", &fixseet);
		ans=ans*dp[fixseet-lastfixed-1];
		lastfixed=fixseet;
	}
	ans=ans*dp[n-lastfixed];
	cout<<ans;
	return 0;
}