#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
using namespace std;

int n, score[301], stairs[301][2];
int main() {
	scanf("%d", &n);
	for (int i=1;i<=n;i++) {
		scanf("%d", &score[i]);
	}

	stairs[1][0]=score[1];
	stairs[2][0]=score[1]+score[2];
	stairs[2][1]=score[2];
	for (int i=3;i<=n;i++) {
		stairs[i][0]=score[i]+stairs[i-1][1];
		stairs[i][1]=score[i]+max(stairs[i-2][0], stairs[i-2][1]);
	}

	cout<<max(stairs[n][1], stairs[n][0]);
	return 0;
}
