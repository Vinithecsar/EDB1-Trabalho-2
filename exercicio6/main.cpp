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

// Questão 1
int *arrayValoresAteN(int n) {
  int *vetor = new int[n];
  for (int i = 0; i < n; i++) {
    vetor[i] = rand() % n;
  }
  return vetor;
}

// Questão 2
bool isOrderedArray(int vetor[], int tamanho) {
  for (int i = 0; i < (tamanho - 1); i++) {
    if (vetor[i] > vetor[i + 1]) {
      return false;
    }
  }
  return true;
}

// Questão 3
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

// Questão 4
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

// Questão 5
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

  // Para cada algoritmo de ordenação implementado, realize testes
  // com vetores desordenados e utilize o algoritmo da questão 2
  // para verificar se a ordenação está correta

  cout << "Teste dos 3 sorts:" << endl;
  cout << "selectionSort, mergeSort e countingSort" << endl;

  int tamanho;

  // selectionSort
  cout
      << "Escolha um valor positivo para o tamanho do vetor do selectionSort: ";
  cin >> tamanho;

  cout << "Gerando vetor de valores aleatórios até esse tamanho" << endl;
  int *vetor1 = new int[tamanho];
  vetor1 = arrayValoresAteN(tamanho);

  cout << "Ordenando por meio do selectionSort" << endl;
  selectionSort(vetor1, tamanho);

  cout << "O vetor está ordenado? " << endl;
  cout << (isOrderedArray(vetor1, tamanho) ? "Sim" : "Não") << endl;

  // mergeSort
  cout
      << "Escolha um valor positivo para o tamanho do vetor do mergeSort: ";
  cin >> tamanho;

  cout << "Gerando vetor de valores aleatórios até esse tamanho" << endl;
  int *vetor2 = new int[tamanho];
  vetor2 = arrayValoresAteN(tamanho);

  cout << "Ordenando por meio do mergeSort" << endl;
  mergeSort(vetor2, 0, tamanho - 1);

  cout << "O vetor está ordenado? " << endl;
  cout << (isOrderedArray(vetor2, tamanho) ? "Sim" : "Não") << endl;

  // countingSort
  cout << "Escolha um valor positivo para o tamanho do vetor do countingSort: ";
  cin >> tamanho;

  cout << "Gerando vetor de valores aleatórios até esse tamanho" << endl;
  int *vetor3 = new int[tamanho];
  vetor3 = arrayValoresAteN(tamanho);

  cout << "Ordenando por meio do countingSort" << endl;
  countingSort(vetor3, tamanho);

  cout << "O vetor está ordenado? " << endl;
  cout << (isOrderedArray(vetor3, tamanho) ? "Sim" : "Não") << endl;

  return 0;
}
