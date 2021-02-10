#include<stdio.h>
#include<stdlib.h>
#include "day_find.h" //User Defined Header file for finding the day of the week and used in the Calendar Program

char *day_find(int dd,int mm,int yy)
{
  char *ch[7]={"Saturday","Sunday","Monday","Tuesday","Wednesday","Thursday","Friday"};
  int year,count, day_f,month_f,n;
  if(dd > 31 || mm > 12)
  {
    printf("\nPlease Enter the Correct Date\n");
    exit(0);
  }
  year = yy - 1900;
  year = year / 4;
  year = year + yy -1900;
  switch(mm)
  {
    case 1: mm = 1;
            break;
    case 2: mm = 4;
            break;
    case 3: mm = 4;
            break;
    case 4: mm = 0;
            break;
    case 5: mm = 2;
            break;
    case 6: mm = 5;
            break;
    case 7: mm = 0;
            break;
    case 8: mm = 3;
            break;
    case 9: mm = 6;
            break;
    case 10: mm = 1;
            break;
    case 11: mm = 4;
            break;
    case 12: mm = 12;
            break;
  }
  year = year + mm;
  year = year + dd;
  dd = year % 7 ;
  dd = dd % 7;
  switch(dd)
  {
    case 0: return ch[0];
            break;
    case 1: return ch[1];
            break;
    case 2: return ch[2];
            break;
    case 3: return ch[3];
            break;
    case 4: return ch[4];
            break;
    case 5: return ch[5];
            break;
    case 6: return ch[6];
            break;
  }
  return *ch;
}
