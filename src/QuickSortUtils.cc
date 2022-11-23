#include <iostream>
#include <tuple>
#include "QuickSortUtils.h"

namespace
{
	/**
		\brief Troca as posi��es do array.

		\param p1 Posi��o de origem
		\param p2 Posi��o destino.
	**/
	void swap(int *p1, int *p2)
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
	int getMediana(int *vet, int start, int end)
	{
		return vet[(end - start) / 2 + start];
	}

	/**
		\brief Particiona o arraycom base na escolha de um pivot.

		\param arr Array que ser� particionado.
		\param start Primeiro indice do array.
		\param end Ultimo indice do array.
		\param pivot Piv� usado no particionamento, o padr�o � usar o ultimo elemento do array.

		\return Retorna o indice do menor elemento.
	**/
	std::tuple<int, int, int> partition(int arr[], int start, int end, int pivot = -1)
	{
		int COMPARING_NUMBER = 0, COPIES_NUMBER = 0;
		if (pivot == -1)
			pivot = arr[end];

		int index = (start - 1);

		for (int j = start; j <= end - 1; j++)
		{
			// Verifica se um elemento menor encontrado.
			if (arr[j] < pivot)
			{
				COMPARING_NUMBER++;
				index++;
				swap(&arr[index], &arr[j]);
				COPIES_NUMBER++;
			}
		}

		swap(&arr[index + 1], &arr[end]);
		COPIES_NUMBER++;

		return std::make_tuple(index + 1, COPIES_NUMBER, COMPARING_NUMBER);
	}
}

std::pair<int, int> QuickSortUtils::qsortIterative(int *vet, int start, int end)
{
	int COMPARING_NUMBER = 0, COPIES_NUMBER = 0;
	int size = end - start + 1;
	int *pilhap = (int *)malloc(size * sizeof(int));
	int *pilhar = (int *)malloc(size * sizeof(int));

	pilhap[0] = start;
	pilhar[0] = end;
	COPIES_NUMBER += 2;

	for (int t = 0; t >= 0;)
	{
		start = pilhap[t];
		end = pilhar[t];
		--t;
		COPIES_NUMBER += 2;

		if (start < end)
		{
			std::tuple<int, int, int> tuple = partition(vet, start, end);
			int j = std::get<0>(tuple);
			COPIES_NUMBER += std::get<1>(tuple);
			COMPARING_NUMBER += std::get<2>(tuple);

			++t;
			pilhap[t] = start;
			pilhar[t] = j - 1;
			COPIES_NUMBER += 2;

			++t;
			pilhap[t] = j + 1;
			pilhar[t] = end;
			COPIES_NUMBER += 2;
		}
		COMPARING_NUMBER++;
	}
	return std::make_pair(COPIES_NUMBER, COMPARING_NUMBER);
}
std::pair<int, int> QuickSortUtils::qsortRecursive(int *vet, int start, int end)
{
	int COMPARING_NUMBER = 0, COPIES_NUMBER = 0;
	if (start < end)
	{
		std::tuple<int, int, int> tuple = partition(vet, start, end);
		int pi = std::get<0>(tuple);
		COPIES_NUMBER += std::get<1>(tuple);
		COMPARING_NUMBER += std::get<2>(tuple);

		auto p1 = qsortRecursive(vet, start, pi - 1);
		COPIES_NUMBER += p1.first;
		COMPARING_NUMBER += p1.second;

		auto p2 = qsortRecursive(vet, pi + 1, end);
		COPIES_NUMBER += p2.first;
		COMPARING_NUMBER += p2.second;
	}
	return std::make_pair(COPIES_NUMBER, COMPARING_NUMBER);
}

std::pair<int, int> QuickSortUtils::qsortMediana(int *vet, int start, int end)
{
	int COMPARING_NUMBER = 0, COPIES_NUMBER = 0;
	if (start < end)
	{
		int mediana = getMediana(vet, start, end);

		std::tuple<int, int, int> tuple = partition(vet, start, end, mediana);
		int pi = std::get<0>(tuple);
		COPIES_NUMBER += std::get<1>(tuple);
		COMPARING_NUMBER += std::get<2>(tuple);

		auto p1 = qsortMediana(vet, start, pi - 1);
		COPIES_NUMBER += p1.first;
		COMPARING_NUMBER += p1.second;

		auto p2 = qsortMediana(vet, pi + 1, end);
		COPIES_NUMBER += p2.first;
		COMPARING_NUMBER += p2.second;
	}
	return std::make_pair(COPIES_NUMBER, COMPARING_NUMBER);
}

std::pair<int, int> QuickSortUtils::qsortSelection(int arr[], int start, int end, int m)
{
	int COMPARING_NUMBER = 0, COPIES_NUMBER = 0;
	if (start < end && m <= end - start)
	{
		std::tuple<int, int, int> tuple = partition(arr, start, end);
		int index = std::get<0>(tuple);
		COPIES_NUMBER += std::get<1>(tuple);
		COMPARING_NUMBER += std::get<2>(tuple);

		if (index - start != m - 1)
		{
			std::pair<int, int> p1;
			if (index - start > m - 1)
				p1 = qsortSelection(arr, start, index - 1, m);
			else
				p1 = qsortSelection(arr, index + 1, end, m - index + start - 1);

			COPIES_NUMBER += p1.first;
			COMPARING_NUMBER += p1.second;
		}
	}
	return std::make_pair(COPIES_NUMBER, COMPARING_NUMBER);
}

std::pair<int, int> QuickSortUtils::qsortEmplhaInteligente(int *vet, int start, int end)
{
	int COMPARING_NUMBER = 0, COPIES_NUMBER = 0;
	if (start < end)
	{
		std::tuple<int, int, int> tuple = partition(vet, start, end);
		int pi = std::get<0>(tuple);
		COPIES_NUMBER += std::get<1>(tuple);
		COMPARING_NUMBER += std::get<2>(tuple);

		auto p1 = qsortEmplhaInteligente(vet, start, pi - 1);
		COPIES_NUMBER += p1.first;
		COMPARING_NUMBER += p1.second;

		auto p2 = qsortEmplhaInteligente(vet, pi + 1, end);
		COPIES_NUMBER += p2.first;
		COMPARING_NUMBER += p2.second;
	}
	return std::make_pair(COPIES_NUMBER, COMPARING_NUMBER);
}

bool QuickSortUtils::isSorted(int arr[], int start, int end)
{
	bool sorted = false;
	int lastValue = arr[0];
	for (int i = start; i < end; i++)
	{
		if (lastValue > arr[i])
		{
			sorted = false;
			break;
		}
		lastValue = arr[i];
	}
	return sorted;
}
