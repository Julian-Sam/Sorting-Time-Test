#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>


void Bucket_Sort(int array[], int n)
{  
    int i, j;  
    int* count = malloc(sizeof(int)*n); 
    for (i = 0; i < n; i++)
        count[i] = 0;
 
    for (i = 0; i < n; i++)
        (count[array[i]])++;
 
    for (i = 0, j = 0; i < n; i++)  
        for(; count[i] > 0; (count[i])--)
            array[j++] = i;

    free(count);
} 

int* CopyList(int* A, int len)
{
	int* B = malloc(sizeof(int)*len);
    int i;
	for ( i = 0; i < len; ++i)
	{
		B[i] = A[i];
	}

	return B;
}





void quickSort( int a[], int l, int r)
{
   int j;

   if( l < r ) 
   {
    // divide and conquer
        j = partition( a, l, r);
       quickSort( a, l, j-1);
       quickSort( a, j+1, r);
   }
    
}



int partition(int a[], int l, int r) {
   int pivot, i, j, t;
   pivot = a[l];
   i = l; j = r+1;
        
   while( 1)
   {
    do ++i; while( a[i] <= pivot && i <= r );
    do --j; while( a[j] > pivot );
    if( i >= j ) break;
    t = a[i]; a[i] = a[j]; a[j] = t;
   }
   t = a[l]; a[l] = a[j]; a[j] = t;
   return j;
}





int64_t timespecDiff(struct timespec *timeA_p, struct timespec *timeB_p)
{
  return ((timeA_p->tv_sec * 1000000000) + timeA_p->tv_nsec) -
           ((timeB_p->tv_sec * 1000000000) + timeB_p->tv_nsec);
}   

int isSorted(int A[], int listLength)
{
    int i = 0;
    for ( i = 0; i < listLength-1; ++i)
    {
        if (A[i] > A[i+1])
            return 0;
    }
    return 1;
}

int main(int argc, char *argv[])
{

    // Open passed in file to see the array
    // Files should be lines of ints
    FILE * pFile ;
    pFile = fopen(argv[1],"r");

    if (pFile == NULL) // Gotta check for them NULL pointers !
    {
        printf("File not found error. Make sure file name is passed as argument\n");
        return 1;
    }
    int listLength;
    fscanf(pFile, "%d", &listLength);

    int* list = malloc(sizeof(int)*listLength);
    
    int listAdd = 0;
    int i = 0;

    while(fscanf(pFile, "%d", &listAdd)>0)
    {
    	list[i] = listAdd;
    	i = i + 1;
    }

    int* list1 = CopyList(list,listLength);

    // Bucketsort Check for time
    clock_t start = clock(), diff;
    Bucket_Sort(list,listLength);
    diff = clock() - start;

    int msec = diff * 1000 / CLOCKS_PER_SEC;
    printf("Time taken %d seconds %d milliseconds for Bucket Sort\n", msec/1000, msec%1000);


    // Quicksort Check for time
    clock_t start1 = clock(), diff1;
    quickSort(list1,0,listLength);
    diff1 = clock() - start1;
    int msec1 = diff1 * 1000 / CLOCKS_PER_SEC;
    printf("Time taken %d seconds %d milliseconds for Quick Sort\n", msec1/1000, msec1%1000);


    // Make sure the lists are sorted
    if (isSorted(list1, listLength)  == 0)
        printf("QERROR\n");
    if (isSorted(list,listLength) == 0)
        printf("ERORR in Bucket Sort\n");

	
    free(list);
    free(list1);
    return 0;



}
