#include "CHeapSort.h"
#include <iomanip>
#include <iostream>
using namespace std;

int comparisonsQuickSort =
0; // Inicializar el contador de comparaciones para QuickSort
int comparisonsBubbleSort =
0; // Inicializar el contador de comparaciones para BubbleSort
int comparisonsHeapSort =
0; // Inicializar el contador de comparaciones para HeapSort

// Función para intercambiar elementos
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Función para reorganizar el arreglo (encontrar el punto de partición)
int partition(int array[], int low, int high) {

    // Seleccionar el elemento más a la derecha como pivote
    int pivot = array[high];

    // Puntero para elementos mayores
    int i = (low - 1);

    // Compararlos con el pivote
    for (int j = low; j < high; j++) {
        comparisonsQuickSort++; // Incrementar el contador de comparaciones para
        // QuickSort
        if (array[j] <= pivot) {
            i++;
            swap(&array[i], &array[j]);
        }
    }

    swap(&array[i + 1], &array[high]);
    return (i + 1);
}

void quickSort(int array[], int low, int high) {
    if (low < high) {

        int pi = partition(array, low, high);

        // Llamada recursiva a la izquierda del pivote
        quickSort(array, low, pi - 1);

        // Llamada recursiva a la derecha del pivote
        quickSort(array, pi + 1, high);
    }
}

void bubbleSort(int arr[], int n) {
    int i, j;

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            comparisonsBubbleSort++; // Incrementar el contador de comparaciones para
            // BubbleSort
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main() {
    CHeapSort myHeapSortAlgorithm;
    // Inicializar el generador de números aleatorios
    srand(time(0));

    int elementos_del_arreglo[] = { 10, 100, 1000, 10000, 100000 };

    cout << "Elementos del Arreglo | Comparaciones de QuickSort | Comparaciones "
        "de BubbleSort | Comparaciones de HeapSort"
        << endl;

    for (int i = 0; i < 5; i++) {
        int n = elementos_del_arreglo[i];

        int arregloAleatorioQuickSort[n];
        int arregloAleatorioBubbleSort[n];
        int arregloAleatorioHeapSort[n];

        for (int j = 0; j < n; j++) {
            int numeroAleatorio = (rand() % 100000);
            arregloAleatorioQuickSort[j] = numeroAleatorio;
            arregloAleatorioBubbleSort[j] = numeroAleatorio;
            arregloAleatorioHeapSort[j] = numeroAleatorio;
        }

        comparisonsQuickSort = 0; // Reiniciar los contadores
        comparisonsBubbleSort = 0;
        comparisonsHeapSort = 0;

        quickSort(arregloAleatorioQuickSort, 0, n - 1);
        bubbleSort(arregloAleatorioBubbleSort, n);

        myHeapSortAlgorithm.heapSort(arregloAleatorioHeapSort, n);
        comparisonsHeapSort = myHeapSortAlgorithm.comparisons();

        cout << setw(21) << n << " | " << setw(26) << comparisonsQuickSort << " | "
            << setw(27) << comparisonsBubbleSort << " | " << setw(25)
            << comparisonsHeapSort << endl;
    }

    return 0;
}
