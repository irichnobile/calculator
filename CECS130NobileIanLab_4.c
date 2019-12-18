//******************************************************************************
//  CECS130NobileIanLab_4.c     Author: Ian Nobile
//  
//  Program_description: this program simulates a calculator. It supports the 
//  five basic operations (addition, subtraction, multiplication, division and 
//  modulus) with additional functionality in the form of primality testing, 
//  factorials and exponents also available. Finally, an interesting 
//  mathematical function computes the first n numbers of the Lucas Series (a 
//  list of numbers not dissimilar to the Fibonacci sequence) specified by the 
//  user. Each mathematical operation in the menu is encapsulated in its own 
//  separate function.
//  
//  Lab section: 01
//  Due Date: 21 September 2018
//******************************************************************************

#include <stdio.h>
#include <stdbool.h>

//Function prototypes:
float addition(float, float);
float subtraction(float, float);
float multiplication(float, float);
float division(float, float);
int modulus(int, int);
bool isPrime(int);
int factorial(int);
int exponentiation(int, int);
void lucasseries(const int);


//------------------------------------------------------------------------------
//  Main Function
//------------------------------------------------------------------------------
main()
{
    int iOperationSelection;//implicitly initialised to zero

    while (iOperationSelection != 10) {
        printf("Calculator Menu:\n");
        printf("(1)\tAddition\n");
        printf("(2)\tSubtraction\n");
        printf("(3)\tMultiplication\n");
        printf("(4)\tDivision\n");
        printf("(5)\tModulus (integers only)\n");
        printf("(6)\tTest if prime (integers only)\n");
        printf("(7)\tFactorial (integers only)\n");
        printf("(8)\tExponentiation (integers only)\n");
        printf("(9)\tThe Lucas Series\n");
        printf("(10)\tExit\n");
        printf("\nPlease select an operation: ");
        scanf("%d", &iOperationSelection);

        switch (iOperationSelection) {
            //------------------------------------------------------------------
            //  Addition Function
            //------------------------------------------------------------------
            case 1:
                printf("You selected \"Addition.\"\n");
                float fAugend, fAddend, fSum;
                printf("\nPlease enter the augend: ");
                scanf("%f", &fAugend);
                printf("Now please enter the addend: ");
                scanf("%f", &fAddend);
                fSum = addition(fAugend,fAddend);
                printf("The sum of %.3f and %.3f is %.3f.\n\n",
                    fAugend, fAddend, fSum);
                system("pause");
                system("cls");
                break;

            //------------------------------------------------------------------
            //  Subtraction Function
            //------------------------------------------------------------------
            case 2:
                printf("You selected \"Subtraction.\"\n");
                float fMinuend, fSubtrahend, fDifference;
                printf("\nPlease enter the minuend: ");
                scanf("%f", &fMinuend);
                printf("Now please enter the subtrahend: ");
                scanf("%f", &fSubtrahend);
                fDifference = subtraction(fMinuend, fSubtrahend);
                printf("The difference between %.3f and %.3f is %.3f.\n\n",
                    fMinuend, fSubtrahend, fDifference);
                system("pause");
                system("cls");
                break;

            //------------------------------------------------------------------
            //  Multiplication Function
            //------------------------------------------------------------------
            case 3:
                printf("You selected \"Multiplication.\"\n");
                float fMultiplicand, fMultiplier, fProduct;
                printf("\nPlease enter the multiplier: ");
                scanf("%f", &fMultiplier);
                printf("Now please enter the multiplicand: ");
                scanf("%f", &fMultiplicand);
                fProduct = multiplication(fMultiplicand, fMultiplier);
                printf("The product of %.3f and %.3f is %.3f.\n\n",
                    fMultiplier, fMultiplicand, fProduct);
                system("pause");
                system("cls");
                break;

            //------------------------------------------------------------------
            //  Division Function
            //------------------------------------------------------------------
            case 4:
                printf("You selected \"Division.\"\n");
                float fDividend,fDivisor, fQuotient;
                printf("\nPlease enter the dividend: ");
                scanf("%f", &fDividend);
                printf("Now please enter the divisor: ");
                scanf("%f", &fDivisor);
                while (fDivisor == 0) {
                    printf("Sorry, but you cannot divide by zero! ");
                    printf("Every program has its limits...\n\n");
                    printf("Please enter a new divisor: ");
                    scanf("%f", &fDivisor);
                }
                fQuotient = division(fDividend, fDivisor);
                printf("The quotient of %.3f divided by %.3f is %.3f.\n\n",
                    fDividend, fDivisor, fQuotient);
                system("pause");
                system("cls");
                break;

            //------------------------------------------------------------------
            //  Modulus Function (Remainder)
            //------------------------------------------------------------------
            case 5:
                printf("You selected \"Modulus.\"\n");
                int iDividend, iDivisor, iModulus;
                printf("\nPlease enter the dividend: ");
                scanf("%d", &iDividend);
                printf("Now please enter the divisor: ");
                scanf("%d", &iDivisor);
                while (iDivisor == 0) {
                    printf("Sorry, but you cannot divide by zero! ");
                    printf("Every program has its limits...\n\n");
                    printf("Please enter a new divisor: ");
                    scanf("%d", &iDivisor);
                }
                iModulus = modulus(iDividend, iDivisor);
                printf("The remainder of the division of %d by %d is %d.\n\n",
                    iDividend, iDivisor, iModulus);
                system("pause");
                system("cls");
                break;

            //------------------------------------------------------------------
            //  Test for Primality
            //------------------------------------------------------------------
            case 6:
                printf("You selected \"Test if prime.\"\n");
                int iPrimeNo;
                printf("\nPlease enter the number you would like tested ");
                printf("(integers only, please): ");
                scanf("%d", &iPrimeNo);
                while (iPrimeNo < 0 || iPrimeNo == 0 || iPrimeNo == 1) {
                    printf("Sorry, but the number %d is not prime. ", iPrimeNo);
                    if (iPrimeNo < 0) {
                        printf("Negative integers cannot be prime.\n\n");
                    }
                    else {
                        printf("Only non-zero integers greater than one can ");
                        printf("be prime.\n\n");
                    }
                    printf("Please enter a new number you would like tested ");
                    printf("(integers only, please): ");
                    scanf("%d", &iPrimeNo);
                }//end while

                if (isPrime(iPrimeNo)) {
                    printf("Congratulations! The number %d is prime.\n\n", 
                        iPrimeNo);
                }
                else {
                    printf("Sorry, but the number %d is not prime. ", iPrimeNo);
                    if (iPrimeNo % 2 == 0)
                        iPrimeNo++;
                    for (;!isPrime(iPrimeNo);iPrimeNo += 2);
                    printf("The next prime would actually be %d.\n\n", 
                        iPrimeNo);
                }//end else

                system("pause");
                system("cls");
                break;

            //------------------------------------------------------------------
            //  Factorial Function
            //------------------------------------------------------------------
            case 7:
                    printf("You selected \"Factorial!\"\n");
                    int iInteger, iFactorial;
                    printf("\nPlease enter your integer: ");
                    scanf("%d", &iInteger);
                    while (iInteger < 0) {
                        printf("Sorry, but negative integers cannot be ");
                        printf("factorialized.\n");
                        printf("Please enter a new integer: ");
                        scanf("%d", &iInteger);
                    }
                    if (iInteger == 0) {
                        printf("The factorial %d! is 1.\n\n", iInteger);
                        system("pause");
                        system("cls");
                        break;
                    }
                    iFactorial = factorial(iInteger);
                    printf("The factorial %d! is %d.\n\n", 
                        iInteger, iFactorial);
                    system("pause");
                    system("cls");
                    iFactorial = 0;
                    break;

            //------------------------------------------------------------------
            //  Exponentiation Function
            //------------------------------------------------------------------
            case 8:
                printf("You selected \"Exponentiation.\"\n");
                int iBase, iExponent, iPowered;
                printf("\nPlease enter the base (integers only, please): ");
                scanf("%i", &iBase);
                printf("Now please enter the exponent (integers only, ");
                printf("please): ");
                scanf("%i", &iExponent);
                iPowered = exponentiation(iBase, iExponent);
                printf("%d raised to the power of %d is %d.\n\n",
                    iBase, iExponent, iPowered);
                system("pause");
                system("cls");
                break;

            //------------------------------------------------------------------
            //  Interesting Function
            //------------------------------------------------------------------
            case 9:
                printf("You selected \"The Lucas Series.\"\n");
                int iLucasDigits = 0;
                printf("\nPlease enter the number of digits of this sequence ");
                printf("you would like rendered: ");
                scanf("%d", &iLucasDigits);
                lucasseries(iLucasDigits);
                system("pause");
                system("cls");
                break;

            //Exits the program:
            case 10:
                break;

            //Catches any bad input:
            default:
                printf("Sorry, but that selection is invalid.\n\n");
                system("pause");
                system("cls");
                break;

        }//end switch

    }//end while


    //Bidding the user farewell:
    system("cls");
    printf("Thanks and goodbye!\n");
    system("pause");

}//end main


//Function definitions:
float addition(float Augend, float Addend) { return Augend + Addend; }

float subtraction(float Minuend, float Subtrahend) { 
    return Minuend - Subtrahend; 
}

float multiplication(float Multiplicand, float Multiplier) { 
    return Multiplicand * Multiplier; 
}

float division(float Dividend, float Divisor) { return Dividend / Divisor; }

int modulus(int Dividend, int Divisor) { return Dividend % Divisor; }

bool isPrime(int PrimeNo) {
    //Two and three are both prime numbers:
    if (PrimeNo == 2 || PrimeNo == 3) {
        return true;
    }
    //Even numbers cannot be prime:
    else if(PrimeNo % 2 == 0){
        return false;
    }
    //Implements the trial division method:
    else {
        for (int i = 3; i * i <= PrimeNo; i += 2)
            if (PrimeNo % i == 0)
                return false;
    }
    //If the above tests are all passed, the number is prime:
    return true;

}//end isPrime


int factorial(int Integer) {
    //Calculates product of (Integer)(Integer - 1)(Integer - 2)...(Integer - n)
    for (int Factorialiser = Integer - 1; Factorialiser >= 1; Factorialiser--) {
        Integer *= Factorialiser;
    }
    return Integer;

}//end factorial


int exponentiation(int Base, int Exponent) {
    int Powered = 1;//one, not zero -- important!
    //Multiplies Base by itself Exponent number of times
    for (;Exponent != 0; Exponent--) {
        Powered *= Base;
    }
    return Powered;

}//end exponentiation

void lucasseries(int LucasDigits) {
    //One way to create a "dynamic" array in C:
    int* LucasArray = malloc(sizeof(int) * LucasDigits);
    LucasArray[0] = 2;
    LucasArray[1] = 1;
    int i;
    for (i = 2;i < LucasDigits;i++) {
        LucasArray[i] = LucasArray[i - 2] + LucasArray[i - 1];
    }
    printf("Behold, %d digits of the Lucas Series: \n", LucasDigits);
    for (i = 0;i < LucasDigits;i++) {
        printf("%d", LucasArray[i]);
        //Commas between each number but not at the end,
        if (i == LucasDigits - 1) {
            break;
        }
        else {
            printf(", ");
        }//end else

    }//end for

    //Formatting:
    printf("\n\n");
    return;

}//end lucasseries

