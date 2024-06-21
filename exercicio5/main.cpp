#include <iostream>

using namespace std;

int findMax(int vetor[], int tamanho) {
  int maior = vetor[0];
  for (int i = 0; i < tamanho; i++) {
    if (maior < vetor[i])
      maior = vetor[i];
  }
  return maior;
}

void countingSort(int vetor[], int tamanho) {
  int maior = findMax(vetor, tamanho);

  int *vetorContagem = new int[maior + 1]{0};

  // Contandos valores pelo índice
  for (int i = 0; i < tamanho; i++) {
    vetorContagem[vetor[i]]++;
  }

  // Soma coletiva dos valores
  for (int i = 1; i <= maior; i++) {
    vetorContagem[i] += vetorContagem[i - 1];
  }

  // Ordenação
  int *vetorOrdenado = new int[tamanho];
  for (int i = tamanho - 1; i >= 0; i--) {
    vetorOrdenado[vetorContagem[vetor[i]] - 1] = vetor[i];
    vetorContagem[vetor[i]]--;
  }

  // Atribuindo ao vetor original
  for (int i = 0; i < tamanho; i++) {
    vetor[i] = vetorOrdenado[i];
  }

  delete[] vetorContagem;
  delete[] vetorOrdenado;
}

int main() {

  // Implemente um dos algoritmos de ordenação por distribuição:
  // escolha entre o counting sort e o radix sort.

  // Algoritmo escolhido: counting sort

  int tamanho;
  cout << "Escolha um valor positivo para o tamanho do vetor: ";
  cin >> tamanho;

  int *vetor = new int[tamanho];

  cout << "Digite os valores do vetor: " << endl;
  for (int i = 0; i < tamanho; i++) {
    cin >> vetor[i];
  }

  countingSort(vetor, tamanho);

  cout << "Vetor ordenado pelo counting sort: " << endl;
  for (int i = 0; i < tamanho; i++) {
    cout << vetor[i] << " ";
  }
  cout << endl;

  return 0;
}
