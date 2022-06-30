#include "multidimensional_arrays/multidimensional_arrays.h"

boost::thread* server_thread;
MultidimentionalArrays_ns::ExecuteAction* control;

void serverThread(ros::NodeHandle n){
    control = new MultidimentionalArrays_ns::ExecuteAction(n);
    ros::Rate r(2);
    while (ros::ok())
    {
        ROS_INFO("test_multidimensional_arrays - buffer[1][0]: %f", control->buffer[1][0]);
        r.sleep();
    }
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "test_multidimensional_arrays");
    ros::NodeHandle n;
    ROS_INFO("Create node test_multidimensional_arrays"); 
    
    server_thread = new boost::thread (&serverThread, n);

    ros::spin();
    delete(control);
    return 0;
}