#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

int n;
long long s[101010], e[101010], ans[101010];
int main() {
	scanf("%d", &n);
	for (int i=0;i<n;i++) {
		scanf("%lld%lld", &s[i], &e[i]);
	}

	for (int i=0;i<n;i++) {
		for (int j=0;j<n;j++) {
			if (s[i]>s[j]&&s[i]<e[j]) ans[i]++;
		}
	}

	for (int i=0;i<n;i++) cout<<ans[i]<<endl;
	return 0;
}