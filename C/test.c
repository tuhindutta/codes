#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int add(int no1, int no2){
    int sum;
    sum = no1 + no2;
    return sum;
}

char* prime(int no){
    int prime=1;
    for(int i=2; i<no; i++){
        if(no%i==0){
            prime=0;
            break;
        }
        else{
            prime=1;
        }
    }

    if(prime==1 || no==2){
        printf("Its a prime number\n");
    }
    else{
        printf("Its a composite number\n");
    }
}

char* vote(int age){
    if(age<18){
        printf("You can't vote yet\n");
    }
    else{
        printf("You are eligible to vote\n");
    }
}

int numGuessGame(){
    int number, guess, nguesses=1;
    srand(time(0));
    number = rand()%100 + 1;
    // printf("The number is %d\n", number);
    do{
        printf("Enter your guessed number between 1to 100:\n");
        scanf("%d", &guess);
        if(guess==number){
            printf("Congrats you guessed the number in %d attempts\n", nguesses);
        }
        else if(number>guess){
            printf("Enter higher number\n");
        }
        else{
            printf("Enter lower number\n");
        }
        nguesses++;
    }while(guess!=number);
}

int factorial(int a){
    int factorial=1;
    for(int i=2; i<a+1; i++){
        factorial *= i;
    }
    // printf("Factorial of %d is %d\n", a, factorial);
    return factorial;
}

int permutation(int n, int r){
    int result;
    result = factorial(n)/factorial(n-r);
    printf("Permutation is %d\n", result);
    return result;
}

int combination(int n, int r){
    int result;
    result = factorial(n)/(factorial(r)*factorial(n-r));
    printf("Combination is %d\n", result);
    return result;
}

int leap(int year){
    int target=0, addFactor=1;
    if((year%100!=0 && year%4==0) || (year%100==0 && year%400==0 && year%4==0)){       
         printf("It is a leap year\n");
    }
    else{
        printf("It is not a leap year\n");
    }
    while(target<1){
        if(((year+addFactor)%100!=0 && (year+addFactor)%4==0) || ((year+addFactor)%100==0 && (year+addFactor)%400==0 && (year+addFactor)%4==0)){
            target=1;
            break;
        }
        else{
            target=0;
            addFactor += 1;
        }        
    }
    printf("The next leap year will be %d which is in %d years\n", (year+addFactor), addFactor);
}

//Recursion
void stars(int n){
    if (n==0 || n==1){
        printf("*\n");
        return;
    }
    else{
        stars(n-1);
    }
    
    for (int i=0; i<(2*n-1); i++){
        printf("*");
    }
    printf("\n");
}

//Fibonacci series
void fib(int count){
    int first=0, second=1, next;    
    printf("0 ");
    if(count==2){
        printf("a ");
    }
    else if (count>2){        
        printf("1 ");
        for(int i=0; i<count-2; i++){            
                next=first+second;                
                printf("%d ", next);
                first=second;
                second=next;
        }
    }
}

int main(){

    // printf("%s\n", prime(17))
    // prime(17);

    // printf("%d\n", add(2,6));

    // printf("%s\n", vote(18));
    // vote(19);

    // numGuessGame(); 

    // factorial(4);
    
    // combination(6,3);

    // leap(1496);

   fib(16);
    
    
    
   
    

    return 0;
}