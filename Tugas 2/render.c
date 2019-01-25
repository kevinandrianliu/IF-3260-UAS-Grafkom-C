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

void bresenham(int x0, int y0, int x1, int y1, char * framebuffer, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo){
    if (x0 > x1){
        int x_temp;
        int y_temp;

        x_temp = x0;
        y_temp = y0;
        x0 = x1;
        y0 = y1;
        x1 = x_temp;
        y1 = y_temp;
    }

    // if (x1 >= y1){
    //     int y = y0;
    //     int eps = 0;

    //     if (y1 >= y0){
    //         int dx = x1 - x0;
    //         int dy = y1 - y0;
    //         for (int x = x0; x <= x1; x++){
    //             long int mem_location = (x + vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (y + vinfo.yoffset) * finfo.line_length;

    //             *(framebuffer + mem_location) = 255;
    //             *(framebuffer + mem_location + 1) = 255;
    //             *(framebuffer + mem_location + 2) = 255;
    //             *(framebuffer + mem_location + 3) = 0;

    //             eps += dy;
    //             if ((eps << 1) >= dx){
    //                 y++;
    //                 eps -= dx;
    //             }
    //         }
    //     } else {
    //         int dx = x1 - x0;
    //         int dy = y0 - y1;
    //         for (int x = x0; x <= x1; x++){
    //             long int mem_location = (x + vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (y + vinfo.yoffset) * finfo.line_length;

    //             *(framebuffer + mem_location) = 255;
    //             *(framebuffer + mem_location + 1) = 255;
    //             *(framebuffer + mem_location + 2) = 255;
    //             *(framebuffer + mem_location + 3) = 0;

    //             eps += dy;
    //             if ((eps << 1) >= dx){
    //                 y--;
    //                 eps -= dx;
    //             }
    //         }
    //     }
    // } else {
    //     int x = x0;
    //     int eps = 0;

    //     if (y1 >= y0){
    //         int dx = x1 - x0;
    //         int dy = y1 - y0;

    //         for (int y = y0; y <= y1; y++){
    //             long int mem_location = (x + vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (y + vinfo.yoffset) * finfo.line_length;

    //             *(framebuffer + mem_location) = 255;
    //             *(framebuffer + mem_location + 1) = 255;
    //             *(framebuffer + mem_location + 2) = 255;
    //             *(framebuffer + mem_location + 3) = 0;

    //             eps += dx;
    //             if ((eps << 1) >= dy){
    //                 x++;
    //                 eps -= dy;
    //             }
    //         }
    //     } else {
    //         int dx = x1 - x0;
    //         int dy = y0 - y1;
    //         for (int y = y0; y <= y1; y++){
    //             long int mem_location = (x + vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (y + vinfo.yoffset) * finfo.line_length;

    //             *(framebuffer + mem_location) = 255;
    //             *(framebuffer + mem_location + 1) = 255;
    //             *(framebuffer + mem_location + 2) = 255;
    //             *(framebuffer + mem_location + 3) = 0;

    //             eps += dx;
    //             if ((eps << 1) >= dy){
    //                 x--;
    //                 eps -= dy;
    //             }
    //         }
    //     }
    // }

    float gradien = (y1 - y0)/(x1 - x0);

    if ((abs(gradien) >= 0) && (abs(gradien) <= 1)){
        int y = y0;
        int eps = 0;

        if (y1 >= y0){
            int dx = x1 - x0;
            int dy = y1 - y0;
            for (int x = x0; x <= x1; x++){
                long int mem_location = (x + vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (y + vinfo.yoffset) * finfo.line_length;

                *(framebuffer + mem_location) = 255;
                *(framebuffer + mem_location + 1) = 255;
                *(framebuffer + mem_location + 2) = 255;
                *(framebuffer + mem_location + 3) = 0;

                eps += dy;
                if ((eps << 1) >= dx){
                    y++;
                    eps -= dx;
                }
            }
        } else {    //y1 < y0
            int dx = x1 - x0;
            int dy = y0 - y1;
            for (int x = x0; x <= x1; x++){
                long int mem_location = (x + vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (y + vinfo.yoffset) * finfo.line_length;

                *(framebuffer + mem_location) = 255;
                *(framebuffer + mem_location + 1) = 255;
                *(framebuffer + mem_location + 2) = 255;
                *(framebuffer + mem_location + 3) = 0;

                eps += dy;
                if ((eps << 1) >= dx){
                    y--;
                    eps -= dx;
                }
            }
        }
    } else {
        int x = x0;
        int eps = 0;

        if (y1 >= y0){
            int dx = x1 - x0;
            int dy = y1 - y0;

            for (int y = y0; y <= y1; y++){
                long int mem_location = (x + vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (y + vinfo.yoffset) * finfo.line_length;

                *(framebuffer + mem_location) = 255;
                *(framebuffer + mem_location + 1) = 255;
                *(framebuffer + mem_location + 2) = 255;
                *(framebuffer + mem_location + 3) = 0;

                eps += dx;
                if ((eps << 1) >= dy){
                    x++;
                    eps -= dy;
                }
            }
        } else {    //y1 < y0
            int dx = x1 - x0;
            int dy = y0 - y1;

            for (int y = y0; y <= y1; y--){
                long int mem_location = (x + vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (y + vinfo.yoffset) * finfo.line_length;

                *(framebuffer + mem_location) = 255;
                *(framebuffer + mem_location + 1) = 255;
                *(framebuffer + mem_location + 2) = 255;
                *(framebuffer + mem_location + 3) = 0;

                eps += dx;
                if ((eps << 1) < dy){
                    x++;
                    eps -= dy;
                }
            }
        }
    }

    long int mem_location = (x1 + vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (y1 + vinfo.yoffset) * finfo.line_length;

    *(framebuffer + mem_location) = 0;
    *(framebuffer + mem_location + 1) = 0;
    *(framebuffer + mem_location + 2) = 255;
    *(framebuffer + mem_location + 3) = 0;

    mem_location = (x0 + vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (y0 + vinfo.yoffset) * finfo.line_length;

    *(framebuffer + mem_location) = 0;
    *(framebuffer + mem_location + 1) = 255;
    *(framebuffer + mem_location + 2) = 0;
    *(framebuffer + mem_location + 3) = 0;
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
    bresenham(100,300,1000,100,fbp,vinfo,finfo);
    bresenham(100,300,300,700,fbp,vinfo,finfo);
    bresenham(100,300,1000,700,fbp,vinfo,finfo);
    bresenham(100,300,200,100,fbp,vinfo,finfo);
    munmap(fbp, screensize);
    close(fbfd);

    while(1);
    return 0;
}

