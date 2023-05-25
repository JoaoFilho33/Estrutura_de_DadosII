/*Dia 19.05.2023
Atividade Morris IN-ORDER (Percurso In Order – LVR):

       10
       / \
      5   20
     /\   /\
    3  7 15 24

A) Qual o resultado do percurso In-Order (LVR) na árvore?
-Percurso in-ordem: 3 5 7 10 15 20 24

B) Explique quais os passos realizados pelo algoritmo de Morris – Percurso inORDER:
-
.Inicializa um ponteiro "p" que aponta para a raiz da árvore;
.Enquanto "p" não for nulo, faça:
	.Verifique se o nó atual p possui um filho esquerdo;
		.Se não, 
			"visit(p)", faz o que for necessário e vá para p->dir;
		.Se sim, 
			encontre o nó mais à direita na subárvore esquerda do nó "p"(nó predecessor);
			
			.Verifique se "predecessor" possui ponteiro direito já definido;
			.Se não, 
				faça apontar para nó "p" a aponte para o nó esq, p->esq;
			.Se sim,
				os nós da subarvore esquerda ja foram visitados, em seguida
				"visit(p)" e faz o que for necessário; remova o ponteiro  direito do predecessor, e o anule. Em seguida atualize o 	ponteiro "p" para p->dir;
				
C) Aplique a árvore no algoritmo e confira se o resultado está correto.
-
.Inicializa "p = 10";
.O nó "p" tem um filho esquerdo, então busca-se o nó mais a direita na subarvore esquerda do nó "p", "p = 7";
	.Como ele não tem um ponteiro direito definido, definimos então ele aponta para  		a raiz. E atualizamos p para o nó esquerdo, "p = 5";
.O nó atual tem um filho esq, então busca-se o nó mais a direita na subarvore esquerda do nó "p", que é p = 3;
	.Ele não tem um ponteiro direito definido, logo definimos para ele apontar para o 		5, e atualizamos "p" para o nó esq, p = 3;
.O nó atual não tem um filho esq. Logo, visita-se o nó 3, e atualizamos "p" para o nó direito(p = 5);
.O nó atual "p" não tem um filho esq. Logo, visita-se o nó 5 e atualizamos "p" para o nó direito (p = 7);
.O nó atual "p" não tem um filho esq. Logo,visita-se o nó 7 e atualizamos "p" para o nó direito (p=10);
.O nó atual "p" não tem um filho esq. Logo,visita-se o nó 10 e atualizamos "p" para o nó direito (p=20);
.O nó atual "p" tem um filho esq. Então encontramos o nó mais a direita na subarvore esq do nó "p". Que é o "15".
	.15 não tem um ponteiro definido, logo, definimos o ponteiro direito do nó "15" para "p" (15->20) e atualizamos "p" para o nó esquerdo (p=15).
				
.O nó atual "p" não tem um filho esq. Logo, visita-se o nó 15 e atualizamos "p" para o nó direito (p = 20);
.O nó atual "p" não tem um filho esq. Logo, visitamos o nó 20 e atualizamos "p" para o nó direito (p = 24)
.O nó atual "p" não tem um filho esq. Logo, visitamos o nó 24 e atualizamos "p" para o nó direito (p = nullptr)

-
Então "p" se torna nulo, e isso significa que percorremos todos os nós da árvore in-ordem.
Resultando na saída expressada na letra a).

*/






