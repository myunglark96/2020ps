#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#pragma warning (disable:4996)
using namespace std;

string pali;
 
int main() {
	cin>>pali;
	int cnt=0, total=0;
	for (int i=0;i<pali.size();i++) {
		for (int j=i+1;j<pali.size();j++) {
			if (pali[i]==pali[j]) cnt++;
			else {
				if (cnt!=0 && cnt%2==1) {
					pali=pali.substr(0, i+1)+pali.substr(j, pali.size()-j);
					total=total+cnt;
					cnt=0;
				}
				else if (cnt!=0&&cnt%2==0) {
					i=j;
					cnt=0;
				}
				break;
			}
		}
		if (cnt!=0 && cnt%2==1) {
			pali=pali.substr(0, i+1);
			total=total+cnt;
			i=1001;
		}
		else if (cnt!=0&&cnt%2==0) {
			cnt=0;
			i=1001;
		}
	}
	int ans=pali.size()-1, halfpali=pali.size()/2;
	for (int i=pali.size()-1;i>=halfpali;i--) {
		for (int j=1;j<=halfpali;j++) {
			if (i+j<=pali.size()-1) {
				if (pali[i+j]!=pali[i-j]) break;
				if (i+j==pali.size()-1) ans=min((int)pali.size()-j*2-1, ans);
			}
		}
	}
	cout<<pali.size()+ans+total;
	return 0;
}

/*
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define FUP(i, a, b) for(int i = a; i <= b; i++)
#define FDOWN(i, a, b) for(int i = a; i >= b; i--)
#define MS(a, b) memset(a, b, sizeof(a))
#define ALL(v) v.begin(), v.end()
#define ENDL '\n'
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);

   string S;
   cin >> S;
   int L = S.length();
   for(int len=L;len<=2*L;len++)
   {
	  bool OK = true;
	  for(int i=len/2; i<=L-1;i++)
	  {
		 if (S[i] != S[len - i - 1])
		 {
			OK = false;
			break;
		 }
	  }
	  if (OK)
	  {
		 cout << len;
		 return 0;
	  }
   }

   return 0;
}
*/