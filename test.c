#include "test.h"
#include "mergesort.h"
#include "insertsort.h"
#include "load_file.h"
#include <time.h>
#include <Windows.h>
#include <stdio.h>

//Global variables - only change these values
int arr[] = { 1,9,9,8,0,1,1,0 }; //Swedish personal number
int n_size = sizeof(arr) / sizeof(arr[0]); //Size of the array
int* array = arr;

char sortingProblem[] = { "sorting_problems/problem-100000-1-problem" };
char sortingSolution[] = { "sorting_problems/problem-100000-1-solution" };
char sortingBackward[] = { "sorting_problems/problem-100000-1-backward" };

//################TASK1&TASK4 INSERT SORT######################################
void test_InsertionSort() {

	//Local variables
	int pers = 1; //So we know to sort personal number or problem array
	int* sortedArray = insertionSort(array, n_size, pers);

	//Printing result
	printf("Task 1 and 4: Insertion Sort\n");
	printPersonalnumber(sortedArray, n_size);
	printf("\n");
}

////################TASK2&TASK4 MERGE SORT######################################
void test_MergeSort() {

	//Local variables
	int p = 0;
	int r = n_size - 1;

	//Functions
	MergeSort(array, p, r);

	//Printing result
	printf("Task 2 and 4: Merge Sort \n");
	printPersonalnumber(array, n_size);
	printf("\n");
}

//################TASK5 LOAD FILES - INSERTION SORT#######################################
void test_InsertionSort_loadf() {

	//Local variabels
	int pers = 0;
	int* problemArr = load_file(sortingProblem);
	int* solutionArr = load_file(sortingSolution);
	int* backwardArr = load_file(sortingBackward);
	//Offset arrary from printing the 0th element, i.e. how many values in the array
	int n = problemArr[0] + 1;

	//Reset running time
	float time_spent = 0.0;

	//Print problem array from file 
	printf("Task 5: Insertion Sort\n");
	printf("Unsorted data #1\n");
	printArray(problemArr, n);

	if (problemArr != NULL) {
		//Calculate running time
		printf("Starting insertion sort on unsorted data...\n");
		clock_t start = clock();
		int* sortedArray_loadf = insertionSort(problemArr, n, pers);
		clock_t end = clock();
		time_spent = ((float)(end - start)) / CLOCKS_PER_SEC;

		printf("Insertion Sort took %f seconds to execute \n\n", time_spent);

		//Print sorted array
		printf("Sorted array #1\n");
		printArray(sortedArray_loadf, n);
	}

	if (backwardArr != NULL) {
		//Calculate running time
		printf("Starting insertion sort on descending order...\n");
		clock_t start = clock();
		int* sortedArray_loadf = insertionSort(backwardArr, n, pers);
		clock_t end = clock();
		time_spent = ((float)(end - start)) / CLOCKS_PER_SEC;

		printf("Insertion Sort took %f seconds to execute \n\n", time_spent);
		
		//Print sorted array
		printf("Sorted array #2\n");
		printArray(sortedArray_loadf, n);
	}

	if (solutionArr != NULL) {
		//Calculate running time
		printf("Starting insertion sort on accending order...\n");
		clock_t start = clock();
		int* sortedArray_loadf = insertionSort(solutionArr, n, pers);
		clock_t end = clock();
		time_spent = ((float)(end - start)) / CLOCKS_PER_SEC;

		printf("Insertion Sort took %f seconds to execute \n\n", time_spent);

		//Print sorted array
		printf("Sorted array #3\n");
		printArray(sortedArray_loadf, n);
	}		

	//Print correct solution from file
	printf("The correct solution InsertionSort\n");
	printArray(solutionArr, n);
}

//################TASK5 LOAD FILES - MERGE SORT#######################################
void test_MergeSort_loadf() {

	//Locla variables
	int* problemArr = load_file(sortingProblem);
	int* solutionArr = load_file(sortingSolution);
	int* backwardArr = load_file(sortingBackward);

	int n = problemArr[0] + 1;
	int p = 1;
	int r = n - 1;

	//Print problem array from file
	printf("Task 5: Merge Sort\n");
	printf("Unsorted data #2\n");
	printArray(problemArr, n);

	if (problemArr != NULL) {
		//Calculate running time	
		double time_spent = 0.0; //Reset running time
		clock_t start = clock();
		int* sortedArray_loadf = MergeSort(problemArr, p, r);
		clock_t end = clock();
		time_spent = ((float)(end - start)) / CLOCKS_PER_SEC;

		printf("Merge Sort took %f seconds to execute \n", time_spent);

		//Print sorted array
		printf("Sorted array #1\n");
		printArray(sortedArray_loadf, n);
	}

	if (backwardArr != NULL) {
		//Calculate running time	
		double time_spent = 0.0; //Reset running time
		clock_t start = clock();
		int* sortedArray_loadf = MergeSort(problemArr, p, r);
		clock_t end = clock();
		time_spent = ((float)(end - start)) / CLOCKS_PER_SEC;

		printf("Merge Sort took %f seconds to execute \n", time_spent);

		//Print sorted array
		printf("Sorted array #2\n");
		printArray(sortedArray_loadf, n);
	}

	if (solutionArr != NULL) {
		//Calculate running time	
		double time_spent = 0.0; //Reset running time
		clock_t start = clock();
		int* sortedArray_loadf = MergeSort(solutionArr, p, r);
		clock_t end = clock();
		time_spent = ((float)(end - start)) / CLOCKS_PER_SEC;

		printf("Merge Sort took %f seconds to execute \n", time_spent);

		//Print sorted array
		printf("Sorted array #3\n");
		printArray(sortedArray_loadf, n);
	}
	//Print correct solution from file
	printf("The correct solution MergeSort\n");
	printArray(solutionArr, n);
}

//Print array of in the case of a Swedish psersonal number
//i.e. print the whole array
void printPersonalnumber(int* array, int n) {
	for (int i = 0; i < n; i++){
		printf("%d ", array[i]);
	}
	printf("\n");
}

//Print array except first element
//i.e. don't print how many elemets are in the array as a part of the array
void printArray(int array[], int n) {
	if (n > 11) {
		printf("Only printing the first 10 values of %d.\n", n-1);
	}
	for (int i = 1; i < n && i <= 10; i++)
	{
		printf("%d ", array[i]);
	}
	if (n > 11) {
		printf("...");
	}
	printf("\n\n");
}
