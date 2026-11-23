#include <stdio.h>
#include <stdlib.h>

// define a estrura no do grafo
struct no {
    int vertice; //mudar pra str no projeto // é a chave do no
    struct no* proximo; // aponta para o proximo no
};

struct no* criarNo(int);
//num sei o que isso faz

// define a estrutura Grafo
struct Grafo {
    int numVertice; //nmr de vertices no grafo
    struct no** listaAdj; 
    // é o vetor lista de adjacencia do grafo onde 
    // armazena as arestas dos vertices
};

// Cria um nó (vertice)
struct no* criaNo(int v) {
    struct no* novoNo = malloc(sizeof(struct no));
    novoNo->vertice = v;
    novoNo->proximo = NULL;
    return novoNo;
}

// Cria um grafo (e insere novos vertices no grafo tbm?)
struct Grafo* criaGrafo (int vertice) {
    //faz a alocação dinâmica da memória 
    struct Grafo* grafo = malloc(sizeof(struct Grafo));
    grafo->numVertice = vertice;

    //faz a alocação dinâmica da memória da lista de adj
    grafo->listaAdj = malloc(vertice * sizeof(struct no*));

    /*acho que atualiza o último elemento da lista para 
    apontar para NULL; não entendi direito
    */
    int i;
    for (i=0; i < vertice; i++) {
        grafo->listaAdj[i] = NULL;
    }

    return grafo;
}

// cria Aresta
void criarAresta (struct Grafo* grafo , int a, int b) {
    // cria uma aresta entre a e b
    // a e b tem que ser vertices existentes do grafo
    struct no* novoNo = criaNo(b); // cria uma var aux 
    novoNo->proximo = grafo->listaAdj[a];
    grafo->listaAdj[a] = novoNo;

    // cria uma aresta entra b e a 
    novoNo = criaNo(a);
    novoNo->proximo = grafo->listaAdj[b];
    grafo->listaAdj[b] = novoNo;
}

// printa o grafo
void printaGrafo (struct Grafo* grafo) {
    int v;
    for (v=0; v<grafo->numVertice; v++) {
        struct no* temp = grafo->listaAdj[v];
        printf("\n Vertice %d:", v);
        while (temp) {
            printf("%d -> ", temp->vertice);
            temp = temp->proximo;
        }
        printf("\n");
    }
}

int main() {
    struct Grafo* grafo = criaGrafo(4);
    criarAresta(grafo, 0, 1);
    criarAresta(grafo, 0, 2);
    criarAresta(grafo, 0, 3);
    criarAresta(grafo, 1, 2);

    printaGrafo(grafo);

    return 0;
}




























