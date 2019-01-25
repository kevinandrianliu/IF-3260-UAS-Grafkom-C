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

            for (int y = y0; y >= y1; y--){
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

void putpixel(int x, int y, char * framebuffer, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo){
    long int mem_location = (x + vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (y + vinfo.yoffset) * finfo.line_length;
    *(framebuffer + mem_location) = 255;
    *(framebuffer + mem_location + 1) = 255;
    *(framebuffer + mem_location + 2) = 255;
    *(framebuffer + mem_location + 3) = 0; 
}

// Function to put pixels 
// at subsequence points 
void drawCircle(int xc, int yc, int x, int y, char * framebuffer, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo) 
{ 
    putpixel(xc+x, yc+y, framebuffer, vinfo, finfo); 
    putpixel(xc-x, yc+y, framebuffer, vinfo, finfo); 
    putpixel(xc+x, yc-y, framebuffer, vinfo, finfo); 
    putpixel(xc-x, yc-y, framebuffer, vinfo, finfo); 
    putpixel(xc+y, yc+x, framebuffer, vinfo, finfo); 
    putpixel(xc-y, yc+x, framebuffer, vinfo, finfo); 
    putpixel(xc+y, yc-x, framebuffer, vinfo, finfo); 
    putpixel(xc-y, yc-x, framebuffer, vinfo, finfo); 
}
  
// Function for circle-generation 
// using Bresenham's algorithm 
void circleBres(int xc, int yc, int r, char * framebuffer, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo) 
{ 
    int x = 0, y = r; 
    int d = 3 - 2 * r; 
    drawCircle(xc, yc, x, y, framebuffer, vinfo, finfo); 
    while (y >= x) 
    { 
        // for each pixel we will 
        // draw all eight pixels 
          
        x++; 
  
        // check for decision parameter 
        // and correspondingly  
        // update d, x, y 
        if (d > 0) 
        { 
            y--;  
            d = d + 4 * (x - y) + 10; 
        } 
        else {d = d + 4 * x + 6;} 
        drawCircle(xc, yc, x, y, framebuffer, vinfo, finfo); 
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

    clear_screen(fbp,800,600,vinfo,finfo);
    circleBres(400,500,50,fbp,vinfo,finfo); 
    munmap(fbp, screensize);
    close(fbfd);

    while(1);
    return 0;
}

