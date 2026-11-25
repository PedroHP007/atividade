#include <iostream>
#include <limits>
using namespace std;

struct No {
    int dado;
    No* esquerda;
    No* direita;
};

bool validarBST(No* raiz, long long minimo, long long maximo) {
    if (raiz == nullptr) return true;
    if (raiz->dado <= minimo || raiz->dado >= maximo) return false;

    return validarBST(raiz->esquerda, minimo, raiz->dado) &&
           validarBST(raiz->direita, raiz->dado, maximo);
}

bool ehBST(No* raiz) {
    return validarBST(raiz, numeric_limits<long long>::lowest(),
                      numeric_limits<long long>::max());
}

int main() {
    No n1{10, nullptr, nullptr};
    No n2{5, nullptr, nullptr};
    No n3{15, nullptr, nullptr};
    No raiz{10, &n2, &n3};

    cout << (ehBST(&raiz) ? "A árvore é uma BST válida.\n"
                          : "A árvore não é uma BST válida.\n");

    // Este caso demonstra que não basta comparar apenas pai e filhos:
    // 12 está na subárvore esquerda de 10, portanto invalida a BST.
    No invalido{12, nullptr, nullptr};
    n2.direita = &invalido;
    cout << (ehBST(&raiz) ? "A árvore é uma BST válida.\n"
                          : "A árvore não é uma BST válida.\n");
}
