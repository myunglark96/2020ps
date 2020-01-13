#include <iostream>
using namespace std;

int max_pri=0, max_index=0, item[100], seq[100], n, m;

int searchM() {
	int count=0, max_seq=n, min_seq=101, min_index=0;
	while (1) {
		for (int i=0; i<n; i++) {
			if (item[i]>max_pri) {
				max_pri=item[i];
				max_index=i;
			}
			else if (item[i]==max_pri&&seq[i]<seq[max_index]) {
				max_index=i;
			}
		}
		while (1) {
			for (int i=0; i<n; i++) {
				if (seq[i]<min_seq) {
					min_seq=seq[i];
					min_index=i;
				}
			}
			if (min_seq==seq[max_index]) break;
			seq[min_index]=max_seq++;
			min_seq=999999;
			min_index=0;
		}
		if (max_index==m) {
			for (int i=0; i<n; i++) {
				if (item[i]==0) {
					count++;
				}
			}
			break;
		}
		else {
			//printf("\n°ª: %d\n", item[max_index]);
			item[max_index]=0;
			max_pri=0;
		}
	}
	max_pri=0;
	max_index=0;
	return count+1;
}

int main() {
	int test_case;
	scanf_s("%d", &test_case);
	for (int i=0; i<test_case; i++) {
		scanf_s("%d%d", &n, &m);
		for (int j=0; j<n; j++) {
			scanf_s("%d", &item[j]);
			seq[j]=j;
		}
		printf("%d\n", searchM());
	}
	return 0;
}