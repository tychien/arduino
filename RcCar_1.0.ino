#include <ros.h>
#include <std_msgs/Empty.h>
#include <sensor_msgs/Joy.h>

ros::NodeHandle nh;
void forward() { digitalWrite(4,LOW); digitalWrite(5,HIGH); digitalWrite(6,HIGH); digitalWrite(7,LOW);}
void backward() { digitalWrite(4,HIGH); digitalWrite(5,LOW); digitalWrite(6,LOW); digitalWrite(7,HIGH);}
void turnLeft() { digitalWrite(4,LOW); digitalWrite(5,LOW); digitalWrite(6,HIGH); digitalWrite(7,LOW);}
void turnRight() { digitalWrite(4,LOW); digitalWrite(5,HIGH); digitalWrite(6,LOW); digitalWrite(7,LOW);}
void circle() { digitalWrite(4,HIGH); digitalWrite(5,LOW); digitalWrite(6,LOW); digitalWrite(7,HIGH);}
void vstop() { digitalWrite(4,LOW); digitalWrite(5,LOW); digitalWrite(6,LOW); digitalWrite(7,LOW);}


void callbackFn( const sensor_msgs::Joy& joy_msg){
  
  //stop
  int movement=0;
  
  if((joy_msg.axes[1]==0)&&(joy_msg.axes[0]==0)){
    movement=0;//stop
  }
  else if(joy_msg.axes[1]>0.2){
    movement=1;//forward fullspeed
  }
  else if(joy_msg.axes[1]<-0.2){
    movement=2;//backward fullspeed
  }
  else if(joy_msg.axes[0]>0.2){
    movement=3;//turnleft fullspeed
  }
  else if(joy_msg.axes[0]<-0.2){
    movement=4;//turnright fullspeed
  }
  else{
    movement=0;
  }
  
  switch(movement){
    case 1:
      forward();
      delay(1);
      break;
    case 2:
      backward();
      delay(1);
      break;
    case 3:
      turnLeft();
      delay(1);
      break;
    case 4:
      turnRight();
      delay(1);
      break;
    case 0:
      vstop();
      delay(1);
      break;
    default:
      vstop();
      delay(1);
      break;
  }
  

}

ros::Subscriber<sensor_msgs::Joy> joy("joy", &callbackFn );


void setup()
{
  pinMode(4, OUTPUT); 
  pinMode(5, OUTPUT); 
  pinMode(6, OUTPUT); 
  pinMode(7, OUTPUT);
  nh.initNode();

}

void loop()
{
  nh.subscribe(joy);
  nh.spinOnce();
  delay(1);
}
