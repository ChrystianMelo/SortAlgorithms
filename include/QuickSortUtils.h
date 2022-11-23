#ifndef QUICKSORTUTILS_H
#define QUICKSORTUTILS_H

class QuickSortUtils {
public:
	/**
		\brief Ordena usando o algoritmo Quicksort iterativo.

		\param arr		Array que será ordenado.
		\param start	Primeiro indice do array.
		\param end		Ultimo indice do array.
	**/
	static void qsortIterative(int* vet, int start, int end);

	/**
		\brief Ordena usando o algoritmo Quicksort recursivo.

		\param arr		Array que será ordenado.
		\param start	Primeiro indice do array.
		\param end		Ultimo indice do array.
	**/
	static void qsortRecursive(int* vet, int start, int end);

	/**
		\brief Ordena usando o algoritmo Quicksort recursivo escolhendo 
		pivô para partição como sendo a mediana de k elementos do vetor,
		aleatoriamente escolhidos.

		\param arr		Array que será ordenado.
		\param start	Primeiro indice do array.
		\param end		Ultimo indice do array.
	**/
	static void qsortMediana(int* vet, int start, int end);


	/**
		\brief Ordena usando o algoritmo Quicksort Recursivo utilizando
		algoritmo de Seleção para ordenar partições (isto é, pedaços do
		vetor) com tamanho menor ou igual a m.

		\param arr		Array que será ordenado.
		\param start	Primeiro indice do array.
		\param end		Ultimo indice do array.
		\param m		Tamanho m.
	**/
	static void qsortSelection(int arr[], int start, int end, int m);

	/**
		\brief Ordena usando o algoritmo Quicksort Recursivo processando
		primeiro a menor partição.

		\param arr		Array que será ordenado.
		\param start	Primeiro indice do array.
		\param end		Ultimo indice do array.
	**/
	static void qsortEmplhaInteligente(int* vet, int start, int end);

	/**
		\brief Verifica se o array está ordenado.

		\param arr		Array que será ordenado.
		\param start	Primeiro indice do array.
		\param end		Ultimo indice do array.
	**/
	static bool isSorted(int arr[], int start, int end);
};

#endif