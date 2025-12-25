/* Assignment: 1
Author: Noa Shem Tov
*/

/*
paragraph A.
the user need to chose 1 for Case change 2 for Digit search and 3 for Failed check
else, the program ends
case change = the user need to type a character if the user typed letter chang to the opposite
for example if the user enter a so the program print A
else, the program will print the same character
digit search = the user need to type a number of 4 digits and digit, the program will print
how many times the digit appears in the number
failed check = the user type 3 grade and the program will print the average of the pass grades
if the user fails all tests the program will print failed
 */



#include <iostream>
using namespace std;
#define FAIL 56
int main()
{
    int choice;// the user's choice 1/2/3
    int passingGrade = 0;// for option 3, sum of the passing grades
    cout<<endl<<"Please enter"<<endl;
    cout<<"1 for Case change"<<endl<<"2 for Digit search"<<endl<<"3 for Failed check"<<endl;
    cin>>choice;
    float counter = 0; // count the passing grades for option 3
    switch (choice) // can be 1 , 2 or 3
    {
        case 1://Case change
            char character;//the character that the user typed
            cout<<"Please enter character"<<endl;
            cin>>character;
            if(character >='A' && character <='Z')//if it is a capital letter
                character+= 'a' - 'A';
            else if (character >= 'a' && character <= 'z')//if it is a small letter
                    character -= 'a' - 'A';
            cout<<character<<endl;
            break;
        case 2://Digit search
            int num,digit;
            cout<<"please enter a number"<<endl;
            cin>>num;
            cout<<"please enter a digit"<<endl;
            cin>>digit;
            //print one reason why is not valid
            if (digit / 10 != 0) // check if the number the user typed is one digit
                cout << "Error: " << digit << " is not a digit" << endl;
            else if (num / 1000 == 0 || num / 10000 != 0) // Checks whether the number has 4 digits else, its mean it OK
                cout << "Error: " << num << " does not have 4 digits" << endl;
            else
            {
                //count the appears of the digit in the number( can be negative or positive)
                int count = (num / 1000 == digit || num / 1000 == digit * -1 ) +
                (num / 100 % 10 == digit || num / 100 % 10 == digit * -1) +
                (num / 10 % 10 == digit || num / 10 % 10 == digit * -1) +
                        (num % 10 == digit || num % 10 == digit * -1);
                cout << digit << " appears " << count << " times in " << num << endl;
            }
            break;
        case 3://Failed check
            int grade1,grade2,grade3;//user's grades and sum of the passing grades
            cout<<"Please enter 3 grades "<<endl;
            cin>>grade1>>grade2>>grade3;
            if (grade1>=FAIL)//If it does not fail it is summarized the amount and raises in one the counter
            {
                counter++;
                passingGrade += grade1;
            }
            if (grade2>=FAIL)//If it does not fail it is summarized the amount and raises in one the counter
            {
                counter++;
                passingGrade += grade2;
            }
            if (grade3>=FAIL)//If it does not fail it is summarized the amount and raises in one the counter
            {
                counter++;
                passingGrade += grade3;
            }
            if (counter == 0)
                cout<<"Failed"<< endl;
            else
                cout<<"Average: "<<(float)passingGrade/counter<<endl;
            break;
        default:
            cout<<"Unsupported operation"<<endl;
    }
    return 0;
}//paragraph A


/*
 * //paragraph B
the program has 2 option 1 for Arithmetic progression and 2 for Palindrome
Arithmetic progression = the user type a series of numbers the program will print if it's an Arithmetic series
Palindrome = the user type a number the program will print if its palindrome
*/


#include <iostream>
using namespace std;
int main()
{
    int choice;// the user's choice 1/2
    cout<<"Please enter"<<endl<<"1 for Arithmetic progression"<<endl<<"2 for Palindrome"<<endl;
    cin>>choice;
    switch (choice)
        {
            case 1:
                int num1,num2,num3,num4,num5;
                cout<<"Please enter 5 numbers "<<endl;
                cin>>num1>>num2>>num3>>num4>>num5;
                if ((num1 - num2) == (num2 - num3) && (num2 - num3) == (num3 - num4) && (num3 - num4) == (num4 - num5)) // check if there is a steady difference for arithmetic series
                    cout<<"This is an arithmetic series."<<endl;
                else
                    cout<<"This is not arithmetic series."<<endl;
                break;
            case 2:
                int numberPalindrome;
                cout<<"Please enter a number with 5 digits:"<<endl;
                cin>>numberPalindrome;
                if (numberPalindrome / 10000 == 0 || numberPalindrome / 100000 != 0) // check if the number doesn't have 4 digit
                    cout<<"Error: number does not have 5 digits "<<endl;
                else
                {
                    // if the digit of unity is equal to the digit of the thousands and the digit of the hundreds is equal to the digit of the tens
                    //else, it's not palindrome
                    if (numberPalindrome / 10000 == numberPalindrome % 10 && numberPalindrome / 10 % 10 == numberPalindrome / 1000 % 10)
                        cout<<"This is a palindrome."<<endl;
                    else
                        cout<<"This is not a palindrome."<<endl;
                }
                break;
            default:
                cout<<"An illegal option"<<endl;
        }
    return 0;
}//paragraph B


/*
 * //paragraph C
A program that receives from the user a whole number, a character and an incomplete number.
Print to the screen the incomplete number with enough digits after the dot the response to the number
the absorbed whole. The printout will occupy exactly 20 spaces, where the spaces must be filled with the received character
 */


#include <iostream>
#include <iomanip>
using namespace std;
#define PLACE 20
int main()
{
    int number;
    char character;
    float realNumber;
    cout<<endl<<"Please enter"<<endl<<endl<<"Integer number"<<endl<<"A character"<<endl<<"And a real number"<<endl;
    cin>>number>>character>>realNumber;
    cout << "The results is: " << setfill(character) << setw(PLACE);
    cout << setprecision(number+1 ) << realNumber << endl;

    return 0;

}//paragraph C


/*
//paragraph Bonus
the user type a id number the program will print if it's a valid id or not
*/


#include <iostream>
using namespace std;
int main()
{
    long idNumber;
    cout<<endl<<"Please enter you're ID number"<<endl;
    cin>>idNumber;
    if(idNumber<10000000 || idNumber>999999998)//input check, <100000000 for ID with 0 at the beginning
        cout<<"The ID number is not valid"<<endl;
    else
    {
        int digit1 = idNumber / 10000000 % 10;//First digit with weight 2
        int digit2 = idNumber / 100000 % 10;//Second digit with weight 2
        int digit3 = idNumber / 1000 % 10;// Third digit with weight 2
        int digit4 = idNumber / 10 % 10;// Fourth digit with weight 2
        int sumDigit = idNumber / 100000000;//first digit // calculate the id for the check if it's valid or not
        sumDigit += (digit1*2)/10 + ((digit1*2) % 10); // 2 digit
        sumDigit += idNumber / 1000000 % 10;//3 digit
        sumDigit += (digit2*2)/10 + ((digit2*2) % 10);//4 digit
        sumDigit += idNumber / 10000 % 10;//5 digit
        sumDigit += (digit3*2)/10 + ((digit3*2) % 10);//6 digit
        sumDigit += idNumber / 100 % 10;//7 digit
        sumDigit += (digit4*2) / 10 + ((digit4*2) % 10);//8 digit
        if((10 - sumDigit % 10) % 10 == idNumber % 10) // also check the option if the Check digit is 0
            cout<< "Correct identify number"<<endl;
        else
            cout<<"Incorrect identify number"<<endl;
    }
    return 0;
}