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

bool f[N][N]; // s中i与a中的第j位已匹配，最终结果应看f[Slen][Pcnt]

int main() {

	// freopen("o.in", "r", stdin);
	// freopen("o.out", "w", stoudt);

	cin >> s;
	cin >> p;

	int Slen = s.length();
	int Plen = p.length();

	for (int i = 0; i < Plen; i ++) {
		
		if(p[i] == '*') continue;
	
		a[Pcnt].flag = bool(p[min(Plen - 1, i + 1)] == '*');

		if(p[i] == '.') 
			a[Pcnt].c = -1;
		else 
			a[Pcnt].c = p[i] - 'a';
		Pcnt ++;
	}

	cout << Slen << ' ' << Pcnt << endl;

	if(a[0].c == -1 || a[0].c == s[0] - 'a') {
		
		f[0][0] = true;
		if(a[0].flag) {
			for (int i = 1; i < Slen; i ++)
				if(a[0].c == -1 || a[0].c == s[i] - 'a')
					f[i][0] = true;
		}
	}

	for (int j = 1; j <= Pcnt; j ++) {
		for (int i = 1; i < Slen; i ++) {
			if(f[i][j]) continue;
			if(a[j].c == -1 || a[j].c == s[i]) {
				
				// if(f[i - 1][j])
				// for (int k = j - 1; k >= 0; k --)
					
				f[i][j] = (f[i - 1][j - 1] || (f[i - 1][j] && a[j].flag));
				
			}
		}
	}

	cout << (int)f[Slen - 1][Pcnt - 1] << endl;

	return 0;
}