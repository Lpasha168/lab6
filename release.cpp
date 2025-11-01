#include "funcs.hpp"
#include <iostream>
#include <cmath>
namespace WorkWithTime {
	TimePoint* newTime(int h, int m, int s) {
		TimePoint* t = new TimePoint;
		TimePoint& timeRef = *t;
		timeRef.hours = h;
		timeRef.min = m;
		timeRef.sec = s;
		return t;
	}

	void deleteTime(TimePoint* t) {
		delete t;

	}

	TimePoint* summtime(TimePoint* t1, TimePoint* t2) {
		TimePoint& time1 = *t1;
		TimePoint& time2 = *t2;
		int s = time1.sec + time2.sec;
		int m = time1.min + time2.min + s / 60;
		int h = time1.hours + time2.hours + m / 60;
		TimePoint* result = new TimePoint;
		TimePoint& resultRef = *result;
		resultRef.sec = s % 60;
		resultRef.min = m % 60;
		resultRef.hours = h % 24;
		return result;
	}

	void difftime(TimePoint* t1, TimePoint* t2, int* result) {
		TimePoint& time1 = *t1;
		TimePoint& time2 = *t2;
		int sec1 = time1.hours * 3600 + time1.min * 60 + time1.sec;
		int sec2 = time2.hours * 3600 + time2.min * 60 + time2.sec;
		*result = abs(sec1 - sec2);
	}

	bool correcttime(int h, int m, int s) {
		return ((h >= 0 && h < 24) && (m >= 0 && m < 60) && (s >= 0 && s < 60));
	}

}