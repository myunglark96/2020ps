#include <iostream>
#include <cmath>
#pragma warning (disable:4996)
using namespace std;

int t, x1, x2, y11, y2, r1, r2;
double comp;

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d%d%d%d%d", &x1, &y11, &r1, &x2, &y2, &r2);
		if (x1==x2&&y11==y2&&r1==r2) cout<<-1<<endl;
		else if (x1==x2&&y11==y2) cout<<0<<endl;
		else {
			comp=sqrt(pow(abs(x1-x2), 2)+pow(abs(y11-y2), 2));
			if (comp>r1+r2) {
				cout<<0<<endl;
			}
			else if (comp==r1+r2) {
				cout<<1<<endl;
			}
			else if(comp+r1==r2||comp+r2==r1) {
				cout<<1<<endl;
			}
			else if (comp+r2<r1||comp+r1<r2) {
				cout<<0<<endl;
			}
			else if (comp<r1+r2) {
				cout<<2<<endl;
			}
		}
	}
	return 0;
}