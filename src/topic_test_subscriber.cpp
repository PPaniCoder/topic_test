#include "ros/ros.h"
#include "topic_test/topicTest.h"

void msgCallback(const topic_test::topicTest::ConstPtr& msg) {
	ROS_INFO("receive msg: %d", msg->data);
}

int main (int argc, char** argv) {
	ros::init(argc, argv, "topic_test_subscriber");
	ros::NodeHandle nh;

	ros::Subscriber subscriber = nh.subscribe("topic_test_msg", 100, msgCallback);
	
	ros::spin();

	return 0;
}
