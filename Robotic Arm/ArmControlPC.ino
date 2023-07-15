
/* **********************************************************************
*  Sample code to implement serial command handler
*  for the compatible commands found on this interface. 
*  See: 
*   - https://www.megunolink.com/documentation/getting-started/processing-serial-commands/
*   - https://www.megunolink.com/documentation/arduino-libraries/serial-command-handler/
*  ********************************************************************** */
#include <CommandHandler.h> // Serial command handler library
#include <Servo.h>

Servo servo01;
Servo servo02;
Servo servo03;
Servo servo04;
Servo servo05;
Servo servo06;


// Command handler decodes and dispatches commands received
// on the serial port.
CommandHandler<> SerialCmds; 

/* ------------------------------------
   Serial command handler functions
   ------------------------------------ */
void Cmd_SetWaistPosition(CommandParameter& params)
{

  int WaistValue = params.NextParameterAsInteger();
  
  if (WaistValue < 0)
  {
    WaistValue = 0; 
  }
  if (WaistValue > 180)
  {
    WaistValue = 180;
  }  
  servo01.write(WaistValue);


}

void Cmd_SetShoulderPosition(CommandParameter& params)
{
  int ShoulderValue = params.NextParameterAsInteger();
    
  if (ShoulderValue < 0)
  {
    ShoulderValue = 0; 
  }
  if (ShoulderValue > 180)
  {
    ShoulderValue = 180;
  }  
  servo02.write(ShoulderValue);
  // todo: implement function
}

void Cmd_SetWristXPosition(CommandParameter& params)
{
  int WristXValue = params.NextParameterAsInteger();
    
  if (WristXValue < 0)
  {
    WristXValue = 0; 
  }
  if (WristXValue > 180)
  {
    WristXValue = 180;
  }  
  servo04.write(WristXValue);
  // todo: implement function
}

void Cmd_SetElbowPosition(CommandParameter& params)
{
  int ElbowValue = params.NextParameterAsInteger();
    
  if (ElbowValue < 0)
  {
    ElbowValue = 0; 
  }
  if (ElbowValue > 180)
  {
    ElbowValue = 180;
  }  
  servo03.write(ElbowValue);
  // todo: implement function
}

void Cmd_SetClawPosition(CommandParameter& params)
{
  int ClawValue = params.NextParameterAsInteger();
    
  if (ClawValue < 0)
  {
    ClawValue = 0; 
  }
  if (ClawValue > 180)
  {
    ClawValue = 180;
  }  
  servo06.write(ClawValue);
  // todo: implement function
}

void Cmd_SetWristYPosition(CommandParameter& params)
{
  int WristYValue = params.NextParameterAsInteger();
    
  if (WristYValue < 0)
  {
    WristYValue = 0; 
  }
  if (WristYValue > 180)
  {
    WristYValue = 180;
  }  
  servo05.write(WristYValue);
  // todo: implement function
}


/* ------------------------------------
   Setup code, to run once
   ------------------------------------ */
void setup()
{
  servo01.attach(5);
  servo02.attach(6);
  servo03.attach(7);
  servo04.attach(8);
  servo05.attach(9);
  servo06.attach(10);
  delay(20);
  
  // Initialize serial port and set baud rate
  Serial.begin(9600);
  Serial.println(F("Robot Gripper Controller"));

  // Register serial commands
  SerialCmds.AddCommand(F("SetWaistPosition"), Cmd_SetWaistPosition);
  SerialCmds.AddCommand(F("SetShoulderPosition"), Cmd_SetShoulderPosition);
  SerialCmds.AddCommand(F("SetWristXPosition"), Cmd_SetWristXPosition);
  SerialCmds.AddCommand(F("SetElbowPosition"), Cmd_SetElbowPosition);
  SerialCmds.AddCommand(F("SetClawPosition"), Cmd_SetClawPosition);
  SerialCmds.AddCommand(F("SetWristYPosition"), Cmd_SetWristYPosition);
}

/* ------------------------------------
   Main code, to run repeatedly
   ------------------------------------ */
void loop()
{
  // Assemble characters received from serial port; 
  // match and dispatch registered commands.
  SerialCmds.Process();
}