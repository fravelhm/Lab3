
#include <iostream>
#include <string>
#include <vector>

#include <map> // Added as part of PART II
#include <set> // Added as part of PART II
#include <algorithm> // Added as part of PART II

#include "WordList.h"
#include "NgramList.h"

using namespace std;

/*
 * PART II Notes
 *
 * Uses a map in place of linked list
 * Map is defined in header and is called "mapOfNgrams"
 *
 */

/*
 * NgramList
 *
 * takes as input the size of the ngrams to be built and the list  
 * of words to build a map
 *
 * param: int ngramSz - size of the ngram
 * param: const WordList & wl - list of the words use
 */
NgramList::NgramList(int ngramSz, const WordList & wl)
{
   this->ngramSz = ngramSz;
   WordList::const_iterator p;
   //first = NULL;
   int nGramTotal = 0;
   p = wl.begin();
   while (p != wl.end())
   {
      std::string ngram = getNextNgram(p, wl.end());
      p++;
      if (!ngram.empty()) insertNgram(ngram);
   }
}

/*
 * NgramList destructor
 *
 * automatically called when NgramList object goes out of scope
 * deletes the linked list
 */
NgramList::~NgramList()
{
  //free(ngramArray);
}

/*
 * getNextNgram
 *
 * takes as input an iterator that points to the word to start the
 * ngram and an iterator that points to the end of the word list
 * and builds and returns the ngram. returns empty string if no
 * ngram can be built, for example, if there are insufficient words
 * to build one.
 *
 * param: WordList::const_iterator start - points to first word in ngram
 * param: WordList::const_iterator end - points to end of word list
 * return: std::string - returns ngram or empty string
 */
std::string NgramList::getNextNgram(WordList::const_iterator start, 
                                    WordList::const_iterator end)
{
   int i, len;
   string ngram = "";
   for (i = 0; i < ngramSz && start != end; i++)
   {
      std::string word = (*start);
      //see if the string ends with punctuation
      //don't create ngrams that continue after punctuation
      if (!isalpha(word[word.length()-1]) && i < ngramSz - 1) return "";

      //take off all ending punctuation
      len = word.length() - 1;
      while (len >= 0 && !isalpha(word[len])) 
      {
         //remove last character
         word = word.substr(0, word.length() - 1);
         len--;
      }
      if (len < 0) return "";  //give up

      //is the first word in the ngram?
      if (ngram == "") ngram = word;
      else ngram = ngram + " " + word;

      start++;
   }

   //could we build a long enough ngram?
   if (i < ngramSz) return "";

   //take off beginning punctuation
   while (ngram.length() > 0 && !isalpha(ngram[0])) 
      ngram = ngram.substr(1, ngram.length());
   return ngram;
}

/*
 * insertNgram
 *
 * looks for the ngram to be inserted
 * if ngram is already in map then increment that value
 * associated to mapped value 
 * Very similiar to a hashmap where we have a key and a value 
 *
 * param: std::string s - ngram to be inserted
 * return: none
 */
void NgramList::insertNgram(std::string s)
{

  //Very easy to insert using map.  Very similiar syntax as python
  // mapOfNgrams["String Key"] = Int Value;

  bool alreadyExists = (mapOfNgrams.find(s) != mapOfNgrams.end());
  if(alreadyExists)
  {
    //Increment our value that exists where our key is the the string
    mapOfNgrams.at(s)++;
  }
  else
  {
    nGramTotal++;
    //Insert into our map as a new key value pair 
    mapOfNgrams[s] = 1;
  }

}

/*
 * Create a simple string array contains the key values for our map
 *
 */
void NgramList::mapKeyToArray()
{
  ngramArray = new string[nGramTotal];
  int i = 0;
    for(const auto &aPair: mapOfNgrams)
    {
      ngramArray[i] = aPair.first;
      i++;
    }
}


void NgramList::mergeSort(int beg, int end)
{
  int mid = beg+(end-beg)/2;
  if(beg < end)
  {
    mergeSort(beg, mid);
    mergeSort(mid+1, end);
    merge(beg, mid, end);
  }
}

/*
*
*
*
*/
void NgramList::merge(int beg, int mid, int end)
{
  std::string tmp[end-beg+1];
  int i = beg; 
  int j = mid+1;
  int k=0;

  while(i <= mid && j <= end)
  {
    if(mapOfNgrams.at(ngramArray[i]) >= mapOfNgrams.at(ngramArray[j]))
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
    ngramArray[i] = tmp[i-beg];
  }
}

/*
 * sortByCount
 *
 * performs a bubble sort on the linked list of ngrams, sorting the
 * nodes in the list by the count
 *
 * param: none
 * return: none (modfied private linked list)
 */
void NgramList::sortByCount()
{
  mapKeyToArray();
  
  mergeSort(0, nGramTotal-1);
}  

/*
 * operator<<
 *
 * prints the list of ngrams
 *
 * param: std::ostream & os - output stream to direct the output to
 * param: const NgramList & nglst - ngram list object
 * return: std::ostream & - output stream
 */  
std::ostream& operator<<(std::ostream& os, const NgramList & nglst)
{
   cout << "List of " << nglst.ngramSz << " word ngrams and counts\n";
   cout << "--------------------------------\n";
   for(int i = 0; i<nglst.nGramTotal; i++)
   {
     cout << nglst.ngramArray[i] << ", " << nglst.mapOfNgrams.at(nglst.ngramArray[i]) << endl;

   }
   return os;
}
