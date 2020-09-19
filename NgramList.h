#include <map> //Added as part of Part II work

class NgramList 
{
   struct Ngram
   {
      std::string ngram;
      int count;
      struct Ngram * next;
   };

   typedef struct Ngram Ngram_t;

   private:
      Ngram_t * first;
      std::string * ngramArray;  //Added as part of part II
      int ngramSz;
      int nGramTotal; //Added as part of part II
      void mapKeyToArray(); //Added as part of part II
      void mergeSort(int beg, int end); //Added as part of part II
      void merge(int beg, int mid, int end); //Added as part of part II
      std::map<std::string, int> mapOfNgrams; //Added as part of part II
      void insertNgram(std::string s);
      std::string getNextNgram(WordList::const_iterator start, 
                               WordList::const_iterator end);
       
   public:
      NgramList(int ngramSz, const WordList & wl);
      ~NgramList();
      void sortByCount();
      friend std::ostream& operator<<(std::ostream& os, const NgramList & nl);
};

