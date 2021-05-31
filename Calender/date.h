struct date
{
    int d_date,month,year,day;
};

struct date getCurrentDate();

/// For Calculate Day On A Particular Date
int getDay(struct date);

int getYearOddNo(int);

int getMonthOddNo(int);

int getDayOddNo(int);

int isLeapYear(int);

void setDate(struct date *);
