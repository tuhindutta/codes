#include<stdio.h>


//Detects whether the year is leap-year or not
int leap(int year){
    int target=0, addFactor=1, noOfDays;
    if((year%100!=0 && year%4==0) || (year%100==0 && year%400==0 && year%4==0)){        
        return 1;        
    }
    else{        
        return 0;        
    }    
}



// Finds no. of days in a particular year
int noOfDaysinYear(int year){
    int noOfDay;
    if(leap(year) == 1){
        noOfDay = 366;
    }
    else{
        noOfDay = 365;
    }
    return noOfDay;
}


int noOfDaysInMonth(int month, int year){
    int monthDays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(leap(year)==1){
        monthDays[1] = 29;
    }
    return monthDays[month-1];
}


// Finds no. of days from 1st Jan of a year to 31st Dec of another year
int noOfDaysinRange(int a, int b){
    int noOfDays = 0;
    for(int i=a; i<b+1; i++){
        noOfDays = noOfDays + noOfDaysinYear(i);
    }
    return noOfDays;
}


// Finds no. of days till the date in that particular year
int noOfDaysTillDate(int date, int month, int year){
    int noOfDays=0, monthDays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(leap(year)==1){
        monthDays[1] = 29;
    }
    for(int i=0; i<(month-1); i++){
        noOfDays = noOfDays + monthDays[i];
    }
    noOfDays = noOfDays + date;
    return noOfDays;
}



int findDay(int date, int month, int year){
    int noOfDays, dayOrder, noOfDaysLeftInMonth, noOfDaysLeftInYear;
    noOfDays = noOfDaysinRange(1900, (year-1))/*Year 1900 has taken to be the initial year from which the day determination starts. This program cannot find days before 1st Jan of 1900*/ + noOfDaysTillDate(date, month, year);    
    // printf("%d\n", noOfDays);
    dayOrder = noOfDays % 7;
    // printf("%d", dayOrder);
    switch (dayOrder){
    case 0:
        printf("Its Sunday\n");
        break;
    case 1:
        printf("Its Monday\n");
        break;
    case 2:
        printf("Its Tuesday\n");
        break;
    case 3:
        printf("Its Wednesday\n");
        break;
    case 4:
        printf("Its Thursday\n");
        break;
    case 5:
        printf("Its Friday\n");
        break;
    case 6:
        printf("Its Saturday\n");
        break;
    case 7:
        printf("Its Sunday\n");
        break;
    
    default:
        break;
    }    
    
    noOfDaysLeftInMonth = noOfDaysInMonth(month, year) - date;
    noOfDaysLeftInYear = noOfDaysinYear(year) - noOfDaysTillDate(date, month, year);

    printf("%d days are left for this month to end and %d days for the year to end", noOfDaysLeftInMonth, noOfDaysLeftInYear);
}







int main(){

    int date, month, year;

    printf("Enter date: ");
    scanf("%d", &date);

    printf("Enter month: ");
    scanf("%d", &month);

    printf("Enter year: ");
    scanf("%d", &year);

    findDay(date,month,year);

    return 0;
}
