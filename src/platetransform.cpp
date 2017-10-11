#include "ros/ros.h"
#include <ros/console.h>
#include <tf/transform_broadcaster.h>
#include "geometry_msgs/PoseStamped.h"



void poseCallback(const geometry_msgs::PoseStamped::ConstPtr& msg){
    // use only every 50th message to slow down the debugging output
    

    static tf::TransformBroadcaster br;
    tf::Transform transform;

    geometry_msgs::Pose pose = msg->pose;
    geometry_msgs::Point position = pose.position;
    geometry_msgs::Quaternion orientation = pose.orientation;


    //ROS_DEBUG("poseCallback called");
    //transform.setPose(msg->pose);

    transform.setOrigin( tf::Vector3(0.0, 0.0, 0.0) );
    transform.setRotation( tf::Quaternion(0, 0, 0, 0) );

    //For later use
    transform.setOrigin( tf::Vector3(position.x, position.y, position.z) );
    transform.setRotation( tf::Quaternion( orientation.x, orientation.y, orientation.z, orientation.w) );

    br.sendTransform(tf::StampedTransform(transform, ros::Time::now(), "ref_objectplate", "plate_base"));


    //ROS_INFO("Broadcasted transformation from pose sensor on plate object to tf");
}


int main(int argc, char** argv){
    ros::init(argc, argv, "platetransform");
    ros::NodeHandle n;

    ros::Subscriber sub = n.subscribe("/plate_pose", 1000, &poseCallback); 

    ros::spin();

    return 0;
}
