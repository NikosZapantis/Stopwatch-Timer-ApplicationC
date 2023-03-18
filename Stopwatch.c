#include <stdio.h>
#include <conio.h>
#include <windows.h> 

int main() {
    int hours = 0, min = 0, sec = 0, ms = 0;
    char ch;

    printf("Do you need a stopwatch or a countdown?\nAvailable choices: Stopwatch (S), Countdown (C)\nType here: ");
    ch = getchar();

    switch(ch) {
        case 'S': 

            printf("~ You can quit stopwatch anytime by pressing ctrl + c ~\n");
            while(1) {

                printf("       \r* Live time %2d : %2d : %2d : %2d", hours, min, sec, ms);
                ++ms;
                Sleep(1);
                if(ms == 100) {

                    ++sec;
                    ms = 0;
                }
                if(sec == 59) {

                    ++min;
                    sec = 0;
                    ms = 0;
                }
                if(min == 59) {

                    ++hours;
                    min = 0;
                    sec = 0;
                    ms = 0;
                }
                if(hours == 24) {

                    hours = 0;
                    min = 0;
                    sec = 0;
                    ms = 0;
                }
            }
            break;
        case 'C': 
            int times;

            printf("Enter your time in similar way HH:MM:SS(using space) between hours, minutes and seconds!\nType here: ");
            scanf("%d%d%d", &hours, &min, &sec);

            if(sec >= 60) {

                times = sec / 60;
                for(int i = times; i > 0; --i){

                    min += 1;
                    sec -= 60;
                }
            }

            if(min >= 60) {

                times = min / 60;
                for(int i = times; i > 0; --i) {

                    hours += 1;
                    min -= 60;
                }
            }
            while(1) {

                printf("      \r* Live time %d:%d:%d", hours, min, sec);
                Sleep(1000);
                if(sec != 0) {

                    --sec;
                }
                if(sec == 0 && min != 0) {
                    
                    sec = 0;
                    printf("      \r* Live time %d:%d:0", hours, min);
                    Sleep(1000);
                    sec = 59;
                    --min;
                }
                if(sec == 0 && min == 0 && hours != 0) {

                    --hours;
                    min = 59;
                    sec = 59;
                }
                if(hours == 0 && min == 0 && sec == 0) {

                    printf("      \r* Live time %d:%d:%d", hours, min, sec);
                    Sleep(1000);
                    printf("\n\t\t\t\t ~ WARNING! Countdown ended ~");
                    exit(0);
                }
            }
    }

    return 0;
}