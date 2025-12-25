/* Assignment: 4
Author: Noa Shem Tov
*/
#include <iostream>
#include <string.h>
using namespace std;

#define VALUE_IN_DICTIONARY 2 //value in the dictionary is word and definition
#define SIZE_WORD 80 // buffer for the word
#define SIZE_DEFINITION 200 //buffer for the definition
#define WORD 0 //the first place in the array is word
#define DEFINITION 1 //the second place in the array is definition
#define FIRST_PLACE 0 //in the array of the word or definition the first place in the array need to be capital word
#define END_SIGN '\0' //end sign in string
#define FIRST_SMALL_LETTER 'a' //small first letter
#define LAST_SMALL_LETTER 'z' //small last letter
#define FIRST_CAPITAL_LETTER 'A' //capital first letter
#define LAST_CAPITAL_LETTER 'Z' //capital last letter
#define DOT '.' //for the definition after dot and space there is a word
#define WORD_AFTER_DOT 2 //the pointer need to jump to word if *p = dot
#define ZERO 0 //for the result from the str function
#define EXIT "exit" //if the user type exit the program terminates

//functions for step 1
void ReceivingData(); //receiving the information from the user
void InputDictionaryMat(int numberOfWords,char ***pointerDictionary ); //Receive the dictionary values from the user
void EnterDictionary(char **&pointerDictionary); // Entering the values
void EnterWord(char *&word); //Entering the word
void EnterDefinition(char *&Definition); //Entering the definition
//functions for step 2
void CreateDictionary(int numberOfWords,char ***pointerDictionary ); //The arrangement of the dictionary
void CorrectWord(char *word,int place); //Correcting a word from the dictionary
void CorrectDefinition(char *definition,int place); //Correcting a definition from the dictionary
void SmallLetter(char &letter); //Switches between uppercase and lowercase letters
void CapitalLetter(char &letter); //Switches between lowercase and uppercase letters
void SortDictionary(int numberOfWords,char ***pointerDictionary); //dictionary sorting
void BubbleSort(int i,int numberOfWords,char ***pointerDictionary,char **&valueInDictionary);//the dictionary is sorted by Bubble sort
int DeleteDuplicates(int numberOfWords,char ***&pointerDictionary);//delete duplicate values
void DeleteValueFromDictionary(char **&ValueToDelete);//delete value
void SetDictionary(char ***&pointerDictionary,int sizeOfNewDictionary, int numberOfWords);//if there was a change in quantity due to deletion a new place should be allocated
void SetDictionary_CutAndCOPY(char **&pointerDictionary,int &newDictionary,char ***&tmp);//move the value from the old dictionary to the new one
//functions for step 3
void SearchWord(char ***pointerDictionary,int numberOfWords);//The function that manages the search procedure
bool SearchWord_FindTheWord(char ***pointerDictionary, char *RequestedWord,int left, int right);//search the word
//function for step 4
void SignOut(char ***&pointerDictionary,int numberOfWords);//when the user type "exit" the program will not before it deletes the assignments

int main()
{
    ReceivingData();//start step 1 receiving the data from the user
    return 0;
}//main
//STEP 1
void ReceivingData()
{
    int numberOfWords;//how many words the user want to enter
    cout<<endl<<"please type the amount of words you want to put in the dictionary "<<endl;
    cin>>numberOfWords;//input the value from the user
    char *** pointerDictionary = new char ** [numberOfWords];//the dictionary pointer
    InputDictionaryMat(numberOfWords,pointerDictionary );//get the values of the dictionary from the user
}//CreateDictionary
void InputDictionaryMat(int numberOfWords,char ***pointerDictionary )
{
    for (int i = 0; i < numberOfWords; ++i)
        EnterDictionary(pointerDictionary[i]);//every cell in the array will be value in the dictionary
    CreateDictionary(numberOfWords,pointerDictionary);//create a correct dictionary with no duplicates and misspellings
}//InputArray
void EnterDictionary(char **&pointerDictionary)
{
    pointerDictionary = new char * [VALUE_IN_DICTIONARY];//the pointer for the array that will contain word and definition = 2 cell
    EnterWord(pointerDictionary[WORD]);//enter the word
    EnterDefinition(pointerDictionary[DEFINITION]);//enter the definition
}//EnterDictionary
void EnterWord(char *&word)
{
    char buffer [SIZE_WORD];//buffer of the word
    cout<<"please enter the word you want to enter into the dictionary "<<endl;
    cin >>buffer;//input from the user
    int sizeOfWord = strlen(buffer) + 1;// creat the string without unnecessary space1+ for the end sign
    word = new char [sizeOfWord];//the array for the string the user typed
    strcpy (word,buffer);//copy from the buffer to the array
}//EnterWord
void EnterDefinition(char *&Definition)
{
    char buffer [SIZE_DEFINITION];//buffer for the definition
    cout<<"Please enter the definition of the word "<<endl;
    getchar();//for the forgotten "enter" in the buffer from typing the word
    cin.getline(buffer, SIZE_DEFINITION);// string input
    int sizeOfDefinition = strlen(buffer) + 1;//+1 for the end sign '\0' in strings
    Definition = new char [sizeOfDefinition];//the array for the definition
    strcpy (Definition,buffer);//copy the word from the buffer to the array
}//EnterDefinition
//STEP 2
void CreateDictionary(int numberOfWords,char ***pointerDictionary)
{
    for (int i = 0; i < numberOfWords; ++i)//the loop goes all the array and corrects the dictionary
    {
        CorrectWord(pointerDictionary[i][WORD], FIRST_PLACE);//correct word
        CorrectDefinition(pointerDictionary[i][DEFINITION], FIRST_PLACE);//correct definition
    }//for
    SortDictionary(numberOfWords,pointerDictionary);//sort the dictionary in lexicographic order
}//CreateDictionary
void CorrectWord(char *word, int place)
{
    if(word[place] == END_SIGN)//the stopping conditions, if is the end of the word return
        return;
    if(place == FIRST_PLACE)//only in first place in word the first letter need to be capital/uppercase letter
        CapitalLetter(word[place]);//check if is capital letter and correct if not
    else SmallLetter(word[place]);//if is another place in the word, so it has to be a small letter
    CorrectWord(word, ++place);//recursive call
}//CapitalLetter
void CorrectDefinition(char *definition, int place)
{
    if(definition[place] == END_SIGN)//if it is the end of the string, stopping conditions
        return;
    if(definition[place] == DOT || place == FIRST_PLACE)//in definition the first letter in every sentence need to be uppercase letter
    {
        if(place != FIRST_PLACE)//if is not the first letter in the definition is the first word in new sentence
            place += WORD_AFTER_DOT;//the pointer jump to the first letter in the new sentence
        CapitalLetter(definition[place]);//check if is capital letter and correct if not
    }//if
    else SmallLetter(definition[place]);//if is another place in the word, so it has to be a small letter
    CorrectDefinition(definition, ++place);//recursive call
}//CorrectsDefinition
void SortDictionary(int numberOfWords,char ***pointerDictionary)
{
    for (int i = 0; i < numberOfWords - 1; ++i)
        BubbleSort(i,numberOfWords,pointerDictionary,pointerDictionary[i]);//each cell is checks with those below it
    int sizeOfNewDictionary = numberOfWords - DeleteDuplicates(numberOfWords,pointerDictionary);//If values were deleted, the size of the new array would be calculated
    if(sizeOfNewDictionary != numberOfWords)//if no word is deleted there will be no change in size
    {
        SetDictionary(pointerDictionary,sizeOfNewDictionary,numberOfWords);//create a new dictionary of the right size
        SearchWord(pointerDictionary,sizeOfNewDictionary);//send to the search function with the new size
    }//if
    else SearchWord(pointerDictionary,numberOfWords);//if there was no change in size, you don't have to create a new dictionary and the size remains the same
}//SortDictionary
void BubbleSort(int i,int numberOfWords,char ***pointerDictionary,char **&valueInDictionary)
{
    //The function checks the given value with all those that came after it
    if(i == numberOfWords - 1)//if it is the last cell in the array, return. the stopping conditions
        return;
    if(strcmp(valueInDictionary[FIRST_PLACE],pointerDictionary[i+1][FIRST_PLACE]) > ZERO)//if it is not sorted, exchange between the values
    {
        char **tmp = pointerDictionary[i+1];
        pointerDictionary[i+1]= valueInDictionary;
        valueInDictionary = tmp;
        tmp = NULL;
        BubbleSort(++i,numberOfWords,pointerDictionary,pointerDictionary[i]);//the function sent with the new place of the word
    }//if
    else BubbleSort(++i,numberOfWords,pointerDictionary,valueInDictionary);//recursive call for another check
}//BubbleSort
int DeleteDuplicates(int numberOfWords,char ***&pointerDictionary)
{
    int i = 0, j = 1;
    int DeletedWordsCounter = 0;//count the word that deleted
    while (j < numberOfWords)//as long as we did not exceed the boundaries of the array
    {
        if (strcmp(pointerDictionary[i][WORD],pointerDictionary[j][WORD]) == ZERO)//if there is a double word
        {
            DeleteValueFromDictionary(pointerDictionary[j]);//deleting the duplicate value
            ++DeletedWordsCounter;//count the word
        }//if
        else i = j;//because the array is sorted if they are not equal they will not be equal, so you have to check with the next word in the dictionary
        ++j;//move on to the next cell in the array
    }//while
    return DeletedWordsCounter;//the amount of the word that deleted
}//DeleteDuplicates
void DeleteValueFromDictionary(char **&ValueToDelete)
{
    delete [] ValueToDelete[WORD];//delete the first array = word
    delete [] ValueToDelete[DEFINITION];//delete the another array = definition
    delete [] ValueToDelete;// delete the array
    ValueToDelete = NULL;//initialization the pointer
}//DeleteValueFromDictionary
void CapitalLetter(char &letter)
{
    if (letter>= FIRST_SMALL_LETTER && letter <= LAST_SMALL_LETTER)//if it is a small letter
             letter-= FIRST_SMALL_LETTER - FIRST_CAPITAL_LETTER;
}//CapitalLetter
void SmallLetter(char &letter)
{
    if(letter >= FIRST_CAPITAL_LETTER && letter <= LAST_CAPITAL_LETTER)//if it is a capital letter
        letter += FIRST_SMALL_LETTER - FIRST_CAPITAL_LETTER;
}//SmallLetter
void SetDictionary(char ***&pointerDictionary,int sizeOfNewDictionary, int numberOfWords)
{
    char ***NewDictionary = new char ** [sizeOfNewDictionary];//new dictionary after delete duplicates words
    int IndexInNewDictionary = 0;//the index in the new dictionary
    for (int i = 0; i < numberOfWords; ++i)
        if (pointerDictionary[i] != NULL)//if there is a value
            SetDictionary_CutAndCOPY(pointerDictionary[i], IndexInNewDictionary, NewDictionary);//move the value to the new dictionary and reset in the old dictionary
    delete [] pointerDictionary;//delete the old dictionary
    pointerDictionary = NewDictionary;
    NewDictionary = NULL;
}//SetDictionary
void SetDictionary_CutAndCOPY(char **&pointerDictionary,int &newDictionary,char ***&tmp)
{
    tmp[newDictionary] = pointerDictionary;//move to the new dictionary
    pointerDictionary = NULL;//initialization the pointer
    ++newDictionary;//move to the next cell
}//SetDictionary_COPY
//STEP 3
void SearchWord(char ***pointerDictionary,int numberOfWords)
{
    char buffer [SIZE_WORD];//the word the user are searching
    do
    {
        cout<<"please enter the word you want to search for in the dictionary "<<endl;
        cin >>buffer;//the word the user type for search
        if (strcmp(buffer, EXIT) == ZERO)//if the user type exit, exit point
        {
            SignOut(pointerDictionary, numberOfWords);//exit from the program
            return;
        }//if
        CorrectWord(buffer,FIRST_PLACE);//correct the word the user type for the searching
        int left = FIRST_PLACE;//the first place
        int right = numberOfWords - 1;//last place in the dictionary
        if (!(SearchWord_FindTheWord(pointerDictionary,buffer,left,right)))//if the word does not exist in the dictionary
            cout << "Unknown word! " << endl;
    }while(ZERO == ZERO);//until the user will type exit
}
bool SearchWord_FindTheWord(char ***pointerDictionary, char* RequestedWord,int left, int right)
{
    /*The function always checks half an array,
   if the word is larger than the middle, you have to check the right half of the array, and if it is smaller, then the left,
   if it reached the last search and the value it stands for is not the word, then the word does not exist in the array*/
    int middle = (left + right) / 2;
    if(left == right)
    {
        if(strcmp(pointerDictionary[left][WORD],RequestedWord) == ZERO)
        {
            cout<<pointerDictionary[left][DEFINITION]<<endl;
            return true;
        }//if
        return false;
    }//if
    if(strcmp(pointerDictionary[middle][WORD],RequestedWord) == ZERO)
    {
        cout<<pointerDictionary[middle][DEFINITION]<<endl;
        return true;
    }//if
    if(strcmp(pointerDictionary[middle][WORD],RequestedWord) > ZERO)
        return SearchWord_FindTheWord(pointerDictionary,RequestedWord,left,middle - 1);
    return SearchWord_FindTheWord(pointerDictionary,RequestedWord,middle + 1,right);
}//SearchWord_FindTheWord
//STEP 4
void SignOut(char ***&pointerDictionary,int numberOfWords)
{
    for (int i = 0; i < numberOfWords; ++i)
        DeleteValueFromDictionary(pointerDictionary[i]);//delete every value from the dictionary
    delete [] pointerDictionary;//delete the dictionary, the main array
}//SignOut

//for me, printed the dictionary
/* for (int i = 0; i < numberOfWords; ++i)
    {
        char *tem = pointerDictionary[i][FIRST_PLACE];
        while (*tem != END_SIGN)
        {
            cout << *tem;
            tem++;
        }
        cout<<endl;
        char *temD = pointerDictionary[i][DEFINITION];
        while (*temD != END_SIGN)
        {
            cout << *tem;
            temD++;
        }
        cout<<endl;
    }
    */