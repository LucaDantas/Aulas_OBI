// Implementação de DSU básica com path compression e small to large

constexpr int maxn = 2e5+10;

struct DSU {
	int peso[maxn], pai[maxn];
	DSU() { for(int i = 0; i < maxn; i++) peso[i] = 1, pai[i] = i; }
	int find(int x) { return pai[x] == x ? x : pai[x] = find(pai[x]); }
	void join(int a, int b) {
		a = find(a), b = find(b);
		if(a == b) return;
		if(peso[a] < peso[b])
			swap(a, b);
		pai[b] = a;
		peso[a] += peso[b];
	}
} dsu;

