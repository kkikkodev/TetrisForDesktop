#include <stdio.h>
#include <time.h>
#include "Time.h"

// ���� �ð��� ������
time_t Time_GetTime() {

	time_t current;
	time(&current);

	return current;
}