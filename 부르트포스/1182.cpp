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

	//s�� �������� ��������� ���� ������ ����� ���������� index�� flag�� ��������
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