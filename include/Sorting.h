#ifndef SORTING_H
#define SORTING_H

class Sorting {
public:
	/**
		\brief O merge sort, ou ordenação por mistura, é um exemplo 
		de algoritmo de ordenação por comparação do tipo 
		dividir-para-conquistar.

		\param arr		Array que será ordenado.
		\param start	Primeiro indice do array.
		\param end		Ultimo indice do array.
	**/
	static void mergeSort(int arr[], int start, int end);

	/**
		\brief O heapsort é um algoritmo de ordenação generalista, 
		e faz parte da família de algoritmos de ordenação por seleção.

		\param arr		Array que será ordenado.
		\param size		Tamanho do array.
	**/
	static void heapSort(int arr[], int size);
};

#endif