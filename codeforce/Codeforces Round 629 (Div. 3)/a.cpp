#include <iostream>
using namespace std;

long long t, a, b;

int main() {
	int div;
	scanf("%d", &t);
	while (t--) {
		scanf("%lld%lld", &a, &b);
		if (a<b) {
			cout<<b-a<<endl;
		}
		else if(a==b||a%b==0){
			cout<<0<<endl;
		}
		else if (a>b) {
			div=a/b;
			cout<<b*(div+1)-a<<endl;
		}
	}
	return 0;
}