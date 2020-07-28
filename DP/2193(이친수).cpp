#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
using namespace std;

long long pinary[91][2], n;

int main() {
	scanf("%d", &n);
	pinary[1][1]=1;
	pinary[2][0]=1;
	for (int i=3;i<=n;i++) {
		pinary[i][0]=pinary[i-1][0]+pinary[i-1][1];
		pinary[i][1]=pinary[i-1][0];
	}

	cout<<pinary[n][0]+pinary[n][1];
	return 0;
}