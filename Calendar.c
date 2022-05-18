#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "day_find.c"   //Finding the Day of the week 
 
/*Declaring the Global variables for accesing them through out the file/program*/
int d=1,weekDay,mon,year,b_da,b_mon,b_year,MonthDays,Date,firstWeekDay,firstDay,lastDay,M;
int month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int day[] = {0, 1, 2, 3, 4, 5, 6};
char *week_d[7] = {"Sun","Mon","Tue","Wed","Thu","Fri","Sat"};
char *months[]=
{"\t\tJanuary","\t\tFebruary","\t\tMarch","\t\tApril","\t\tMay","\t\tJune","\t\tJuly","\t\tAugust","\t\tSeptember","\t\tOctober","\t\tNovember","\t\tDecember"};

/* Calculating the weekday for the starting in the Month*/
int dayWeek(int d, int m, int y){
    
    int i;
    
    if (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0)){
        month[1] = 29;
    }
    else
    {
        month[1]= 28;
    }
    if (y < 1900 || m < 1 || m > 12 || d < 1 || d > month[m - 1]) {
        printf("This is an invalid date.\n");
        exit(1);
    }
    for (i = 1990; i < y; i++){
        if (i % 4 == 0 && (i % 100 != 0 || i % 400 == 0)){
            d += 366;
        }else{
            d += 365;
        }
    }
    for (i = 0; i < m - 1; i++){
        d += month[i];
    }
    return day[d % 7];
}
 
/*Calculating the Number of days in a Month */
int monthdays(int m,int y)
{
    if (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0)){
      return  month[1] = 29;
    }
    else
    {
      return month[m-1];
    }
  
}
int monNum(int mon)
{
  int n,i,j=1;
  n =sizeof(months)/sizeof(char*);
  for(i=1;i<=n;i++)
  {
     MonthDays = monthdays(i-1,year);
     if(month[i-1]== MonthDays)
       j++;
  }
  return j;
}

/*Printing the individual Month*/
void printMonth(int firstDay,int lastDay, int firstWeekDay ,int mon){
    int i,Date,M,Y,num;
    static int num_days=0;
    time_t t;
    t = time(NULL);
    struct tm tm = *localtime(&t);
    Date = tm.tm_mday;
    M=tm.tm_mon+1; 
    Y=tm.tm_year+1900;
    num = monNum(M);
    printf("\033[1m\033[37mSun  Mon  Tue  Wed  Thu  Fri  Sat\n");
    for(i = 0; i < firstWeekDay ; i ++ ) {
        printf("     ");
    }
    for(i = 1; i <= lastDay; i++) {
          if(Date == i)
          {
            if(M == mon )
            {
            printf("\e[45m\033[1m\033[32m%2d\e[49m   ", i );
            if((i + firstDay + firstWeekDay - 1)%7 ==0){
            printf("\n");}
            continue;
            }
          }
        ((i + firstDay + firstWeekDay - 1)%7 == 0 )?printf("\033[1m\033[31m%2d   ", i ):printf("\033[1m\033[36m%2d   ", i);
        if((i + firstDay + firstWeekDay - 1)%7 ==0){
            printf("\n");
        }
    }
}
/*Printing the name according the date,month and year which they are born */
char* birth_name(int B_Mon,int B_Dat, int Year)
{
  const char* Name[4]= {"Ram","Sita","Laxman","Urmila"};
  int B_Date,i;
  const int Dates[4]= {5,21,23,2};
  const int Months[4]={6,1,6,10};
  char s[100];
  for(i=0;i<4;i++)
  {
    if(B_Dat == Dates[i] && B_Mon == Months[i])
    {
      printf("\n\t\e[42m\033[1m\033[165mHey %s, HAPPY BIRTHDAY....\e[49m\t\n",Name[i]);
      exit(0);
      
    }
  }
  printf("\n\t\e[46m\033[1m\033[91mYOUR Name is NOT Added into the LIST\e[49m\t\n");
}

/*Printing the Calendar*/
void calendar(int year,int weekDay,int MonthDays,int m1)
{
  int i,j=weekDay,k=MonthDays;
  printMonth(d,k,j,m1);
}
void birthmonth(int b_da,int b_mon,int week,int Month,int firstDay)
{
  int i;
  printf("\033[1m\033[37mSun  Mon  Tue  Wed  Thu  Fri  Sat\n");
  for(i = 0; i < week ; i ++ ) {
        printf("     ");
    }
  for(i = 1; i <= Month; i++) {
   if(i == b_da)
    { 
      printf("\e[45m\033[1m\033[32m%2d\e[49m   ", i );
      if((i + firstDay + week - 1)%7 ==0)
      {
        printf("\n");
      }
      continue;
    }
    ((i + firstDay + week - 1)%7 == 0 )?printf("\033[1m\033[31m%2d   ", i ):printf("\033[1m\033[36m%2d   ", i);
    if((i + firstDay + week - 1)%7 ==0)
    {
      printf("\n");
    }
  }

}
/* Date printing after the particular number of days*/
void date_after_particular_days(int days_after,int y)
{
  int month_days[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
  int i,k=0, p,a;
  time_t t;
  t = time(NULL);
  struct tm tm = *localtime(&t);
  Date = tm.tm_mday;
  M=tm.tm_mon;
  for(i=0;i<M+1;i++)
  k=k+month_days[i];
  k=k+Date+days_after;
 printf("\nNew Date :");
 if(k<=365)
 {
  for(i=0;i<13;i++)
  {
   p=k-month_days[i];
   if(p<=month_days[i+1])
   {
    a=i+1;
    break;
   }
   else
    k=p;
  }
 printf(" %d-%d-%d",p,a,y);
 }
 else
 {
  k=k-365;
   for(i=0;i<13;i++)
    {
     p=k-month_days[i];
     if(p<=month_days[i+1])
     {
       a=i+1;
       break;
     }
     else
      k=p;
    }
  printf(" %d-%d-%d",p,a,y+1);
 } 
}

/*Main Function starts*/
int main(void){
    int d = 1,mon,year,weekDay,MonthDays,k,i,not_dat,not_mon;
    char ch,*s,*B;
    struct Msg *m;
    printf("\nEnter the Year:\n");
    scanf("%d",&year);
    for(i=1;i<=12;i++)
    {
       weekDay = dayWeek(d,i,year); 
       k= month[i-1];
       MonthDays = monthdays(i-1,year);
       printf("\n");
       printf("\033[4m\033[4m\033[1m\033[33m\e[5m%s-\033[4m%d\033[4m\e[5m\n",months[i-1],year);
       printf("\033[0m");
       calendar(year,weekDay,k,i);
    }  
    printf("\n\033[1m\033[31m\e[5mPrinting the Birthday Month:\e[5m\t\n");
    printf("\nEnter the birth month and date Year:\n");
    scanf("%d%d%d",&b_mon,&b_da,&b_year);
    weekDay = dayWeek(d,b_mon,b_year); 
    k= month[b_mon-1];
    MonthDays = monthdays(b_mon,year);
    printf("\n");
    printf("\033[4m\033[4m\033[1m\033[33m\e[5m%s-\033[4m%d\033[4m\e[5m\n",months[b_mon-1],b_year);
    printf("\033[0m");
    birthmonth(b_da,b_mon,weekDay,MonthDays,1);
    printf("\n\n%d/%d/%d ::",b_da,b_mon,b_year);
    s = day_find(b_da,b_mon,year);
    printf("%s\n",s);
    printf("\n");
    birth_name(b_mon,b_da,year);
    printf("\n\n\e[5m\033[1m\033[35mHappy Coding...\n\e[25m");
    printf("\n\033[0mEnter the number of days to print the date:\n ");
    scanf("%d",&days_after);
    date_after_particular_days(days_after,year);
    printf("\n");
    return 0;
}
