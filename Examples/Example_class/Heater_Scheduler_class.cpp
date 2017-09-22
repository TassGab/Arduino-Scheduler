#include "Heater_scheduler_class.h"
#include <Arduino.h>
String HeaterSchedulerCs::SetEventDay(timeDayOfWeek_t dow, EventNum_sc Evnum, TimeQuarter_sc TimeQ, SwitchState_sc SwSt, SwitchNum_sc SwN)
 {
   String s="Dow: ";   
   Sched.WeekSched[dow-1].dow=dow;
   Sched.WeekSched[dow-1].Event[Evnum].EvTimeQ=TimeQ;
   Sched.WeekSched[dow-1].Event[Evnum].EventCtrl.isEnabled=evEN;
   Sched.WeekSched[dow-1].Event[Evnum].EventCtrl.swTurn=SwSt;
   Sched. WeekSched[dow-1].Event[Evnum].EventCtrl.nSwitch=SwN;
//   Serial.print("DOW=");
//   Serial.print(dayStr(dow));
//   Serial.print("\t");
//   Serial.print("Event=");
//   Serial.print(Evnum);
//   Serial.println(EventToStr(WeekSched[dow-1].Event[Evnum]));
   s+=dayStr(dow);
   s+=" ; EventNum: ";
   s+=Evnum;
   s+=" ; ";
   s+=EventToStrShort(Sched.WeekSched[dow-1].Event[Evnum]);
   return s;
 }
String HeaterSchedulerCs::EventToStrShort(EventType_sc Ev)
{
  String s="[";
  s+=Ev.EvTimeQ;
  s+=",";
  s+=Ev.EventCtrl.isEnabled;
  s+=",";
  s+=Ev.EventCtrl.swTurn;
  s+=",";
  s+=Ev.EventCtrl.nSwitch;
  s+="]";
  return s;
}
String HeaterSchedulerCs::EventToStrLong(EventType_sc Ev)
 {
  String s="[Quarter: ";
  s+=Ev.EvTimeQ;
  s+=" (time: ";
  //Serial.print("\nEvent=[time: ");
  s+=TimeToStr(QuartToTime(Ev.EvTimeQ));
  //Serial.print(" ; En: ");
  s+=") ; En:"; 
  //Serial.print(Ev.EventCtrl.isEnabled);
  s+=Ev.EventCtrl.isEnabled ? "Enabled":"Disabled";
  //Serial.print(" ; SwState: ");
  s+=" ; SwState: ";
  //Serial.print(Ev.EventCtrl.swTurn);
  s+=Ev.EventCtrl.swTurn ? "ON":"OFF";
  //Serial.print(" ; SwNum; ");
  s+=" ; SwNum; ";
  //Serial.print(Ev.EventCtrl.nSwitch);
  s+=Ev.EventCtrl.nSwitch;
  //Serial.println("]");
  s+="]";
  return s;
 }
String HeaterSchedulerCs::TimeToStr(time_t tt)
 {
  String s="";
  s+=hour(tt);
  s+=":";
  s+=minute(tt);
  s+=":";
  s+=second(tt);
//  Serial.print("\n");
//  Serial.print(hour(tt));
//  Serial.print(":");
//  Serial.print(minute(tt));
//  Serial.print(":");
//  Serial.println(second(tt));
  return s;
 }
 time_t HeaterSchedulerCs::SetTimeOfDay(uint8_t hh, uint8_t mm, uint8_t ss)
 {
  tmElements_t tt;
  tt.Hour=hh;
  tt.Minute=mm;
  tt.Second=ss;
  return makeTime(tt);
 }

