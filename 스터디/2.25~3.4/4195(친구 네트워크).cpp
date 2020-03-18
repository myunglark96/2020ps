#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int t, f,p[202020],frinum[202020];
char u[21], v[21];
map<string, int> fl;

int findp(int u) {
	if (u==p[u]) return u;
	else {
		return p[u]=findp(p[u]);
	}
}

int Uni(int a, int b) {
	a=findp(a);
	b=findp(b);
	if (a!=b) {
		p[b]=a;
		frinum[a]+=frinum[b];
	}
	return frinum[a];
}

int main() {
	scanf_s("%d", &t);
	for (int i=0; i<t; i++) {
		scanf_s("%d", &f);
		for (int j=0;j<f; j++) {
			scanf_s("%s %s", &u, &v);
			if (fl.count(u)==0) {
				fl[u]=fl.size();
				p[fl[u]]=fl[u];
				frinum[fl[u]]=1;
			} 
			if (fl.count(v)==0) {
				fl[v]=fl.size();
				p[fl[v]]=fl[v];
				frinum[fl[v]]=1;
			} 
			printf("%d\n", Uni(fl[u], fl[v]));
		}
		fl.clear();
	}
	return 0;
}