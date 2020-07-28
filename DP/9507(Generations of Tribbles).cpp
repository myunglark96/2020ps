#include <iostream>
using namespace std;

long long dp[71];
int t, n;


int main() {
	dp[0]=1;
	dp[1]=1;
	dp[2]=2;
	dp[3]=4;
	for (int i=4;i<70;i++) {
		dp[i]=dp[i-4]+dp[i-3]+dp[i-2]+dp[i-1];
	}
	cin>>t;
	while (t--) {
		cin>>n;
		cout<<dp[n]<<endl;
	}
	return 0;
}