
#ifndef AppIO_h
#define AppIO_h

#include "Common.h"
#include <stdio.h>

//����Լ�
void AppIO_out_msg_startSolvingLinearEquation();
void AppIO_out_msg_endSolvingLinearEquation();

void AppIO_out_linearEquation(float c0, float c1);

void AppIO_out_root(float root);
void AppIO_out_msg_firstOrderTermCoefficientIsZero(void);


//�Է��Լ�
Boolean AppIO_in_solvingIsRequested();

void AppIO_in_linearEquation(float* p_c0, float* p_c1);

#endif
