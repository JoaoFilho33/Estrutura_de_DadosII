// função que verifica se a árvore é estritamente binária
int eb(no* raiz) {
    if (raiz == NULL) {
        return 1;
    } else if (raiz->esq == NULL && raiz->dir == NULL) {
        return 1;
    } else if (raiz->esq != NULL && raiz->dir != NULL) {
        return eb(raiz->esq) && eb(raiz->dir);
    } else {
        return 0;
    }
}