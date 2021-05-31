#include <stdio.h>

#include "calender.h"
#include "date.h"
#include "interface.h"

extern int monthDays[];
extern char week[7][5];
extern char monthNames[12][10];

void showCalender(struct date d)
{
    int tempDay = d.day,totaldays = monthDays[d.month - 1];

    printf("\t\t\t  %s %d\n\n",monthNames[d.month - 1],d.year);
    struct date currDate = getCurrentDate();
    setColor(Red);
    TAB
    printf("%s \t",week[0]);
    setColor(Yellow);
    for(int i = 1;i < 7;i++)
    {
        printf("%s \t",week[i]);
    }
    printf("\n");

    TAB
    for(int i = 0;i < d.day;i++)
    {
        printf(" \t");
    }

    if(isLeapYear(d.year) && 2 == d.month)
    {
        totaldays++;
    }

    for(int i = 1;i <= totaldays;i++,tempDay++)
    {
        if(currDate.d_date == i && currDate.month == d.month && currDate.year == d.year)
        {
            setColor(LightBlue);
            printf("%d \t",i);
            setColor(Yellow);
        }
        else if(0 == tempDay)
        {
            setColor(Red);
            printf("%d \t",i);
            setColor(Yellow);
        }
        else
        {
            printf("%d \t",i);
        }
        if(6 == tempDay)
        {
            tempDay = -1;
            printf("\n");
            TAB
        }
    }
    printf("\n");

    return;
}
