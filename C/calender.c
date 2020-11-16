#include<stdio.h>
#include<time.h>

// Calculates power of a number.
int power(int num, int restTo){
    int result = num;
    if(restTo == 0){
        result = 1;
    }
    else{
        for(int i=0; i<(restTo-1); i++){
            result = result * num;
        }
    }    
    return result;
}

// Extracts numbers from a given string.
int valueExtractor(char* str, int loc1, int loc2){    
    int result=0, size, place, arb, n=0, zeroAlert=0;
    // char* value;
    size = loc2 - loc1 + 1;
    
    while (n != size){
        arb = str[loc2-n];
        switch (arb)
        {
        case '0':
            zeroAlert = 1;
            break;
        case '1':
            zeroAlert = 0;
            place = 1;
            break;
        case '2':
            zeroAlert = 0;
            place = 2;
            break;
        case '3':
            zeroAlert = 0;
            place = 3;
            break;
        case '4':
            zeroAlert = 0;
            place = 4;
            break;
        case '5':
            zeroAlert = 0;
            place = 5;
            break;
        case '6':
            zeroAlert = 0;
            place = 6;
            break;
        case '7':
            zeroAlert = 0;
            place = 7;
            break;
        case '8':
            zeroAlert = 0;
            place = 8;
            break;
        case '9':
            zeroAlert = 0;
            place = 9;
            break;
        
        default:
            break;
        }

        result += place*power(10,n);

        if(zeroAlert == 1){
            result -= place*power(10,n);
        }

        n++;
    }    
    return result;    
}


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

//Find no. of days in a particular month.
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


// Returns the day of the given date.
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

// Additional function to print a message stating no. of days left in the month and year.
void dayFinder(int date, int month, int year){
    int noOfDaysLeftInMonth, noOfDaysLeftInYear;
    printf("Its %s\n", findDay(date, month, year));
    noOfDaysLeftInMonth = noOfDaysInMonth(month, year) - date;
    noOfDaysLeftInYear = noOfDaysinYear(year) - noOfDaysTillDate(date, month, year);

    printf("%d days left for this month to end and %d days for the year to end\n", noOfDaysLeftInMonth, noOfDaysLeftInYear);
}

// Finds the system's current date & time.
char* todaysDate(){
        time_t t;
        time(&t);
        return ctime(&t);
}

//Extracts the month from the above function.
int monthFinder(){
    int month, i=4;
    char arb, arb1;
   
    arb = todaysDate()[6];
    arb1 = todaysDate()[4];
   
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

// Extracts date from the above function.
int dateFinder(){
    valueExtractor(todaysDate(),8,9);
}

// Extracts year from the above function.
int yearFinder(){
    valueExtractor(todaysDate(),20,23);
}

// Extracts time from the above function.
int timeFinder(char type){
    if(type == 'h'){
        valueExtractor(todaysDate(),11,12);
    }
    else if(type == 'm'){
        valueExtractor(todaysDate(),14,15);
    }
    else if(type == 's'){
        valueExtractor(todaysDate(),17,18);
    }    
}

// Gives the next date of the given date.
int nextDate(int date, int month, int year, char type){
    char* str;
    date++;
    if(date>noOfDaysInMonth(month,year)){
        date = 1;
        month++;
        if(month>12){
            month = 1;
            year++;
        }
    }
    if(type == 'd'){
        return date;
    }
    else if(type == 'm'){
        return month;
    }
    else if(type == 'y'){
        return year;
    }
 
}

// Water is supplied on every alternative day. This program states whether today is the day or not based on the system's date.
void waterDay(){
    int n, firstDate[3] = {16, 8, 2020}, upcomingDate[3];
    n= noOfDaysTillDate(dateFinder(),monthFinder(),yearFinder()) - noOfDaysTillDate(firstDate[0],firstDate[1],firstDate[2]);
    
    upcomingDate[0] = nextDate(dateFinder(),monthFinder(),yearFinder(),'d');
    upcomingDate[1] = nextDate(dateFinder(),monthFinder(),yearFinder(),'m');
    upcomingDate[2] = nextDate(dateFinder(),monthFinder(),yearFinder(),'y');
    
    if (n%2 == 0){
        for(int i=0; i<1; i++){
            upcomingDate[0] = nextDate(upcomingDate[0],upcomingDate[1],upcomingDate[2],'d');
    	    upcomingDate[1] = nextDate(upcomingDate[0],upcomingDate[1],upcomingDate[2],'m');
            upcomingDate[2] = nextDate(upcomingDate[0],upcomingDate[1],upcomingDate[2],'y');
        }
        
        printf("Today was a water day. The next water day is day after tomorrow, i.e., %d/%d/%d-%s\n", upcomingDate[0], upcomingDate[1], upcomingDate[2], findDay(upcomingDate[0], upcomingDate[1], upcomingDate[2]));
    }
    
    else{
        printf("Today was not a water day. The next water day is tomorrow, i.e., %d/%d/%d-%s\n", upcomingDate[0], upcomingDate[1], upcomingDate[2], findDay(upcomingDate[0], upcomingDate[1], upcomingDate[2]));
    }
}

// Finds age.
float findAge(int birthdate, int birthmonth, int birthyear){
    int noOfDays;
    float years, months, days;
    noOfDays =  (noOfDaysinYear(birthyear) - noOfDaysTillDate(birthdate,birthmonth,birthyear) + noOfDaysinRange((birthyear+1),(yearFinder()-1)) + noOfDaysTillDate(dateFinder(),monthFinder(),yearFinder()));
    years = noOfDays/365.0;
    months = (noOfDays%365)/30;
    days =  (noOfDays%365)%30;
    return years;
    
}

//Additional function to print a message.
void ageFinder(int birthdate, int birthmonth, int birthyear){
    printf("You were born on %s and you are %.1f years old.\n", findDay(birthdate,birthmonth,birthyear), findAge(birthdate,birthmonth,birthyear));
}






int main(){

        

    int date=3, month=4, year=1958;

    // printf("Enter date: ");
    // scanf("%d", &date);

    // printf("Enter month: ");
    // scanf("%d", &month);

    // printf("Enter year: ");
    // scanf("%d", &year);

    // findDay(date,month,year);
    printf("It is %s\n", findDay(date,month,year));
    printf("Your age is %.1f\n", findAge(date,month,year));

    dayFinder(dateFinder(),monthFinder(),yearFinder());    

    ageFinder(3,4,1996);

    printf("Now the time is %d:%d:%d\n", timeFinder('h'), timeFinder('m'), timeFinder('s'));

    waterDay();    

    return 0;
}
