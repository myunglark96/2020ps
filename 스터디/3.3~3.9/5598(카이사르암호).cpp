#include <iostream>
using namespace std;

char str[1001];

int main() {
	cin>>str;
	for (int i=0;;i++) {
		if (str[i]=='\0') break;
		if (str[i]=='A'||str[i]=='B'||str[i]=='C') str[i]=str[i]+26;
		printf("%c", str[i]-3);
	}
	return 0;
}