/*
 * 10/09/2017
 * Gabriele Tasselli
 * 
 * Scheduler for Chorno Thermostat
 * weekly scheduler to be used with TimeAlarm library
 * The schedule is stored in the eeprom
 * For memory optimization the resolution is 15 minutes.
 * Intially 4 events per day are allocated
 */
#include "Heater_scheduler_class.h"

void setup() {
  // put your setup code here, to run once:
  HeaterSchedulerCs HS=HeaterSchedulerCs(); //class instance
  Serial.begin(9600);
  Serial.print("Day Size=");
  Serial.println(sizeof(HS.Sched.WeekSched[0]),DEC);
  Serial.println(HS.SetEventDay(dowSunday,Event1,3,swOFF,sw2));
   //time_t now_t=now();
   time_t now_t;
   now_t=HS.SetTimeOfDay(3,10,10);
   Serial.println(HS.TimeToStr(now_t));
   Serial.print("now in quarter=");
   Serial.println(TimeToQuart(now_t));
}

void loop() {
  // put your main code here, to run repeatedly:

}

/*
 * Functions
 */
 
