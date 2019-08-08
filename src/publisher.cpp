#include "ros/ros.h"
#include "begineer_tutorials/msgTutorial.h"

int main(int argc, char **argv)
{
    ros::init(argc,argv,"publisher");
    ros::NodeHandle nh;

    ros::Publisher publisher = nh.advertise<begineer_tutorials::msgTutorial>("msg",100);
    ros::Rate loop_rate(10);
    int count = 0;

    while(ros::ok())
    {
        begineer_tutorials::msgTutorial msg;
        msg.data = count;
        ROS_INFO("send msg = %d",count);
        publisher.publish(msg);
        loop_rate.sleep();
        ++count;

    }
    return 0;
}