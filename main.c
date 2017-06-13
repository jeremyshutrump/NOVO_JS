#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "statemachine.h"

state_struct SYS_STATE;

int main()
{
    uint8_t ch;
    SYS_STATE.State=S_PWROFF;
    SYS_STATE.transition.event=T_PWROFF;

    do{
    printf("POWER OFF state:\nPress 'o' to turn on the printer\n");
    //wait until 'o' is pressed send pwr on into state transition
    scanf(" %s",&ch);
    }while(ch!='o');

    SYS_STATE.transition.event=PWRON;
    SYS_STATE.NextState=IDLE;

    while(1)
    {
        if(SYS_STATE.State != SYS_STATE.NextState)
        {
        //state transition
        state_transition(&SYS_STATE);

        // state action
        state_action(&SYS_STATE);
        }
    }
    return 0;
}
