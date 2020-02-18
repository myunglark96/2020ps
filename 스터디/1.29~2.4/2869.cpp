#include <iostream>
using namespace std;

int main() {
	long long a, b, v, cnt=0, nowloc=0;
	scanf_s("%ld%ld%ld", &a, &b, &v);
	if((v-a)%(a-b)==0) printf("%ld", (v-a)/(a-b)+1);
	else printf("%ld", (v-a)/(a-b)+2);
	return 0;
}