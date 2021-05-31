#include <stdio.h>
#include <conio.h>
#define _WIN32_WINNT 0x0500
#include <windows.h>

#include "calender.h"
#include "date.h"
#include "interface.h"


extern int week[7][5];
enum arrowKeys {KEY_UP = 72,KEY_DOWN = 80,KEY_LEFT = 75,KEY_RIGHT = 77};

void mainMenu()
{
    HWND console = GetConsoleWindow();
    MoveWindow(console,250,250,510,290,TRUE);
    SetConsoleTitle("Calender");
    system("color 07");
    struct date currentDate = getCurrentDate();
    currentDate.d_date = 1;
    currentDate.day = getDay(currentDate);
    unsigned char choice;
    do
    {
        system("cls");
        showCalender(currentDate);
        guideLines();
        choice = getch();

        if(224 == choice)
        {
            choice = getch();
        }

        switch(choice)
        {
            case KEY_LEFT:  /// Move One Month Backward
            {
                currentDate.d_date = 1;

                if(1 == currentDate.month)
                {
                    currentDate.month = 12;
                    currentDate.year--;
                }
                else
                {
                    currentDate.month--;
                }

                currentDate.day = getDay(currentDate);

                break;
            }
            case KEY_RIGHT: /// Move One Month Forward
            {
                currentDate.d_date = 1;

                if(12 == currentDate.month)
                {
                    currentDate.month = 1;
                    currentDate.year++;
                }
                else
                {
                    currentDate.month++;
                }

                currentDate.day = getDay(currentDate);

                break;
            }
            case 32:    /// Space = 32
            {
                do
                {
                    system("cls");

                    printf("Options\n\n");
                    printf("1.Jump To Date\n");
                    printf("Esc For Back\n");
                    choice = getch();
                    switch(choice)
                    {
                        case 49:
                        {
                            system("cls");
                            setDate(&currentDate);
                            choice = 27;
                            break;
                        }
                    }
                }while(27 != choice);
                choice = '\0';
                break;
            }
        }

    }while(27 != choice); /// 27 = Esc

}

void guideLines()
{
    TAB
    setColor(Yellow);
    printf("<- Previous \t\t\t\t   Next ->\n");
    TAB
    printf("Space For More Option");
    TAB TAB TAB
    printf("Esc For Exit\n");
    setColor(White);
}

void setColor(int ForgC)
{
     WORD wColor;
     //This handle is needed to get the current background attribute

     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
     CONSOLE_SCREEN_BUFFER_INFO csbi;
     //csbi is used for wAttributes word

    //SetConsoleTextAttribute(hStdOut, ForgC);

     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {
          //To mask out all but the background attribute, and to add the color
          wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
            SetConsoleTextAttribute(hStdOut, wColor);
     }
     return;
}
