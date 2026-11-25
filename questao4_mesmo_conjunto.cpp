#include <iostream>
#include <vector>
using namespace std;

struct No {
    int dado;
    No* esquerda;
    No* direita;
};

void coletarEmOrdem(No* raiz, vector<int>& elementos) {
    if (raiz == nullptr) return;
    coletarEmOrdem(raiz->esquerda, elementos);
    elementos.push_back(raiz->dado);
    coletarEmOrdem(raiz->direita, elementos);
}

bool mesmoConjunto(No* arvore1, No* arvore2) {
    vector<int> elementos1;
    vector<int> elementos2;
    coletarEmOrdem(arvore1, elementos1);
    coletarEmOrdem(arvore2, elementos2);
    // Em uma BST sem duplicatas, a travessia em ordem produz os elementos
    // ordenados. Assim, a comparação não depende da estrutura das árvores.
    return elementos1 == elementos2;
}

int main() {
    No a1{2, nullptr, nullptr}, a2{1, nullptr, nullptr}, a3{3, nullptr, nullptr};
    a1.esquerda = &a2;
    a1.direita = &a3;

    No b1{1, nullptr, nullptr}, b2{3, nullptr, nullptr}, b3{2, nullptr, nullptr};
    b2.esquerda = &b3;
    b1.direita = &b2;

    cout << (mesmoConjunto(&a1, &b1)
                 ? "As árvores possuem o mesmo conjunto de elementos.\n"
                 : "As árvores possuem conjuntos diferentes.\n");
}
