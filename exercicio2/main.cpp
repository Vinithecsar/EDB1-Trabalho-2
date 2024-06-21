#include <iostream>

using namespace std;

bool isOrderedArray(int vetor[], int tamanho) {
  for (int i = 0; i < (tamanho - 1); i++) {
    if (vetor[i] > vetor[i + 1]) {
      return false;
    }
  }
  return true;
}

int main() {

  // Implemente um algoritmo que dado um vetor de entrada A, retorne
  // verdadeiro em caso do vetor está ordenado e falso caso contrário.

  int tamanho;
  cout << "Escolha um valor positivo para o tamanho do vetor: ";
  cin >> tamanho;

  int *vetor = new int[tamanho];

  cout << "Digite os valores do vetor: " << endl;
  for (int i = 0; i < tamanho; i++) {
    cin >> vetor[i];
  }

  cout << "O vetor está ordenado? " << endl;
  cout << (isOrderedArray(vetor, tamanho) ? "Sim" : "Não") << endl;

  return 0;
}
