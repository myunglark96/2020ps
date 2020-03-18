#include <iostream>
using namespace std;

int t, n, m;

int main() {
	scanf_s("%d", &t);
	for (int i=0;i<t;i++) {
		scanf_s("%d%d", &n, &m);
		if (n%m==0) cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}