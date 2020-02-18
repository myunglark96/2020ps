#include <iostream>
#include <algorithm>
using namespace std;

int board[3], maxans=0, minans=999999, maxdp[2][3], mindp[2][3];

int main() {
	int n;
	scanf_s("%d", &n);
	for (int i=0; i<n; i++) {
		for (int j=0; j<3; j++) {
			scanf_s("%d",&board[j]);
		}
		if (i==0) {
			maxdp[0][0]=board[0];
			maxdp[0][1]=board[1];
			maxdp[0][2]=board[2];

			mindp[0][0]=board[0];
			mindp[0][1]=board[1];
			mindp[0][2]=board[2];
		}
		else {
			//left
			if (maxdp[0][0]>maxdp[0][1]) {
				maxdp[1][0]=board[0]+maxdp[0][0];
			}
			else {
				maxdp[1][0]=board[0]+maxdp[0][1];
			}
			//center
			if (maxdp[0][0]>=maxdp[0][1]&&maxdp[0][0]>=maxdp[0][2]) {
				maxdp[1][1]=board[1]+maxdp[0][0];
			}
			else if (maxdp[0][1]>=maxdp[0][0]&&maxdp[0][1]>=maxdp[0][2]) {
				maxdp[1][1]=board[1]+maxdp[0][1];
			}
			else {
				maxdp[1][1]=board[1]+maxdp[0][2];
			}
			//right
			if (maxdp[0][2]>maxdp[0][1]) {
				maxdp[1][2]=board[2]+maxdp[0][2];
			}
			else {
				maxdp[1][2]=board[2]+maxdp[0][1];
			}

			maxdp[0][0]=maxdp[1][0];
			maxdp[0][1]=maxdp[1][1];
			maxdp[0][2]=maxdp[1][2];

			//left
			if (mindp[0][0]<mindp[0][1]) {
				mindp[1][0]=board[0]+mindp[0][0];
			}
			else {
				mindp[1][0]=board[0]+mindp[0][1];
			}
			//center
			if (mindp[0][0]<=mindp[0][1]&&mindp[0][0]<=mindp[0][2]) {
				mindp[1][1]=board[1]+mindp[0][0];
			}
			else if (mindp[0][1]<=mindp[0][0]&&mindp[0][1]<=mindp[0][2]) {
				mindp[1][1]=board[1]+mindp[0][1];
			}
			else {
				mindp[1][1]=board[1]+mindp[0][2];
			}
			//right
			if (mindp[0][2]<mindp[0][1]) {
				mindp[1][2]=board[2]+mindp[0][2];
			}
			else {
				mindp[1][2]=board[2]+mindp[0][1];
			}
			mindp[0][0]=mindp[1][0];
			mindp[0][1]=mindp[1][1];
			mindp[0][2]=mindp[1][2];
		}
	}

	for (int i=0; i<3; i++) {
		maxans=max(maxdp[0][i], maxans);
		minans=min(mindp[0][i], minans);
	}
	cout<<maxans<<" "<<minans;
	return 0;
}