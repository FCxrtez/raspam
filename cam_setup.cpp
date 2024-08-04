#include "cam_setup.h"
#include <stdio.h>
#include <linux/videodev2.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <unistd.h>

int cam_init(int* fd, const char* device){
    *fd = open(device, O_RDWR);

    if(*fd == -1)
    {
        perror("Couldn't open video device correctly");
        return -1;
    }

    return 0;
}

int cam_query_set(int* fd){
    struct v4l2_capability cam_cap;
    struct v4l2_format fmt;

    if(ioctl(*fd, VIDIOC_QUERYCAP, &cam_cap) != 0)
    {
        perror("Couldn't query device capabilities\n");
        return -1;
    }

    fmt.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
    fmt.fmt.pix.width = 640;
    fmt.fmt.pix.height = 480;
    fmt.fmt.pix.pixelformat = V4L2_PIX_FMT_RGB24;
    fmt.fmt.pix.field = V4L2_FIELD_NONE;

    if (ioctl(*fd, VIDIOC_S_FMT, &fmt) != 0) {
        perror("Setting Pixel Format");
        close(*fd);
        return -1;
    }

    return 0;
}