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
#include <Logging_class.h>
AlarmId id0,id1,id2,id3,id4,id5;
EventNum_sc ev; //Global var for event of the day 
HeaterSchedulerCs HS=HeaterSchedulerCs(); //class instance
void setup() {
  // put your setup code here, to run once:
Log.LogLevel=_Info;
Log.ZBen=true;
Log.ZBLogLevel=_Error;
Log.AutoCR=false;
  Serial.begin(9600);
//  Serial.print("Day Size=");
//  Serial.println(sizeof(HS.Sched.WeekSched[0]),DEC);
  Log.Info(HS.SetEventDay(dowTuesday,Event0,0,evEN,swON,sw1));Log.Info("\n");
  Log.Info(HS.SetEventDay(dowTuesday,Event1,1,evEN,swOFF,sw1));Log.Info("\n");
  Log.Info(HS.SetEventDay(dowTuesday,Event2,2,evEN,swON,sw1));Log.Info("\n");
  Log.Info(HS.SetEventDay(dowTuesday,Event3,3,evEN,swOFF,sw1));Log.Info("\n");
  Log.Info(HS.SetEventDay(dowTuesday,Event4,4,evEN,swON,sw1));Log.Info("\n");
  Log.Info(HS.SetEventDay(dowTuesday,Event5,5,evEN,swOFF,sw1));Log.Info("\n");
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
 int FindAlarmID(AlarmId id)
 {
  int _ev=255;
   if(id==id0) _ev=0;     
   if(id==id1) _ev=1;
   if(id==id2) _ev=2;
   if(id==id3) _ev=3;
   if(id==id4) _ev=4;
   if(id==id5) _ev=5;
   Log.Debug("Event found="+String(_ev));
   //Log.Debug(_ev);
  return _ev;
 }
 void Event0R() {
  //AlarmId id=  Alarm.getTriggeredAlarmId();
  ev=0;
  Log.Info("Triggered Alarm=");Log.Info(String(ev)); Log.Info("\n");
  //Serial.println(ev,DEC);
  int dow=weekday()-1;
  // use Alarm.free() to disable a timer and recycle its memory.

  if (HS.Sched.WeekSched[dow].Event[ev].EventCtrl.swTurn==swON)
  {
    Log.Info("Switch ON\n");
  }
  else
  {
    Log.Info("Switch OFF\n");
  }
  Alarm.free(id0);
  // optional, but safest to "forget" the ID after memory recycled
  id0 = dtINVALID_ALARM_ID;
  // you can also use Alarm.disable() to turn the timer off, but keep
  // it in memory, to turn back on later with Alarm.enable().
}
void Event1R() {
  //AlarmId id=  Alarm.getTriggeredAlarmId();
  ev=1;
  Log.Info("Triggered Alarm=");Log.Info(String(ev)); Log.Info("\n");
  //Serial.println(ev,DEC);
  int dow=weekday()-1;
  // use Alarm.free() to disable a timer and recycle its memory.

  if (HS.Sched.WeekSched[dow].Event[ev].EventCtrl.swTurn==swON)
  {
    Log.Info("Switch ON\n");
  }
  else
  {
    Log.Info("Switch OFF\n");
  }
  Alarm.free(id1);
  // optional, but safest to "forget" the ID after memory recycled
  id1 = dtINVALID_ALARM_ID;
  // you can also use Alarm.disable() to turn the timer off, but keep
  // it in memory, to turn back on later with Alarm.enable().
}
void Event2R() {
  //AlarmId id=  Alarm.getTriggeredAlarmId();
  ev=2;
  Log.Info("Triggered Alarm=");Log.Info(String(ev)); Log.Info("\n");
  //Serial.println(ev,DEC);
  int dow=weekday()-1;
  // use Alarm.free() to disable a timer and recycle its memory.

  if (HS.Sched.WeekSched[dow].Event[ev].EventCtrl.swTurn==swON)
  {
    Log.Info("Switch ON\n");
  }
  else
  {
    Log.Info("Switch OFF\n");
  }
  Alarm.free(id2);
  // optional, but safest to "forget" the ID after memory recycled
  id2 = dtINVALID_ALARM_ID;
  // you can also use Alarm.disable() to turn the timer off, but keep
  // it in memory, to turn back on later with Alarm.enable().
}
void Event3R() {
  //AlarmId id=  Alarm.getTriggeredAlarmId();
  ev=3;
  Log.Info("Triggered Alarm=");Log.Info(String(ev)); Log.Info("\n");
  //Serial.println(ev,DEC);
  int dow=weekday()-1;
  // use Alarm.free() to disable a timer and recycle its memory.

  if (HS.Sched.WeekSched[dow].Event[ev].EventCtrl.swTurn==swON)
  {
    Log.Info("Switch ON\n");
  }
  else
  {
    Log.Info("Switch OFF\n");
  }
  Alarm.free(id3);
  // optional, but safest to "forget" the ID after memory recycled
  id3 = dtINVALID_ALARM_ID;
  // you can also use Alarm.disable() to turn the timer off, but keep
  // it in memory, to turn back on later with Alarm.enable().
}
void Event4R() {
  //AlarmId id=  Alarm.getTriggeredAlarmId();
  ev=4;
  Log.Info("Triggered Alarm=");Log.Info(String(ev)); Log.Info("\n");
  //Serial.println(ev,DEC);
  int dow=weekday()-1;
  // use Alarm.free() to disable a timer and recycle its memory.

  if (HS.Sched.WeekSched[dow].Event[ev].EventCtrl.swTurn==swON)
  {
    Log.Info("Switch ON\n");
  }
  else
  {
    Log.Info("Switch OFF\n");
  }
  Alarm.free(id4);
  // optional, but safest to "forget" the ID after memory recycled
  id4 = dtINVALID_ALARM_ID;
  // you can also use Alarm.disable() to turn the timer off, but keep
  // it in memory, to turn back on later with Alarm.enable().
}
void Event5R() {
  //AlarmId id=  Alarm.getTriggeredAlarmId();
  ev=5;
  Log.Info("Triggered Alarm=");Log.Info(String(ev)); Log.Info("\n");
  //Serial.println(ev,DEC);
  int dow=weekday()-1;
  // use Alarm.free() to disable a timer and recycle its memory.

  if (HS.Sched.WeekSched[dow].Event[ev].EventCtrl.swTurn==swON)
  {
    Log.Info("Switch ON\n");
  }
  else
  {
    Log.Info("Switch OFF\n");
  }
  Alarm.free(id5);
  // optional, but safest to "forget" the ID after memory recycled
  id5 = dtINVALID_ALARM_ID;
  // you can also use Alarm.disable() to turn the timer off, but keep
  // it in memory, to turn back on later with Alarm.enable().
}
void UpdateSched()
{
  Log.Info("update Schedule\n");
  int dow=weekday()-1;
//Serial.print(dow); 
    
    if (HS.Sched.WeekSched[dow].Event[Event0].EventCtrl.isEnabled==evEN)
    {
      id0=Alarm.timerOnce(HS.QuartToTime(HS.Sched.WeekSched[dow].Event[Event0].EvTimeQ), Event0R);
      Log.Info("id0: ");
      Log.Info(HS.EventToStrShort(HS.Sched.WeekSched[dow].Event[Event0]));
      Log.Info("\n");
    }
     if (HS.Sched.WeekSched[dow].Event[Event1].EventCtrl.isEnabled==evEN)
    {
      id1=Alarm.timerOnce(HS.QuartToTime(HS.Sched.WeekSched[dow].Event[Event1].EvTimeQ), Event1R);
      Log.Info("id1: ");
      Log.Info(HS.EventToStrShort(HS.Sched.WeekSched[dow].Event[Event1]));
      Log.Info("\n");
    }
   if (HS.Sched.WeekSched[dow].Event[Event2].EventCtrl.isEnabled==evEN)
    {
      id2=Alarm.timerOnce(HS.QuartToTime(HS.Sched.WeekSched[dow].Event[Event2].EvTimeQ), Event2R);
      Log.Info("id2: ");
      Log.Info(HS.EventToStrShort(HS.Sched.WeekSched[dow].Event[Event2]));
      Log.Info("\n");
    }
    if (HS.Sched.WeekSched[dow].Event[Event3].EventCtrl.isEnabled==evEN)
    {
      id3=Alarm.timerOnce(HS.QuartToTime(HS.Sched.WeekSched[dow].Event[Event3].EvTimeQ), Event3R);
      Log.Info("id3: ");
      Log.Info(HS.EventToStrShort(HS.Sched.WeekSched[dow].Event[Event3]));
      Log.Info("\n");
    }
     if (HS.Sched.WeekSched[dow].Event[Event4].EventCtrl.isEnabled==evEN)
    {
      id4=Alarm.timerOnce(HS.QuartToTime(HS.Sched.WeekSched[dow].Event[Event4].EvTimeQ), Event4R);
      Log.Info("id4: ");
      Log.Info(HS.EventToStrShort(HS.Sched.WeekSched[dow].Event[Event4]));
      Log.Info("\n");
    }
     if (HS.Sched.WeekSched[dow].Event[Event5].EventCtrl.isEnabled==evEN)
    {
      id5=Alarm.timerOnce(HS.QuartToTime(HS.Sched.WeekSched[dow].Event[Event5].EvTimeQ), Event5R);
      Log.Info("id5: ");
      Log.Info(HS.EventToStrShort(HS.Sched.WeekSched[dow].Event[Event5]));
      Log.Info("\n");
    }
}
void digitalClockDisplay() {
  // digital clock display of the time
  Log.Info(String(hour()));
  printDigits(minute());
  printDigits(second());
  Log.Info("\n");
}

void printDigits(int digits) {
  Log.Info(":");
  if (digits < 10)
    Log.Info("0");
  Log.Info(String(digits));
}

