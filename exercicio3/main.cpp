#include <iostream>

using namespace std;

void selectionSort(int vetor[], int tamanho) {
  for (int i = 0; i < tamanho; i++) {
    int menor = i;
    for (int j = i + 1; j < tamanho; j++) {
      if (vetor[j] < vetor[menor]) {
        menor = j;
      }
    }

    int aux = vetor[i];
    vetor[i] = vetor[menor];
    vetor[menor] = aux;
  }
}

int main() {

  // Implemente um dos algoritmos de complexidade O(n²): escolha entre o
  // algoritmo insertion sort e o selection sort.

  // Algoritmo escolhido: selection sort

  int tamanho;
  cout << "Escolha um valor positivo para o tamanho do vetor: ";
  cin >> tamanho;

  int *vetor = new int[tamanho];

  cout << "Digite os valores do vetor: " << endl;
  for (int i = 0; i < tamanho; i++) {
    cin >> vetor[i];
  }

  selectionSort(vetor, tamanho);

  cout << "Vetor ordenado pelo selection sort: " << endl;
  for (int i = 0; i < tamanho; i++) {
    cout << vetor[i] << " ";
  }
  cout << endl;

  return 0;
}
