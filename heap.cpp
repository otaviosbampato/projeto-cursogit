#include <iostream>
#include <cstdlib>

typedef int dado;

class maxHeap{
    private:
        dado* heap;
        int capacidade;
        int tamanho;
        inline int pai(int i);
        inline int esquerdo(int i);
        inline int direito(int i);
        void arruma(); //tb chamada heapify
        void corrigeDescendo(int i);
        void corrigeSubindo(int i);
    public:
        maxHeap(int capac);
        maxHeap(dado vet[], int tam);
        ~maxHeap();
        void imprime();
        dado espia();
        dado retiraRaiz();
        void insere(dado &d);
};

maxHeap::maxHeap(int capac){
    capacidade = capac;
    heap = new dado[capac];
    tamanho = 0;
}

maxHeap::maxHeap(dado vet[], int tam){
    capacidade = tam;
    heap = new dado[capacidade];

    for(int i=0; i<tam; i++){
        heap[i] = vet[i];
    }

    tamanho = tam;
    arruma();
}

maxHeap::~maxHeap(){
    delete[] heap;
}

int maxHeap::pai(int i){
    return (i-1)/2;
}

int maxHeap::esquerdo(int i){
    return (2*i)+1;
}

int maxHeap::direito(int i){
    return (2*i)+2;
}

void maxHeap::arruma(){
    for(int i=((tamanho/2)-1); i>=0; i--){
        corrigeDescendo(i);
    }
}

void maxHeap::corrigeDescendo(int i){
    int esq = esquerdo(i);
    int dir = direito(i);
    int maior = i;

    if((esq<tamanho) && (heap[esq] > heap[maior])){
        maior = esq;
    }

    if((dir < tamanho) && (heap[dir] > heap[maior])){
        maior = dir;
    }

    if(maior!=i){
        std::swap(heap[i], heap[maior]);
            corrigeDescendo(maior);
    }

}

void maxHeap::corrigeSubindo(int i){
    int p = pai(i);
    if(heap[i] > heap[p]){
        std::swap(heap[i], heap[p]);
        corrigeSubindo(p);
    }
}

void maxHeap::imprime(){
    for(int i=0; i<tamanho; i++){
        std::cout << heap[i] << " ";
    }
    std::cout << std::endl;
}

dado maxHeap::espia(){
    return heap[0];
}

dado maxHeap::retiraRaiz(){
    if(tamanho == 0){
        std::cerr << "erro ao retirar raiz\n";
        exit(EXIT_FAILURE);
    }
    dado aux = heap[0];
    std::swap(heap[0], heap[tamanho-1]);
    tamanho--;
    corrigeDescendo(0);
    return aux;
}

void maxHeap::insere(dado &d){
    if(tamanho == capacidade){
        std::cerr << "falha ao inserir, heap cheio\n";
        exit(EXIT_FAILURE);
    }
    heap[tamanho] = d;
    corrigeSubindo(tamanho);
    tamanho++;
}

int main(){ //create own main

    int tam;
    std::cout << "insira a qtd de elementos do seu heap: ";
    std::cin >> tam;

    int vet[tam];
    std::cout << "preencha seu heap: ";

    for(int i=0; i<tam; i++){
        std::cin >> vet[i];
    }

    maxHeap *h = new maxHeap(vet, tam);

    for(int i=0; i<tam; i++){
        std::cout << h->retiraRaiz() << " : "; 
        h->imprime();
    }

    std::cout << "\n\n";

    return 0;
}