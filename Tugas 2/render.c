#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <linux/fb.h>
#include <sys/mman.h>
#include <sys/ioctl.h>
#include <time.h>
#define CHARWIDTH 16
#define CHARHEIGHT 20

int sign(float i){
    if (i > 0)
        return 1;
    if (i < 0)
        return -1;
    return 0;
}

void bresenham(int x0, int y0, int x1, int y1, char * framebuffer, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo){
    int m_new = 2 * (y1 - y0);
    int slope_error_new = m_new - (x1 - x0);

    int y = y0;
    for (int x = x0; x <= x1; x++){
        long int mem_location = (x + vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (y + vinfo.yoffset) * finfo.line_length;

        *(framebuffer + mem_location) = 255;
        *(framebuffer + mem_location + 1) = 255;
        *(framebuffer + mem_location + 2) = 255;
        *(framebuffer + mem_location + 3) = 0;

        slope_error_new += m_new;

        if (slope_error_new >= 0){
            y++;
            slope_error_new -= 2 * (x1 - x0);
        }
    }
}

void clear_screen(char * framebuffer, unsigned int x_size, unsigned int y_size, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo){
    long int mem_location;

    for (int y = 0; y < y_size; y++){
        for (int x = 0; x < x_size; x++){
            mem_location = (x + vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (y + vinfo.yoffset) * finfo.line_length;

            *(framebuffer + mem_location) = 0;
            *(framebuffer + mem_location + 1) = 0;
            *(framebuffer + mem_location + 2) = 0;
            *(framebuffer + mem_location + 3) = 0;
        }
    }
}

int main()
{
    int fbfd;
    struct fb_var_screeninfo vinfo;
    struct fb_fix_screeninfo finfo;
    long int screensize;
    char *fbp;

    fbfd = open("/dev/fb0", O_RDWR);
    if (fbfd == -1) {
        // Framebuffer can't be opened
        exit(1);
    }

    if (ioctl(fbfd, FBIOGET_FSCREENINFO, &finfo) == -1) {
        // Error reading fixed screen information
        exit(2);
    }

    if (ioctl(fbfd, FBIOGET_VSCREENINFO, &vinfo) == -1) {
        // Error reading variable screen information
        exit(3);
    }

    // Calculating the screen size in bytes
    screensize = vinfo.xres * vinfo.yres * vinfo.bits_per_pixel / 8;

    // Map the framebuffer into memory
    fbp = (char *) mmap(0, screensize, PROT_READ | PROT_WRITE, MAP_SHARED, fbfd, 0);
    if ((int)fbp == -1) {
        // Mapping failed
        exit(4);
    }

    clear_screen(fbp,1366,762,vinfo,finfo);
    bresenham(100,100,1200,200,fbp,vinfo,finfo);
    munmap(fbp, screensize);
    close(fbfd);

    while(1);
    return 0;
}

