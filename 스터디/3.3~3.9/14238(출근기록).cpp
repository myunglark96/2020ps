#include <iostream>
using namespace std;

string str, ans;
int na, nb, nc;
bool visited[51][51][51][3][3];

bool abc(int a, int b, int c, string s, int end1, int end2) {
	if (a==na&&b==nb&&c==nc) {
		ans=s;
		return true;
	}
	else if (a>na||b>nb||c>nc) return false;
	
	if (visited[a][b][c][end1][end2]) return false;
	visited[a][b][c][end1][end2]=true;

	if (a<na) {
		s+='A';
		if (abc(a+1, b, c, s, end2, 0)) return true;
		s.pop_back();
	}
	if (end2!=1&&b<nb) {
		s+='B';
		if (abc(a, b+1, c, s, end2, 1)) return true;
		s.pop_back();
	}
	if (end1!=2&&end2!=2&&c<nc) {
		s+='C';
		if (abc(a, b, c+1, s, end2, 2)) return true;
		s.pop_back();
	}

	return false;
}

int main() {
	cin>>str;
	for (int i=0;i<str.size();i++) {
		if (str[i]=='A') na++;
		else if (str[i]=='B') nb++;
		else if (str[i]=='C') nc++;
	}

	if (abc(0, 0, 0, "", 0,0)) cout<<ans;
	else cout<<-1;
	
	return 0;
}