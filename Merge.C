/**
 * Names: Andrew Evans
 *        Hayden Fravel
 */

//merges the two arrays
int * merge(int * arr1, int * arr2){
    int n1, n2, i, j, k;
    i = j = k = 0;
    n1 = sizeof(arr1);
    n2 = sizeof(arr2);
    int arr0[n1+n2];
    
    while (i < n1 && j < n2){        //chooses lesser of two elements in each array
        if (arr1[i] < arr2[j]){
            arr0[k++] = arr1[i++];
        }
        else{
            arr0[k++] = arr2[j++];
        }
    }
    
    while (i < n1){                 //throws remaining elements into the return array
        arr0[k++] = arr1[i++];
    }
    while (j < n2){
        arr0[k++] = arr2[j++];
    }

    return arr0;                    //return
}

//Splits array in two, left and right
int * mergeSort(int * arr, int beg, int end){
    if (end > beg){;
        int * arr1 = mergeSort(arr, beg, end/2);    //left side
        int * arr2 = mergeSort(arr, end/2+1, end);  //right side
        return merge(arr1, arr2);                   //merges the two sides
    }
    return arr;
}

