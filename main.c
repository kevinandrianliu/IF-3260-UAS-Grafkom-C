#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <linux/fb.h>
#include <sys/mman.h>
#include <sys/ioctl.h>
#include <utilities.h>
#define CHARWIDTH 16
#define CHARHEIGHT 20

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
    render_t(100, 100, fbp, vinfo, finfo);
    render_o(116, 100, fbp, vinfo, finfo);
    render_s(136, 100, fbp, vinfo, finfo);
    render_w(156, 100, fbp, vinfo, finfo);
    munmap(fbp, screensize);
    close(fbfd);
    return 0;
}

