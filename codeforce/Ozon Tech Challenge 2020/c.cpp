#include <iostream>
using namespace std;

int n, m;
long long a[202020], mul;

int main() {
	scanf("%d%d", &n, &m);
	for (int i=1;i<=n;i++) {
		scanf("%lld", &a[i]);
	}
	if (n>1000) {
		cout<<0;
		return 0;
	}
	for (int i=1;i<n;i++) {
		for (int j=i+1;j<=n;j++) {
			if (i==1&&j==2) mul=abs(a[i]-a[j]);
			else mul=mul*abs(a[i]-a[j]);
			if (mul>m) mul=mul%m;
			if (mul==0) {
				cout<<0;
				return 0;
			}
		}
	}
	cout<<mul%m;
	return 0;
}