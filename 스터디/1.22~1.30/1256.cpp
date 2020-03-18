#include <iostream>
using namespace std;

int n, m, flaga, flagz;
long long k;
string s, INF;
bool ans;

void chanstr(string& str, int a, int b) {
	if (a<b&&a<str.size()&&b<str.size()) {
		char tmp=str[a];
		str[a]=str[b];
		str[b]=tmp;
		flaga++;
		flagz--;
	}
}

void movez(int d) {
	if (d<m) { ans=true; return; }
	if (s==INF) { ans=false; return; }

	if (d/m>m) {
		chanstr(s, flaga, flagz);
		movez(d/m);
	}
	else {
		chanstr(s, flagz, flagz);
	}

	return;
}

int main() {
	scanf_s("%d%d%lld", &n, &m, &k);
	for (int i=0; i<n; i++) {
		s=s+'a';
	}
	for (int i=0; i<m; i++) {
		s=s+'z';
	}
	for (int i=0; i<m; i++) {
		INF=INF+'z';
	}
	for (int i=0; i<n; i++) {
		INF=INF+'a';
	}
	flaga=0;
	flagz=n;
	movez(k);
	if (ans) cout<<s<<endl<<INF;
	else cout<<-1;
	return 0;
}