#include <iostream>
using namespace std;

struct NoArvore {
    int data;
    NoArvore* esquerda;
    NoArvore* direita;
};

int validarBST(NoArvore* raiz, NoArvore*& anterior) {
    if (raiz == NULL) {
        return 1;
    }

    if (validarBST(raiz->esquerda, anterior) == 0) {
        return 0;
    }

    if (anterior != NULL && raiz->data <= anterior->data) {
        return 0;
    }

    anterior = raiz;
    return validarBST(raiz->direita, anterior);
}

int ehBST(NoArvore* raiz) {
    NoArvore* anterior = NULL;
    return validarBST(raiz, anterior);
}

int main() {
    NoArvore noEsquerdo{5, NULL, NULL};
    NoArvore noDireito{15, NULL, NULL};
    NoArvore raiz{10, &noEsquerdo, &noDireito};

    if (ehBST(&raiz) == 1) {
        cout << "A arvore e uma BST valida." << endl;
    } else {
        cout << "A arvore nao e uma BST valida." << endl;
    }

    NoArvore noInvalido{12, NULL, NULL};
    noEsquerdo.direita = &noInvalido;

    if (ehBST(&raiz) == 1) {
        cout << "A arvore e uma BST valida." << endl;
    } else {
        cout << "A arvore nao e uma BST valida." << endl;
    }
}
