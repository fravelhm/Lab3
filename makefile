CC = g++ 
CFLAGS = -g -pg -c -std=c++0x
OBJS = NgramList.o WordList.o main.o
MYOBJS = MyNgramList.o WordList.o myMain.o
LFLAGS = -pg 

.C.o:
	$(CC) $(CFLAGS) $< -o $@

#my-ngram: MyNgramList.o WordList.o myMain.o
#	$(CC) $(LFLAGS) $(MYOBJS) -o my-ngram

ngram: NgramList.o WordList.o main.o
	$(CC) $(LFLAGS) $(OBJS) -o ngram

main.o: WordList.h NgramList.h

myMain.o: WordList.h MyNgramList.h

WordList.o: WordList.h

NgramList.o: NgramList.h WordList.h

MyNgramList.o: MyNgramList.h WordList.h

clean:
	rm *.o ngram my-ngram gmon.out 

submit:
	submit efb 3482-lab3 NgramList.h NgramList.C WordList.h WordList.C main.C report.txt makefile
