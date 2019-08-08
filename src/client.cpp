#include "ros/ros.h"
#include "begineer_tutorials/srvTutorial.h"
#include <cstdlib>

int main(int argc, char **argv)
{
    ros::init(argc,argv,"client");
    if(argc!=3)
    {
        ROS_INFO("cmd: rosrun begineer_tutorials client arg() arg1");
        ROS_INFO("arg0: double number, arg1: double number");
        return 1;
    }

    ros::NodeHandle nh;
    ros::ServiceClient client = nh.serviceClient<begineer_tutorials::srvTutorial>("service");

    begineer_tutorials::srvTutorial srv;
    srv.request.a = atoll(argv[1]);
    srv.request.b = atoll(argv[2]);
    //client.call(srv);
    if (client.call(srv))
    {
        ROS_INFO("send srv, srv.Request.a and b: %ld, %ld", (long int)srv.request.a, (long int)srv.request.b);
        ROS_INFO("receive srv, srv.Response.result: %ld", (long int)srv.response.result);
    }
    else
    {
        ROS_ERROR("Failed to call service ros_tutorial_srv");
        return 1;
    }
    return 0;
}