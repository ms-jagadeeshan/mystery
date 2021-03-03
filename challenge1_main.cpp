#include <iostream>
#include <cmath>
#include "challenge1_header.h"
using std::cin;
using std::cout;
using std::string;
//global variables
int no_of_inputs = 0;
int function_code;

int main()
{
    // opens input file
    FILE *inputdata = fopen("input.txt", "r");
    if (inputdata == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }

    //analyse input data
    csvAnalyse(inputdata);
    fclose(inputdata);
    //re-opens input file
    inputdata = fopen("input.txt", "r");
    if (inputdata == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }

    float data[no_of_inputs][2];
    float result[no_of_inputs];

    // reads the input data and assigns in data
    getData((float *)data, inputdata);
    fclose(inputdata);

    //prints menu and triggers the respective function
    switch (printMenu(2))
    {
    case 1:
        addition(data, result);
        break;
    case 2:
        subraction(data, result);
        break;
    case 3:
        multiplication(data, result);
        break;
    case 4:
        division(data, result);
        break;
    case 5:
        average(data, result);
        break;
    case 6:
        maximum(data, result);
        break;
    case 7:
        minimum(data, result);
        break;
    }

    printresult(result);
    return 0;
}