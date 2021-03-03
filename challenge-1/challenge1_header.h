#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
using std::cin;
using std::cout;
using std::string;
extern int no_of_inputs;
extern int function_code;

//calculates no of inputs
void inputAnalyse(FILE *inputdata)
{
    char s[200];
    while (fscanf(inputdata, "%s", s) == 1)
    {
        ++no_of_inputs;
    }
}

//reads data from input file and assigns to 2d array called data
void getData(float *data, FILE *inputdata)
{
    for (int i = 0; i < no_of_inputs; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            if (j < 2)
            {
                fscanf(inputdata, "%f%*c", ((data + i * 2) + j));
                //printf("%f,", *((data + i * 2) + j));
            }
        }
    }
}

//prints menu and returns the function code
int printMenu(int a)
{
    int option;
    printf("Your given data have %d inputs\n", no_of_inputs);
    printf("And also it have %d variables\n\n", 2);
    printf("What do you want?\n");
    printf("1.Addition\n");       //function code =>1,
    printf("2.Subraction\n");     //function code =>2,
    printf("3.Multiplication\n"); //function code =>3,
    printf("4.Division\n");       //function code =>4,
    printf("5.Average\n");        //function code =>5,
    printf("Your choice(1-5):");
    cin >> option;
    if (option <= 5 && option >= 1)
        function_code = option;
    else
        printMenu(a);

    return function_code;
}

// FUNCTIONS

void addition(float data[][2], float *result)
{
    for (int i = 0; i < no_of_inputs; ++i)
    {
        result[i] = 0;
        for (int j = 0; j < 2; ++j)
        {
            result[i] += data[i][j];
        }
    }
}

void subraction(float data[][2], float *result)
{
    int option;
    printf("\n\033[1m2.SUBTRACTION\033[0m\n");
    printf("If your input format is x,y\n");
    printf("Do you want 1)x-y or 2)y-x ?\n");
    printf("Your option(1 or 2):");
    cin >> option;
    if (option == 1)
    {
        for (int i = 0; i < no_of_inputs; ++i)
            result[i] = data[i][0] - data[i][1];
    }
    else if (option == 2)
    {
        for (int i = 0; i < no_of_inputs; ++i)
            result[i] = data[i][1] - data[i][0];
    }
    else
    {
        subraction(data, result);
    }
}
void multiplication(float data[][2], float *result)
{
    for (int i = 0; i < no_of_inputs; ++i)
    {
        result[i] = data[i][0];
        for (int j = 1; j < 2; ++j)
        {
            result[i] *= data[i][j];
        }
    }
}
void division(float data[][2], float *result)
{
    int option;
    printf("\n\033[1m4.DIVISION\033[0m\n");
    printf("If your input format is x,y\n");
    printf("Do you want 1)x/y or 2)y/x ?\n");
    printf("Your option(1 or 2):");
    cin >> option;
    if (option == 1)
    {
        for (int i = 0; i < no_of_inputs; ++i)
            result[i] = data[i][0] / (float)data[i][1];
    }
    else if (option == 2)
    {
        for (int i = 0; i < no_of_inputs; ++i)
            result[i] = data[i][1] / data[i][0];
    }
    else
    {
        division(data, result);
    }
}
void average(float data[][2], float *result)
{
    addition(data, result);
    for (int i = 0; i < no_of_inputs; ++i)
    {
        result[i] = result[i] / (float)2;
    }
}
void printresult(float *result)
{
    int option;
    printf("\nWhat do you want?\n");
    printf("1.To be displayed on output console.\n");
    printf("2.Export as file(.txt).\n");
    printf("Your option(1 or 2): ");
    cin >> option;
    if (option == 1)
    {
        printf("\n\033[1mResult\033[0m\n");
        for (int i = 0; i < no_of_inputs; ++i)
        {
            printf("%f\n", result[i]);
        }
    }
    else if (option == 2)
    {
        char *output;
        printf("Enter output file name(with extension): ");
        cin >> output;
        FILE *output_data = fopen(output, "w");
        for (int i = 0; i < no_of_inputs; ++i)
        {
            fprintf(output_data, "%f\n", result[i]);
        }
        fclose(output_data);
    }
}