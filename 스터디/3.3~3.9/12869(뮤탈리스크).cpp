#include <iostream>
#include <algorithm>
using namespace std;

int n, hp[4], dp[65][65][65];

int atk(int a, int b, int c) {
	if (a<=0&&b<=0&&c<=0) return 0;
	if (a<0) a=0;
	if (b<0) b=0;
	if (c<0) c=0;
	if (dp[a][b][c]!=0) return dp[a][b][c];
	return dp[a][b][c]=min({ atk(a-9, b-3, c-1)+1, atk(a-9, c-3, b-1)+1,atk(b-9, a-3, c-1)+1, atk(b-9, c-3, a-1)+1,atk(c-9, b-3, a-1)+1, atk(c-9, a-3, b-1)+1});
}

int main() {
	scanf_s("%d", &n);
	for (int i=0;i<n;i++) {
		scanf_s("%d", &hp[i]);
	}
	int ans=atk(hp[0],hp[1],hp[2]);
	cout<<ans;
	return 0;
}