#include<stdio.h>
#include<time.h>


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



char* findDay(int date, int month, int year){
    int noOfDays, dayOrder;
    noOfDays = noOfDaysinRange(1900, (year-1))/*Year 1900 has taken to be the initial year from which the day determination starts. This program cannot find days before 1st Jan of 1900*/ + noOfDaysTillDate(date, month, year);    
    // printf("%d\n", noOfDays);
    dayOrder = noOfDays % 7;
    // printf("%d", dayOrder);
    switch (dayOrder){
    case 0:
        return "Sunday";
        break;
    case 1:
        return "Monday";
        break;
    case 2:
        return "Tuesday";
        break;
    case 3:
        return "Wednesday";
        break;
    case 4:
        return "Thursday";
        break;
    case 5:
        return "Friday";
        break;
    case 6:
        return "Saturday";
        break;
    case 7:
        return "Sunday";
        break;
    
    default:
        break;
    }    
      
}

void dayFinder(int date, int month, int year){
    int noOfDaysLeftInMonth, noOfDaysLeftInYear;
    printf("Its %s\n", findDay(date, month, year));
    noOfDaysLeftInMonth = noOfDaysInMonth(month, year) - date;
    noOfDaysLeftInYear = noOfDaysinYear(year) - noOfDaysTillDate(date, month, year);

    printf("%d days left for this month to end and %d days for the year to end\n", noOfDaysLeftInMonth, noOfDaysLeftInYear);
}

char* todaysDate(){
        time_t t;
        time(&t);
        return ctime(&t);
}

int monthFinder(){
    int month, i=4;
    char arb, arb1;

    
    // char date;
   
    arb = todaysDate()[6];
    arb1 = todaysDate()[4];
    // return todaysDate()[6];

    switch (arb)
    {
    case 'n':
        if(arb1 == 'J'){
            month = 1;
        }
        else{
            month = 6;
        }
        break;
    case 'b':
        month = 2;
        break;
    case 'r':
        if(arb1 == 'M'){
            month = 3;
        }
        else{
            month = 4;
        }
        break;
    case 'y':
        month = 5;
        break;
    case 'l':
        month = 7;
        break;
    case 'g':
        month = 8;
        break;
    case 'p':
        month = 9;
        break;
    case 't':
        month = 10;
        break;
    case 'v':
        month = 11;
        break;
    case 'c':
        month = 12;
        break;
    
    default:
        break;
    }

    return month;
  
}

int dateFinder(){
    int arb = todaysDate()[8], arb1 = todaysDate()[9];
    int date, tens;

    switch (arb)
    {
    case '1':
        tens = 10;
        break;
    case '2':
        tens = 20;
        break;
    case '3':
        tens = 30;
        break;
    case '4':
        tens = 40;
        break;
    case '5':
        tens = 50;
        break;
    case '6':
        tens = 60;
        break;
    case '7':
        tens = 70;
        break;
    case '8':
        tens = 80;
        break;
    case '9':
        tens = 90;
        break;
    
    default:
        break;
    }
    // printf("%d", atoi(todaysDate()[8]));

    if(todaysDate()[9] == ' '){
        date = arb;
    }
    else{
        switch (arb1)
        {
        case '0':
            date = tens;
            break;
        case '1':
            date = tens+1;
            break;
        case '2':
            date = tens+2;
            break;
        case '3':
            date = tens+3;
            break;
        case '4':
            date = tens+4;
            break;
        case '5':
            date = tens+5;
            break;
        case '6':
            date = tens+6;
            break;
        case '7':
            date = tens+7;
            break;
        case '8':
            date = tens+8;
            break;
        case '9':
            date = tens+9;
            break;
        
        default:
            break;
        }
    }  
    return date;
}

int yearFinder(){
    int arb = todaysDate()[22], arb1 = todaysDate()[23];
    int year, tens;

    switch (arb)
    {
    case '1':
        tens = 10;
        break;
    case '2':
        tens = 20;
        break;
    case '3':
        tens = 30;
        break;
    case '4':
        tens = 40;
        break;
    case '5':
        tens = 50;
        break;
    case '6':
        tens = 60;
        break;
    case '7':
        tens = 70;
        break;
    case '8':
        tens = 80;
        break;
    case '9':
        tens = 90;
        break;
    
    default:
        break;
    }
    // printf("%d", atoi(todaysDate()[8]));

    if(todaysDate()[9] == ' '){
        year = 2000+arb;
    }
    else{
        switch (arb1)
        {
        case '0':
            year = 2000+tens;
            break;
        case '1':
            year = 2000+tens+1;
            break;
        case '2':
            year = 2000+tens+2;
            break;
        case '3':
            year = 2000+tens+3;
            break;
        case '4':
            year = 2000+tens+4;
            break;
        case '5':
            year = 2000+tens+5;
            break;
        case '6':
            year = 2000+tens+6;
            break;
        case '7':
            year = 2000+tens+7;
            break;
        case '8':
            year = 2000+tens+8;
            break;
        case '9':
            year = 2000+tens+9;
            break;
        
        default:
            break;
        }
    }  
    return year;
}


float findAge(int birthdate, int birthmonth, int birthyear){
    int noOfDays;
    float years, months, days;
    noOfDays =  (noOfDaysinYear(birthyear) - noOfDaysTillDate(birthdate,birthmonth,birthyear) + noOfDaysinRange((birthyear+1),(yearFinder()-1)) + noOfDaysTillDate(dateFinder(),monthFinder(),yearFinder()));
    years = noOfDays/365.0;
    months = (noOfDays%365)/30;
    days =  (noOfDays%365)%30;
    return years;
    
}

void ageFinder(int birthdate, int birthmonth, int birthyear){
    printf("You were born on %s and you are %.1f years old.\n", findDay(birthdate,birthmonth,birthyear), findAge(birthdate,birthmonth,birthyear));
}






int main(){

    int date, month, year;

    printf("Enter date: ");
    scanf("%d", &date);

    printf("Enter month: ");
    scanf("%d", &month);

    printf("Enter year: ");
    scanf("%d", &year);

    // findDay(date,month,year);
    printf("%s\n", findDay(date,month,year));
    printf("%.1f\n", findAge(date,month,year));

    dayFinder(dateFinder(),monthFinder(),yearFinder());    

    ageFinder(3,4,1996);
    

    return 0;
}
