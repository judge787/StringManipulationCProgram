#include "../include/judgeJashanA2.h"

//Task 1
    //opens the file for reading gets the filesize and puts the filecontents in aString in main
char * readFile(char *fileName){ //opens the file for reading returns NULl if file is not found 
    FILE * fptr;
    fptr = fopen(fileName, "r");
    if (fptr == NULL){
        printf("File not found");
        return NULL;
    }

    fseek(fptr, 0, SEEK_END); //seeks the file until it ends and then stores the filesize
    int fileSize = ftell(fptr);
    fileSize = fileSize/sizeof(char);
    rewind(fptr);
    if (fileSize == 0){
        return NULL;
    }

    char * fileContents;
    fileContents = malloc((sizeof(char) * (fileSize) +1 )); //allocates space and initalizes the filecontents array

    fread(fileContents, sizeof(char), fileSize, fptr);// add a null character to the end of the string 
    fileContents[fileSize]= '\0'; 
    if (fileContents[fileSize] != '\0'){
        printf("NULL character on the string not found\n\n");
    }
    
    return fileContents;

    //for testing remember to move this above return if you want to test
    //  for (int i=0; i<fileSize; i++){
    // //printf("i:%d value %c\n\n", i, fileContents[i]);
    //  }
    //printf("\nfilesize: %d\n", fileSize);
    }


//Task 2
    //goes through aString and counts the number of words and sentences using strok
void dejaVu(char *aString, int * numWords, int *numSentences){

    char *aStringCopy;
    aStringCopy = malloc(sizeof(char)* (strlen(aString)+1));//allocate space for copy varible which copies aString, im doing this because strtok puts null characters in string you pass through it
    strcpy(aStringCopy, aString);
    *numWords =0;
            //char *delimiterWords2 ="!.,:;? \n"; //there is a downside to this if the newline has no text and a empty space my code will count it as a sentence
    char *delimiterWords2 =" \n"; //if the string has a space or \n, tokenize 
    char* tokenWords = strtok(aStringCopy, delimiterWords2);//strtok parses through the string when it sees a newline or space it spilts into tokens and increments the number count
    while(tokenWords != NULL){//until the while loop reaches the end of the string increment words by 1 
            *numWords = *numWords +1;
         //printf("\ntoken#%d: %s\n", *numWords, tokenWords);
        tokenWords = strtok(NULL, delimiterWords2);
    }
            // for(int i=0; i< strlen(tokenWords); i++){                                                                      //removing ? gets me 19 wordxs for discord text
            //     if(tokenWords[i]=='!' ||tokenWords[i]=='.' ||tokenWords[i]==',' ||tokenWords[i]==';' || tokenWords[i]==':' || tokenWords[i]=='?'){ //checks if the word is only , ! ; . then decreases 
            //     //if(tokenWords[i]=='!' ||tokenWords[i]=='.' ||tokenWords[i]==';' || tokenWords[i]==':' || tokenWords[i]=='?'){   
            //         matchCount++;
            //         if (matchCount == tokenWordsLen && matchCount!=1){
            //             *numWords = *numWords-1;
            //         }
            //     }
            //    }  
    char *strCpySen;//starts the portion of the function that seperates sentences by the delimiters
    strCpySen = malloc(sizeof(char)* strlen(aString) + 1); //allocate space for varibles again im copying the string beacuse strtok puts null characters in the string
    strcpy(strCpySen, aString);
    *numSentences =0;
    char *tokenSen;
    char *delimiterSentences = "!.;:?";//delimiters for my sentence 

    tokenSen = strtok(strCpySen, delimiterSentences);
    while(tokenSen != NULL){// keep on iterating until it reaches the end of the stirng 
        if (strlen(tokenSen)>1){ 
            *numSentences= *numSentences + 1;
            //printf("\nTokensen#%d: %s",*numSentences, tokenSen);
        }                     
    tokenSen = strtok(NULL, delimiterSentences);
                            }
    
            //check if sentence does not have any punctuation and if the sentence is greater then 0 and if 
            // int delimeterCheck = 0;  
            // for (int i =0; i <strlen(aString); i++){ 
            // if (aString[i] == '!' || aString[i] == '.' || aString[i] == ';'|| aString[i] == ':' || aString[i]=='?'){
            // delimeterCheck++;
            // // printf("\nvalue:%c dc:%d", aString[i], delimeterCheck);
            //                                                                                                                               }
            //                                         }
            // if (delimeterCheck ==0 && *numSentences>0){
            //     *numSentences = *numSentences -1;
            // }
            
    char *aStringCopy2;
    aStringCopy2 = malloc(sizeof(char)* strlen(aString)+1);
    strcpy(aStringCopy2, aString);
   //checks if last charcter has punctuation and if it doesntr and numsentences >0 then -1 sentence
    if (((aStringCopy2[strlen(aStringCopy2)-1] == '!') ||(aStringCopy2[strlen(aStringCopy2)-1] == ':')|| (aStringCopy2[strlen(aStringCopy2)-1] == '.')|| (aStringCopy2[strlen(aStringCopy2)-1] == ';') || (aStringCopy2[strlen(aStringCopy2)-1] == '?'))&& (*numSentences > 0)){
        // printf("\n last character has punctuation");
    }
    else if(*numSentences>=1){
        //printf("\ndelete sen character %c", aStringCopy2[strlen(aStringCopy2)-1]);
         *numSentences = *numSentences -1;
    }
   // printf("\ndc: %d\n", delimeterCheck);
    //printf("\nNumSen T2:%d", *numSentences);        
}

//Task 3 GoBig
    //takes the string and asks the user to input strlen(string) number of int and then uses each input int with its corresponding character to stretch it 
char* goBig(char* aString) {
    int *charArray;
    charArray = malloc(sizeof(int) * (strlen(aString)+1));
    int value = 0;
    printf("Enter %lu valid positive integers, if its not the same amount program will have a error: ", strlen(aString));
    for(int i=0; i<strlen(aString); i++) {
        do {
            scanf("%d",&charArray[i]);
        } while(charArray[i] <= 0);
        value = value + charArray[i];
    }
    char* stretchedString = (char*) malloc((value + 1) * sizeof(char));
    int count = 0;
    for(int i=0; i<strlen(aString); i++) {
        for(int j=0; j<charArray[i]; j++) {
            stretchedString[count++] = aString[i];
        }
    }
    stretchedString[count] = '\0';
    return stretchedString;
}

// int *numWords = malloc(sizeof(int));
  
    // char *tokenWords;

    // tokenWords = strtok(aStringCopy, " ");
    // while(tokenWords != NULL){
    //     if (*tokenWords > 0){
    //     *numWords = *numWords +1;
    //     }
    //     for (int i=0; i< *numWords; i++){
    //     strcpy(wordsArray[i], tokenWords);  
    //     }
    
    //    printf("token: %s numwords:%d\n", tokenWords, *numWords);
    //     tokenWords = strtok(NULL, " ");
    // }


//T4 GoAway
    //this function takes in a string uses strtok to seperate words and then puts them into a string 
char ** goAway(char *aString, int *numWordsReturned){
    char **wordsArray = calloc((strlen(aString)+1), sizeof(char*) );//alocate space for a 2D Array
    for(int i =0; i < strlen((aString)+1); i++){
    wordsArray[i] = calloc(strlen(aString)+1, sizeof(char));
    }

    char *aStringCopyGoAway;
    aStringCopyGoAway = malloc(sizeof(char)* (strlen(aString)+1));
    strcpy(aStringCopyGoAway, aString);
    char *delimiterWordsGoAway = " \n";//delimiters for goAway words 
    
    char *tokenWordsGoAway = strtok(aStringCopyGoAway, delimiterWordsGoAway);//pass the string and delimiters through strtok increment numwordsreturned for each iteration
    while (tokenWordsGoAway != NULL){
    *numWordsReturned = *numWordsReturned +1;
            
    for (int i=0; i< 1; i++){
            strcpy(wordsArray[*numWordsReturned-1],tokenWordsGoAway);//stores the words into the string 
                     // printf("token: %s wordsArray: %s numwords:%d tokenLen:%lu\n", tokenWordsGoAway, wordsArray[i], *numWordsReturned, strlen(tokenWordsGoAway));
        }

        tokenWordsGoAway = strtok(NULL, delimiterWordsGoAway);
    }
//for testing
// for(int i =0; i< *numWordsReturned; i++){
//     for(int j=0; j< strlen (wordsArray[i]); j++){
// printf("\ni:%d j:%d %c", i, j, wordsArray[i][j]);
//                                             }    }
    return wordsArray;//return the 2d array
}
        //random t2 
        // while (tokenSen != NULL && (*(tokenSen + strlen(tokenSen)) == '!' || *(tokenSen + strlen(tokenSen)) == ',' || *(tokenSen + strlen(tokenSen)) == '.' || *(tokenSen + strlen(tokenSen)) == ';')) {
            //             tokenSen = strtok(NULL, delimiterSentences);
            //             printf("second tokensen:%s", tokenSen);
            // }    
                                    // } 
//T5
    //this fucntion iterates throught he string and copies each character over if it does not involve punctuation
char * breathless (char *aString){

    char *aStringBreath = malloc(sizeof(char)* strlen(aString)+1);

    int j =0;
    for(int i =0; i< strlen(aString); i++){
    if ((aString[i]=='!') || (aString[i]=='?') ||(aString[i]==':') ||(aString[i]==';') ||(aString[i]=='.')){ //checks if the string includes these characters if it doessnt it adds them to the brethless string
    }
    else{
        if (j==0){
        aStringBreath[j]= aString[i];
       // printf("\nbc0 %c", aString[i]);
        j++;
        }
        else if (j != 0){ 
        aStringBreath[j++]= aString[i];
       // printf("\nbc:%c i:%d",aString[i], i);  
        }
    }
   // printf("\nonlyi:%d", i);
    }
    return aStringBreath;//return array
    }

//T6 Tail
    //this function takes in user input for which word they want to add a suffix to by finding the the corresponding nth (int which word) word and adding a suffix to it for each letter of the word chosen
void tail (char* aString, int whichWord, char *desiredSuffix){

    char ** string2D;
    int numWords =0;

    string2D= goAway(aString, &numWords); //use goaway function to access words from that function

    char *whichWordString = malloc(sizeof(char) * (strlen(string2D[whichWord-1])+1));
    strcpy(whichWordString,string2D[whichWord-1]);//this is for storing the values of the nth word to whichwordstring

    char **stringAnswer = calloc((strlen(whichWordString)+1), sizeof(char*));//2d array for storing and printing out new values with suffix
    for (int i = 0; i < strlen(whichWordString); i++) {
    stringAnswer[i] = calloc((strlen(desiredSuffix) + 1), sizeof(char));
    }

    // for(int i =0; i<strlen(whichWordString); i++){
    // //printf("\ni check:%s i:%d", stringAnswer[i], i );
    // }
    //printf("\nds:%s", desiredSuffix);

    for (int i =0; i< (strlen(whichWordString)); i++){//loops for the length of which word string so that it can add the suffix to end of the first character
        for(int j =0; j<(strlen(desiredSuffix)+1); j++){
        if (j==0){
            stringAnswer[i][j] = whichWordString[i];//store first letter of original word
       // printf("\nsac:%c sa:%s i:%d j:%d", stringAnswer[i][j], stringAnswer[i], i,j);
        }
        else{
            stringAnswer[i][j] = desiredSuffix[j-1];//stores uffix 
        //printf("\nsac:%c sa:%s i:%d j:%d", stringAnswer[i][j], stringAnswer[i], i,j);
    
        }
        }
    }

    for(int i =0; i<strlen(whichWordString); i++){
    //stringAnswer[i][strlen(desiredSuffix)+1] = '\0';
    printf("\n%s", stringAnswer[i]);
    }

}