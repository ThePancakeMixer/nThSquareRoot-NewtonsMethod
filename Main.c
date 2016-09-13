#include <stdio.h>

double pow (double x,int n)
{
    int i;
    double number = 1;

    for (i = 0; i < n; ++i)
        number *= x;

    return number;
}

double absoluteValue(double abNumber){
if(abNumber<=0){
    abNumber=abNumber*-1;
}
else{
    abNumber=abNumber;
}
    return abNumber;
}

double fGuess(double base3,double nRoot3){
double bestGuess = 1;
double answer2 = 0;
double finalAnswer = 0;
if(base3>=0){
for( bestGuess = 1; answer2<=base3; ++bestGuess){
    answer2 = pow(bestGuess, nRoot3);
    if(answer2<=base3){
        finalAnswer = bestGuess;
    }
}
}
else{
for( bestGuess = -1; answer2>=base3; --bestGuess){
    answer2 = pow(bestGuess, nRoot3);
    if(answer2>=base3){
        finalAnswer = bestGuess;
    }
}
}
return finalAnswer;
}


int checkPrecision (double guess4, double nroot4, double base4){
double precision = 0;
precision = absoluteValue(pow(guess4, nroot4)-base4);
if(precision<.00001){
    precision = 1;
}
else{
    precision = 0;
}
return precision;
}

double SquareRoot(double base2, double nRoot2){
double guess;
guess=fGuess(base2, nRoot2);
while(checkPrecision(guess, nRoot2, base2)==0){
    guess=guess - (pow(guess,nRoot2)-base2)/(nRoot2*(pow(guess,(nRoot2-1))));
}
return guess;
}

int main() {
double userInput, nRoot, answer;
printf("Please enter base: ");
scanf("%lf", &userInput);
printf("Please enter nth root: ");
scanf("%lf", &nRoot);
answer= SquareRoot(userInput, nRoot);
printf("The answer is: %lf", answer);
}
