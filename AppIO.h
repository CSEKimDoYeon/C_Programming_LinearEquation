
#ifndef AppIO_h
#define AppIO_h

#include "Common.h"
#include <stdio.h>

//출력함수
void AppIO_out_msg_startSolvingLinearEquation();
void AppIO_out_msg_endSolvingLinearEquation();

void AppIO_out_linearEquation(float c0, float c1);

void AppIO_out_root(float root);
void AppIO_out_msg_firstOrderTermCoefficientIsZero(void);


//입력함수
Boolean AppIO_in_solvingIsRequested();

void AppIO_in_linearEquation(float* p_c0, float* p_c1);

#endif
