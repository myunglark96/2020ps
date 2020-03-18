#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool visited[31][31][31][450],ans;
char abc[31];
int N, K;

bool finds(int n, int a, int b, int k) {
	if (n==N&&k==K) {
		return true;
	}
	else if (n==N&&k!=K) return false;

	if (visited[n][a][b][k]) return false;
	visited[n][a][b][k]=true;

	abc[n]='A';
	if (finds(n+1, a+1, b, k)) return true;
	abc[n]='B';
	if (finds(n+1, a, b+1, k+a)) return true;
	abc[n]='C';
	if (finds(n+1, a, b, k+a+b)) return true;

	return false;
}

int main()
{
	scanf_s("%d%d", &N, &K);
	if (finds(0, 0, 0, 0)) printf("%s", abc);
	else printf("%d",-1);
	return 0;
}