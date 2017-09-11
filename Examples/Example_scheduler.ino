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
#include "TimeLib.h"
#define nEventPerDay 6 
//Macro
#define QuartToTime(_quarter_) (_quarter_ * SECS_PER_MIN * 15UL)
#define TimeToQuart(_time_) (((_time_ % SECS_PER_DAY) / SECS_PER_MIN)/15UL)
typedef uint8_t TimeQuarter_sc;
enum EventState_sc:bool {evEN=true, evDIS=false} ; 
enum SwitchState_sc:bool {swON=true, swOFF=false} ; 
enum SwitchNum_sc:uint8_t {sw1=1, sw2=2} ;
typedef enum {Event0, Event1, Event2, Event3, Event4, Event5} EventNum_sc;
typedef struct
{
  EventState_sc isEnabled ; //Enable=1 disable=0
  SwitchNum_sc nSwitch; //Switch 1=0 Switch 2=1
  SwitchState_sc swTurn; //State=0 --> turn off, State=1 --> turn ON
} EventCtrl_sc;
typedef struct 
{  
  TimeQuarter_sc EvTimeQ; //Time of the event in quarter of hour
  EventCtrl_sc EventCtrl; //Event control (ON OFF, En Dis, switch to turn
}EventType_sc;
typedef struct
{
  timeDayOfWeek_t dow; // day of the week
  EventType_sc Event[nEventPerDay]; //array of events per day
} DaySchedule_sc;
DaySchedule_sc WeekSched[7]; //Array of DaySchedule_sc representing the week schedule
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.print("Day Size=");
  Serial.println(sizeof(WeekSched[0]),DEC);
  Serial.println(SetEvent(dowSunday,Event1,3,swOFF,sw2));
   //time_t now_t=now();
   time_t now_t;
   now_t=SetTimeOfDay(3,10,10);
   Serial.println(TimeToStr(now_t));
   Serial.print("now in quarter=");
   Serial.println(TimeToQuart(now_t));
}

void loop() {
  // put your main code here, to run repeatedly:

}

/*
 * Functions
 */
 String SetEvent(timeDayOfWeek_t dow, EventNum_sc Evnum, TimeQuarter_sc TimeQ, SwitchState_sc SwSt, SwitchNum_sc SwN)
 {
  String s="Dow: ";
   WeekSched[dow-1].dow=dow;
   WeekSched[dow-1].Event[Evnum].EvTimeQ=TimeQ;
   WeekSched[dow-1].Event[Evnum].EventCtrl.isEnabled=evEN;
   WeekSched[dow-1].Event[Evnum].EventCtrl.swTurn=SwSt;
   WeekSched[dow-1].Event[Evnum].EventCtrl.nSwitch=SwN;
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
   s+=EventToStrShort(WeekSched[dow-1].Event[Evnum]);
   return s;
 }
String EventToStrShort(EventType_sc Ev)
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
String EventToStrLong(EventType_sc Ev)
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
 String TimeToStr(time_t tt)
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
 time_t SetTimeOfDay(uint8_t hh, uint8_t mm, uint8_t ss)
 {
  tmElements_t tt;
  tt.Hour=hh;
  tt.Minute=mm;
  tt.Second=ss;
  return makeTime(tt);
 }

