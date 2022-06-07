// Implementação de DSU básica com rollback
// Usa small to large mas não usa path compression

// É possível codar o rollback de um jeito mais compacto
// porém assim é mais intuitivo e menos susceptível a erros

constexpr int maxn = 2e5+10;

struct DSU {
	struct Rollback { int a, b, peso_a, peso_b; };
	int peso[maxn], pai[maxn];

	vector<Rollback> rb;

	DSU() { for(int i = 0; i < maxn; i++) peso[i] = 1, pai[i] = i; }
	
	int find(int x) { return pai[x] == x ? x : find(pai[x]); }
	void join(int a, int b) {
		a = find(a), b = find(b);
		if(a == b) return;
		
		if(peso[a] < peso[b])
			swap(a, b);
		
		rb.push_back({a, b, peso[a], peso[b]});

		pai[b] = a;
		peso[a] += peso[b];
	}

	void rollback() {
		assert(rb.size());
		Rollback now = rb.back();
		rb.pop_back();

		peso[now.a] = now.peso_a;
		peso[now.b] = now.peso_b;
		pai[now.a] = now.a;
		pai[now.b] = now.b;
	}
} dsu;


// Maneira compacta de codar o rollback
// só salvo 'a' e 'b' no rollback e desfaço as operações assim

struct DSU {
	struct Rollback { int a, b; };
	int peso[maxn], pai[maxn];

	vector<Rollback> rb;

	DSU() { for(int i = 0; i < maxn; i++) peso[i] = 1, pai[i] = i; }
	
	int find(int x) { return pai[x] == x ? x : find(pai[x]); }
	void join(int a, int b) {
		a = find(a), b = find(b);
		if(a == b) return;
		
		if(peso[a] < peso[b])
			swap(a, b);
		
		// é importante salvar o rollback depois de fazer o swap do peso
		rb.push_back({a, b});

		pai[b] = a;
		peso[a] += peso[b];
	}

	void rollback() {
		assert(rb.size());
		int a = rb.back().a, b = rb.back().b;
		rb.pop_back();

		pai[b] = b;
		peso[a] -= peso[b];
	}
} dsu;
