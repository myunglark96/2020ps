#include <iostream>
#include <algorithm>
using namespace std;

int n, leftdeck[2010], rightdeck[2010], ans, visited[2010][2010];

int dfs(int l, int r) {
	if (visited[l][r]!=-1) return visited[l][r];
	if (l==n||r==n) {
		return 0;
	}
	else {
		if (leftdeck[l]>rightdeck[r]) {
			visited[l][r]=dfs(l, r+1)+rightdeck[r];
			return visited[l][r];
		}
		else {
			visited[l][r]= max(dfs(l+1, r), dfs(l+1, r+1));
			return visited[l][r];
		}
	}
}

int main() {
	int lflag=0, rflag=0;
	scanf_s("%d", &n);
	for (int i=0; i<n; i++) {
		scanf_s("%d", &leftdeck[i]);
	}
	for (int i=0; i<n; i++) {
		scanf_s("%d", &rightdeck[i]);
	}
	for (int i=0; i<=n; i++) {
		for (int j=0; j<=n; j++) {
			visited[i][j]=-1;
		}
	}
	cout<<dfs(0, 0)<<endl;
	return 0;
}