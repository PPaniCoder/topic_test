#include "ros/ros.h"
#include "topic_test/topicTest.h"

int main(int argc, char** argv) {
	ros::init(argc, argv, "topic_test_publisher");
	ros::NodeHandle nh;

	ros::Publisher publisher = nh.advertise<topic_test::topicTest>("topic_test_msg", 100);

	ros::Rate loop_rate(10);

	int count=0;

	while (ros::ok()) {
		topic_test::topicTest msg;
		msg.data = count;

		ROS_INFO("send msg = %d", count);

		publisher.publish(msg);
		loop_rate.sleep();
		++count;	
	}
	return 0;
}
