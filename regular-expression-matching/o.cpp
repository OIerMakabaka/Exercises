#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 32;

string s, p;

struct P {
	int c;
	bool flag;
};

P a[N];

int Pcnt;

int main() {

	// freopen("o.in", "r", stdin);
	// freopen("o.out", "w", stoudt);

	cin >> s;
	cin >> p;

	int Slen = s.length();
	int Plen = p.length();

	for (int i = 0; i < Plen; i ++) {
		
		if(p[i] == '*') continue;
		
		Pcnt ++;
		a[Pcnt].flag = bool(p[min(Plen - 1, i + 1)] == '*');

		if(p[i] == '.') 
			a[Pcnt].c = -1;
		else 
			a[Pcnt].c = p[i] - 'a' + 1;
	}

	


	return 0;
}