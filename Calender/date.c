#include <stdio.h>
#include <windows.h>

#include "date.h"

int monthDays[] = {31,28,31,30,31,30,31,31,30,31,30,31};
char week[7][5] = {"Sun","Mon","Tue","Wed","Thur","Fri","Sat"};
char monthNames[12][10] = {"January","February","March","April","May","June",
                            "July","August","September","October","November","December"};

struct date getCurrentDate()
{
    SYSTEMTIME sTime;
    struct date currentDate;

    GetSystemTime(&sTime);

    currentDate.d_date = sTime.wDay;
    currentDate.month = sTime.wMonth;
    currentDate.year = sTime.wYear;
    currentDate.day = sTime.wDayOfWeek;

    return currentDate;
}

void setDate(struct date *d)
{
    printf("Enter month ");
    scanf("%d",&(d->month));
    printf("Enter Year ");
    scanf("%d",&(d->year));

    d->day = getDay(*d);

}

int isLeapYear(int year)
{
    int result = 0;

    if(0 == year % 4)
    {
        if(0 == year % 100)
        {
            if(0 == year % 400)
            {
                result = 1;
            }
            else
            {
                return 0;
            }
        }
        result = 1;
    }

    return result;
}

int getDay(struct date d)
{
    int odd = 0;
    odd = getYearOddNo(d.year - 1);
    odd = odd + getMonthOddNo(d.month - 1);
    odd = odd + getDayOddNo(d.d_date);

    if(isLeapYear(d.year))
    {
        if(2 < d.month)
        {
            odd++;
        }
        else if(2 == d.month)
        {
            if(29 == d.day)
            {
                odd++;
            }
        }
    }

    return odd % 7;
}

int getDayOddNo(int day)
{
    return day % 7;
}

int getMonthOddNo(int month)
{
    int monthCode[12] = {3,0,3,2,3,2,3,3,2,3,2,3},odd = 0;
    for(int i = 0;i < month;i++)
    {
        odd = odd + monthCode[i];
    }
    return odd % 7;
}

int getYearOddNo(int year)
{
    int odd = 0,leap = 0;
    if(year >= 400)
    {
        year = year % 400;
        odd = 0;
    }
    if(year >= 300)
    {
        odd = odd + (year/300);
        year = year % 300;
    }
    if(year >= 200)
    {
        odd = odd + ((year/200)*3);
        year = year % 200;
    }
    if(year >= 100)
    {
        odd = odd + ((year/100)*5);
        year = year % 100;
    }
    if(year > 0)
    {
        leap = year / 4;
        odd = odd + (leap * 2);
        odd = odd + (year - leap);
    }
    return odd % 7;
}
