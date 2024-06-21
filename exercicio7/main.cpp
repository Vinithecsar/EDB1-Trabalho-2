#include <iostream>
#include <time.h>

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

void testeSelectionSort() {

  double tempo_levado;
  clock_t start, end; // Para medir o tempo de execução

  // 100
  cout << "Teste com tamanho 100" << endl;
  int *vetor1 = new int[100];
  vetor1 = arrayValoresAteN(100);

  start = clock();
  selectionSort(vetor1, 100);
  end = clock();

  tempo_levado = double(end - start) / double(CLOCKS_PER_SEC);
  cout << "Tempo levado pelo programa: " << fixed << tempo_levado << " seg "
       << endl
       << endl;

  delete[] vetor1;

  // 1000
  cout << "Teste com tamanho 1000" << endl;
  int *vetor2 = new int[1000];
  vetor2 = arrayValoresAteN(1000);

  start = clock();
  selectionSort(vetor2, 1000);
  end = clock();

  tempo_levado = double(end - start) / double(CLOCKS_PER_SEC);
  cout << "Tempo levado pelo programa: " << fixed << tempo_levado << " seg "
       << endl
       << endl;

  delete[] vetor2;

  // 10000
  cout << "Teste com tamanho 10000" << endl;
  int *vetor3 = new int[10000];
  vetor3 = arrayValoresAteN(10000);

  start = clock();
  selectionSort(vetor3, 10000);
  end = clock();

  tempo_levado = double(end - start) / double(CLOCKS_PER_SEC);
  cout << "Tempo levado pelo programa: " << fixed << tempo_levado << " seg "
       << endl
       << endl;

  delete[] vetor3;

  // 100000
  cout << "Teste com tamanho 100000" << endl;
  int *vetor4 = new int[100000];
  vetor4 = arrayValoresAteN(100000);

  start = clock();
  selectionSort(vetor4, 100000);
  end = clock();

  tempo_levado = double(end - start) / double(CLOCKS_PER_SEC);
  cout << "Tempo levado pelo programa: " << fixed << tempo_levado << " seg "
       << endl
       << endl;

  delete[] vetor4;

  // 500000
  cout << "Teste com tamanho 500000" << endl;
  int *vetor5 = new int[500000];
  vetor5 = arrayValoresAteN(500000);

  start = clock();
  selectionSort(vetor5, 500000);
  end = clock();

  tempo_levado = double(end - start) / double(CLOCKS_PER_SEC);
  cout << "Tempo levado pelo programa: " << fixed << tempo_levado << " seg "
       << endl
       << endl;

  delete[] vetor5;
}

void testeMergeSort() {

  double tempo_levado;
  clock_t start, end; // Para medir o tempo de execução

  // 100
  cout << "Teste com tamanho 100" << endl;
  int *vetor1 = new int[100];
  vetor1 = arrayValoresAteN(100);

  start = clock();
  mergeSort(vetor1, 0, 100 - 1);
  end = clock();

  tempo_levado = double(end - start) / double(CLOCKS_PER_SEC);
  cout << "Tempo levado pelo programa: " << fixed << tempo_levado << " seg "
       << endl
       << endl;

  delete[] vetor1;

  // 1000
  cout << "Teste com tamanho 1000" << endl;
  int *vetor2 = new int[1000];
  vetor2 = arrayValoresAteN(1000);

  start = clock();
  mergeSort(vetor2, 0, 1000 - 1);
  end = clock();

  tempo_levado = double(end - start) / double(CLOCKS_PER_SEC);
  cout << "Tempo levado pelo programa: " << fixed << tempo_levado << " seg "
       << endl
       << endl;

  delete[] vetor2;

  // 10000
  cout << "Teste com tamanho 10000" << endl;
  int *vetor3 = new int[10000];
  vetor3 = arrayValoresAteN(10000);

  start = clock();
  mergeSort(vetor3, 0, 10000 - 1);
  end = clock();

  tempo_levado = double(end - start) / double(CLOCKS_PER_SEC);
  cout << "Tempo levado pelo programa: " << fixed << tempo_levado << " seg "
       << endl
       << endl;

  delete[] vetor3;

  // 100000
  cout << "Teste com tamanho 100000" << endl;
  int *vetor4 = new int[100000];
  vetor4 = arrayValoresAteN(100000);

  start = clock();
  mergeSort(vetor4, 0, 100000 - 1);
  end = clock();

  tempo_levado = double(end - start) / double(CLOCKS_PER_SEC);
  cout << "Tempo levado pelo programa: " << fixed << tempo_levado << " seg "
       << endl
       << endl;

  delete[] vetor4;

  // 500000
  cout << "Teste com tamanho 500000" << endl;
  int *vetor5 = new int[500000];
  vetor5 = arrayValoresAteN(500000);

  start = clock();
  mergeSort(vetor5, 0, 500000 - 1);
  end = clock();

  tempo_levado = double(end - start) / double(CLOCKS_PER_SEC);
  cout << "Tempo levado pelo programa: " << fixed << tempo_levado << " seg "
       << endl
       << endl;

  delete[] vetor5;
}

void testeCountingSort() {

  double tempo_levado;
  clock_t start, end; // Para medir o tempo de execução

  // 100
  cout << "Teste com tamanho 100" << endl;
  int *vetor1 = new int[100];
  vetor1 = arrayValoresAteN(100);

  start = clock();
  countingSort(vetor1, 100);
  end = clock();

  tempo_levado = double(end - start) / double(CLOCKS_PER_SEC);
  cout << "Tempo levado pelo programa: " << fixed << tempo_levado << " seg "
       << endl
       << endl;

  delete[] vetor1;

  // 1000
  cout << "Teste com tamanho 1000" << endl;
  int *vetor2 = new int[1000];
  vetor2 = arrayValoresAteN(1000);

  start = clock();
  countingSort(vetor2, 1000);
  end = clock();

  tempo_levado = double(end - start) / double(CLOCKS_PER_SEC);
  cout << "Tempo levado pelo programa: " << fixed << tempo_levado << " seg "
       << endl
       << endl;

  delete[] vetor2;

  // 10000
  cout << "Teste com tamanho 10000" << endl;
  int *vetor3 = new int[10000];
  vetor3 = arrayValoresAteN(10000);

  start = clock();
  countingSort(vetor3, 10000);
  end = clock();

  tempo_levado = double(end - start) / double(CLOCKS_PER_SEC);
  cout << "Tempo levado pelo programa: " << fixed << tempo_levado << " seg "
       << endl
       << endl;

  delete[] vetor3;

  // 100000
  cout << "Teste com tamanho 100000" << endl;
  int *vetor4 = new int[100000];
  vetor4 = arrayValoresAteN(100000);

  start = clock();
  countingSort(vetor4, 100000);
  end = clock();

  tempo_levado = double(end - start) / double(CLOCKS_PER_SEC);
  cout << "Tempo levado pelo programa: " << fixed << tempo_levado << " seg "
       << endl
       << endl;

  delete[] vetor4;

  // 500000
  cout << "Teste com tamanho 500000" << endl;
  int *vetor5 = new int[500000];
  vetor5 = arrayValoresAteN(500000);

  start = clock();
  countingSort(vetor5, 500000);
  end = clock();

  tempo_levado = double(end - start) / double(CLOCKS_PER_SEC);
  cout << "Tempo levado pelo programa: " << fixed << tempo_levado << " seg "
       << endl
       << endl;

  delete[] vetor5;
}

int main() {

  // Para cada algoritmo de ordenação implementado nas questões 3, 4 e 5,
  // realize a medição do tempo de execução de cada algoritmo para vetores
  // aleatórios gerados através do algoritmo da questão 1
  // de tamanho 100, 1000, 10000, 100000, 500000.

  cout << "-----SelectionSort-----" << endl;
  testeSelectionSort();
  cout << "-----MergeSort-----" << endl;
  testeMergeSort();
  cout << "-----CountingSort-----" << endl;
  testeCountingSort();

  return 0;
}
