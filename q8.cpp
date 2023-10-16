#include <iostream>
#include <cstring>
#include <algorithm> 
using namespace std;

const int INVALIDO = -1;

class torneio{
private:
	int valaux;
	int *heap;
	int tamanho;
	int capacidade;
    int inicioDados;
	inline int pai(int filho);
	inline int esquerda(int getPai);
	inline int direita(int getPai);
	void arruma();
	void compete(int i);
    void verBaseMaior();
    void alterna();

public:
	torneio(int vet[], int tam);
	~torneio();
};

//Construtor da classe
torneio::torneio(int vet[], int tam){ 
	capacidade = 1;
	
	while(capacidade < tam){
		capacidade *= 2;
	}
	
	capacidade = capacidade - 1 + tam;
	
	heap = new int[capacidade];
	inicioDados = capacidade - tam;

	memcpy(&heap[inicioDados],vet,tam*sizeof(int));
	
	tamanho = tam;
	
	arruma();
}

// Destrutor da classe
torneio::~torneio(){
	delete[] heap;
}

// Retorno a posição do nó pai de um determinado elemento
int torneio::pai(int filho){  
	return (filho-1)/2;
}

// Retorna o filho à esquerda de um determinado nó
int torneio::esquerda(int pai){ 
	return (2*pai)+1;
}

// Retorna o filho à direita do nó pai
int torneio::direita(int pai){ 
	return (2*pai)+2;
}

// Faz a competição por cada posição vencedora no vetor e imprime o vencedor
void torneio::arruma(){
	for(int i=inicioDados-1;i>=0;i--){
		compete(i);
	}
	verBaseMaior();
}

void torneio::verBaseMaior(){
	cout << heap[0];
}

// Faz a competição entre os elementos
void torneio::compete(int i){ 
	int esq = esquerda(i);
	int dir = direita(i);
	int maior = INVALIDO;

	if(esq < capacidade){
		if((dir < capacidade) and (heap[dir] > heap[esq])){
			maior = dir;
		}
		else{
			maior = esq;
		}
		heap[i] = heap[maior];
	}
	else{
		heap[i] = INVALIDO;
	}
}

void torneio::alterna(){
	int aux = valaux/2;
    valaux = valaux/2;
	for (int i = inicioDados; i >= 0; i--)
	{
		compete(i);
		aux--;
		if(aux==0){
			valaux = valaux/2;
			aux = valaux;
		}
	}
	
	verBaseMaior();
}

int main(){
    
    int tam;
    cin >> tam;

    int vet[tam];
    for(int i = 0; i < tam; i++){
        cin >> vet[i];
    }

    torneio participantes(vet, tam);
    


    return 0;
}
