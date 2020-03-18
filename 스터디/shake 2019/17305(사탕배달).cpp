#include <iostream>
#include <algorithm>
using namespace std;

int n, w, smallc[252020], bigc[252020], sflag, bflag;
long long dp[1250001],s,t;
bool visited[1250001];
int ss=0,bs=0;

long long trip(int s, int b, int sf, int bf) {
	if (3*s+5*b>=w||s>=ss||b>=bs) return 0;
	if (dp[3*s+5*b]!=0) return dp[3*s+5*b];

	if (3*(s+1)+5*b<=w&&3*s+5*(b+1)<=w) {
		dp[3*s+5*b]=max(trip(s+1, b, sf+1, bf)+smallc[sf], trip(s, b+1, sf, bf+1)+bigc[bf]);
		//return dp[3*s+5*b];
	}
	else if (3*(s+1)+5*b<=w) {
		dp[3*s+5*b]=max(trip(s+1, b, sf+1, bf)+smallc[sf], dp[3*s+5*b]);
		//return dp[3*s+5*b];
	}
	/*
	else if (3*s+5*(b+1)<=w) {
		dp[3*s+5*b]=max(dp[3*s+5*b], trip(s, b+1, sf, bf+1)+bigc[bf]);
		//return dp[3*s+5*b];
	}
	*/
	return dp[3*s+5*b];
}

int main() {
	scanf_s("%d%d", &n, &w);
	for (int i=0;i<n;i++) {
		scanf_s("%lld%lld", &t, &s);
		if (t==3) {
			smallc[ss++]=s;
		}
		if (t==5) {
			bigc[bs++]=s;
		}
	}
	sort(smallc, smallc+ss,greater<int>());
	sort(bigc, bigc+bs, greater<int>());
	cout<<trip(0, 0, 0, 0)<<"\n";
	return 0;
}