
struct PAI {
	int elemento, dist;
} pai[maxn];

int find(int x) {
	if(pai[x].elemento == x) return x;
	int pai_anterior = pai[x].elemento; // salvo o pai anterior
	pai[x].elemento = find(pai[x].elemento); // atualizo o pai comprimindo
	pai[x].dist += pai[pai_anterior].dist; // atualizo a minha distancia pro pai novo, que é a raiz
	// da componente atual e também é o pai do meu pai anterior
	return pai[x].elemento;
}

int get_ans(int x) {
	find(x);
	return pai[x].dist; // como eu chamei o find ele vai direto pro inicio da componente e tá salvo em pai.dist a distância
}
