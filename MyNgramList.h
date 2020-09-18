
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
      Ngram_t ** ngramArray;  //Added as part of part II
      int ngramTotal;  //Added as part of part II
      int ngramSz;
      void insertNgram(std::string s);
      std::string getNextNgram(WordList::const_iterator start, 
                               WordList::const_iterator end);
       
   public:
      NgramList(int ngramSz, const WordList & wl);
      ~NgramList();
      void sortByCount();
      void linkedToArray(); //Added as part of part II
      void merge(int beg, int mid, int end); //Added as part of part II
      void mergeSort(int beg, int end); //Added as part of part II
      friend std::ostream& operator<<(std::ostream& os, const NgramList & nl);
};

