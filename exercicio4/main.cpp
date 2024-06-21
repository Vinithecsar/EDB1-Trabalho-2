#include <iostream>

using namespace std;

void merge(int vetor[], int esquerda, int meio, int direita) {

  int n1 = meio - esquerda + 1;
  int n2 = direita - meio;

  int *vetorEsquerdo = new int[n1], *vetorDireito = new int[n2];

  for (int i = 0; i < n1; i++) {
    vetorEsquerdo[i] = vetor[esquerda + i];
  }
  for (int j = 0; j < n2; j++) {
    vetorDireito[j] = vetor[meio + 1 + j];
  }

  int indexVetorEsquerdo = 0, indexVetorDireito = 0, indexVetor = esquerda;

  while (indexVetorEsquerdo < n1 && indexVetorDireito < n2) {
    if (vetorEsquerdo[indexVetorEsquerdo] <= vetorDireito[indexVetorDireito]) {
      vetor[indexVetor] = vetorEsquerdo[indexVetorEsquerdo];
      indexVetorEsquerdo++;
    } else {
      vetor[indexVetor] = vetorDireito[indexVetorDireito];
      indexVetorDireito++;
    }
    indexVetor++;
  }

  while (indexVetorEsquerdo < n1) {
    vetor[indexVetor] = vetorEsquerdo[indexVetorEsquerdo];
    indexVetorEsquerdo++;
    indexVetor++;
  }

  while (indexVetorDireito < n2) {
    vetor[indexVetor] = vetorDireito[indexVetorDireito];
    indexVetorDireito++;
    indexVetor++;
  }
}

void mergeSort(int vetor[], int esquerda, int direita) {
  if (esquerda < direita) {
    int meio = esquerda + (direita - esquerda) / 2;

    mergeSort(vetor, esquerda, meio);
    mergeSort(vetor, meio + 1, direita);

    merge(vetor, esquerda, meio, direita);
  }
}

int main() {

  // Implemente um dos algoritmos de complexidade O(nlogn):
  // escolha entre o algoritmo merge sort e o insertion sort.

  // Algoritmo escolhido: merge sort

  int tamanho;
  cout << "Escolha um valor positivo para o tamanho do vetor: ";
  cin >> tamanho;

  int *vetor = new int[tamanho];

  cout << "Digite os valores do vetor: " << endl;
  for (int i = 0; i < tamanho; i++) {
    cin >> vetor[i];
  }

  mergeSort(vetor, 0, tamanho - 1);

  cout << "Vetor ordenado pelo merge sort: " << endl;
  for (int i = 0; i < tamanho; i++) {
    cout << vetor[i] << " ";
  }
  cout << endl;

  return 0;
}
