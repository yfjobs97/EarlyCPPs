/*C program to design a digital clock.*/

#include <stdio.h>
#include <time.h> //for sleep() function
#include <cstdlib>
#include <Windows.h>
#include <ctime>

int main()
{
    int hour, minute, second;

    hour=minute=second=0;

	time_t t = time(0);
	struct tm* now = localtime(&t);
	second = now->tm_sec;
	minute = now->tm_min;
	hour = now->tm_hour;


    while(1)
    {
        //clear output screen
        system("CLS");

        //print time in HH : MM : SS format
        printf("%02d : %02d : %02d ",hour,minute,second);

         //clear output buffer in gcc
        fflush(stdout);

         //increase second
        second++;

        //update hour, minute and second
        if(second==60){
            minute+=1;
            second=0;
        }
        if(minute==60){
            hour+=1;
            minute=0;
        }
        if(hour==24){
            hour=0;
            minute=0;
            second=0;
        }

        Sleep(1000);   //wait till 1 second
    }

    return 0;
}
