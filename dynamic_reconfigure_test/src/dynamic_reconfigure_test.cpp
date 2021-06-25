#include <ros/ros.h>
#include <dynamic_reconfigure/server.h>
#include <dynamic_reconfigure_test/dyn_reconfig_testConfig.h>

void callback(dynamic_reconfigure_test::dyn_reconfig_testConfig &config, uint32_t level) {
      ROS_INFO("Dynamic parameter: %d", config.test_parameter);
}

int main(int argc, char **argv) {
      ros::init(argc, argv, "dynamic_reconfigure_test");

      dynamic_reconfigure::Server<dynamic_reconfigure_test::dyn_reconfig_testConfig> server;
      dynamic_reconfigure::Server<dynamic_reconfigure_test::dyn_reconfig_testConfig>::CallbackType f;

      f = boost::bind(&callback, _1, _2);
      server.setCallback(f);

      ros::spin();
      return 0;
}
