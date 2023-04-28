/*
Student Name: Jashan Judge
Student ID: 1150301
Due Date: Monday March 6
Course: CIS*2500
I have exclusive control over this submission via my password.
By including this header comment, I certify that:
1) I have read and understood the policy on academic integrity.
2) I have completed Moodle's module on academic integrity.
3) I have achieved at least 80% on the academic integrity quiz
I Jashan Judge assert that this work is my own. I have appropriate acknowledged
any and all material that I have used, be it directly quoted or
paraphrased. Furthermore, I certify that this assignment was written
by me in its entirety.*/
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