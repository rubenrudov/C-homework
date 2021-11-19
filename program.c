/**
 * @Authors: Amit Machluf & Ruben Rudov
 * @Purpose: Matrix classwork and homework
 */
#include <stdio.h>
#define COL 3
#define ROW 3
#define enum { true, false } bool;

 // Function declerations 

// Matrixes page 1
void getValue(int* [], int);
void printMat(int* [], int);
void printMatRow(int* [], int);
int matSum(int* [], int);
int matDiaSum(int* [], int);
int matsSum(int* [], int* [], int* [], int);
int maxElem(int* [], int);
int minmax(int* [], int);
int maxmin(int* [], int);
//bool findelement(int*[], int, int);
int findelement(int*[], int, int);

// Matrixes page 2
int balanced(int* [], int);
int arrmult(int [], int); 
void perfect(int* [], int);
int placed(int**);
int allin(int[], int);
int latin(int* [], int);


// Main function
void main()
{
	int a[ROW][COL];
	getValue(a, ROW);
	printMatRow(a, ROW);
	printf("%d", matDiaSum(a, ROW));
	scanf_s("%d", &a);
}


// Page 1 implementations
void getValue(int(*a)[COL], int n)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < COL; j++)
		{
			scanf_s("%d", &a[i][j]);
		}
	}
}

// Print the matrix's elements
void printMat(int(*a)[COL], int n) {
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < COL; j++)
		{
			printf("%d ", a[i][j]);
		}
	}

	printf("\n");
}

// Print the matrix's elements by rows
void printMatRow(int(*a)[COL], int n) {
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < COL; j++)
		{
			printf("%d ", a[j][i]);
		}
	}

	printf("\n");
}

int matSum(int(*a)[COL], int n)
{
	int i, j, sum = 0;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < COL; j++)
		{
			sum += a[i][j];
		}
	}
	return sum;
}

int matDiaSum(int(*a)[COL], int n)
{
	int i, j, sum = 0;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < COL; j++)
		{
			if ((j == i) || (j + i == n - 1))
				sum += a[i][j];
		}
	}
	return sum;
}

int matsSum(int(*a)[COL], int(*b)[COL], int(*c)[COL], int n)
{
	int i, j, sum = 0;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < COL; j++)
		{
			c[i][j] = a[i][j] + b[i][j];
		}
	}
	return sum;
}

int maxElem(int(*a)[COL], int n)
{
	int max = **a;
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < COL; j++)
		{
			if (((a + i) + j) > max)
				max = ((a + i) + j);
		}
	}
	return max;
}

int maxarr(int* a, int n)
{
	int max = *a;
	int i;
	for (i = 1; i < n; i++)
	{
		if (*(a + i) > max)
			max = *(a + i);
	}
	return max;
}

int minmax(int(*a)[COL], int n)
{
	int i;
	int min = maxarr(a[0], COL);
	for (i = 1; i < n; i++)
	{
		if (maxarr(a[i], COL) < min)
			min = maxarr(a[i], COL);
	}
	return min;
}

int maxindex(int* a, int n)
{
	int max = *a;
	int i, maxindex = 0;
	for (i = 1; i < n; i++)
	{
		if (*(a + i) > max) {
			max = *(a + i);
			maxindex = i;
		}
	}
	return maxindex;
}

int maxmin(int(*a)[COL], int n)
{
	int i, j, max, min;
	for (i = 0; i < n; i++)
	{
		max = maxindex(a[i], COL);
		min = maxarr(a[i], COL);
		for (j = 0; j < n; j++)
		{
			if (a[j][max] < min)
				break;
			if (j == n - 1)
				return min;
		}
	}
	return -1;
}
int findelement(int(*a)[COL], int n, int x)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < COL; j++)
			if (a[i][j] == x)
				return 1;
	}
	return 0;
}


// Page 2 implementations
int balanced(int(*a)[COL], int n)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < i; j++)
		{
			if (a[i][j] != a[j][i])
				return 0;
		}
	}
	return 1;
}

int arrmult(int a[], int n)
{
	int mul = 1;
	int i;
	for (i = 0; i < n; i++)
		mul *= a[i];
	return mul;
}

void perfect(int(*a)[COL], int n)
{
	int i, j;
	int sum1 = 0, sum2 = 0;
	for (i = 0; i < n; i++)
	{
		if (arrmult(a[i], COL) != (i + 1) * (i + 1)) {
			printf("not perfect");
			return;
		}
		for (j = 0; j < n; j++)
		{
			if (i == j) {
				sum1 += a[i][j];
			}
			if (i + j == COL - 1) {
				sum2 += a[i][j];
			}
		}
	}
	if (sum1 != sum2)
		printf("not perfect");
	else
		printf("perfect");
	return;
}

int placed(int a[5][7])
{
	int i, j, counter = 0;
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 7; j++)
			if (i + j == a[i][j])
				counter++;

	}
	return counter;
}

int allin(int a[], int n)
{
	int i;
	int* temp = (int*)calloc(n, sizeof(int));
	assert(temp != NULL);
	for (i = 0; i < n; i++) temp[i] = 0;
	for (i = 0; i < n; i++)
	{
		if (a[i] > n)
			return 0;
		temp[a[i] - 1] = temp[a[i] - 1] + 1;
	}
	for (i = 0; i < n; i++)
		if (temp[i] == 0 || temp[i] > 1) {
			free(temp);
			return 0;
		}
	free(temp);
	return 1;
}

int latin(int(*a)[COL], int n)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		if (allin(a[i], COL) == 0)
			return 0;
	}
	return 1;
}
