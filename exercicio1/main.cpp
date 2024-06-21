#include <iostream>

using namespace std;

int *arrayValoresAteN(int n) {
  int *vetor = new int[n];
  for (int i = 0; i < n; i++) {
    vetor[i] = rand() % n;
  }
  return vetor;
}

int main() {

  // Implemente um algoritmo que recebe como entrada o tamanho N do vetor e
  // retorna um vetor de tamanho N como valores aleatórios variando de 0 a N.
  int tamanho;
  cout << "Escolha um valor positivo para o tamanho do vetor: ";
  cin >> tamanho;

  int *vetor = arrayValoresAteN(tamanho);

  cout << "Valores do vetor: " << endl;
  for (int i = 0; i < tamanho; i++) {
    cout << vetor[i] << " ";
  }
  cout << endl;

  return 0;
}
