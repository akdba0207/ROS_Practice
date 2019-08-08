#include "ros/ros.h"
#include "begineer_tutorials/srvTutorial.h"

bool calculation(begineer_tutorials::srvTutorial::Request &req, begineer_tutorials::srvTutorial::Response &res)
{
    res.result = req.a + req.b;

    ROS_INFO("request:x %ld, y=%ld,",(long int)req.a, (long int)req.b);
    ROS_INFO("sending back response: [%ld]",(long int)res.result);
    return true;

}

int main(int argc, char **argv)
{
    ros::init(argc,argv, "server");
    ros::NodeHandle nh;

    ros::ServiceServer server = nh.advertiseService("service",calculation);
    ROS_INFO("ready srv server!!");

    ros::spin();
    return 0;
}

