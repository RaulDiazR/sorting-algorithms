#include "CHeapSort.h"

// Funcion que permite ordenar un array
// como monticulo maximo (Max - Heap)
void CHeapSort::heapify(int arr[], int tamanoArray, int nodoPadre)
{
    int largest = nodoPadre; // Nodo Padre
    int l = 2 * nodoPadre + 1; // Nodo Izquiero = 2*i + 1
    int r = 2 * nodoPadre + 2; // Nodo Derecho = 2*i + 2

    comparisonsHeapSort++;
    // Si el nodo Izquierdo es mas grande que el Nodo Padre
    if (l < tamanoArray && arr[l] > arr[largest]) {
        largest = l;
    }

    // Si el nodo derecho es mas grande que el nodo mas grande 
    if (r < tamanoArray && arr[r] > arr[largest]) {
        largest = r;
    }

    // Revisa si el nodo mas grande no es un raiz
    if (largest != nodoPadre) {
        swap(arr[nodoPadre], arr[largest]);

        // Se aplica recursividad para crear nuevamente un Sub - Arbol
        heapify(arr, tamanoArray, largest);
    }
}

// Funcion principal para ralizar el Algoritmo
void CHeapSort::heapSort(int arr[], int n)
{
    comparisonsHeapSort = 0;

    // Creamos un Sub - Arbol (Sub - Array)
    for (int i = n / 2 - 1; i >= 0; i--)  // O(n)
        heapify(arr, n, i);   // nlog(n)

    // Se extrae elemento por elemento del monticulo
    for (int i = n - 1; i >= 0; i--) {
        // 
        swap(arr[0], arr[i]);

        // 
        heapify(arr, i, 0);
    }
}

int CHeapSort::comparisons()
{
    return comparisonsHeapSort;
}

/* Funcion para imprimir el array */
void CHeapSort::printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}


