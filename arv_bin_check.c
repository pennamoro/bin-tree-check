#include <stdio.h>

typedef struct arvore {
int info;
struct arvore *esq;
struct arvore *dir;
} Arvore;

int max(struct arvore* a)
{
    if (a == NULL) {
        return 0;
    }

    int maxEsq = max(a->esq);
    int maxDir = max(a->dir);

    int valor = 0;
    if (maxEsq > maxDir) {
        valor = maxEsq;
    }
    else {
        valor = maxDir;
    }

    if (valor < a->info) {
        valor = a->info;
    }

    return valor;
}

int min(struct arvore * a)
{
    if (a == NULL) {
        return 0;
    }

    int maxEsq = min(a->esq);
    int maxDir = min(a->dir);

    int valor = 0;
    if (maxEsq < maxDir) {
        valor = maxEsq;
    }
    else {
        valor = maxDir;
    }

    if (valor > a->info) {
        valor = a->info;
    }

    return valor;
}

int arv_bin_check(Arvore * a){

    if (a == NULL)
        return 1;

    if (a->esq != NULL && max(a->esq) > a->info)
        return 0;

    if (a->dir != NULL && min(a->dir) < a->info)
        return 0;

    if (!arv_bin_check(a->esq) || !arv_bin_check(a->dir))
        return 0;

    return 1;
}

void main(){

}
