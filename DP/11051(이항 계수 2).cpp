#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

long long bino[1001][1001];

int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i=1;i<=n;i++) {
		for (int j=0;j<=i;j++) {
			if (i==j||j==0) bino[i][j]=1;
			else if(j==1) bino[i][j]=i;
			else {
				bino[i][j]=(bino[i-1][j-1]+bino[i-1][j])%10007;
			}
		}
	}
	cout<<bino[n][k];
	return 0;
}