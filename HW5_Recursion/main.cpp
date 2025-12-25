/* Assignment: 5
Author: Noa Shem Tov
*/
#include <iostream>
#include <fstream>
using namespace std;
#define SIZE_ARR 30 //buffer for array
#define START 0 //point start at file
#define ZERO 0 //if there is an equal amount for the open and clos parenthesis in function 1 ||
#define END_SIGN '\0' //end sign for string
#define OPEN_PARENTHESES '(' //for function 1
#define CLOSE_PARENTHESES ')'// for function 1
#define ONE 1 //for function 2 and for function 5
#define TWO 2 //for function 3
#define ODD 1 //for function 3
#define POSITIVE (-1)//for function 3, if the number is negative
#define TEN 10 // Reduce the number , the point stop is number with one digit
#define FIRST_LOWERCASE 'a'//for function equal string
#define LAST_LOWERCASE 'z'//for function equal string
#define FIRST_UPPERCASE 'A'//for function equal string
#define LAST_UPPERCASE 'Z'//for function equal string
//function 1
bool balance_parenthesis_helper(int counterParenthesis ,char *forWard);//return true if the Array is BALANCED PARENTHESES, else false
bool balance_parenthesis(char *NameOfFile);//create the array that send to balance_parenthesis_helper function
//function 2
int num_of_neg(int *arrayNeg, int SizeOfArray);//counted the negative numbers in the array
//function 3
int num_of_odd_digits(int number);//count the amount of odd digit in integer number
//function 4
bool equal_strings(char *str1, char *str2);//check if 2 strings are equal without reference to uppercase or lowercase
//function 5
void differentials(int *ArrayDiff,int SizeOfArray);//prints the series of differences between any two numbers with consecutive indexes in an array
int main()
{
    char NameFile [SIZE_ARR];//the name of the file
    cout<<"please enter the path with a suffix '.txt'"<<endl;
    cin>>NameFile;//the name file is up to 30 characters
    if (balance_parenthesis(NameFile))
        cout << "true,The file does contain a quantity of balanced parentheses" << endl;
    else
        cout << "false, file does not contain a quantity of balanced parentheses" << endl;//According to the answer of Dr. david tankus , if the file doesn't open = false
    //END function 1
    int SizeOfArray;
    cout<<"please enter the amount of the numbers you want to type "<<endl;
    cin>>SizeOfArray;
    if(SizeOfArray > START)//if the user type 0 it doesn't do anything
    {
        int *NegOfArray = new int[SizeOfArray];//the array of the integer numbers
        cout << "please type " << SizeOfArray << " integer numbers" << endl;
        for (int i = ZERO; i < SizeOfArray; ++i)
            cin >> NegOfArray[i];//input the array
        cout << "the amount of negative numbers you've typed is " << num_of_neg(NegOfArray, SizeOfArray) << endl;
        delete [] NegOfArray;//delete the array
    }//if//end function 2
    int integer;//the integer number the user typed
    cout<<"please enter integer number"<<endl;
    cin>>integer;
    if(integer < 0)//if the number the user type is negative
        cout<<"the amount of odd digits in the number "<< integer <<" is "<< num_of_odd_digits(integer * POSITIVE)<<endl;
    else cout<<"the amount of odd digits in the number "<< integer <<" is "<< num_of_odd_digits(integer)<<endl;
    //end function 3
    //
    cout<<"please enter 2 string"<<endl;//for function 4
    cin>>NameFile;//string number one,up to 30 characters
    char str[SIZE_ARR];//create another array for the second string
    cin>>str;//input string number 2,up to 30 characters
    if(equal_strings(str,NameFile))
        cout<<"The strings are equal"<<endl;
    else
        cout<<"Not equal"<< endl;
    //End function 4
    cout<<"please enter the amount of the numbers you want to type "<<endl;
    cin>>SizeOfArray;//the size of the array
    if(SizeOfArray > ONE) //if the user type 1 for size there is no difference to calculate
    {
        int *ArrayDiff = new int[SizeOfArray];//the array that send to "differentials" function
        cout << "please type " << SizeOfArray << " integer numbers" << endl;
        for (int i = ZERO; i < SizeOfArray; ++i)
            cin >> ArrayDiff[i];//input the array
        differentials(ArrayDiff, SizeOfArray);
        delete[] ArrayDiff;
    }//if//End function 5
    return 0;
}//main
bool balance_parenthesis(char *NameOfFile)
{
    fstream FileToArr;//the pointer in the file
    FileToArr.open(NameOfFile, ios::app);//I add this because it doesn't work for me without this.
    FileToArr.close();
    FileToArr.open(NameOfFile, ios::in);//open for reading from the file
    if(!FileToArr)//if the file not exist
        return false;
    int counterOfChar = 0;//count the character in the file
    char spam;// the pointer need to move to the next character
    while (!FileToArr.eof())//if the file doesn't end
    {
        FileToArr >> spam;//gos on the file and count the characters
        ++counterOfChar;
    }//while
    char *Array = new char [counterOfChar + ONE];//new array with the size of the characters from the file, 1+ for the end sign in string
   // FileToArr.seekg(START, ios::beg);//mov the pointer back to the start point.
   // it doesn't work for me.so the program do this instead:close and open again
    FileToArr.close();
    FileToArr.open(NameOfFile,ios::in);//mov the pointer back to the start point
    for (int i = ZERO; i < counterOfChar; ++i)
         FileToArr >> Array[i];//input from the file
    FileToArr.close();//close the file
    Array[counterOfChar] = END_SIGN;//because the recursive function - balance_parenthesis_helper, get string ,not Array of char
    char *forWard = &Array[START];//the pointer that moves forward on the array
    int counterParenthesis = 0;//count the parenthesis in the string
    if (balance_parenthesis_helper(counterParenthesis,forWard ))//if the array is balanced
    {
        delete [] Array;//delete the array
        return true;//it's balance
    }//if
    delete [] Array;//delete the array
    return false;//it's not balance
}//balance_parenthesis
bool balance_parenthesis_helper(int counterParenthesis,char *forWard)
{
    if(*forWard == END_SIGN)//if the pointer is on the last place in the string can be 2 situations - or is balanced or not
    {
        if (counterParenthesis == ZERO)//if it's equal to zero it's mean that is balanced
            return true;
        return false;//else, mean no balanced
    }//if
    if(*forWard == OPEN_PARENTHESES)//if there is open parenthesis +1
        ++counterParenthesis;
    else if(*forWard == CLOSE_PARENTHESES)
          --counterParenthesis;//else, if the function get string it can contain different kinds of character therefor, only if it's close parenthesis -1
    if(counterParenthesis < ZERO)//there is more close parenthesis than open parenthesis, it's not balanced
        return false;
    return balance_parenthesis_helper(counterParenthesis,++forWard);//check the next place in the string
}//balance_parenthesis_helper
int num_of_neg(int *arrayNeg, int SizeOfArray)
{
    if (SizeOfArray == ZERO)//THE end of the array
        return ZERO;
    if(arrayNeg[SizeOfArray - ONE] < ZERO)
        return ONE + num_of_neg(arrayNeg,--SizeOfArray);//count the negative number and continues to check the rest of the array
    return num_of_neg(arrayNeg,--SizeOfArray);//continues to check the rest of the array
}//num_of_neg
int num_of_odd_digits(int number)
{
    if(number / TEN == ZERO)//if the number has 1 digit left.
        return number % TWO;//can be 1 for odd digit or 0 for even digit
    if(number % TWO == ODD)//else if there is more than 1 digit check for odd or even
        return ONE + num_of_odd_digits(number / TEN);//if odd, count 1 and check the rest of the digit in the number
    return num_of_odd_digits(number / TEN);//the last digit is even, so it check the rest of the digit in the number
}//num_of_odd_digits
bool equal_strings(char *str1, char *str2)//function number 4
{
    if(*str1 == END_SIGN && *str2 == END_SIGN)//if the strings ends
        return true;
    if(*str1 == END_SIGN || *str2 == END_SIGN)//if one of string end it mean the strings not equal
        return false;
    if(((*str1 >= FIRST_LOWERCASE && *str1<= LAST_LOWERCASE)||(*str1 >= FIRST_UPPERCASE && *str1<= LAST_UPPERCASE))//if *str1 && *str2 are letter
    && ((*str2 >= FIRST_LOWERCASE && *str2<= LAST_LOWERCASE)||(*str2 >= FIRST_UPPERCASE && *str2<= LAST_UPPERCASE)))
    {
        if (*str1 > *str2) //if *str1 is capital letter
        {
            if (*str1 - (FIRST_LOWERCASE - FIRST_UPPERCASE) != *str2)
                return false;
        }//if
        else if (*str1 < *str2)//if *str2 is capital letter
        {
            if (*str2 - (FIRST_LOWERCASE - FIRST_UPPERCASE) != *str1)
                return false;
        }//if//else
    }//if letter
    else
        if(*str1 != *str2)//if is characters and are not equal
            return false;
    return equal_strings(++str1, ++str2);//In case they are equal
}//equal_strings
void differentials(int *ArrayDiff,int SizeOfArray)
{
    if(SizeOfArray == TWO)//only 2 numbers left to be calculated
    {
        cout<<"the differences between the cells are"<<endl;
        cout<<ArrayDiff[ZERO] - ArrayDiff[ONE]<<" ";//the difference between the 2 last consecutive cells
        return;
    }//if
    differentials(ArrayDiff,--SizeOfArray);//call the function for the rest of the array
    cout<<ArrayDiff[SizeOfArray - ONE] - ArrayDiff[SizeOfArray]<<" ";//print the difference between the 2 consecutive temporary cells
}//differentials