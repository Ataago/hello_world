//Insertion Sort

#include<stdio.h>
#include<time.h>
int main()
{
    int a[100000], n, i, j, temp;
    float start,end;

    printf("Enter number of elements: ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
        a[i] = rand()%59;

    printf("array elements: ");
    for( i=0; i<n; i++)
        printf("%d",a[i]);

    start = clock();
    for( i = 1; i < n; i++)     //key traverse from a[1] to a[n-1]
        for( j = i;  j > 0; j--)    //checks if key < the previous all to swap
            if( a[j-1] > a[j])
            {
                temp = a[j];
                a[j] = a[j-1];
                a[j-1] = temp;
            }
    end = clock();


    printf("sorted array is: ");
    for(i = 0; i < n; i++)
        printf("%d ",a[i]);

    printf("\nTime : %f",(end - start)/CLK_TCK);

   return 0;
}
