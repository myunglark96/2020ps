#include <iostream>
using namespace std;

int main() {
	int k=1, s[50], lotto[6];
	while (k!=0) {
		scanf_s("%d", &k);
		for (int i=0; i<k; i++) {
			scanf_s("%d", &s[i]);
		}

		printf("\n");
		for (int a=0; a<k; a++) {
			lotto[0]=s[a];
			for (int b=a+1; b<k; b++) {
				lotto[1]=s[b];
				for (int c=b+1; c<k; c++) {
					lotto[2]=s[c];
					for (int d=c+1; d<k; d++) {
						lotto[3]=s[d];
						for (int e=d+1; e<k; e++) {
							lotto[4]=s[e];
							for (int f=e+1; f<k; f++) {
								lotto[5]=s[e];
								for (int i=0; i<6; i++) {
									printf("%d ", lotto[i]);
								}
								printf("\n");
							}
						}
					}
				}
			}
		}
	}

	return 0;
}