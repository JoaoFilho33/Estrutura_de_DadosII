template<class T>
void balancear(T vetor[], int first, int last) {
    if(first<=last) {
        int middle = (first + last) / 2;
        insert(vetor[middle]);
        balancear(vetor, first, middle-1);
        balancear(vetor, middle+1, last);
    }
}

/*
q01.
d)

No algoritmo acima, a estrutura "vetor" guarda elementos que podem ou não estar ordenados. 
O algoritmo não verifica se o vetor está ordenado antes de inserir os elementos na árvore. 
Ele simplesmente divide o vetor ao meio e insere o elemento do meio na árvore. 
Em seguida, ele chama recursivamente a função balancear para a metade inferior e superior do vetor, repetindo o processo de inserção.

Portanto, o resultado final será uma árvore balanceada, independentemente da ordem dos elementos no vetor de entrada. 
A estrutura "vetor" não é uma árvore em si, mas é usado para construir uma árvore balanceada.
*/