/*=============================================================================
#  Author: Jeremy Shutrump
=============================================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "statemachine.h"

//state-machine functions

void state_transition(state_struct *StSt){ //Event structure passed by reference

    switch(StSt->transition.event){

    case PWRON:
    printf("...POWER ON\n\n");
    break;

    case T_PWROFF:
    printf("...POWER OFF\n\n");
    break;

    case PREPPRT:
    printf("...PREPARING TO PRINT\n\n");
    break;

    case STRPRT:
    printf("...PRINTING\n\n");
    break;

    case PRTCOM:
    printf("...PRINTING COMPLETE\n\n");
    break;

    case ERRR:
    printf("...ERROR\n\n");
    break;

    case ERRC:
    printf("...ERROR CLEARED\n\n");
    break;

    }
   StSt->State = StSt->NextState;

}

void state_action(state_struct *StSt)
{
    uint8_t ch;
    uint8_t t=0;
    switch(StSt->State){

    case S_PWROFF:

        do{
         printf("POWER OFF state:\nPress 'o' to turn on\n");
         scanf(" %s",&ch);
         }while(ch!='o');

            StSt->transition.event=PWRON;
            StSt->NextState=IDLE;
    break;

    case IDLE:
        do{
        printf("IDLE state:\nPress 'o' to turn off, 'p' for initialize print, 'e' for error\n");
        scanf(" %s",&ch);

            if(ch=='o')
            {
            StSt->NextState=S_PWROFF;
            StSt->transition.event=T_PWROFF;
            }
            else if(ch=='p'){
            StSt->NextState=RDY_PRINT;
            StSt->transition.event=PREPPRT;
            }
            else if (ch=='e'){
            StSt->NextState=SETERR;
            StSt->transition.event=ERRR;
            }
            else{
                printf("Invalid entry\n");
                t=1;
            }
        }while (t==1);
    break;

    case RDY_PRINT:
        do{
        printf("READY TO PRINT state:\n's' for print, 'e' for error\n");
        scanf(" %s",&ch);

            if(ch=='s'){
            StSt->NextState=PRINT;
            StSt->transition.event=STRPRT;
            }
            else if (ch=='e'){
            StSt->NextState=PRTERR;
            StSt->transition.event=ERRR;
            }
            else{
                printf("Invalid entry\n");
                t=1;
            }
        }while (t==1);
    break;

    case PRINT:
        do{
        printf("PRINT state:\nPress 'c' for print complete, 'e' for error\n");
        scanf(" %s",&ch);

            if(ch=='c'){
            StSt->NextState=IDLE;
            StSt->transition.event=PRTCOM;
            }
            else if (ch=='e') {
            StSt->NextState=PRTERR;
            StSt->transition.event=ERRR;
            }
            else{
                printf("Invalid entry\n");
                t=1;
            }
        }while (t==1);
    break;

    case SETERR:

        do{
        printf("SETUP ERROR state:\nPress 'r' to clear error\n");
        scanf(" %s",&ch);
            if(ch!='r'){
               printf("Invalid entry\n");
            }
        }while(ch!='r');

            StSt->NextState=IDLE;
            StSt->transition.event=ERRC;

    break;

    case PRTERR:

        do{
        printf("PRINT ERROR state:\nPress 'r' to clear error\n");
        scanf(" %s",&ch);
         if(ch!='r'){
               printf("Invalid entry\n");
            }
        }while(ch!='r');

            StSt->NextState=IDLE;
            StSt->transition.event=ERRC;

    break;
    }

}
