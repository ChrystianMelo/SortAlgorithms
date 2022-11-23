#include <iostream>
#include "QuickSortUtils.h"

namespace {
	/**
		\brief Troca as posições do array.

		\param p1 Posição de origem
		\param p2 Posição destino.
	**/
	void swap(int* p1, int* p2)
	{
		int temp = *p1;
		*p1 = *p2;
		*p2 = temp;
	}

	/**
		\brief Faz o calculo da mediana dos valores do array.

		\param vet Array .
		\param start Primeiro indice do array.
		\param end Ultimo indice do array.
	**/
	int getMediana(int* vet, int start, int end) {
		return vet[(end - start) / 2 + start];
	}

	/**
		\brief Particiona o arraycom base na escolha de um pivot.

		\param arr Array que será particionado.
		\param start Primeiro indice do array.
		\param end Ultimo indice do array.
		\param pivot Pivô usado no particionamento, o padrão é usar o ultimo elemento do array.

		\return Retorna o indice do menor elemento.
	**/
	int partition(int arr[], int start, int end, int pivot = -1)
	{
		if (pivot == -1)
			pivot = arr[end];

		int index = (start - 1);

		for (int j = start; j <= end - 1; j++) {
			// Verifica se um elemento menor encontrado.
			if (arr[j] < pivot) {
				index++;
				swap(&arr[index], &arr[j]);
			}
		}

		swap(&arr[index + 1], &arr[end]);

		return (index + 1);
	}
}

void QuickSortUtils::qsortIterative(int* vet, int start, int end)
{
	int size = end - start + 1;
	int* pilhap = (int*)malloc(size * sizeof(int));
	int* pilhar = (int*)malloc(size * sizeof(int));

	pilhap[0] = start; pilhar[0] = end;

	for (int t = 0; t >= 0;) {
		start = pilhap[t]; end = pilhar[t]; --t;
		if (start < end) {
			int j = partition(vet, start, end);
			++t; pilhap[t] = start; pilhar[t] = j - 1;
			++t; pilhap[t] = j + 1; pilhar[t] = end;
		}
	}
}
void QuickSortUtils::qsortRecursive(int* vet, int start, int end)
{
	if (start < end) {
		int pi = partition(vet, start, end);

		qsortRecursive(vet, start, pi - 1);
		qsortRecursive(vet, pi + 1, end);
	}
}

void QuickSortUtils::qsortMediana(int* vet, int start, int end)
{
	if (start < end) {
		int mediana = getMediana(vet, start, end);
		int pi = partition(vet, start, end, mediana);

		qsortMediana(vet, start, pi - 1);
		qsortMediana(vet, pi + 1, end);
	}
}

void  QuickSortUtils::qsortSelection(int arr[], int start, int end, int m)
{
	// If k is smaller than number of 
	// elements in array
	if (start < end && m <= end - start) {
		int index = partition(arr, start, end);

		// If position is same as k
		if (index - start != m - 1) {
			// If position is more, recur 
			// for left subarray
			if (index - start > m - 1)
				qsortSelection(arr, start, index - 1, m);
			else
				qsortSelection(arr, index + 1, end,
					m - index + start - 1);
		}
	}
}

void QuickSortUtils::qsortEmplhaInteligente(int* vet, int start, int end)
{
	if (start < end) {
		int pi = partition(vet, start, end);

		qsortEmplhaInteligente(vet, start, pi - 1);
		qsortEmplhaInteligente(vet, pi + 1, end);
	}
}

bool QuickSortUtils::isSorted(int arr[], int start, int end) {
	bool sorted = false;
	int lastValue = arr[0];
	for (int i = start; i < end; i++) {
		if (lastValue > arr[i]) {
			sorted = false;
			break;
		}
		lastValue = arr[i];
	}
	return sorted;
}

