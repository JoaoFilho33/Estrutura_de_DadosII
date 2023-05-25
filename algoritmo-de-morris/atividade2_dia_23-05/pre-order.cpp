/*
/*Dia 19.05.2023
Atividade Morris IN-ORDER (Percurso In Order – LVR):

       10
       / \
      5   20
     /\   /\
    3  7 15 24

A) Qual o resultado do percurso In-Order (LVR) na árvore?
Percurso pré-ordem: 10 5 3 7 20 15 24

B) Explique quais os passos realizados pelo algoritmo de Morris – Percurso PRE-ORDER:
-
Os próximos passos são bem semelhantes ao in-order.

.Inicializa um ponteiro "p" que aponta para a raiz da árvore.
.Enquanto "p" não for nulo, faça:
    .Verifique se o nó atual "p" possui um filho esquerdo.
    .Se não possuir,
                    visite o nó "p" e vá para o nó direito, ou seja, atualize "p" para p->dir.
    .Se possuir um filho esquerdo:
        .Encontre o nó mais à direita na subárvore esquerda do nó "p" (nó predecessor).
        .Verifique se o predecessor possui um ponteiro direito já definido.
            .Se não possuir, faça o ponteiro direito do predecessor apontar
                para o nó "p" (predecessor->dir = p) e visite o nó "p".
                Em seguida, atualize "p" para o nó esquerdo, ou seja, p = p->esq.
            .Se possuir, os nós da subárvore esquerda já foram visitados.
                Visite o nó "p" e remova o ponteiro direito do predecessor,
                ou seja, predecessor->dir = nullptr. Em seguida, atualize "p" para o nó direito, ou seja, p = p->dir.


C) Aplique a árvore no algoritmo e confira se o resultado está correto.
-
.Inicializa "p" como 10.
.O nó atual "p" tem um filho esquerdo, então buscamos o nó mais à direita na subárvore esquerda de "p", que é 7.
	.Como o nó 7 não tem um ponteiro direito definido, definimos o ponteiro direito do nó 7 para apontar para "p" (7 -> 10) e visitamos o nó 10. Em seguida, atualizamos "p" para o nó esquerdo, ou seja, p = 5.
.O nó atual "p" tem um filho esquerdo, então buscamos o nó mais à direita na subárvore esquerda de "p", que é 3.
	.Como o nó 3 não tem um ponteiro direito definido, definimos o ponteiro direito do 	nó 3 para apontar para "p" (3 -> 5) e visitamos o nó 5. Em seguida, atualizamos "p" para o nó esquerdo, ou seja, p = 3.
.O nó atual "p" não tem um filho esquerdo. Portanto, visitamos o nó 3 e atualizamos "p" para o nó direito, ou seja, p = 5.
.O nó atual "p" não tem um filho esquerdo. Portanto, visitamos o nó 5 e atualizamos "p" para o nó direito, ou seja, p = 7.
.O nó atual "p" não tem um filho esquerdo. Portanto, visitamos o nó 7 e atualizamos "p" para o nó direito, ou seja, p = 10.
.O nó atual "p" não tem um filho esquerdo. Portanto, visitamos o nó 10 e atualizamos "p" para o nó direito, ou seja, p = 20.
.O nó atual "p" tem um filho esquerdo. Portanto, buscamos o nó mais à direita na subárvore esquerda de "p", que é 15.
	.Como o nó 15 não tem um ponteiro direito definido, definimos o ponteiro direito  do nó 15 para apontar para "p" (15 -> 20) e visitamos o nó 20. Em seguida, atualizamos "p" para o nó esquerdo, ou seja, p = 15.
.O nó atual "p" não tem um filho esquerdo. Portanto, visitamos o nó 15 e atualizamos "p" para o nó direito, ou seja, p = 20.
.O nó atual "p" não tem um filho esquerdo. Portanto, visitamos o nó 20 e atualizamos "p" para o nó direito, ou seja, p = 24.
.O nó atual "p" não tem um filho esquerdo. Portanto, visitamos o nó 24 e atualizamos "p" para nulo.

Então "p" se torna nulo, e isso significa que percorremos todos os nós da árvore in-ordem.
Resultando na saída expressada na letra a).



*/