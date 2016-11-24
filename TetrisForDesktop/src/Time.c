#include <stdio.h>
#include <time.h>
#include "Time.h"

int _Time_ChangePerSecond(Time t);

// add_v003: �ð� �ʷ� ��ȯ
int _Time_ChangePerSecond(Time t) {

	int totalSecond = 0;

	totalSecond += t.hour * 3600;
	totalSecond += t.minute * 60;
	totalSecond += t.second;

	return totalSecond;
}

// add_v003: �ð� ���� ��� (�Ϸ簡 ������...)
int Time_GetTimeDifference(Time currentTime, Time lastTime) {

	int timeDifference;
	int currentTimeSecond;
	int lastTimeSecond;

	currentTimeSecond = _Time_ChangePerSecond(currentTime);
	lastTimeSecond = _Time_ChangePerSecond(lastTime);
	timeDifference = currentTimeSecond - lastTimeSecond;

	return timeDifference;
}

// add_v003: �ð� �ʱ�ȭ
Time Time_Init() {

	Time t;
	t.hour = 0;
	t.minute = 0;
	t.second = 0;

	return t;
}

// add_v002: ���� �ð��� ������
Time Time_GetCurrentTime() {

	Time currentTime;

	time_t current;
	struct tm *timeInfo;
	current = time(NULL);
	timeInfo = localtime(&current);

	currentTime.second = timeInfo->tm_sec;
	currentTime.minute = timeInfo->tm_min;
	currentTime.hour = timeInfo->tm_hour;

	return currentTime;
}

