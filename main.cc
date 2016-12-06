#include "RoboticArm.h"
#include <unistd.h>

int main()
{
 RoboticArm robotic_arm;
 do
 {
   int servo;
   int angle;
   std::cout << "Please input servo and angle you'd like to use" <<'\n';
   std::cin >> servo, angle, speed;
 robotic_arm.MoveServo(servo, angle, 20);
 }
 while (1==1);
}
