#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

int ia,ib, ic,dp[101][101][101];

int w(int a, int b, int c) {
	if (dp[a+50][b+50][c+50]!=0) return dp[a+50][b+50][c+50];

	if (a<=0||b<=0||c<=0) dp[a+50][b+50][c+50]=1;
	else if (a>20||b>20||c>20) dp[a+50][b+50][c+50]=w(20, 20, 20);
	else if (a<b&&b<c) dp[a+50][b+50][c+50]=w(a, b, c-1)+w(a, b-1, c-1)-w(a, b-1, c);
	else dp[a+50][b+50][c+50]=w(a-1, b, c)+w(a-1, b-1, c)+w(a-1, b, c-1)-w(a-1, b-1, c-1);

	return dp[a+50][b+50][c+50];
}

int main() {
	while (1) {
		scanf("%d%d%d", &ia, &ib, &ic);
		if (ia==-1&&ib==-1&&ic==-1) return 0;
		printf("w(%d, %d, %d) = %d\n", ia, ib, ic, w(ia, ib, ic));
	}
	return 0;
}