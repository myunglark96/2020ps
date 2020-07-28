#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
using namespace std;

int t, a, b, c, d,n;

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d%d%d%d",&n,&a, &b, &c, &d);
		if (n*(a+b)<c-d||n*(a-b)>c+d) cout<<"NO\n";
		else cout<<"YES\n";
	}
	return 0;
}