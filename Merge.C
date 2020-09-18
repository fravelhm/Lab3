/**
 * Names: Andrew Evans
 *        Hayden Fravel
 */
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;
//merges the two arrays
int * merge(int * arr1, int * arr2){
    int n1, n2, i, j, k;
    i = j = k = 0;
    n1 = sizeof(arr1)/sizeof(arr1[0]);
    cout << "size of n1: " << n1 << endl;
    n2 = sizeof(arr2)/sizeof(arr2[0]);
    cout << "size of n2: " << n2 << endl;
    int arr0[n1+n2];
    
    while (i < n1 && j < n2){        //chooses lesser of two elements in each array
        if (arr1[i] < arr2[j]){
            arr0[k] = arr1[i];
            k++;
            i++;
        }
        else{
            arr0[k] = arr2[j];
            k++;
            j++;
        }
    }
    
    while (i < n1){                 //throws remaining elements into the return array
        arr0[k] = arr1[i];
        k++;
        i++;
    }
    while (j < n2){
        arr0[k] = arr2[j];
        k++;
        j++;
    }

    return arr0;                    //return
}

//Splits array in two, left and right
int * mergeSort(int * arr, int beg, int end){
  int mid = (beg+end)/2;
    if (end > beg){
        int * arr1 = mergeSort(arr, beg, mid);    //left side
        int * arr2 = mergeSort(arr, mid+1, end);  //right side
        merge(arr1, arr2);                   //merges the two sides
    } 
}

int main(int argc, char * argv[])
{
  int test[5] = {1,2,3,4,5};
  int* result = mergeSort(test, 0, 4);
  for(int x=0; x<5; x++)
  {
  cout << result[x] << "\n";
  }
}


