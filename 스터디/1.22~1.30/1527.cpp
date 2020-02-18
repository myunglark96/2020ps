#include <iostream>
using namespace std;

long long a, b, ans=0;

long long kms4(long long k) {
	return k*10+4;
}

long long kms7(long long k) {
	return k*10+7;
}

void dfs(long long k) {
	if (k>b) return;
	if (a<=k&&k<=b) ans++;
	dfs(kms4(k));
	dfs(kms7(k));

	return;
}

int main() {
	scanf_s("%d%d", &a, &b);
	dfs(4);
	dfs(7);
	cout<<ans<<endl;
	return 0;
}