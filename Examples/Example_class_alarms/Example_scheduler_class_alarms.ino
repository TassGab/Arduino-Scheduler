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
#include <TimeAlarms.h>
AlarmId id;
HeaterSchedulerCs HS=HeaterSchedulerCs(); //class instance
void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
//  Serial.print("Day Size=");
//  Serial.println(sizeof(HS.Sched.WeekSched[0]),DEC);
  Serial.println(HS.SetEventDay(dowTuesday,Event0,0,swON,sw1));
setTime(23,59,50,25,9,17); // set time
   //time_t now_t=now();
//   time_t now_t;
//   now_t=HS.SetTimeOfDay(3,10,10);
//   Serial.println(HS.TimeToStr(now_t));
//   Serial.print("now in quarter=");
//   Serial.println(TimeToQuart(now_t));
   Alarm.alarmRepeat(0,0,0, UpdateSched);  // update schedule at midnight
   
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalClockDisplay();
  Alarm.delay(1000); // wait one second between clock display
}

/*
 * Functions
 */
 void OnceOnly() {
  Serial.println("This timer only triggers once");
  // use Alarm.free() to disable a timer and recycle its memory.
  Alarm.free(id);
  // optional, but safest to "forget" the ID after memory recycled
  id = dtINVALID_ALARM_ID;
  // you can also use Alarm.disable() to turn the timer off, but keep
  // it in memory, to turn back on later with Alarm.enable().
}
void UpdateSched()
{
  Serial.println("update Schedule");
  int dow=weekday();
  if HS.Sched.WeekSched[dow].Event[Event0].EventCtrl.isEnabled==evEN
  {
  id=Alarm.timerOnce(HS.QuartToTime(HS.Sched.WeekSched[dow].Event[Event0].EvTimeQ), OnceOnly);
  }
}
void digitalClockDisplay() {
  // digital clock display of the time
  Serial.print(hour());
  printDigits(minute());
  printDigits(second());
  Serial.println();
}

void printDigits(int digits) {
  Serial.print(":");
  if (digits < 10)
    Serial.print('0');
  Serial.print(digits);
}

