#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int n, m, pack[51], piece[51],dp[51][101];

int buy(int p1,int p2) {
	if (p1*6+p2>=n) return 0;
	if (dp[p1][p2]!=-1) return dp[p1][p2];
	dp[p1][p2]=min(buy(p1+1, p2)+pack[0], buy(p1, p2+1)+piece[0]);
	return dp[p1][p2];
}

int main() {
	memset(dp, -1, sizeof(dp));
	scanf_s("%d%d", &n, &m);
	for (int i=0;i<m;i++) {
		scanf_s("%d%d", &pack[i], &piece[i]);
	}
	sort(pack, pack+m);
	sort(piece, piece+m);
	
	cout<<buy(0,0);
	return 0;
}