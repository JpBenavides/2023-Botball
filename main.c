#include <kipr/wombat.h>
//variables 
//updated functions for the robot not fully complete 
int lmotor = 0;
int rmotor = 3;
int nospeed = 0;
int midspeed = 60;
int neg_midspeed = -60;
int arm_port = 0;
int arm_down = 940; 
int arm_up = 1600;
int wrist_port = 1;
int wrist_vert = 350;
int wrist_horiz = 1550;
int claw_port = 2;
int claw_open = 1000;
int claw_close = 415;
int move_time = 3000;

//functions 
void forward()
{
motor(lmotor,midspeed);
motor(rmotor,midspeed);
}

void grabbing_rings_at_start()
{
  enable_servos();    
    //lowering arm into position
    printf("lower arm\n");
    set_servo_position(arm_port, arm_down);
    msleep(move_time);   
    ao();
    
    //grabbing the yellow and orange rings to move it 
    printf("open claw\n");
    set_servo_position(claw_port, claw_open);
    msleep(move_time);
    printf("close claw\n");
    set_servo_position(claw_port, claw_close);
    msleep(move_time);    
    ao();
}

void turn_right_with_rings()
{
  //we have the rings grabbed and we are now going to turn right to go straight 
  printf("turning right with rings\n");  
  motor(lmotor, midspeed);
  msleep(4000);  
  ao();
   motor(lmotor, midspeed);
   motor(rmotor, neg_midspeed);
    msleep(2000);
}
void backwards()
{
  //backing up 
  printf("backwards with rings\n");  
  motor(lmotor, neg_midspeed);
  motor(rmotor, neg_midspeed);
  msleep(move_time);  
}

int main()
{
  grabbing_rings_at_start();
  turn_right_with_rings();
    ao();
    return 0;
}

