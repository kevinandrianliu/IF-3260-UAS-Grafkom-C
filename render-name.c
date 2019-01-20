#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <linux/fb.h>
#include <sys/mman.h>
#include <sys/ioctl.h>
#include <time.h>
#include "utilities.h"
#define CHARWIDTH 16
#define CHARHEIGHT 20

void delay(unsigned int ms){
    clock_t goal = ms + clock();
    while (goal > clock());
}

void nama( int y, char *fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo){
    
    int b = 0;
    int g = 0;
    int r = 200;

    render_s(346, y, b, g, r, fbp, vinfo, finfo);
    render_i(366, y, b, g, r, fbp, vinfo, finfo);
    render_d(376, y, b, g, r, fbp, vinfo, finfo);
    render_e(396, y, b, g, r, fbp, vinfo, finfo);
    render_r(416, y, b, g, r, fbp, vinfo, finfo);
}
    
void yora(int y, char *fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo){

    int b = 0;
    int g = 220;
    int r = 220;

    render_kotak(80, y, 255, 255, 255, fbp, vinfo, finfo);
    render_d(106, y, b, g, r, fbp, vinfo, finfo);
    render_i(126, y, b, g, r, fbp, vinfo, finfo);
    render_n(136, y, b, g, r, fbp, vinfo, finfo);
    render_d(156, y, b, g, r, fbp, vinfo, finfo);
    render_a(176, y, b, g, r, fbp, vinfo, finfo);
    render_y(204, y, b, g, r, fbp, vinfo, finfo);
    render_o(220, y, b, g, r, fbp, vinfo, finfo);
    render_r(240, y, b, g, r, fbp, vinfo, finfo);
    render_a(260, y, b, g, r, fbp, vinfo, finfo);
    render_i(288, y, b, g, r, fbp, vinfo, finfo);
    render_s(296, y, b, g, r, fbp, vinfo, finfo);
    render_l(316, y, b, g, r, fbp, vinfo, finfo);
    render_a(332, y, b, g, r, fbp, vinfo, finfo);
    render_m(352, y, b, g, r, fbp, vinfo, finfo);
    render_i(376, y, b, g, r, fbp, vinfo, finfo);
    //render_strip(400, y, 150, 150, 150, fbp, vinfo, finfo);
    render_p(620, y, b, g, r, fbp, vinfo, finfo);
    render_a(640, y, b, g, r, fbp, vinfo, finfo);
    render_d(660, y, b, g, r, fbp, vinfo, finfo);
    render_a(680, y, b, g, r, fbp, vinfo, finfo);
    render_n(700, y, b, g, r, fbp, vinfo, finfo);
    render_g(720, y, b, g, r, fbp, vinfo, finfo);
}

void tere(int y,char *fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo){

    int b = 200;
    int g = 0;
    int r = 100;

    render_kotak(80, y, 255, 255, 255, fbp, vinfo, finfo);
    render_t(106, y, b, g, r, fbp, vinfo, finfo);
    render_e(126, y, b, g, r, fbp, vinfo, finfo);
    render_r(146, y, b, g, r, fbp, vinfo, finfo);
    render_e(166, y, b, g, r, fbp, vinfo, finfo);
    render_s(186, y, b, g, r, fbp, vinfo, finfo);
    render_a(206, y, b, g, r, fbp, vinfo, finfo);
    //render_strip(520, y, 150, 150, 150, fbp, vinfo, finfo);
    render_p(556, y, b, g, r, fbp, vinfo, finfo);
    render_e(576, y, b, g, r, fbp, vinfo, finfo);
    render_k(596, y, b, g, r, fbp, vinfo, finfo);
    render_a(616, y, b, g, r, fbp, vinfo, finfo);
    render_n(636, y, b, g, r, fbp, vinfo, finfo);
    render_b(656, y, b, g, r, fbp, vinfo, finfo);
    render_a(680, y, b, g, r, fbp, vinfo, finfo);
    render_r(700, y, b, g, r, fbp, vinfo, finfo);
    render_u(720, y, b, g, r, fbp, vinfo, finfo);
}

void bella(int y, char *fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo) {

    int b = 0;
    int g = 100;
    int r = 200;

    render_kotak(80, y, 255, 255, 255, fbp, vinfo, finfo);    

    render_b(106, y, b, g, r, fbp, vinfo, finfo);
    render_e(106+25, y, b, g, r, fbp, vinfo, finfo);
    render_l(106+45, y, b, g, r, fbp, vinfo, finfo);
    render_l(106+60, y, b, g, r, fbp, vinfo, finfo);
    render_a(106+75, y, b, g, r, fbp, vinfo, finfo);

    render_d(106+105, y, b, g, r, fbp, vinfo, finfo);
    render_e(106+125, y, b, g, r, fbp, vinfo, finfo);
    render_s(106+145, y, b, g, r, fbp, vinfo, finfo);
    render_t(106+165, y, b, g, r, fbp, vinfo, finfo);
    render_i(106+185, y, b, g, r, fbp, vinfo, finfo);
    render_a(106+195, y, b, g, r, fbp, vinfo, finfo);
    render_n(106+215, y, b, g, r, fbp, vinfo, finfo);
    render_a(106+235, y, b, g, r, fbp, vinfo, finfo);

    render_j(106+265, y, b, g, r, fbp, vinfo, finfo);

    //render_strip(580, y, 150, 150, 150, fbp, vinfo, finfo);

    render_j(605, y, b, g, r, fbp, vinfo, finfo);
    render_a(625, y, b, g, r, fbp, vinfo, finfo);
    render_k(645, y, b, g, r, fbp, vinfo, finfo);
    render_a(665, y, b, g, r, fbp, vinfo, finfo);
    render_r(685, y, b, g, r, fbp, vinfo, finfo);
    render_t(705, y, b, g, r, fbp, vinfo, finfo);
    render_a(720, y, b, g, r, fbp, vinfo, finfo);
}

void kevin_a(int y, char *fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo) {

    int b = 0;
    int g = 200;
    int r = 0;

    render_kotak(80, y, 255, 255, 255, fbp, vinfo, finfo);    

    render_k(106, y, b, g, r, fbp, vinfo, finfo);
    render_e(106+25, y, b, g, r, fbp, vinfo, finfo);
    render_v(106+45, y, b, g, r, fbp, vinfo, finfo);
    render_i(106+65, y, b, g, r, fbp, vinfo, finfo);
    render_n(106+75, y, b, g, r, fbp, vinfo, finfo);

    render_a(106+105, y, b, g, r, fbp, vinfo, finfo);
    render_n(106+125, y, b, g, r, fbp, vinfo, finfo);
    render_d(106+145, y, b, g, r, fbp, vinfo, finfo);
    render_r(106+165, y, b, g, r, fbp, vinfo, finfo);
    render_i(106+185, y, b, g, r, fbp, vinfo, finfo);
    render_a(106+195, y, b, g, r, fbp, vinfo, finfo);
    render_n(106+215, y, b, g, r, fbp, vinfo, finfo);

    render_l(106+255, y, b, g, r, fbp, vinfo, finfo);

    //render_strip(540, y, 150, 150, 150, fbp, vinfo, finfo);

    render_t(560, y, b, g, r, fbp, vinfo, finfo);
    render_a(580, y, b, g, r, fbp, vinfo, finfo);
    render_n(600, y, b, g, r, fbp, vinfo, finfo);
    render_g(620, y, b, g, r, fbp, vinfo, finfo);
    render_e(640, y, b, g, r, fbp, vinfo, finfo);
    render_r(660, y, b, g, r, fbp, vinfo, finfo);
    render_a(680, y, b, g, r, fbp, vinfo, finfo);
    render_n(700, y, b, g, r, fbp, vinfo, finfo);
    render_g(720, y, b, g, r, fbp, vinfo, finfo);
}

void kevin_f(int y, char *fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo) {

    int b = 200;
    int g = 0;
    int r = 0;

    render_kotak(80, y, 255, 255, 255, fbp, vinfo, finfo);    

    render_k(106, y, b, g, r, fbp, vinfo, finfo);
    render_e(106+25, y, b, g, r, fbp, vinfo, finfo);
    render_v(106+45, y, b, g, r, fbp, vinfo, finfo);
    render_i(106+65, y, b, g, r, fbp, vinfo, finfo);
    render_n(106+75, y, b, g, r, fbp, vinfo, finfo);

    render_f(106+105, y, b, g, r, fbp, vinfo, finfo);
    render_e(106+125, y, b, g, r, fbp, vinfo, finfo);
    render_r(106+145, y, b, g, r, fbp, vinfo, finfo);
    render_n(106+165, y, b, g, r, fbp, vinfo, finfo);
    render_a(106+185, y, b, g, r, fbp, vinfo, finfo);
    render_l(106+205, y, b, g, r, fbp, vinfo, finfo);
    render_d(106+220, y, b, g, r, fbp, vinfo, finfo);
    render_y(106+240, y, b, g, r, fbp, vinfo, finfo);
    

    //render_strip(580, y, 150, 150, 150, fbp, vinfo, finfo);

    render_j(605, y, b, g, r, fbp, vinfo, finfo);
    render_a(625, y, b, g, r, fbp, vinfo, finfo);
    render_k(645, y, b, g, r, fbp, vinfo, finfo);
    render_a(665, y, b, g, r, fbp, vinfo, finfo);
    render_r(685, y, b, g, r, fbp, vinfo, finfo);
    render_t(705, y, b, g, r, fbp, vinfo, finfo);
    render_a(720, y, b, g, r, fbp, vinfo, finfo);
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

    x = 0; y = 0;

    clear_screen(fbp,800,600,vinfo,finfo);

    y = 600;
    for (;;){
        clear_screen(fbp,800,600,vinfo,finfo);
        if(y>=0){nama(y,fbp, vinfo, finfo);}
        if(y+50>=0){bella(y+50, fbp, vinfo, finfo);}
        if(y+100>=0){yora(y+100,fbp,vinfo, finfo);}
        if(y+150>=0){kevin_a(y+150, fbp, vinfo, finfo);}
        if(y+200>=0){kevin_f(y+200, fbp, vinfo, finfo);}
        if(y+250>=0){tere(y+250, fbp, vinfo, finfo);}

        y -= 3;
        delay(50000);

        if (y < -300)
            break;
    }
    munmap(fbp, screensize);
    close(fbfd);
    return 0;
}

