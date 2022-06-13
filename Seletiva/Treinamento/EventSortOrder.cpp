#include <bits/stdc++.h>
using namespace std;

constexpr int maxn = 3e3 + 10;
constexpr int mod = 1000000007;

int power(int b, int e) {
	int ans = 1;
	while(e) {
		if(e&1) ans = (int)(1ll * ans * b % mod);
		b = (int)(1ll * b * b % mod);
		e >>= 1;
	}
	return ans;
}

int dp[3*maxn][2];

void add(int& a, int b) { a += b; if(a >= mod) a -= mod; }

int choose2(int b) { return (int)((1ll * b * (b-1) / 2ll) % mod); }

void calc_s(int s, int l) {
	for(int i = 1 + (dp[1][0] == 1); i <= s; i++) {
		for(int j = 1; j <= s + 2*l; j++)
			add(dp[j+1][1], (int)(1ll * dp[j][0] * (j+1) % mod)), add(dp[j][1], (int)(1ll * dp[j][0] * j % mod));
		for(int j = 1; j <= s + 2*l; j++)
			dp[j][0] = dp[j][1], dp[j][1] = 0;
	}
}

void calc_l(int l) {
	dp[2][0] = 1;
	for(int i = 1; i < l; i++) {
		for(int j = 1; j <= 2*l; j++) {
			// coloco os dois em blocos anteriores
			add(dp[j][1], (int)(1ll * dp[j][0] * choose2(j) % mod));
			// coloco um em um bloco e outro fora
			add(dp[j+1][1], (int)(1ll * dp[j][0] * (2 * choose2(j+1)%mod) % mod));
			// coloco os dois fora
			add(dp[j+2][1], (int)(1ll * dp[j][0] * (choose2(j+1) + j+1) % mod));
		}
		for(int j = 1; j <= 2*l; j++)
			dp[j][0] = dp[j][1], dp[j][1] = 0;
	}
}

int main() {
	int l, s; scanf("%d %d", &l, &s);
	if(l) calc_l(l);
	else dp[1][0] = 1;
	calc_s(s, l);

	int ans = 0;
	for(int i = 1; i <= s + 2*l; i++)
		add(ans, dp[i][0]);
	printf("%d\n", ans);
}
