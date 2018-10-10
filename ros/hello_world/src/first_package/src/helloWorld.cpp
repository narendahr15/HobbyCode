#include <ros.h>
#include <std_msgs/String.h>

ros::NodeHandle nodeHandle;

std_msgs::String str_msg;
ros::Publisher chatter("chatter", &str_msg);


char hello[] = "Hello ROS!";

void setup() {
  nodeHandle.initNode();
  nodeHandle.advertise(chatter);
}

void loop(){
  str_msg.data = hello;
  chatter.publish(&str_msg);
  nodeHandle.spinOnce();
  delay(1000);
}
