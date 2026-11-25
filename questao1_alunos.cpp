#include <iostream>
#include <string>
using namespace std;

struct Aluno {
    int matricula;
    string nome;
};

struct No {
    Aluno aluno;
    No* esquerda;
    No* direita;
};

No* inserirBST(No*& raiz, Aluno aluno) {
    if (raiz == NULL) {
        No* novoNo = new No;
        novoNo->aluno = aluno;
        novoNo->esquerda = NULL;
        novoNo->direita = NULL;

        raiz = novoNo;
        return raiz;
    }

    if (aluno.matricula > raiz->aluno.matricula) {
        raiz->direita = inserirBST(raiz->direita, aluno);
    }

    if (aluno.matricula < raiz->aluno.matricula) {
        raiz->esquerda = inserirBST(raiz->esquerda, aluno);
    }

    return raiz;
}

No* buscaBST(No*& raiz, int matricula) {
    if (raiz == NULL || raiz->aluno.matricula == matricula) {
        return raiz;
    }

    if (matricula < raiz->aluno.matricula) {
        return buscaBST(raiz->esquerda, matricula);
    } else {
        return buscaBST(raiz->direita, matricula);
    }
}

No* removerBST(No*& raiz, int matricula) {
    if (raiz == NULL) {
        return NULL;
    }

    if (matricula < raiz->aluno.matricula) {
        raiz->esquerda = removerBST(raiz->esquerda, matricula);
    } else if (matricula > raiz->aluno.matricula) {
        raiz->direita = removerBST(raiz->direita, matricula);
    } else {
        if (raiz->esquerda == NULL && raiz->direita == NULL) {
            delete raiz;
            raiz = NULL;
            return raiz;
        } else if (raiz->esquerda == NULL) {
            No* aux = raiz;
            raiz = raiz->direita;
            delete aux;
        } else if (raiz->direita == NULL) {
            No* aux = raiz;
            raiz = raiz->esquerda;
            delete aux;
        } else {
            No* aux = raiz->esquerda;

            while (aux->direita != NULL) {
                aux = aux->direita;
            }

            raiz->aluno = aux->aluno;
            raiz->esquerda = removerBST(raiz->esquerda, aux->aluno.matricula);
        }
    }

    return raiz;
}

void listarEmOrdem(No* raiz) {
    if (raiz == NULL) {
        return;
    }

    listarEmOrdem(raiz->esquerda);
    cout << raiz->aluno.matricula << " - " << raiz->aluno.nome << endl;
    listarEmOrdem(raiz->direita);
}

void liberar(No* raiz) {
    if (raiz == NULL) {
        return;
    }

    liberar(raiz->esquerda);
    liberar(raiz->direita);
    delete raiz;
}

int main() {
    No* raiz = NULL;

    inserirBST(raiz, {2024003, "Ana"});
    inserirBST(raiz, {2024001, "Bruno"});
    inserirBST(raiz, {2024005, "Carla"});

    cout << "Alunos em ordem de matricula:" << endl;
    listarEmOrdem(raiz);

    No* aluno = buscaBST(raiz, 2024001);
    if (aluno != NULL) {
        cout << "Encontrado: " << aluno->aluno.nome << endl;
    } else {
        cout << "Matricula nao encontrada." << endl;
    }

    removerBST(raiz, 2024003);
    cout << "Apos remover a matricula 2024003:" << endl;
    listarEmOrdem(raiz);

    liberar(raiz);
}
