#ifndef RTC_clock_h
#define RTC_clock_h

#include "Arduino.h"

// Includes Atmel CMSIS
#include <chip.h>

#define RC							0
#define	XTAL						1

class RTC_clock
{
	public:
		RTC_clock (int source);
		void init ();
		void set_time (int hour, int minute, int second);
		int get_hours ();
		int get_minutes ();
		int get_seconds ();
		void set_date (int day, int month, uint16_t year);
		uint16_t get_years ();
		int get_months ();
		int get_days ();
		int get_day_of_week ();
		int set_hours (int _hour);
		int set_minutes (int minute);
		int set_seconds (int second);
		int set_days (int day);
		int set_months (int month);
		int set_years (uint16_t year);
		void set_alarmtime (int hour, int minute, int second);
		void set_alarmdate (int day, int month);
		
		void attachalarm (void (*)(void));
		void disable_alarm ();
	private:
		int _source;
		int _hour;
		int _minute;
		int _second;
		int _day;
		int _month;
		uint16_t _year;
		int _day_of_week;
		int calculate_day_of_week (uint16_t _year, int _month, int _day);
		uint32_t current_time ();
		uint32_t current_date ();
		uint32_t _current_time;
		uint32_t _current_date;
		uint32_t change_time (uint32_t _now);
		uint32_t change_date (uint32_t _now);
		uint32_t _now;
		uint32_t _changed;
};

#endif