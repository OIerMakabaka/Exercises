class Solution {
public:
    bool isMatch(string s, string p) {
        
        const int N = 32;

        struct P {
            int c;
            bool flag;
        };
        P a[N];
        int Pcnt = 0;

        bool f[N][N]; // s中i与a中的第j位已匹配，最终结果应看f[Slen][Pcnt]

        int Slen = s.length();
        int Plen = p.length();

        for (int i = 0; i < Plen; i ++) {
            
            if(p[i] == '*') continue;
        
            a[Pcnt].flag = bool(p[min(Plen - 1, i + 1)] == '*');

            if(p[i] == '.') 
                a[Pcnt].c = -1;
            else 
                a[Pcnt].c = p[i];
            Pcnt ++;
        }

        memset(f, false, sizeof(f));

        f[0][0] = true;
        for (int i = 1; i <= Pcnt; i ++) {
            if (!a[i - 1].flag) break;
            f[0][i] = true;
        }


        for (int j = 1; j <= Pcnt; j ++) 
        for (int i = 1; i <= Slen; i ++) {
            
            if(f[i][j]) continue;
            
            if(a[j - 1].c == -1 || a[j - 1].c == s[i - 1]) {
                
                f[i][j] = (f[i - 1][j - 1] || (f[i - 1][j] && a[j - 1].flag));
                
                if(f[i][j]) {
                    
                    for(int k = j + 1; k <= Pcnt; k ++) {
                        if(!a[k - 1].flag) break;
                        f[i][k] = true;
                    }
                }	
            }
        }

        return f[Slen][Pcnt];
    }
};