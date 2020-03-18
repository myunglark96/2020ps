#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

string str1, str2;
int dp[1001][1001];

int solve(int flag1, int flag2) {
	if (flag1==str1.size()||flag2==str2.size()) {
		return 0;
	}

	if (dp[flag1][flag2]!=-1) return dp[flag1][flag2];

	if (str1[flag1]==str2[flag2]) {
		return dp[flag1][flag2]=max({ solve(flag1+1,flag2+1)+1, solve(flag1+1, flag2), solve(flag1,flag2+1) });
	}
	else {
		return dp[flag1][flag2]=max({ solve(flag1+1, flag2), solve(flag1,flag2+1) });
	}

}

int main() {
	cin>>str1>>str2;
	memset(dp, -1, sizeof(dp));
	cout<<solve(0,0);
	return 0;
}