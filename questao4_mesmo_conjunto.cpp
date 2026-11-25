#include <iostream>
#include <vector>
using namespace std;

struct NoArvore {
    int data;
    NoArvore* esquerda;
    NoArvore* direita;
};

void listarEmOrdem(NoArvore* raiz, vector<int>& elementos) {
    if (raiz == NULL) {
        return;
    }

    listarEmOrdem(raiz->esquerda, elementos);
    elementos.push_back(raiz->data);
    listarEmOrdem(raiz->direita, elementos);
}

int mesmoConjunto(NoArvore* raiz1, NoArvore* raiz2) {
    vector<int> elementos1;
    vector<int> elementos2;

    listarEmOrdem(raiz1, elementos1);
    listarEmOrdem(raiz2, elementos2);

    if (elementos1.size() != elementos2.size()) {
        return 0;
    }

    for (int i = 0; i < elementos1.size(); i++) {
        if (elementos1[i] != elementos2[i]) {
            return 0;
        }
    }

    return 1;
}

int main() {
    NoArvore raiz1{2, NULL, NULL};
    NoArvore noEsquerdo1{1, NULL, NULL};
    NoArvore noDireito1{3, NULL, NULL};
    raiz1.esquerda = &noEsquerdo1;
    raiz1.direita = &noDireito1;

    NoArvore raiz2{1, NULL, NULL};
    NoArvore noDireito2{3, NULL, NULL};
    NoArvore noEsquerdo2{2, NULL, NULL};
    raiz2.direita = &noDireito2;
    noDireito2.esquerda = &noEsquerdo2;

    if (mesmoConjunto(&raiz1, &raiz2) == 1) {
        cout << "As arvores possuem o mesmo conjunto de elementos." << endl;
    } else {
        cout << "As arvores possuem conjuntos diferentes." << endl;
    }
}
