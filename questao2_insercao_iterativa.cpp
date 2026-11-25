#include <iostream>
using namespace std;

struct No {
    int dado;
    No* esquerda;
    No* direita;

    explicit No(int valor) : dado(valor), esquerda(nullptr), direita(nullptr) {}
};

// Insere sem recursividade. Valores repetidos são ignorados.
void inserirIterativo(No*& raiz, int valor) {
    if (raiz == nullptr) {
        raiz = new No(valor);
        return;
    }

    No* atual = raiz;
    No* pai = nullptr;
    while (atual != nullptr) {
        pai = atual;
        if (valor < atual->dado) {
            atual = atual->esquerda;
        } else if (valor > atual->dado) {
            atual = atual->direita;
        } else {
            return; // Não permite valores duplicados.
        }
    }

    if (valor < pai->dado) {
        pai->esquerda = new No(valor);
    } else {
        pai->direita = new No(valor);
    }
}

void listarEmOrdem(No* raiz) {
    if (raiz == nullptr) return;
    listarEmOrdem(raiz->esquerda);
    cout << raiz->dado << ' ';
    listarEmOrdem(raiz->direita);
}

void liberar(No* raiz) {
    if (raiz == nullptr) return;
    liberar(raiz->esquerda);
    liberar(raiz->direita);
    delete raiz;
}

int main() {
    No* raiz = nullptr;
    int valores[] = {50, 30, 70, 20, 40, 60, 80};
    for (int valor : valores) inserirIterativo(raiz, valor);

    cout << "Elementos em ordem: ";
    listarEmOrdem(raiz);
    cout << '\n';
    liberar(raiz);
}
