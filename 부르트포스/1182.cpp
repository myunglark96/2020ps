#include <iostream>
using namespace std;

int seq_count=0, n, s, flag, seq[20], sum=0;

int dfs(int start, int depth, int index) {
	sum=sum+start;
	if (sum<s) {
		
	}
	else if (sum>s) {

	}
	else {
		seq_count++;
	}
}

int main() {
	scanf_s("%d%d", &n, &s);
	for (int i=0; i<n; i++) {
		scanf_s("%d", &seq[i]);
	}

	//s가 음수인지 양수인지에 따라 음수와 양수가 나누어지는 index를 flag에 설정해줌
	if (s<0) {
		for (int i=0; i<n; i++) {
			if (seq[i]>0) {
				flag=i-1;
				break;
			}
		}
	}
	else {
		for (int i=0; i<n; i++) {
			if (seq[i]>0) {
				flag=i;
				break;
			}
		}
	}

	return 0;
}