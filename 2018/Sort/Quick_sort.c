//Quick Sort

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void Quick_Sort(int a[], int low, int high);
int Partition(int a[], int low, int high);

int main()
{
	int a[100],n,i;
	//clrscr();

	printf("Enter the number of Elements: ");
	scanf("%d",&n);

	for(i = 0; i<n; i++)
		a[i] = rand()%50;

	printf("Array is: ");
	for(i=0; i<n; i++)
		printf("%d ",a[i]);

	Quick_Sort(a,0,n-1);

	printf("\nSorted Array is: ");
	for(i=0; i<n; i++)
		printf("%d ",a[i]);

	//getch();
	return NULL;
}

void Quick_Sort(int a[], int low, int high)
{
	int PivotLoc;

	if(high > low)
	{
		PivotLoc = Partition(a,low,high);
		Quick_Sort(a,low, PivotLoc - 1);
		Quick_Sort(a,PivotLoc + 1, high);
	}
}

int Partition(int a[], int low, int high)
{
	int left=low, right=high, temp;

	while(left < right)
	{
		while( a[low] >= a[left])    //a[low] is the pivot element
			left++;
		while( a[low] < a[right])
			right--;
		if( left < right )
		{
			temp = a[left];
			a[left] = a[right];
			a[right] = temp;
		}
	}
	temp = a[right];
	a[right] = a[low];
	a[low] = temp;
	return right;
}

