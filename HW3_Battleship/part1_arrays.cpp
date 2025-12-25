/* Assignment: 3 Part 'a'
Author: Noa Shem Tov
*/
#include <iostream>
using namespace std;
#define SIZE 8

//A function that receives from the user the elements of the array
void inputArray(int arr [], int size);

/*The function accepts two parameters Arrays of integers and their common size.
It returns the number of indexes in the arrays Equals. */
int equal(int arr1 [],int arr2 [], int size);

int main()
{
    int array_1 [SIZE];//Create the first array
    inputArray(array_1,SIZE);//Initialization of the array_1
    int array_2 [SIZE];//Create the second array
    inputArray(array_2,SIZE);//Initialization of the array_2
    cout<<"The amount of indexes in which the arrays are equal is :"<<endl<<equal(array_1,array_2,SIZE)<<endl;

    return 0;
}//main

//Initialization of the array
void inputArray(int arr[], int size)
{
    int i;
    cout<<endl<<"please enter "<< size<<" integer numbers"<<endl;//put values iun the array
    for (i = 0; i < size ; ++i)
        cin>>arr[i];
}//inputArray

int equal(int arr1[],int arr2[], int size)
{
    int counter = 0;//The amount of indexes in which the arrays are equal
    for (int i = 0; i < size; ++i)
        if (arr1[i] == arr2[i])//check if in the same index the values are equal
            counter++;
    return counter;
}//equal