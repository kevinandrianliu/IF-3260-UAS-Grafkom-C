#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <linux/fb.h>
#include <sys/mman.h>
#include <sys/ioctl.h>
#include "utilities.h"
#define CHARWIDTH 16
#define CHARHEIGHT 20

void bella(int y, char *fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo) {

    render_kotak(80, y, fbp, vinfo, finfo);    

    render_b(106, y, fbp, vinfo, finfo);
    render_e(106+25, y, fbp, vinfo, finfo);
    render_l(106+45, y, fbp, vinfo, finfo);
    render_l(106+60, y, fbp, vinfo, finfo);
    render_a(106+75, y, fbp, vinfo, finfo);

    render_d(106+105, y, fbp, vinfo, finfo);
    render_e(106+125, y, fbp, vinfo, finfo);
    render_s(106+145, y, fbp, vinfo, finfo);
    render_t(106+165, y, fbp, vinfo, finfo);
    render_i(106+185, y, fbp, vinfo, finfo);
    render_a(106+195, y, fbp, vinfo, finfo);
    render_n(106+215, y, fbp, vinfo, finfo);
    render_a(106+235, y, fbp, vinfo, finfo);

    render_j(106+265, y, fbp, vinfo, finfo);

    render_strip(580, y, fbp, vinfo, finfo);

    render_j(600, y, fbp, vinfo, finfo);
    render_a(620, y, fbp, vinfo, finfo);
    render_k(640, y, fbp, vinfo, finfo);
    render_a(665, y, fbp, vinfo, finfo);
    render_r(685, y, fbp, vinfo, finfo);
    render_t(705, y, fbp, vinfo, finfo);
    render_a(720, y, fbp, vinfo, finfo);
}

void kevin_a(int y, char *fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo) {

    render_kotak(80, y, fbp, vinfo, finfo);    

    render_k(106, y, fbp, vinfo, finfo);
    render_e(106+25, y, fbp, vinfo, finfo);
    render_v(106+45, y, fbp, vinfo, finfo);
    render_i(106+65, y, fbp, vinfo, finfo);
    render_n(106+75, y, fbp, vinfo, finfo);

    render_a(106+105, y, fbp, vinfo, finfo);
    render_n(106+125, y, fbp, vinfo, finfo);
    render_d(106+145, y, fbp, vinfo, finfo);
    render_r(106+165, y, fbp, vinfo, finfo);
    render_i(106+185, y, fbp, vinfo, finfo);
    render_a(106+195, y, fbp, vinfo, finfo);
    render_n(106+215, y, fbp, vinfo, finfo);

    render_l(106+255, y, fbp, vinfo, finfo);

    render_strip(540, y, fbp, vinfo, finfo);

    render_t(560, y, fbp, vinfo, finfo);
    render_a(580, y, fbp, vinfo, finfo);
    render_n(600, y, fbp, vinfo, finfo);
    render_g(620, y, fbp, vinfo, finfo);
    render_e(640, y, fbp, vinfo, finfo);
    render_r(660, y, fbp, vinfo, finfo);
    render_a(680, y, fbp, vinfo, finfo);
    render_n(700, y, fbp, vinfo, finfo);
    render_g(720, y, fbp, vinfo, finfo);
}

int main()
{
    int fbfd = 0;
    struct fb_var_screeninfo vinfo;
    struct fb_fix_screeninfo finfo;
    long int screensize = 0;
    char *fbp = 0;
    int x = 0, y = 0;
    long int location = 0;

    // Open the file for reading and writing
    fbfd = open("/dev/fb0", O_RDWR);
    if (fbfd == -1) {
        perror("Error: cannot open framebuffer device");
        exit(1);
    }
    printf("The framebuffer device was opened successfully.\n");

    // Get fixed screen information
    if (ioctl(fbfd, FBIOGET_FSCREENINFO, &finfo) == -1) {
        perror("Error reading fixed information");
        exit(2);
    }

    // Get variable screen information
    if (ioctl(fbfd, FBIOGET_VSCREENINFO, &vinfo) == -1) {
        perror("Error reading variable information");
        exit(3);
    }

    printf("%dx%d, %dbpp\n", vinfo.xres, vinfo.yres, vinfo.bits_per_pixel);

    // Figure out the size of the screen in bytes
    screensize = vinfo.xres * vinfo.yres * vinfo.bits_per_pixel / 8;

    // Map the device to memory
    fbp = (char *)mmap(0, screensize, PROT_READ | PROT_WRITE, MAP_SHARED, fbfd, 0);
    if ((int)fbp == -1) {
        perror("Error: failed to map framebuffer device to memory");
        exit(4);
    }
    printf("The framebuffer device was mapped to memory successfully.\n");

    x = 0; y = 0;       // Where we are going to put the pixel

    // Figure out where in memory to put the pixel
    for (y = 0; y < vinfo.yres; y++)
        for (x = 0; x < vinfo.xres; x++) {

            location = (x+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                       (y+vinfo.yoffset) * finfo.line_length;

        if (((y < 80)||(x <80))||((y > 520)||(x > 720))) {
        pixel_color(fbp, location, 0, 0, 0);
        } else if (vinfo.bits_per_pixel == 32) {
                /* *(fbp + location) = 255;        // Some blue
                *(fbp + location + 1) = 15+x/2;     // A little green
                *(fbp + location + 2) = 200-y/5;    // A lot of red
                *(fbp + location + 3) = 0;      // No transparency */
        pixel_color(fbp, location, 0, 0, 0);

        //location += 4;
            } else  { //assume 16bpp
                int b = 0;
                int g = 0;     // A little green
                int r = 0;    // A lot of red
                unsigned short int t = r<<11 | g << 5 | b;
                *((unsigned short int*)(fbp + location)) = t;
            }

        }

    bella(100, fbp, vinfo, finfo);
    kevin_a(150, fbp, vinfo, finfo);

    munmap(fbp, screensize);
    close(fbfd);
    return 0;
}

