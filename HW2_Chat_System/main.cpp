/* Assignment: 2
Author: Noa Shem Tov
*/

#include <iostream>
#include <cstdlib>

//option for the main menu
enum {NEW_CUSTOMER = 1,EXIST_CUSTOMER = 2,QUIT_COMPANY = 3,EXIT_PROGRAM = 4};
//option for the second menu CUSTOMER EXIST
enum {MONTH_BILL = 'a' ,INFORMATION = 'b', CONVERSATION = 'c',BACK_TO_MENU = 'd'};

// for age check, the customer must be between the ages 18 and 120
#define MIN_AGE 18
#define MAX_AGE 120
//Sweepstakes for the customer's monthly billing
#define MAX_VALUE 100
#define MIN_VALUE 20
//The range of numbers for the logo
#define FAV_NUM_MIN 3
#define FAV_NUM_MAX 9
//Number of lines for the logo
#define LOGO 5
//the hourly range for callback to customers
#define MIN_HOURS 72
#define MAX_HOURS 168
//middle e-mail
#define E_MAIL_MIDDLE '@'
//end Email
#define SPACE ' '
//end name
#define DOT_END_NAME '.'
//end for input
#define END_INPUT '\n'
//character for max digit
#define MAX_DIGIT '9'
//character for min digit
#define MIN_DIGIT '0'
//the user need to type 4 digit for credit number
#define CREDIT 4
//the user need to type 9 digit for id number
#define ID 9
using namespace std;

//function

void NameCustomer(char);//function for valid last / first name
void IdCustomer(char);//function for valid ID
void MainMenu(char);//function for main menu
void NewCustomer(char);//option 1 in the main menu
void ExistentCustomer(char);//option 2 in the main menu
void QuitCompany(char);//option 3 in the main menu
void ExitProgram();//option 4 in the main menu
void AgeCustomer();//function for valid age
void EmailCustomer(char);//function for valid email address
void startConversation();//start the program with name, ID and the main menu
void digitOfCredit(char);//function that checks the integrity of the last 4 digits of the credit card
void monthlyBilling(char);//option 'a' in the Secondary menu
void MoreInfo(char);//option b in the Secondary menu
void demandTalk(char);//option c in the Secondary menu
void LogoComp();//print the logo 's'
void ClearDataOfChar(char);//clear the character if the user type more than necessary
bool CapitalLetter(char);//for valid name this check if it stars with capital letter
bool LowerCase(char);//for valid name all the letter should be non-capital letter
bool CheckID(char,int);//check if the user type 9 digits
bool CheckCreditNumber(char, int);//check if the user type 4 digits
bool CheckEmail(char);//check if the Email is valid part one of the Email before the @
bool checkEmailPart2(char);//check if the Email is valid part two of the Email after the @

int main()
{
    srand((unsigned)time(NULL));// Initialization of random for option a
    startConversation();//start the program the user will type ID and name valid before the Main menu
    return 0;
}//main
void startConversation()
{
  char tav;//the char that will get the input in the whole program create the variable once, Instead of any function
  cout<<endl<<"Please verify your identity before entering the system"<< endl;
  cout<<"please enter your first name, for end press dot"<<endl;
  NameCustomer(tav);//only when the name will be valid the user will type the ID
  IdCustomer(tav);//only when the id will be valid Only then will the client be transferred to the main menu
  MainMenu(tav);
}//start
void NameCustomer(char letter)//check if the user typed first / last name valid
{
    while (!(CapitalLetter(letter)))//if the name is not valid
        cout << "please type again, press dot for end" << endl;
}//NameCustomer
void IdCustomer(char digitID)
{
    int i;//for the loop create the variable once, Instead of in the function
    cout<<"please enter your ID number"<<endl;
    while (!(CheckID(digitID,i)))//if the id is not valid
        cout<<"please type again you're ID number"<<endl;
    //do-while
}//IdCustomer
void MainMenu(char tav)
{
    int choice;//the choice of the user
    int counter = 0; //It counts the number of times to incorrect input when it is equal to the three client is moved to exit the program
    char flag = 'N';//if the user choose valid option the flag is Y and the loop will end's
    while (counter != 3 && flag == 'N')//if the user type less than 3 times wrong input
    {
        cout<<"Thank you for choosing SCE Internet Company! How can we help you?"<<endl;
        cout<<" 1) I want to join your company as a new client."<<endl;
        cout<<" 2) I want to find out some details about my already existing account."<<endl;
        cout<<" 3) I want to leave your company."<<endl;
        cout<<" 4) I want to exit the chat"<<endl;
        cin >> choice;
        switch (choice)
        {
            case NEW_CUSTOMER: // for input 1
                NewCustomer(tav);
                flag = 'Y';//the input was valid so when the program will come back to this point
                // the loop will end because of the flag that turn to Y
                break;
            case EXIST_CUSTOMER: //for input 2
                ClearDataOfChar(tav);
                ExistentCustomer(tav);
                flag = 'Y';//the input was valid so when the program will come back to this point
                // the loop will end because of the flag that turn to Y
                break;
            case QUIT_COMPANY://for input 3
                ClearDataOfChar(tav);//clean the buffer from the extra character
                QuitCompany(tav);
                flag = 'Y';//the input was valid so when the program will come back to this point
                // the loop will end because of the flag that turn to Y
                break;
            case EXIT_PROGRAM://for input 4
                ExitProgram();
                flag = 'Y';//the input was valid so when the program will come back to this point
                // the loop will end because of the flag that turn to Y
                break;
            default: // for invalid input
                ClearDataOfChar(tav);//clean the buffer from the extra character
                counter++;
                cout<<"An illegal option! This is the "<< counter << " time you chose an illegal option."<<endl;
                if (counter != 3)
                    cout<<"Please retry."<<endl;
        }//switch
        if (counter == 3)//the user type 3 times invalid option
        {
            cout<<"Please come back only when you need something. Have a good day!"<<endl;
            ExitProgram();
        }//if
    }//while
}//MainMenu
void NewCustomer(char tav)
{
    ClearDataOfChar(tav);//clean the buffer from the extra character
    cout<<"please enter your last name ,to end press dot"<<endl;
    NameCustomer(tav);//valid name
    AgeCustomer();//valid age
    ClearDataOfChar(tav);//clean the buffer from the extra character
    EmailCustomer(tav);//valid email
    digitOfCredit(tav);//valid last 4 digits of the credit number
    cout<<"Thank you for choosing our company and welcome! Our people will contact you shortly!"<<endl<<endl;
    MainMenu(tav);
}//NewCustomer
void AgeCustomer()
{
    int ageOfCustomer = -1;//the age of the customer
    while (ageOfCustomer < MIN_AGE || ageOfCustomer > MAX_AGE)
    {
        cout<<"please enter your age"<<endl;
        cin >> ageOfCustomer;
    }//while
}//AgeCustomer
void EmailCustomer(char Email)
{
    cout<<"please type your Email"<<endl;
    while (!(CheckEmail(Email)))//if the email is not valid
        cout << "please type again your Email" << endl;
}//EmailCustomer
void digitOfCredit(char digCred)
{
    int i;//for the for loop,Instead of creating in every iteration variable
    cout<<"please enter your 4 last digit of the credit number"<<endl;
    while (!(CheckCreditNumber(digCred, i)))//if the user type invalid credit number
        cout<<"please type again, for end press enter"<<endl;
}//digitOfCredit
void ExistentCustomer(char choice)
{
    int counter = 0; //It counts the number of times to incorrect input when it is equal to the three client is moved to exit the program
    char flag = 'N';//if the user chose valid option the flag is Y and the loop will end's
    while (counter != 3 && flag == 'N')
    {
        cout<<"What information are you after?"<<endl;
        cout<<"a) I would like to know how much I need to pay this month."<<endl;
        cout<<"b) I would like to know more about you."<<endl;
        cout<<"c) I would like to speak with a real human."<<endl;
        cout<<"d) I want to return to the main menu."<<endl;
        cin >> choice;//the choice of the user
        switch (choice)
        {
            case MONTH_BILL: // for input a
                ClearDataOfChar(choice);//clean the buffer from the extra character
                monthlyBilling(choice);
                flag = 'Y';//the input was valid
                break;
            case INFORMATION: //for input b
                ClearDataOfChar(choice);//clean the buffer from the extra character
                MoreInfo(choice);
                flag = 'Y';//the input was valid
                break;
            case CONVERSATION://for input c
                ClearDataOfChar(choice);//clean the buffer from the extra character
                demandTalk(choice);
                flag = 'Y';//the input was valid
                break;
            case BACK_TO_MENU://for input d
                MainMenu(choice);
                flag = 'Y';//the input was valid
                break;
            default: // for invalid input
                ClearDataOfChar(choice);//clean the buffer from the extra character
                counter++;
                cout<<"An illegal option! This is the "<< counter << " time you chose an illegal option."<<endl;
                if (counter != 3)
                    cout<<"Please retry."<<endl;
        }//switch
        if (counter == 3)//the user type 3 times invalid option
        {
            cout<<"Please come back only when you need something. Have a good day!"<<endl;
            ExitProgram();
        }//if
    }//while
}//ExistentCustomer
void monthlyBilling(char tav)
{
    digitOfCredit(tav);//valid credit number
    int debt = rand()%(MAX_VALUE-MIN_VALUE)+MIN_VALUE;
    cout<<"Your monthly charge for the coming month is "<< debt <<endl<<endl;
    ExistentCustomer(tav);//return to the second menu CUSTOMER EXIST
}//monthlyBilling
void MoreInfo(char tav)
{
    LogoComp();//print the logo of the company 's'
    cout<<endl<<"SCE Internet Company is a growing internet service company located in Israel."<<endl;
    cout<<"More details can be found in our website."<<endl<<endl;
    ExistentCustomer(tav);//return to the second menu CUSTOMER EXIST
}//moreInfo
void LogoComp()
{
    int favNum;//favorite number that the user type
    cout<<endl<<"please enter your favorite number between "<<FAV_NUM_MIN << " and "<<FAV_NUM_MAX<<endl;
    cin >> favNum;
    while(favNum < FAV_NUM_MIN || favNum > FAV_NUM_MAX)//until the user will type valid age between 18 and 120
    {
        cout << "please try again" << endl;
        cin >> favNum;
    }//while
    int j,i;
    for (i = 1; i <= LOGO ; ++i)//the number of the logo line = 5
    {
        if(i % 2 == 0 && i % 4 != 0)//if it's the second line it will print 1 time '*'
            cout<<'*';
        else
        {
            for (j = 1; j < favNum; ++j)
            {
                if (i % 2 == 1)//the odd line, then it will print line of '*'
                    cout << '*';
                else//if it is the fourth line it will print space
                    cout << " ";
            }
           cout<<'*';
        }//else
        cout<<endl;
    }//for
}//LogoComp()
void demandTalk(char tav)
{
    cout<<"We apologize, but no service representative is currently available"<<endl;
    cout<<"Please leave an email address so that a service representative will contact you as soon as possible."<<endl;
    EmailCustomer(tav);//valid email
    cout<<endl<<"We will contact you in the next 48 hours."<<endl<<endl;
    ExistentCustomer(tav);//return to the second menu CUSTOMER EXIST
}//demandTalk
void QuitCompany(char tav)
{
    cout<<"You must speak to a service representative"<<endl;
    cout<<"We apologize but there is currently no service representative available"<<endl<<endl;
    cout<<"So that we can contact you"<<endl;
    EmailCustomer(tav);//valid email
    int hours = rand() % (MAX_HOURS-MIN_HOURS) + MIN_HOURS;
    cout<<"We are sorry to hear you are unhappy. We will contact you in the next " << hours << " hours."<<endl<<endl;
    MainMenu(tav);//return to the second menu CUSTOMER EXIST
}//QuitCompany
void ExitProgram()
{
    LogoComp();//print the logo of the company
    cout<<"Have a great day & see you soon!"<<endl;
}//ExitProgram
void ClearDataOfChar(char spam)
{
    //clean the buffer from the extra character
    do{
        spam = (char)getchar();
    } while (spam != END_INPUT);//until the enter
    //while
}//ClearDataOfChar
bool CapitalLetter(char letter)
{
    letter = (char)getchar();
    if (letter > 'Z' || letter < 'A')//if the first letter of the name is not capital the name is not valid
    {
        ClearDataOfChar(letter);//clean the buffer from the character
        return false;
    }//if
    return LowerCase(letter);
}//CapitalLetter
bool LowerCase(char letter)
{
    letter = (char)getchar();
    do
    {
        if ((letter < 'a' || letter > 'z' ) && letter != SPACE)//the name can be more than one word
        {
            ClearDataOfChar(letter);//clean the buffer from the extra character
            return false;//the name is invalid
        }//if
        letter = (char)getchar();
    } while (letter != DOT_END_NAME && letter != END_INPUT);//while until the dot
    if(letter == END_INPUT)
        return false;//the user has to type dot for end
    ClearDataOfChar(letter);//clean the buffer from the extra character
    return true;//the name is valid
}//LowerCase
bool CheckID(char digitID,int i)
{
    i = 0;
    digitID = (char)getchar();
    do
    {
        if (digitID < MIN_DIGIT || digitID > MAX_DIGIT)//if it is not digit or
        {
            ClearDataOfChar(digitID);//clean the rest if it is not valid
            return false;//the user type less than 9 digits don't need to clean the buffer
        }//if
        i++;
        digitID = (char)getchar();
    } while (digitID != END_INPUT);
    //do-while
    if (i != ID)//only 9 digits
        return false;
    return true;
}//CheckID
bool CheckCreditNumber(char digitCredit, int i)
{
    i = 0;
    digitCredit = (char)getchar();
    do//the user need to type only 4 digit
    {
        if(digitCredit < '0' || digitCredit > '9')//if it is not digit
        {
            ClearDataOfChar(digitCredit);//clean the rest if it is not valid
            return false;//if the user type less than 4 digit don't need to clean the buffer
        }//if
        i++;
        digitCredit = (char)getchar();
    } while (digitCredit != END_INPUT);
    if (i != CREDIT)//only 4 digits
        return false;
    return true;
}//CheckCreditNumber
bool CheckEmail(char Email)
{//part one of the email until the '@'
    Email = (char)getchar();
    do{
        if (Email < '0' || Email > '9')//if ist not digit
            if (Email != DOT_END_NAME)//it is not dot
                if (Email != '_')
                    if (Email < 'a' || Email > 'z')//if it's not small letter
                        if (Email < 'A' || Email > 'Z')//if it's not capital letter
                        {
                            ClearDataOfChar(Email);//clean the buffer from the character
                            return false;//the email is not valid
                        }//if
        Email = (char)getchar();
    } while (Email != E_MAIL_MIDDLE && Email != END_INPUT);
    if (Email == END_INPUT)//the user can't type enter in email
        return false;
    //do-while
    return checkEmailPart2(Email);//if part one is valid the part 2 also need to be
}//CheckEmail
bool checkEmailPart2(char Email)
{
    Email = (char)getchar();
    do//part two in the email
    {
        if (Email < '0' || Email > '9')//if ist not digit
            if (Email != DOT_END_NAME)
                if (Email < 'a' || Email > 'z')//if it's not small letter
                    if (Email < 'A' || Email > 'Z')//if it's not capital letter
                    {
                        if (Email != END_INPUT)//if it's not enter clear
                            ClearDataOfChar(Email);//clean the buffer from the character
                        return false;
                    }//if
        Email = (char)getchar();
    } while (Email != SPACE && Email != END_INPUT);
    if (Email == END_INPUT)//the user cant type enter before space
        return false;
    ClearDataOfChar(Email);//clean the buffer from the extra character
    return true;//the email is valid
}//checkEmailPart2