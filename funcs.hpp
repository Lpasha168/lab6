#pragma once 
namespace WorkWithTime {
	struct TimePoint {
		int hours;
		int min;
		int sec;
	};
	bool correcttime(int h, int m, int s);
	TimePoint* summtime(TimePoint* t1, TimePoint* t2);
	void difftime(TimePoint* t1, TimePoint* t2, int* result);
	TimePoint* newTime(int hours, int min, int sec);
	void deleteTime(TimePoint* t);
}