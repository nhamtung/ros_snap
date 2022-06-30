#include "multidimensional_arrays/multidimensional_arrays.h"

namespace MultidimentionalArrays_ns
{
    // ExecuteAction
    ExecuteAction::ExecuteAction(ros::NodeHandle n){
        ROS_INFO("multidimensional_arrays -> Init ExecuteAction()");
        // Registration to publish the topic
        
        // Registration to subscriber the topic
        current_pose_sub = n.subscribe<geometry_msgs::PoseStamped>("/agv_current_pose", 1, boost::bind(&ExecuteAction::currentPoseCallback, this, _1));
        ROS_INFO("multidimensional_arrays - Register subscriber topic /agv_current_pose");
    }
    ExecuteAction::~ExecuteAction() {}
    
    // Subscriber the topic
    void ExecuteAction::currentPoseCallback(const geometry_msgs::PoseStamped::ConstPtr& msg){
        current_pose = *msg;
        ROS_INFO("multidimensional_arrays - buffer_height: %d", buffer_height);
        buffer[0][buffer_height] = ros::Time::now().toSec();
        buffer[1][buffer_height] = current_pose.pose.position.x;
        buffer[2][buffer_height] = current_pose.pose.position.y;
        buffer[3][buffer_height] = current_pose.pose.position.z;
        buffer[4][buffer_height] = current_pose.pose.orientation.x;
        buffer[5][buffer_height] = current_pose.pose.orientation.y;
        buffer[6][buffer_height] = current_pose.pose.orientation.z;
        buffer[7][buffer_height] = current_pose.pose.orientation.w;
        buffer_height = buffer_height+1;
        if(buffer_height == 500) buffer_height = 0;
    }    
}