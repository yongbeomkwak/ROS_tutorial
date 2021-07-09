#!/usr/bin/env python

import rospy
from dynamic_reconfigure.server import Server
# PACKAGE + .cfg
from dynamic_foscar_test.cfg import dynamic_testConfig
# from:  PACKAGE+.cfg
# import:third parameter of exit function + Config
a=0
b=0.0

def callback(config, level):
    global a
    global b

    a=config.test1
    b=config.test2
    rospy.loginfo("""Reconfigure Request: {test1} {test2},""".format(**config))
    print(a+b)
    return config

    
if __name__ == "__main__":
    rospy.init_node("test2", anonymous = False)
    srv = Server(dynamic_testConfig, callback)
    rospy.spin()
# run window command:rosrun rqt_gui rqt_gui -s reconfigure
