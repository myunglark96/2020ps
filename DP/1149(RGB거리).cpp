#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
using namespace std;

//R==0,G==1,B==2 
int n, dp[1010][3], arr[1010][3];

int main() {
	scanf("%d", &n);
	for (int i=0;i<n;i++) {
		for (int j=0;j<3;j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	dp[0][0]=arr[0][0];
	dp[0][1]=arr[0][1];
	dp[0][2]=arr[0][2];
	for (int i=1;i<n;i++) {
		dp[i][0]=arr[i][0]+min(dp[i-1][1], dp[i-1][2]);
		dp[i][1]=arr[i][1]+min(dp[i-1][0], dp[i-1][2]);
		dp[i][2]=arr[i][2]+min(dp[i-1][1], dp[i-1][0]);
	}
	cout<<min({ dp[n-1][0], dp[n-1][1], dp[n-1][2] });
	return 0;
}