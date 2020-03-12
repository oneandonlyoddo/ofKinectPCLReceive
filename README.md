# ofKinectPCLReceive

A proof concept of receiving Kinect V2 point cloud data over the network via [zeroMQ](https://zeromq.org/).

See my other repository [ofKinectPCLPublish](https://github.com/oneandonlyoddo/ofKinectPCLPublish) for obtaining the point cloud data and sending it.

Written in c++ with [openFrameworks](https://openframeworks.cc/).

____

Tested on Windows 10



Requires:

+ openFrameWorks  (0.11.0)

+ [ofxZmqWindows](https://github.com/wearenocomputer/ofxZmqWindows) (make sure to follow the instructions about the .dll in the readme)

____

Create as many receivers as you want and make to sure to use the correct ip and port

```c++
kinect0.connect("tcp://localhost:13000");
```

also make sure you set the same cloud density as in [ofKinectPCLPublish](https://github.com/oneandonlyoddo/ofKinectPCLPublish)

```c++
int cloudDensity = 3;
```

Cloud density is somewhat inverse. _int cloudDensity = 3;_ means only send every %3==0 point from the data. 



