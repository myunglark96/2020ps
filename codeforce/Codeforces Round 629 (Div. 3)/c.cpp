#include <iostream>
#include <string>
using namespace std;

int n, t;
char str[50501];
string a, b;
bool big;

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		cin>>str;
		for (int i=0;i<n;i++) {
			if (str[i]=='1'&&!big) {
				a.append("1");
				b.append("0");
				big=true;
			}
			else if (str[i]=='1'&&big) {
				a.append("0");
				b.append("1");
			}
			else if (str[i]=='2'&&!big) {
				a.append("1");
				b.append("1");
			}
			else if (str[i]=='2'&&big) {
				a.append("0");
				b.append("2");
			}
			else if (str[i]=='0') {
				a.append("0");
				b.append("0");
			}
		}
		cout<<a<<endl<<b<<endl;
		a="";
		b="";
		big=false;
	}
	return 0;
}