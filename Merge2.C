//Assume using globally defined array 
// {1,2,3,4,5}
void mergeSort(int beg, int end)
{
  int mid = beg+(end-beg)/2;
  if(beg < end)
  {
    mergeSort(beg, mid);
    mergeSort(mid+1, end);
    merge(beg, mid, end);
  }
}

void merge(int beg, int mid, end)
{
  Ngram_t ** tmp[end-beg+1];
  int i = start, j = mid+1, k=0;

  while(i <= mid && j <= end)
  {
    if(ngramArray[i]->cout <= ngramArray[j]->count)
    {
      tmp[k] = ngramArray[i];
      k++;
      i++;
    }
    else
    {
      tmp[k] = ngramArray[j];
      k++;
      j++;
    }
  }

  while(i <= mid)
  {
    tmp[k] = ngramArray[i];
    k++;
    i++;
  }

  while(j <= end)
  {
    tmp[k] = ngramArray[j];
    k++;
    j++;
  }

  for(i = beg; i<=end; i++)
  {
    ngramArray[i] = tmp[i-start];
  }
}
