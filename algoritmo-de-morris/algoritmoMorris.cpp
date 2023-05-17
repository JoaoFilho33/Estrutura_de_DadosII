/*
O algoritmo é implementado de forma correta.
Pois ele consegue retornar ao nó atual a partir do seu anterior, sem utilizar pilhas.

*/


void MorrisPreorder(){
    ArvoreNo<T> *p=root, *tmp;
    while (p!=0){
        if (p->left==0){ // se nó atual "p" n tem um filho esquerdo.
            visit(p); // visit o nó
            p=p->right; // nó atual p é movido para o seu filho direito
        }
        else{
            tmp = p->left;  
            while (tmp->right!=0 && tmp->right!=p) // encontra o nó mais a direita da subarvore esquerda do nó atual p
                tmp=tmp->right; 
                if (tmp->right==0){ // se esse ponteiro right for nulo 
                    visit(p); // visit o nó
                    tmp->right=p; // o ponteiro right aponta para o nó atual p
                    p=p->left;
                }
                else{   // se o ponteiro right ja aponta para o nó atual p   
                    tmp->right=0; //é configurado como nulo
                    p=p->right; //e o ponteiro p é movido para o filho direito 
                } /*fim else*/  }
        } /*fim while*/    }