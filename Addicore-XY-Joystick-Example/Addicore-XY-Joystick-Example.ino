//**********************************************************************************************************************
//
//                          Addicore Dual-Axis XY Joystick with Push Button Example Sketch
//                                                 by Addicore.com
//
//**********************************************************************************************************************
//  Example sketch for the Addicore Dual-Axis XY Joystick with Push Button found
//  at https://www.addicore.com/Dual-Axis-XY-Joystick-with-Push-Button-p/ad139.htm
//  
//  Wire the Addicore joystick to your Arduino as detailed below. Then
//  Upload this code to your Arduino and open the Serial Monitor on your
//  computer to see the states of the joystick axes and push switch.
//  (Make sure the baud is set to 9600 in your Serial Monitor)
//  
//  Wiring:
//              Joystick ---> Arduino
//                 GND          GND
//                 +5V          5V
//                 VRx          A0
//                 VRy          A1
//                 SW           3
//**********************************************************************************************************************
// Revision History:
//
//       12-15-2014   Craig Thompson    Version 1.0   Initial Release
//       06-30-2020   Andre McKay       Version 1.1   Clean up
//
//
// Copyright (C) 2020  Boffintronics, LLC
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
//
//**********************************************************************************************************************

//Arduino pins attached to joystick 
#define joystick_switch_pin  3
#define joystick_x_pin       A0
#define joystick_y_pin       A1

// the setup routine runs once when you press reset:
void setup() {
  Serial.begin(9600);                          // initialize serial communication at 9600 bits per second:
  pinMode(joystick_switch_pin, INPUT_PULLUP);  // Enable the pullup resistor on pin 3 for the joystick's switch signal
}

// the loop routine runs over and over again forever:
void loop() {
  int X_Axis = analogRead(joystick_x_pin);     // read the x axis value
  int Y_Axis = analogRead(joystick_y_pin);     // read the x axis value
  //X_Axis = map(X_Axis, 0, 1023, 1023, 0);      // Example to invert the input from the x axis so that pressing the stick forward gives larger values
  //Y_Axis = map(Y_Axis, 0, 1023, 1023, 0);      // Example to invert the input from the y axis so that pressing the stick forward gives larger values
  int SwitchValue = digitalRead(joystick_switch_pin);  // read the state of the switch
  SwitchValue = map(SwitchValue, 0, 1, 1, 0);  // invert the input from the switch to be high when pressed
  
  // print out the values you read:
  Serial.print("Switch: ");
  Serial.print(SwitchValue);
  Serial.print("   X_Axis: ");
  Serial.print(X_Axis);
  Serial.print("   Y_Axis: ");
  Serial.println(Y_Axis);
  delay(10);        // delay in between reads
}
