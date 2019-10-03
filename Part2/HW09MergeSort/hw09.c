// ***
// *** You must modify this file
// ***
#include <stdio.h>  
#include <stdlib.h> 
#include <string.h> 
#include <stdbool.h>
#include "hw09.h"

// DO NOT MODIFY --->>>> From Here
// Do not modify this function. It is used for grading.
void printInput(char * msg, int * arr, int l, int m, int r)
{
  printf("%s(%6d, %6d, %6d)", msg, l, m, r);
  int ind;
  for (ind = l; ind <= r; ind ++)
    {
      printf("%d\n", arr[ind]);
    }
}
// DO NOT MODIFY <<<<--- Until Here

#ifdef TEST_READDATA
// the input file is binary, storing integers
//
// arr stores the address of a pointer for storing the
// address of the allocated memory
//
// size stores the address keeping the size of the array
bool readData(char * filename, int * * arr, int * size)
{
  // use fopen to open the file for read
  // return false if fopen fails
  FILE * file;
  file = fopen(filename, "r");
  
  if(file == NULL)
  {
	return false;
  }

  // use fseek to go to the end of the file
  // check whether fseek fails
  // if fseek fails, fclose and return false
  
  // fseek returns integer
  // 0 for success, -1 for failure
  
  int seekTest; // answer for if fseek succeeds or fails
  
  seekTest = fseek(file, 0, SEEK_END);
  if(seekTest == -1)
  {
	fclose(file);
	return false;
  }

  // use ftell to determine the size of the file
  *size = ftell(file);

  // use fseek to go back to the beginning of the file
  // check whether fseek fails
  // if fseek fails, fclose and return false
  seekTest = fseek(file, 0, SEEK_SET);
    
    if(seekTest == -1)
  {
	fclose(file);
	return false;
  }
  
  // the number of integers is the file's size divided by size of int  
  *size = *size / sizeof(int);

  // allocate memory for the array
  *arr = malloc(sizeof(int) * (*size));
  
  // if malloc fails, fclose and return false
  if(*arr == NULL)
  {
	fclose(file);
	return false;
  }

  // use fread to read the number of integers in the file
  int count; // number of integers read by the fread function
  
  count = fread(*arr, sizeof(int), *size, file);
  
  // if fread does not read the correct number
  // release allocated memory
  // fclose
  // return false
  
  if(count != *size)
  {
	free(arr);
	fclose(file);
	return false;
  }
  
  // if fread succeeds
  // close the file
  fclose(file);
  
  return true;
}
#endif

#ifdef TEST_WRITEDATA
// the output file is binary, storing sorted integers
// write the array of integers to a file
// must use fwrite. must not use fprintf
bool writeData(char * filename, const int * arr, int size)
{
  // fopen for write
  FILE * file;
  file = fopen(filename, "w");

  // if fopen fails, return false
  if(file == NULL)
  {
	fclose(file);
	return false;
  }

  // use fwrite to write the entire array to a file
  int count; // number of integers written to the file
  count = fwrite(&arr, sizeof(int), size, file);
  
  // check whether all elements of the array have been written
  // if not all elements have been written, return false
  if(count != size)
  {
	fclose(file);
	return false;
  }

  // fclose
  fclose(file);

  // if all elements have been written, return true
  return true;
}
#endif


#ifdef TEST_MERGE
// input: arr is an array and its two parts arr[l..m] and arr[m+1..r]
// are already sorted
//
// output: arr is an array and all elements in arr[l..r] are sorted
//
// l, m, r mean left, middle, and right respectively
//
// You can assume that l <= m <= r.
//
// Do not worry about the elements in arr[0..l-1] or arr[r+1..]

static void merge(int * arr, int l, int m, int r)
// a static function can be called within this file only
// a static function is invisible to other files
{
  // at the beginning of the function
#ifdef DEBUG
  // Do not modify this part between #ifdef DEBUG and #endif
  // This part is used for grading. 
  printInput("Merge in", arr, l, m, r);
#endif

  int i;
  int left_end; 
  int count;
  int tmp_pos;

  int * tmp;
  
  tmp = malloc(sizeof(int) * sizeof(arr));
    
  left_end = m - 1;
  tmp_pos = l;
  count = r - l + 1;
 
    while ((l <= left_end) && (m <= r))
    {
        if (arr[l] <= arr[m])
        {
            tmp[tmp_pos] = arr[l];
            tmp_pos = tmp_pos + 1;
            l = l + 1;
        }
        else
        {
            tmp[tmp_pos] = arr[m];
            tmp_pos = tmp_pos + 1;
            m = m + 1;
        }
    }
 
    while (l <= left_end)
    {
        tmp[tmp_pos] = arr[l];
        l = l + 1;
        tmp_pos = tmp_pos + 1;
    }
    while (m <= r)
    {
        tmp[tmp_pos] = arr[m];
        m = m + 1;
        tmp_pos = tmp_pos + 1;
    }
 
    for (i = 0; i <= count; i++)
    {
        arr[r] = tmp[r];
        r = r - 1;
    }
  
	  
	  
	  
	  
 
  

  // if one or both of the arrays are empty, do nothing
  




  // Hint: you may consider to allocate memory here.
  // Allocating additional memory makes this function easier to write




  // merge the two parts (each part is already sorted) of the array
  // into one sorted array

  


  // the following should be at the bottom of the function
#ifdef DEBUG
  // Do not modify this part between #ifdef DEBUG and #endif
  // This part is used for grading. 
  printInput("Merge out", arr, l, m, r);
#endif
}
#endif

// merge sort has the following steps:

// 1. if the input array has one or no element, it is already sorted
// 2. break the input array into two arrays. Their sizes are the same,
//    or differ by one
// 3. send each array to the mergeSort function until the input array
//    is small enough (one or no element)
// 4. sort the two arrays 
#ifdef TEST_MERGESSORT
void mergeSort(int arr[], int l, int r) 
{
  // at the beginning of the function
#ifdef DEBUG
  // Do not modify this part between #ifdef DEBUG and #endif
  // This part is used for grading. 
  printInput("mergeSort", arr, l, r, -1);
#endif
  // local variables
  int midpoint; // middle of the array
  
  midpoint = 0;
  
  // if the array has no or one element, do nothing
  if(l < r)
  {
	// divide the array into two arrays
    midpoint = (l + r) / 2; 
	
	// call mergeSort with each array
    mergeSort(arr, l, midpoint);
    mergeSort(arr, midpoint + 1, r);
  
    // merge the two arrays into one
 
    merge(arr, l, midpoint, r);
  }

  


} 
#endif
