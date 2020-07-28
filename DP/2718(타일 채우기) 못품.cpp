#include <iostream>
using namespace std;

int t, n,dp[1010];

int main() {
	dp[1]=1;
	dp[2]=5;
	dp[3]=11;
	for (int i=4;i<1000;i++) {
		if(i%2==1) dp[i]=dp[i-1]+dp[i-2]*4+dp[i-3]*2;
		else dp[i]=dp[i-1]+dp[i-2]*4+dp[i-3]*2;
	}
	cin>>t;
	while (t--){
		cin>>n;
		if (n%2==0) {

		}
		else {

		}
	}
	return 0;
}