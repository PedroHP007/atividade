#include <iostream>
using namespace std;

struct NoArvore {
    int data;
    NoArvore* esquerda;
    NoArvore* direita;
};

void inserirBSTIterativo(NoArvore*& raiz, int chave) {
    if (raiz == NULL) {
        NoArvore* novoNo = new NoArvore;
        novoNo->data = chave;
        novoNo->esquerda = NULL;
        novoNo->direita = NULL;
        raiz = novoNo;
        return;
    }

    NoArvore* atual = raiz;
    NoArvore* pai = NULL;

    while (atual != NULL) {
        pai = atual;

        if (chave < atual->data) {
            atual = atual->esquerda;
        } else if (chave > atual->data) {
            atual = atual->direita;
        } else {
            return;
        }
    }

    NoArvore* novoNo = new NoArvore;
    novoNo->data = chave;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;

    if (chave < pai->data) {
        pai->esquerda = novoNo;
    } else {
        pai->direita = novoNo;
    }
}

void listarEmOrdem(NoArvore* raiz) {
    if (raiz == NULL) {
        return;
    }

    listarEmOrdem(raiz->esquerda);
    cout << raiz->data << endl;
    listarEmOrdem(raiz->direita);
}

void liberar(NoArvore* raiz) {
    if (raiz == NULL) {
        return;
    }

    liberar(raiz->esquerda);
    liberar(raiz->direita);
    delete raiz;
}

int main() {
    NoArvore* raiz = NULL;

    inserirBSTIterativo(raiz, 50);
    inserirBSTIterativo(raiz, 30);
    inserirBSTIterativo(raiz, 70);
    inserirBSTIterativo(raiz, 20);
    inserirBSTIterativo(raiz, 40);
    inserirBSTIterativo(raiz, 60);
    inserirBSTIterativo(raiz, 80);

    cout << "Elementos em ordem:" << endl;
    listarEmOrdem(raiz);

    liberar(raiz);
}
