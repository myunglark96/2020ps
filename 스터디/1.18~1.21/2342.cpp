#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int ret=9999999, dp[100010][5][5]{ 0, };
vector<int> order;

void dfs(int nowloc, int leftloc, int rightloc) {
	if (order[nowloc]==0) {
		ret=min(ret, dp[nowloc][leftloc][rightloc]);
		return;
	}
	//같은 발판 밟을때
	if (order[nowloc]==leftloc||order[nowloc]==rightloc&&dp[nowloc+1][leftloc][rightloc]<ret) {
		if (dp[nowloc+1][leftloc][rightloc]==0) {
			dp[nowloc+1][leftloc][rightloc]=dp[nowloc][leftloc][rightloc]+1;
			dfs(nowloc+1, leftloc, rightloc);
		}
		else {
			if (dp[nowloc+1][leftloc][rightloc]>dp[nowloc][leftloc][rightloc]+1) {
				dp[nowloc+1][leftloc][rightloc]=dp[nowloc][leftloc][rightloc]+1;
				dfs(nowloc+1, leftloc, rightloc);
			}
		}
	}
	//맨 처음 시작
	else if (leftloc==0&&rightloc==0) {
		dp[nowloc+1][order[nowloc]][rightloc]=dp[nowloc][leftloc][rightloc]+2;
		dfs(nowloc+1, order[nowloc], rightloc);
	}
	//왼쪽발 처음 (없어두댐)
	else if (leftloc==0) {
		if (dp[nowloc+1][order[nowloc]][rightloc]==0) {
			dp[nowloc+1][order[nowloc]][rightloc]=dp[nowloc][leftloc][rightloc]+2;
			dfs(nowloc+1, order[nowloc], rightloc);
		}
		else {
			if (dp[nowloc+1][order[nowloc]][rightloc]>dp[nowloc][leftloc][rightloc]+2) {
				dp[nowloc+1][order[nowloc]][rightloc]=min(dp[nowloc+1][order[nowloc]][rightloc], dp[nowloc][leftloc][rightloc]+2);
				dfs(nowloc+1, order[nowloc], rightloc);
			}
		}
		if (abs(order[nowloc]-rightloc)==2) {
			if (dp[nowloc+1][leftloc][order[nowloc]]==0) {
				dp[nowloc+1][leftloc][order[nowloc]]=dp[nowloc][leftloc][rightloc]+4;
				dfs(nowloc+1, leftloc, order[nowloc]);
			}
			else {
				dp[nowloc+1][leftloc][order[nowloc]]=min(dp[nowloc+1][leftloc][order[nowloc]], dp[nowloc][leftloc][rightloc]+4);
			}

		}
		else {
			if (dp[nowloc+1][leftloc][order[nowloc]]==0) {
				dp[nowloc+1][leftloc][order[nowloc]]=dp[nowloc][leftloc][rightloc]+3;
				dfs(nowloc+1, leftloc, order[nowloc]);
			}
			else {
				dp[nowloc+1][leftloc][order[nowloc]]=min(dp[nowloc+1][leftloc][order[nowloc]], dp[nowloc][leftloc][rightloc]+3);
			}
		}
	}
	//오른쪽발 처음
	else if (rightloc==0&&dp[nowloc+1][leftloc][order[nowloc]]<ret&&dp[nowloc+1][order[nowloc]][rightloc]<ret) {
		if (dp[nowloc+1][leftloc][order[nowloc]]==0) {
			dp[nowloc+1][leftloc][order[nowloc]]=dp[nowloc][leftloc][rightloc]+2;
			dfs(nowloc+1, leftloc, order[nowloc]);
		}
		else {
			if (dp[nowloc+1][leftloc][order[nowloc]]>dp[nowloc][leftloc][rightloc]+2) {
				dp[nowloc+1][leftloc][order[nowloc]]=min(dp[nowloc+1][leftloc][order[nowloc]], dp[nowloc][leftloc][rightloc]+2);
				dfs(nowloc+1, leftloc, order[nowloc]);
			}
		}
		if (abs(order[nowloc]-leftloc)==2) {
			if (dp[nowloc+1][order[nowloc]][rightloc]==0) {
				dp[nowloc+1][order[nowloc]][rightloc]=dp[nowloc][leftloc][rightloc]+4;
				dfs(nowloc+1, order[nowloc], rightloc);
			}
			else {
				if (dp[nowloc+1][order[nowloc]][rightloc]>dp[nowloc][leftloc][rightloc]+4) {
					dp[nowloc+1][order[nowloc]][rightloc]=min(dp[nowloc+1][order[nowloc]][rightloc], dp[nowloc][leftloc][rightloc]+4);
					dfs(nowloc+1, order[nowloc], rightloc);
				}
			}

		}
		else {
			if (dp[nowloc+1][order[nowloc]][rightloc]==0) {
				dp[nowloc+1][order[nowloc]][rightloc]=dp[nowloc][leftloc][rightloc]+3;
				dfs(nowloc+1, order[nowloc], rightloc);
			}
			else {
				if (dp[nowloc+1][order[nowloc]][rightloc]>dp[nowloc][leftloc][rightloc]+3) {
					dp[nowloc+1][order[nowloc]][rightloc]=min(dp[nowloc+1][order[nowloc]][rightloc], dp[nowloc][leftloc][rightloc]+3);
					dfs(nowloc+1, order[nowloc], rightloc);
				}
			}
		}
	}
	//계속 진행
	else if(dp[nowloc+1][leftloc][order[nowloc]]<ret&&dp[nowloc+1][order[nowloc]][rightloc]<ret) {
		//왼발로 진행
		if (abs(order[nowloc]-leftloc)==2) {
			if (dp[nowloc+1][order[nowloc]][rightloc]==0) {
				dp[nowloc+1][order[nowloc]][rightloc]=dp[nowloc][leftloc][rightloc]+4;
				dfs(nowloc+1, order[nowloc], rightloc);
			}
			else {
				if (dp[nowloc+1][order[nowloc]][rightloc]>dp[nowloc][leftloc][rightloc]+4) {
					dp[nowloc+1][order[nowloc]][rightloc]=min(dp[nowloc+1][order[nowloc]][rightloc], dp[nowloc][leftloc][rightloc]+4);
					dfs(nowloc+1, order[nowloc], rightloc);
				}
			}
		}
		else {
			if (dp[nowloc+1][order[nowloc]][rightloc]==0) {
				dp[nowloc+1][order[nowloc]][rightloc]=dp[nowloc][leftloc][rightloc]+3;
				dfs(nowloc+1, order[nowloc], rightloc);
			}
			else {
				if (dp[nowloc+1][order[nowloc]][rightloc]>dp[nowloc][leftloc][rightloc]+3) {
					dp[nowloc+1][order[nowloc]][rightloc]=min(dp[nowloc+1][order[nowloc]][rightloc], dp[nowloc][leftloc][rightloc]+3);
					dfs(nowloc+1, order[nowloc], rightloc);
				}
			}
		}
		//오른발로 진행
		if (abs(order[nowloc]-rightloc)==2) {
			if (dp[nowloc+1][leftloc][order[nowloc]]==0) {
				dp[nowloc+1][leftloc][order[nowloc]]=dp[nowloc][leftloc][rightloc]+4;
				dfs(nowloc+1, leftloc, order[nowloc]);
			}
			else {
				if (dp[nowloc+1][leftloc][order[nowloc]]>dp[nowloc][leftloc][rightloc]+4) {
					dp[nowloc+1][leftloc][order[nowloc]]=min(dp[nowloc+1][leftloc][order[nowloc]], dp[nowloc][leftloc][rightloc]+4);
					dfs(nowloc+1, leftloc, order[nowloc]);
				}
			}
			
		}
		else {
			if (dp[nowloc+1][leftloc][order[nowloc]]==0) {
				dp[nowloc+1][leftloc][order[nowloc]]=dp[nowloc][leftloc][rightloc]+3;
				dfs(nowloc+1, leftloc, order[nowloc]);
			}
			else {
				if (dp[nowloc+1][leftloc][order[nowloc]]>dp[nowloc][leftloc][rightloc]+3) {
					dp[nowloc+1][leftloc][order[nowloc]]=min(dp[nowloc+1][leftloc][order[nowloc]], dp[nowloc][leftloc][rightloc]+3);
					dfs(nowloc+1, leftloc, order[nowloc]);
				}
			}
		}
	}
}

int main() {
	int input=1;
	while (input) {
		scanf_s("%d", &input);
		order.push_back(input);
	}
	for (int i=0; i<5; i++) {
		for (int j=0; j<5; j++) {
			dp[order.size()-1][i][j]=999999;
		}
	}
	dfs(0, 0, 0);
	for (int i=0; i<5; i++) {
		for (int j=0; j<5; j++) {
			ret=min(ret, dp[order.size()-1][i][j]);
		}
	}
	if (order.size()==1) cout<<0<<endl;
	else cout<<ret<<endl;
	return 0;
}