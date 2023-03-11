// função que verifica se as árvores são iguais
int igual(no* a, no* b) {
    if (a == NULL && b == NULL) {
        return 1;
    } else if (a != NULL && b != NULL) {
        return (a->valor == b->valor) && igual(a->esq, b->esq) && igual(a->dir, b->dir);
    } else {
        return 0;
    }
}