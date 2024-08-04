#ifndef CAM_SETUP
#define CAM_SETUP

int cam_init(int* fd, const char* device);

int cam_query_set(int* fd);

#endif