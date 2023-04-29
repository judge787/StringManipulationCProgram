
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>

//prototypes for functions
char * readFile (char * filename);
void dejaVu (char * aString, int * numWords, int * numSentences);
char * goBig (char * aString);
char ** goAway (char *aString, int * numWordsReturned);
char * breathless (char * aString);
void tail (char* aString, int whichWord, char *desiredSuffix);
