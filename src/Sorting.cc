#include <iostream>
#include "Sorting.h"

namespace {
	/**
		\brief Troca as posições do array.

		\param p1 Posição de origem
		\param p2 Posição destino.
	**/
	void swap(int* p1, int* p2);


	/**
		\brief Troca as posições do array.

		\param arr		Array que será ordenado.
		\param left		Primeiro indice do array.
		\param mid		Indice do meio do array.
		\param right	Ultimo indice do array.
	**/
	void merge(int arr[], int left, int mid,
		int right);

	/**
		\brief Empilha.

		\param arr		Array que será ordenado.
		\param size		Tamnho do array.
		\param index	Indice do array.
	**/
	void heapify(int arr[], int n, int i);

}

void Sorting::heapSort(int arr[], int n)
{
	for (int i = n / 2 - 1; i >= 0; i--) heapify(arr, n, i);

	for (int i = n - 1; i >= 0; i--) {
		swap(&arr[0], &arr[i]);
		heapify(arr, i, 0);
	}
}

void Sorting::mergeSort(int arr[], int start, int end)
{
	if (start >= end) return;

	auto mid = start + (end - start) / 2;
	mergeSort(arr, start, mid);
	mergeSort(arr, mid + 1, end);
	merge(arr, start, mid, end);
}


namespace {
	void swap(int* p1, int* p2)
	{
		int temp = *p1;
		*p1 = *p2;
		*p2 = temp;
	}

	void merge(int arr[], int  left, int  mid, int  right)
	{
		auto const subArrayOne = mid - left + 1;
		auto const subArrayTwo = right - mid;

		auto* leftArray = new int[subArrayOne];
		auto* rightArray = new int[subArrayTwo];

		for (auto i = 0; i < subArrayOne; i++)
			leftArray[i] = arr[left + i];
		for (auto j = 0; j < subArrayTwo; j++)
			rightArray[j] = arr[mid + 1 + j];

		auto indexOfSubArrayOne = 0;
		auto indexOfSubArrayTwo = 0;
		int indexOfMergedArray = left;

		while (indexOfSubArrayOne < subArrayOne
			&& indexOfSubArrayTwo < subArrayTwo) {
			if (leftArray[indexOfSubArrayOne]
				<= rightArray[indexOfSubArrayTwo]) {
				arr[indexOfMergedArray]
					= leftArray[indexOfSubArrayOne];
				indexOfSubArrayOne++;
			}
			else {
				arr[indexOfMergedArray]
					= rightArray[indexOfSubArrayTwo];
				indexOfSubArrayTwo++;
			}
			indexOfMergedArray++;
		}

		while (indexOfSubArrayOne < subArrayOne) {
			arr[indexOfMergedArray]
				= leftArray[indexOfSubArrayOne];
			indexOfSubArrayOne++;
			indexOfMergedArray++;
		}

		while (indexOfSubArrayTwo < subArrayTwo) {
			arr[indexOfMergedArray]
				= rightArray[indexOfSubArrayTwo];
			indexOfSubArrayTwo++;
			indexOfMergedArray++;
		}

		delete[] leftArray;
		delete[] rightArray;
	}


	void heapify(int arr[], int size, int index)
	{
		int largest = index;
		int left = 2 * index + 1;
		int right = 2 * index + 2;

		if (left < size && arr[left] > arr[largest]) largest = left;
		if (right < size && arr[right] > arr[largest])	largest = right;

		if (largest != index) {
			swap(&arr[index], &arr[largest]);
			heapify(arr, size, largest);
		}
	}

}
