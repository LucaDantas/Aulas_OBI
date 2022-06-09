# Bosses

A solução é explorar mais path compression mas sem fazer small to large. O join é só criar normalmente a aresta como ele dá mas o find é um pouco diferente.
Eu quero salvar agora não só qual o meu pai mas também qual a minha distância pra ele. Inicialmente eu crio todas as ligações com distância 1, mas quando eu fizer o find eu faço a compressão e recalculo a minha distância pra esse novo pai.
Agora a parte principal que falta do problema é só tentar entender como implementar isso. Vou deixar para vocês tentarem ao invés de detalhar tudo aqui e caso tenham dificuldade vou deixar o código desse find também.
