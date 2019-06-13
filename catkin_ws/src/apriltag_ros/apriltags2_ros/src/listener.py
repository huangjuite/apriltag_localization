#! /usr/bin/env python
import rospy
import tf
import tf2_ros
from geometry_msgs.msg import Pose, TransformStamped
from nav_msgs.msg import Odometry
from std_msgs.msg import Header
from apriltags2_ros.msg import *


class tfListener():
    def __init__(self):
        self.br = tf.TransformBroadcaster()
        self.tfListener = tf.TransformListener()
        self.statictfbr = tf2_ros.StaticTransformBroadcaster()
        self.timer = rospy.Timer(rospy.Duration(0.1), self.cb_listen)
        self.sub_tag = rospy.Subscriber(
            "/tag_detections", AprilTagDetectionArray, self.cb_tag, queue_size=1)
        self.pub_odom = rospy.Publisher("/tag_odom",Odometry,queue_size=1)
        self.tag_id = 0
        self.init_flag = 0
        self.init_odom = 0


    def cb_tag(self, msg):
        if len(msg.detections) > 0:
            tag = msg.detections[0]
            self.tag_id = tag.id[0]

    def cb_listen(self, event):
        try:
            tran, rota = self.tfListener.lookupTransform(
                '/tag%d'%self.tag_id, '/camera', rospy.Time(0))
            #print(mtf)
            self.br.sendTransform(tran,rota,rospy.Time.now(),"boat","ftag%d"%self.tag_id)
            if self.init_flag == 0:
                self.init_flag = 1
                static_transformStamped = geometry_msgs.msg.TransformStamped()
                static_transformStamped.header.stamp = rospy.Time.now()

                euler = tf.transformations.euler_from_quaternion(rota)
                print euler
                quat = tf.transformations.quaternion_from_euler(euler[0]+1.57, euler[1]+1.57, euler[2])

                static_transformStamped.transform.translation.x = tran[0]
                static_transformStamped.transform.translation.y = tran[1]
                static_transformStamped.transform.translation.z = tran[2]
                static_transformStamped.transform.rotation.x = quat[0]
                static_transformStamped.transform.rotation.y = quat[1]
                static_transformStamped.transform.rotation.z = quat[2]
                static_transformStamped.transform.rotation.w = quat[3]

                static_transformStamped.header.frame_id = "ftag%d"%self.tag_id
                static_transformStamped.child_frame_id = "init_boat"
                self.init_odom = static_transformStamped
            self.init_odom.header.stamp = rospy.Time.now()
            self.statictfbr.sendTransform(self.init_odom)

        except (tf.LookupException, tf.ConnectivityException, tf.ExtrapolationException):
            pass

        try:
            tran, rota = self.tfListener.lookupTransform(
                '/map', '/boat', rospy.Time(0))
            odom = self.tf_to_odom(tran,rota)
            print(odom)
            self.pub_odom.publish(odom)
        except (tf.LookupException, tf.ConnectivityException, tf.ExtrapolationException):
            pass            
    
    def tf_to_odom(self,translation,rotation):
        odom = Odometry()
        odom.header = Header()
        odom.header.stamp = rospy.Time.now()
        odom.header.frame_id = "map"
        odom.pose.pose.position.x = translation[0]
        odom.pose.pose.position.y = translation[1]
        odom.pose.pose.position.z = translation[2]
        odom.pose.pose.orientation.x = rotation[0]
        odom.pose.pose.orientation.y = rotation[1]
        odom.pose.pose.orientation.z = rotation[2]
        odom.pose.pose.orientation.w = rotation[3]
        return odom

    def on_shutdown(self):
        pass


if __name__ == "__main__":
    rospy.init_node('tfListener')
    broadcaster = tfListener()
    rospy.on_shutdown(tfListener.on_shutdown)
    rospy.spin()
