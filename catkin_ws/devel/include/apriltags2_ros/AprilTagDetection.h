// Generated by gencpp from file apriltags2_ros/AprilTagDetection.msg
// DO NOT EDIT!


#ifndef APRILTAGS2_ROS_MESSAGE_APRILTAGDETECTION_H
#define APRILTAGS2_ROS_MESSAGE_APRILTAGDETECTION_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <geometry_msgs/PoseWithCovarianceStamped.h>

namespace apriltags2_ros
{
template <class ContainerAllocator>
struct AprilTagDetection_
{
  typedef AprilTagDetection_<ContainerAllocator> Type;

  AprilTagDetection_()
    : id()
    , size()
    , pose()  {
    }
  AprilTagDetection_(const ContainerAllocator& _alloc)
    : id(_alloc)
    , size(_alloc)
    , pose(_alloc)  {
  (void)_alloc;
    }



   typedef std::vector<int32_t, typename ContainerAllocator::template rebind<int32_t>::other >  _id_type;
  _id_type id;

   typedef std::vector<double, typename ContainerAllocator::template rebind<double>::other >  _size_type;
  _size_type size;

   typedef  ::geometry_msgs::PoseWithCovarianceStamped_<ContainerAllocator>  _pose_type;
  _pose_type pose;





  typedef boost::shared_ptr< ::apriltags2_ros::AprilTagDetection_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::apriltags2_ros::AprilTagDetection_<ContainerAllocator> const> ConstPtr;

}; // struct AprilTagDetection_

typedef ::apriltags2_ros::AprilTagDetection_<std::allocator<void> > AprilTagDetection;

typedef boost::shared_ptr< ::apriltags2_ros::AprilTagDetection > AprilTagDetectionPtr;
typedef boost::shared_ptr< ::apriltags2_ros::AprilTagDetection const> AprilTagDetectionConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::apriltags2_ros::AprilTagDetection_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::apriltags2_ros::AprilTagDetection_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace apriltags2_ros

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'sensor_msgs': ['/opt/ros/melodic/share/sensor_msgs/cmake/../msg'], 'std_msgs': ['/opt/ros/melodic/share/std_msgs/cmake/../msg'], 'apriltags2_ros': ['/home/ray/apriltag_localization/catkin_ws/src/apriltag_ros/apriltags2_ros/msg'], 'geometry_msgs': ['/opt/ros/melodic/share/geometry_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::apriltags2_ros::AprilTagDetection_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::apriltags2_ros::AprilTagDetection_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::apriltags2_ros::AprilTagDetection_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::apriltags2_ros::AprilTagDetection_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::apriltags2_ros::AprilTagDetection_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::apriltags2_ros::AprilTagDetection_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::apriltags2_ros::AprilTagDetection_<ContainerAllocator> >
{
  static const char* value()
  {
    return "090173a6e2b6c8fd96ce000fe9378b4e";
  }

  static const char* value(const ::apriltags2_ros::AprilTagDetection_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x090173a6e2b6c8fdULL;
  static const uint64_t static_value2 = 0x96ce000fe9378b4eULL;
};

template<class ContainerAllocator>
struct DataType< ::apriltags2_ros::AprilTagDetection_<ContainerAllocator> >
{
  static const char* value()
  {
    return "apriltags2_ros/AprilTagDetection";
  }

  static const char* value(const ::apriltags2_ros::AprilTagDetection_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::apriltags2_ros::AprilTagDetection_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# Tag ID(s). If a standalone tag, this is a vector of size 1. If a tag bundle,\n"
"# this is a vector containing the IDs of each tag in the bundle.\n"
"int32[] id\n"
"\n"
"# Tag size(s). If a standalone tag, this is a vector of size 1. If a tag bundle,\n"
"# this is a vector containing the sizes of each tag in the bundle, in the same\n"
"# order as the IDs above.\n"
"float64[] size\n"
"\n"
"# Pose in the camera frame, obtained from homography transform. If a standalone\n"
"# tag, the homography is from the four tag corners. If a tag bundle, the\n"
"# homography is from at least the four corners of one member tag and at most the\n"
"# four corners of all member tags.\n"
"geometry_msgs/PoseWithCovarianceStamped pose\n"
"================================================================================\n"
"MSG: geometry_msgs/PoseWithCovarianceStamped\n"
"# This expresses an estimated pose with a reference coordinate frame and timestamp\n"
"\n"
"Header header\n"
"PoseWithCovariance pose\n"
"\n"
"================================================================================\n"
"MSG: std_msgs/Header\n"
"# Standard metadata for higher-level stamped data types.\n"
"# This is generally used to communicate timestamped data \n"
"# in a particular coordinate frame.\n"
"# \n"
"# sequence ID: consecutively increasing ID \n"
"uint32 seq\n"
"#Two-integer timestamp that is expressed as:\n"
"# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')\n"
"# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')\n"
"# time-handling sugar is provided by the client library\n"
"time stamp\n"
"#Frame this data is associated with\n"
"string frame_id\n"
"\n"
"================================================================================\n"
"MSG: geometry_msgs/PoseWithCovariance\n"
"# This represents a pose in free space with uncertainty.\n"
"\n"
"Pose pose\n"
"\n"
"# Row-major representation of the 6x6 covariance matrix\n"
"# The orientation parameters use a fixed-axis representation.\n"
"# In order, the parameters are:\n"
"# (x, y, z, rotation about X axis, rotation about Y axis, rotation about Z axis)\n"
"float64[36] covariance\n"
"\n"
"================================================================================\n"
"MSG: geometry_msgs/Pose\n"
"# A representation of pose in free space, composed of position and orientation. \n"
"Point position\n"
"Quaternion orientation\n"
"\n"
"================================================================================\n"
"MSG: geometry_msgs/Point\n"
"# This contains the position of a point in free space\n"
"float64 x\n"
"float64 y\n"
"float64 z\n"
"\n"
"================================================================================\n"
"MSG: geometry_msgs/Quaternion\n"
"# This represents an orientation in free space in quaternion form.\n"
"\n"
"float64 x\n"
"float64 y\n"
"float64 z\n"
"float64 w\n"
;
  }

  static const char* value(const ::apriltags2_ros::AprilTagDetection_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::apriltags2_ros::AprilTagDetection_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.id);
      stream.next(m.size);
      stream.next(m.pose);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct AprilTagDetection_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::apriltags2_ros::AprilTagDetection_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::apriltags2_ros::AprilTagDetection_<ContainerAllocator>& v)
  {
    s << indent << "id[]" << std::endl;
    for (size_t i = 0; i < v.id.size(); ++i)
    {
      s << indent << "  id[" << i << "]: ";
      Printer<int32_t>::stream(s, indent + "  ", v.id[i]);
    }
    s << indent << "size[]" << std::endl;
    for (size_t i = 0; i < v.size.size(); ++i)
    {
      s << indent << "  size[" << i << "]: ";
      Printer<double>::stream(s, indent + "  ", v.size[i]);
    }
    s << indent << "pose: ";
    s << std::endl;
    Printer< ::geometry_msgs::PoseWithCovarianceStamped_<ContainerAllocator> >::stream(s, indent + "  ", v.pose);
  }
};

} // namespace message_operations
} // namespace ros

#endif // APRILTAGS2_ROS_MESSAGE_APRILTAGDETECTION_H
