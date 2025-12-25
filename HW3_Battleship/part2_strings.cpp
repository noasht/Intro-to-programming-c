/* Assignment: 3 Part 'b'
Author: Noa Shem Tov
*/
#include <iostream>
using namespace std;

#define END_SIGN '\0'
#define MIDDLE_SENTENCE ' '
#define SIZE_STR 20

int words (char str[], int length);//the function count how many words in the right length and print them
int countLetter(char str[], int i);//count the letter in 1 word
void PrintWord(char str[],int i,int length);//the function that print the word in the correct length

int main()
{
    char str[SIZE_STR];//create the string
    int lengthWord;//the words length
    cout<<endl<<"Please enter a sentence that is up to "<< SIZE_STR <<" characters long"<<endl;
    cin.get(str, SIZE_STR);// string input
    getchar();
    cout<<"please enter the size that you want for the search"<<endl;
    cin>>lengthWord;
    int countedWord = words(str, lengthWord);//amount of the words of the appropriate length
    cout<<endl<<"The number of words that are "<<lengthWord<<" in length is "<<endl<<countedWord<<endl;
    return 0;
}//main
//the function get string and the length the word should be in,
// every word in the sentence sent to another function that count the letter if is
//equal to the length, the index sent to another function that print the word and also count the amount of the words of the appropriate length
int words (char str[], int length)
{
    int i = 0;//Will go over the array
    int countWord = 0;//Counts the number of words that meet the condition
    int sumLetter;//sum of the letters in the word
    while ( str[i] != END_SIGN)//if it is not the end of string
    {
        if(str[i] == MIDDLE_SENTENCE)//if it is space, which means, between words, move to the next cell
            i++;
        sumLetter = countLetter(str, i);//the amount of the letters in the word
        if (sumLetter == length)//if it is the right length it will print the word and add +1 to the counter
        {
           PrintWord(str,i,length);
           countWord++;
        }//if
        i+= sumLetter;//move to the next word
    }//while
    return countWord;//amount of the words of the appropriate length back to main
}//word
int countLetter(char str[], int i)
{
    int counter = 0;//counter the letters in 1 word
    //check if is not the end of the word ,end of the word in the middle of the sentence is space and in the end of the
    //sentence is '\o'
    while (str[i] != MIDDLE_SENTENCE && str[i] != END_SIGN)
    {
        counter++;
        i++; // for move on in the string
    }//while
    return counter;
}//countLetter
void PrintWord(char str[],int i,int length)
{
    //print the word in the right length
    for (int j = 0; j < length; ++j)
    {
        cout <<str[i];
        i++;
    }//for
    cout<<" ";
}//PrintWord