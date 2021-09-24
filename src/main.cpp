#include <ros/ros.h>
#include <ros/package.h>
#include <geometry_msgs/PoseWithCovarianceStamped.h>

int main(int argc, char **argv)
{
    ros::init(argc, argv, "random_pose_node");
    ros::Time::init();
    ros::NodeHandle node_;
    ros::Publisher initpose_publisher_ = node_.advertise<geometry_msgs::PoseWithCovarianceStamped>("/initialpose", 100);
    int count = 0;
    ros::Rate r(0.06);
    while (ros::ok())
    {
        count++;
        ROS_WARN("send num = %d", count);
        geometry_msgs::PoseWithCovarianceStamped msg;
        msg.pose.pose.position.x = rand() % 50;
        msg.pose.pose.position.y = rand() % 50;
        msg.pose.pose.position.z = 0.0;
        msg.pose.pose.orientation.x = 0.0;
        msg.pose.pose.orientation.y = 0.0;
        msg.pose.pose.orientation.z = 0.0;
        msg.pose.pose.orientation.w = 1.0;
        initpose_publisher_.publish(msg);
        r.sleep();
    }

    ros::spin();
    return 0;
}