#ifndef QUICKSORTUTILS_H
#define QUICKSORTUTILS_H

class QuickSortUtils {
public:
	/**
		\brief Ordena usando o algoritmo Quicksort iterativo.

		\param arr		Array que ser� ordenado.
		\param start	Primeiro indice do array.
		\param end		Ultimo indice do array.
	**/
	static void qsortIterative(int* vet, int start, int end);

	/**
		\brief Ordena usando o algoritmo Quicksort recursivo.

		\param arr		Array que ser� ordenado.
		\param start	Primeiro indice do array.
		\param end		Ultimo indice do array.
	**/
	static void qsortRecursive(int* vet, int start, int end);

	/**
		\brief Ordena usando o algoritmo Quicksort recursivo escolhendo 
		piv� para parti��o como sendo a mediana de k elementos do vetor,
		aleatoriamente escolhidos.

		\param arr		Array que ser� ordenado.
		\param start	Primeiro indice do array.
		\param end		Ultimo indice do array.
	**/
	static void qsortMediana(int* vet, int start, int end);


	/**
		\brief Ordena usando o algoritmo Quicksort Recursivo utilizando
		algoritmo de Sele��o para ordenar parti��es (isto �, peda�os do
		vetor) com tamanho menor ou igual a m.

		\param arr		Array que ser� ordenado.
		\param start	Primeiro indice do array.
		\param end		Ultimo indice do array.
		\param m		Tamanho m.
	**/
	static void qsortSelection(int arr[], int start, int end, int m);

	/**
		\brief Ordena usando o algoritmo Quicksort Recursivo processando
		primeiro a menor parti��o.

		\param arr		Array que ser� ordenado.
		\param start	Primeiro indice do array.
		\param end		Ultimo indice do array.
	**/
	static void qsortEmplhaInteligente(int* vet, int start, int end);

	/**
		\brief Verifica se o array est� ordenado.

		\param arr		Array que ser� ordenado.
		\param start	Primeiro indice do array.
		\param end		Ultimo indice do array.
	**/
	static bool isSorted(int arr[], int start, int end);
};

#endif