#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<long long> all, eall;

int n,sbig,ebig;
long long s[101010], e[101010], ans[101010];
int main() {
	scanf("%d", &n);
	for (int i=0;i<n;i++) {
		scanf("%lld%lld", &s[i], &e[i]);
		all.push_back(s[i]);
		eall.push_back(e[i]);
	}
	sort(all.begin(), all.end());
	sort(eall.begin(), eall.end());
	for (int i=0;i<n;i++) {
		if (s[i]>all[i]) sbig++;
		if (s[i]>eall[i]) ebig++;
	}
	for (int i=0;i<n;i++) {
		ans[i]=sbig[i]-ebig[i];
	}

	for (int i=0;i<n;i++) cout<<ans[i]<<endl;
	return 0;
}