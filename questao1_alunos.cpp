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

    explicit No(const Aluno& valor)
        : aluno(valor), esquerda(nullptr), direita(nullptr) {}
};

// As três operações da BST: inserir, buscar e remover.
void inserir(No*& raiz, const Aluno& aluno) {
    if (raiz == nullptr) {
        raiz = new No(aluno);
    } else if (aluno.matricula < raiz->aluno.matricula) {
        inserir(raiz->esquerda, aluno);
    } else if (aluno.matricula > raiz->aluno.matricula) {
        inserir(raiz->direita, aluno);
    } else {
        // Matrículas são únicas; ao repetir, atualiza o cadastro.
        raiz->aluno = aluno;
    }
}

No* buscar(No* raiz, int matricula) {
    if (raiz == nullptr || raiz->aluno.matricula == matricula) {
        return raiz;
    }
    if (matricula < raiz->aluno.matricula) {
        return buscar(raiz->esquerda, matricula);
    }
    return buscar(raiz->direita, matricula);
}

No* menorNo(No* raiz) {
    while (raiz != nullptr && raiz->esquerda != nullptr) {
        raiz = raiz->esquerda;
    }
    return raiz;
}

void remover(No*& raiz, int matricula) {
    if (raiz == nullptr) return;

    if (matricula < raiz->aluno.matricula) {
        remover(raiz->esquerda, matricula);
    } else if (matricula > raiz->aluno.matricula) {
        remover(raiz->direita, matricula);
    } else if (raiz->esquerda == nullptr || raiz->direita == nullptr) {
        No* antigo = raiz;
        raiz = (raiz->esquerda != nullptr) ? raiz->esquerda : raiz->direita;
        delete antigo;
    } else {
        No* sucessor = menorNo(raiz->direita);
        raiz->aluno = sucessor->aluno;
        remover(raiz->direita, sucessor->aluno.matricula);
    }
}

void listarEmOrdem(No* raiz) {
    if (raiz == nullptr) return;
    listarEmOrdem(raiz->esquerda);
    cout << raiz->aluno.matricula << " - " << raiz->aluno.nome << '\n';
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
    inserir(raiz, {2024003, "Ana"});
    inserir(raiz, {2024001, "Bruno"});
    inserir(raiz, {2024005, "Carla"});

    cout << "Alunos em ordem de matrícula:\n";
    listarEmOrdem(raiz);

    if (No* aluno = buscar(raiz, 2024001)) {
        cout << "Encontrado: " << aluno->aluno.nome << '\n';
    } else {
        cout << "Matrícula não encontrada.\n";
    }

    remover(raiz, 2024003);
    cout << "Após remover a matrícula 2024003:\n";
    listarEmOrdem(raiz);
    liberar(raiz);
}
