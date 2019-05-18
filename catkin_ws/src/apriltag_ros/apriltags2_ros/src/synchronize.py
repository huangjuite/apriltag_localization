#! /usr/bin/env python

import rospy
import cv2
import message_filters
from cv_bridge import CvBridge,CvBridgeError
from sensor_msgs.msg import Image,CameraInfo
from std_msgs.msg import Header

rospy.init_node("synchronizer")

info = CameraInfo()

pub_image = rospy.Publisher("/camera_rect/image_rect",Image,queue_size=1)
pub_info = rospy.Publisher("/camera_rect/camera_info",CameraInfo,queue_size=1)

def cb_image(image):
    info.header.stamp = image.header.stamp
    pub_image.publish(image)
    pub_info.publish(info)
    #sprint("publish synchronized message")

def cb_info(msg):
    global info
    info = msg


image_sub = rospy.Subscriber('/camera/color/image_raw', Image,cb_image)
info_sub = rospy.Subscriber('/camera/color/camera_info', CameraInfo,cb_info)

#ts = message_filters.TimeSynchronizer([image_sub, info_sub],20)
#ts.registerCallback(callback)


rospy.spin()