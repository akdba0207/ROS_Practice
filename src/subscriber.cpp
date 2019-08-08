#include "ros/ros.h"                         
#include "begineer_tutorials/msgTutorial.h" 


void msgCallback(const begineer_tutorials::msgTutorial::ConstPtr &msg)
{
    ROS_INFO("recieve msg: %d", msg->data); // 수신된 메시지를 표시하는 함수
}
int main(int argc, char **argv) // 노드 메인 함수
{
    ros::init(argc, argv, "subscriber"); 
    ros::NodeHandle nh;                                   
    ros::Subscriber ros_tutorial_sub = nh.subscribe("msg", 100, msgCallback);
    ros::spin();
    return 0;
}