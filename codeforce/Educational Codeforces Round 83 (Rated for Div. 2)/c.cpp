#include <iostream>
#include <cstring>
using namespace std;

int t, n, k;
long long arr[31], v[31];
bool use[100];

bool findnum(long long num, int depth) {
	//if (num==1&&!use[depth]) return true;
	if (num%k==0) {
		return findnum(num/k, depth+1);
	}
	else if (num%k==1) {
		if (num==1) {
			if (use[depth]) return false;
			else {
				use[depth]=true;
				return true;
			}
		}
		if (!use[depth]) {
			use[depth]=true;
			return findnum((num-1)/k, depth+1);
		}
		else return false;
	}
	else {
		return false;
	}
}

int main() {
	scanf("%d", &t);
	for (int i=0;i<t;i++) {
		memset(use, false, sizeof(use));
		bool ans=true;
		int cnt=1;
		scanf("%d%d", &n, &k);
		for (int j=0;j<n;j++) {
			scanf("%lld", &arr[j]);
			if (arr[j]==1&&cnt==0) ans=false;
			else if (arr[j]==1&&cnt==1) cnt--;
			if (ans&&arr[j]!=0&&!findnum(arr[j], 0)) ans=false;

		}
		if (ans) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}