/*=============================================================================
#  Author: Jeremy Shutrump
=============================================================================*/

#ifndef STATEMACHINE_H_INCLUDED
#define STATEMACHINE_H_INCLUDED

//State definitions
#define S_PWROFF 1
#define IDLE 2
#define RDY_PRINT 3
#define PRINT 4
#define SETERR 5
#define PRTERR 6

//Transition definitions
#define PWRON 7
#define T_PWROFF 8
#define PREPPRT 9
#define STRPRT 10
#define ERRR 11
#define ERRC 12
#define PRTCOM 13


typedef struct{
    uint8_t event;
}trans_struct;

typedef struct {

    uint8_t State;
    uint8_t NextState;
    trans_struct transition;

}state_struct;

void state_transition(state_struct *StSt);
void state_action(state_struct *StSt);
#endif // STATEMACHINE_H_INCLUDED
