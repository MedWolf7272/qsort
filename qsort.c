#include <stdio.h>
#include <stdlib.h>

//опорный - последний элемент массива
void	qsort(int	*arr, int arr_left, int arr_right)
{

	if (arr_left == arr_right || arr_left > arr_right) //условие остановки рекусрии
	{
		return;
	}
	else
	{
		int buf;
		int pillar = arr_right;
		for (int i = 0; i < pillar; i++)
		{
			if (arr[i] > arr[pillar]) //свдиг опорного
			{
				buf = arr[i];
				arr[i] = arr[pillar - 1];
				arr[pillar - 1] = arr[pillar];
				arr[pillar] = buf;
				pillar--;
				i--;
			}
			else
			{
				//nothing
			}
		}
		qsort(arr, arr_left, pillar - 1);
		qsort(arr, pillar + 1, arr_right);
		return;
	}
}
int main()
{
	int n;
	scanf_s("%d", &n);
	int *arr;
	arr = (int*)malloc(sizeof(int)*n);
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", &arr[i]);
	}
	qsort(arr, 0, n - 1);
	for (int i = 0; i < n - 1; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("%d\n", arr[n - 1]);
	return 0;
}
