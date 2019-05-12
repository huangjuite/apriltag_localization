#! /usr/bin/env python
import rospy
import tf
from geometry_msgs.msg import Pose,TransformStamped
from apriltags2_ros.msg import *


class Broadcaster():
    def __init__(self):
        self.br = tf.TransformBroadcaster()
        self.sub_tag = rospy.Subscriber(
            "/tag_detections", AprilTagDetectionArray, self.cb_tag, queue_size=1)

    def cb_tag(self, msg):
        if len(msg.detections) > 0:
            tag = msg.detections[0]
            mtf = self.tag_pose_to_tf(tag,"tag%d"%tag.id[0])
            self.br.sendTransformMessage(mtf)

    def tag_pose_to_tf(self,tag,parent):
        mtf = TransformStamped()
        mtf.child_frame_id = "camera"
        mtf.header.stamp = tag.pose.header.stamp
        mtf.header.frame_id = parent
        mtf.transform.translation = tag.pose.pose.pose.position
        mtf.transform.rotation = tag.pose.pose.pose.orientation

        return mtf


    def on_shutdown(self):
        pass


if __name__ == "__main__":
    rospy.init_node('broadcaster')
    broadcaster = Broadcaster()
    rospy.on_shutdown(broadcaster.on_shutdown)
    rospy.spin()
