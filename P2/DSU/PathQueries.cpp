#include <bits/stdc++.h>
using namespace std;

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
	int sz(int a) { return peso[find(a)]; }
} dsu;

struct Edge {
	int a, b, w;
	bool operator<(const Edge& o) { return w < o.w; }
} edges[maxn];

struct Query {
	int id, val;
	bool operator<(const Query& o) { return val < o.val; }
} queries[maxn];

long long ans_query[maxn];

int main() {
	int n, q; scanf("%d %d", &n, &q);
	
	for(int i = 0; i < n-1; i++) {
		int a, b, w; scanf("%d %d %d", &a, &b, &w);
		edges[i] = {a, b, w};
	}

	for(int i = 0; i < q; i++) {
		int val; scanf("%d", &val);
		queries[i] = {i, val};
	}

	// ordeno as arestas e queries pelo peso, vou responder offline
	sort(edges, edges+n-1);
	sort(queries, queries+q);

	// faço um two pointers pra ir respondendo as queries
	long long ans_now = 0;
	for(int i = 0, ptr = 0; i < q; i++) {
		for(; ptr < n-1 && edges[ptr].w <= queries[i].val; ptr++) {
			ans_now += 1ll * dsu.sz(edges[ptr].a) * dsu.sz(edges[ptr].b);
			dsu.join(edges[ptr].a, edges[ptr].b);
		}
		ans_query[queries[i].id] = ans_now;
	}

	for(int i = 0; i < q; i++)
		printf("%lld ", ans_query[i]);
	puts("");
}
