# RPLiDAR-Driver-For-ATMEGA128
RPLiDAR Driver for ATMEGA128

RPLidar A1M8 is widely used in ROS, but it is challenging to use it with microcontrollers like ATMEGA. This driver is for ATMEGA128 which is a good choice for embedded system projects as it contains two communication channels.

RPLidar has protocols to guide you on how it works and what the data packets look like when sending or receiving it. Here is the datasheet for RPLiDAR A1M8 protocols and how to use them.
[LR001_SLAMTEC_rplidar_protocol_v2.4_en.pdf](https://github.com/BahaaMadeeh/RPLiDAR-Driver-For-ATMEGA128/files/12062895/LR001_SLAMTEC_rplidar_protocol_v2.4_en.pdf)

The cycle process of RPLiDAR is important to avoid any kind of error. The following flowchart shows how to use it.
![Capture](https://github.com/BahaaMadeeh/RPLiDAR-Driver-For-ATMEGA128/assets/106497280/a8cdac0c-c6d8-41fb-89ca-ee3ec3ab666e)

