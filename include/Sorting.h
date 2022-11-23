#ifndef SORTING_H
#define SORTING_H

class Sorting
{
public:
	/**
		\brief O merge sort, ou ordena��o por mistura, � um exemplo
		de algoritmo de ordena��o por compara��o do tipo
		dividir-para-conquistar.

		\param arr		Array que ser� ordenado.
		\param start	Primeiro indice do array.
		\param end		Ultimo indice do array.
	**/
	static void mergeSort(int arr[], int start, int end);

	/**
		\brief O heapsort � um algoritmo de ordena��o generalista,
		e faz parte da fam�lia de algoritmos de ordena��o por sele��o.

		\param arr		Array que ser� ordenado.
		\param size		Tamanho do array.
	**/
	static void heapSort(int arr[], int size);

	/**
		\brief O melhor algoritmo de ordena��o quicksort desenvolvido no passo anterior.

		\param arr		Array que ser� ordenado.
		\param start	Primeiro indice do array.
		\param end		Ultimo indice do array.
	**/
	static void quickSort(int arr[], int start, int end);
};

#endif