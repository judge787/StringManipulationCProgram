#include "../include/judgeJashanA2.h"


int main(int argc, char**argv){

       if (argv[1] == NULL){//checks if the correct arguments/file are not found from the command line (file name)
        printf("Arguments not found");
        exit(0);
    }

//Read File T1 
    //reads the argument from the command line for a filename which the contents from get stored in aString
    char * aString;
    aString = malloc(sizeof(char)*100000);
    aString = readFile(argv[1]);

//Deja Vu T2

    int *numWords;//allocate space for variables and set them to 0
    numWords = malloc(sizeof(int));
    int *numSentences;
    numSentences = malloc(sizeof(int));
    *numWords = 0; 
    *numSentences =0;


    dejaVu(aString, numWords, numSentences);//caal the function
    printf("\nMain:\n%s \nwords:%d sentences:%d\n", aString, *numWords, *numSentences);//for testing


    //free(numSentences);//free the varaible since theres no more use for them 
//Go Big T3
    char *goBigString;//this varibale will be used to store the string returned from GoBig
    goBigString = malloc(sizeof(char) * 100000);
    goBigString = goBig(aString);//store function value to string 
    printf("\ngoBig String:%s", goBigString);//for testing 

//Go Away T4

    int length = strlen(aString);
    char **wordsArray;
    wordsArray = malloc(sizeof(char*)* *numWords);
    for (int i =0; i< strlen(aString); i++){
    wordsArray[i] = malloc(sizeof(char)* (length +1));
    }
    int numWordsReturned =0;

    wordsArray = goAway(aString, &numWordsReturned);

    // for(int i =0; i< *numWords; i++){
    //     for(int j=0; j< strlen (wordsArray[i]); j++){ 
    // printf("\ni:%d j:%d %c", i, j, wordsArray[i][j]);
    // }
    //  }
    for (int i=0; i < *numWords; i++){
        printf("\nGoAway Main:%s i:%d", wordsArray[i], i);
    }

//Breathless T5
    char *aStringBreath;
    aStringBreath = malloc(sizeof(char)* (strlen(aString)+1));

    aStringBreath = breathless(aString);
    printf("\nBreathless:%s", aStringBreath);

//Tail T6

    int whichWord = 0;//initialze variables and also get input from thr user so that you have the parameters for the function
    //char *desiredSuffix= malloc(sizeof(char)*100000);
    char *desiredSuffix = calloc(1000, sizeof(char));
    printf("\nPlease enter a number so that the program can posiiton your text on the right word:");
    scanf("%d", &whichWord); //if not right number should i have a safe proof
    //printf("\nn:%d", whichWord);
    printf("\nPlease enter the desired suffix:");
    getchar();
    fgets(desiredSuffix, 1000, stdin);//why didnt this work ask ta
    //scanf("%s", desiredSuffix);
    desiredSuffix= realloc(desiredSuffix, strlen(desiredSuffix)+1);
    //printf("\nds:%s", desiredSuffix);
    
    tail(aString, whichWord, desiredSuffix);//call the function it will print the answer



    free(numWords);//free the dynamically allocated variables
    free(numSentences);
        
    return 0;

}