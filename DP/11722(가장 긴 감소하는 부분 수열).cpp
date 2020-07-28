#include <iostream>
#include <algorithm>
using namespace std;

int arr[1010],n,dp[1010];

int main() {
	int ans=0;
	cin>>n;
	for (int i=0;i<n;i++) {
		cin>>arr[i];
	}
	for (int i=0;i<n;i++) {
		dp[i]=1;
		for (int j=0;j<=i;j++) {
			if (arr[i]<arr[j]&&dp[i]<dp[j]+1) {
				dp[i]=dp[j]+1;
			}
		}
	}

	for (int i=0;i<n;i++) {
		ans=max(ans, dp[i]);
	}
	cout<<ans;
	return 0;
}