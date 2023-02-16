/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\txzsp                                            */
/*    Created:      Fri Oct 28 2022                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// LimitSwitchB         limit         B               
// DigitalOutC          digital_out   C               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;
motor cat1 = motor(PORT11,gearSetting::ratio36_1,false);

motor intake = motor(PORT20, gearSetting::ratio18_1, true); 

motor leftfront = motor(PORT3, gearSetting::ratio18_1, true);
motor leftmid =  motor(PORT2, gearSetting::ratio18_1, true);
motor leftback = motor(PORT1, gearSetting::ratio18_1, false);
motor rightfront = motor(PORT10, gearSetting::ratio18_1,false);
motor rightmid = motor(PORT9, gearSetting::ratio18_1, false);
motor rightback = motor(PORT8, gearSetting::ratio18_1, true);

controller Controller = vex::controller(primary);



float pi = M_PI;
float dia = 4.85;


void autocata(){


if (Controller.ButtonR2.pressing() == 1){

  while (LimitSwitchB.pressing() == 0){

    cat1.spin(vex::directionType::fwd, 12, vex::voltageUnits::volt);
    leftfront.spin(vex::directionType::fwd, Controller.Axis3.value()/(100/12),vex::voltageUnits::volt);
    leftmid.spin(vex::directionType::fwd, Controller.Axis3.value()/(100/12),vex::voltageUnits::volt);
    leftback.spin(vex::directionType::fwd, Controller.Axis3.value()/(100/12),vex::voltageUnits::volt);
    rightfront.spin(vex::directionType::fwd, Controller.Axis2.value()/(100/12),vex::voltageUnits::volt);
    rightmid.spin(vex::directionType::fwd, Controller.Axis2.value()/(100/12),vex::voltageUnits::volt);
    rightback.spin(vex::directionType::fwd, Controller.Axis2.value()/(100/12),vex::voltageUnits::volt);
  }
  cat1.stop();


}
  if(Controller.ButtonR1.pressing()== 1)
  {

    cat1.spin(vex::directionType::fwd, 12, vex::voltageUnits::volt);
    vex::task::sleep(300);
    cat1.stop();


  }


}

void workinglimitcat(){

    if(Controller.ButtonR1.pressing()==1 ){
      cat1.spin(vex::directionType::fwd,12,vex::voltageUnits::volt);



    }
    else if (LimitSwitchB.pressing()==1)
    {

      cat1.spin(vex::directionType::fwd,0,vex::voltageUnits::volt);


    }
    

    else if (Controller.ButtonR2.pressing() == 1)
    {

      cat1.spin(vex::directionType::fwd,12,vex::voltageUnits::volt);


    }
    else if (Controller.ButtonR1.pressing() == 0 && Controller.ButtonR2.pressing() ==0){

      cat1.stop();
    }



}





int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  while(1==1){

    leftfront.spin(vex::directionType::fwd, Controller.Axis3.value()/(100/12),vex::voltageUnits::volt);
    leftmid.spin(vex::directionType::fwd, Controller.Axis3.value()/(100/12),vex::voltageUnits::volt);
    leftback.spin(vex::directionType::fwd, Controller.Axis3.value()/(100/12),vex::voltageUnits::volt);
    rightfront.spin(vex::directionType::fwd, Controller.Axis2.value()/(100/12),vex::voltageUnits::volt);
    rightmid.spin(vex::directionType::fwd, Controller.Axis2.value()/(100/12),vex::voltageUnits::volt);
    rightback.spin(vex::directionType::fwd, Controller.Axis2.value()/(100/12),vex::voltageUnits::volt);

    if(Controller.ButtonA.pressing()==1)
    {
      DigitalOutC.set(false);
    }

    else
    {
      DigitalOutC.set(true);
    }
    
    if (Controller.ButtonL1.pressing() == 1)
    {

      intake.spin(vex::directionType::fwd,12,vex::voltageUnits::volt);

    }


    else if (Controller.ButtonL2.pressing() == 1)
    {

      intake.spin(vex::directionType::fwd,-12,vex::voltageUnits::volt);
      
    }
    else{


      intake.stop();
    }
    autocata();
    
    



     
     



     
  }
  
}
