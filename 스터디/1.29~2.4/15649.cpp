#include <iostream>
using namespace std;

int n, m, visited[10], arr[10];

void printans(int depth) {
	if (depth==m) {
		for (int i=0; i<m; i++) {
			cout<<arr[i]<<" ";
		}
		printf("\n");
	}

	for (int i=1; i<=n; i++) {
		if (!visited[i]) {
			arr[depth]=i;
			visited[i]=1;
			printans(depth+1);
			visited[i]=0;
		}
	}
	return ;
}

int main() {
	scanf_s("%d%d", &n, &m);
	printans(0);
	return 0;
}