#include<stdio.h>
#include<stdlib.h>

int BinarySearch(int *a, int l, int h, int k)
{
	int m;
	while(h > l)
	{
		m = (h + l) / 2;
		if (k < a[m])
			h = m - 1;
		else if (k > a[m])
			l = m + 1;
		else
			return m;
	}
	if (h == l && k == a[l])
		return l;
	else
		return -1;
}

int main()
{
	int *a, n, i, key, pos;
	printf("\n  Enter the number of elements : ");
	scanf("%d", &n);
	a = (int*)calloc(n, sizeof(int));
	if (a == NULL)
	{
		printf("\n  Unable to allocate memory!!!");
		exit(1);
	}
	printf("\n  Enter the elements in ascending order ...\n\n");
	for (i = 0; i < n; i++)
	{
		printf("  Enter a[%d] : ", i);
		scanf("%d", &a[i]);
	}
	printf("\n  Enter the search key : ");
	scanf("%d", &key);
	pos = BinarySearch(a, 0, n-1, key);
	if (pos != -1)
		printf("\n  %d is found at index : %d\n", key, pos);
	else
		printf("\n  %d is not found.\n", key);
	return 0;
}
