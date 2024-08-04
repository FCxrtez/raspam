#define CAM_PATH "/dev/video0"

#include <stdio.h>
#include "cam_setup.h"

int main (){
    int* fd;
    const char *path2device = CAM_PATH;

    if(cam_init(fd, path2device) != 0)
    {
        fprintf(stderr, "failed to initialize cam\n");
    }

    cam_query_set(fd);

    printf("cam initalized successfully\n");



}