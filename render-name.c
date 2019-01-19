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
    render_a(336, y, fbp, vinfo, finfo);
    render_a(368, y, fbp, vinfo, finfo);
    render_a(400, y, fbp, vinfo, finfo);
    render_a(432, y, fbp, vinfo, finfo);
}
    
void yora(int y, char *fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo){
    render_kotak(80, y, fbp, vinfo, finfo);
    render_d(106, y, fbp, vinfo, finfo);
    render_i(126, y, fbp, vinfo, finfo);
    render_n(136, y, fbp, vinfo, finfo);
    render_d(156, y, fbp, vinfo, finfo);
    render_a(176, y, fbp, vinfo, finfo);
    render_y(204, y, fbp, vinfo, finfo);
    render_o(220, y, fbp, vinfo, finfo);
    render_r(240, y, fbp, vinfo, finfo);
    render_a(260, y, fbp, vinfo, finfo);
    render_i(288, y, fbp, vinfo, finfo);
    render_s(296, y, fbp, vinfo, finfo);
    render_l(316, y, fbp, vinfo, finfo);
    render_a(332, y, fbp, vinfo, finfo);
    render_m(352, y, fbp, vinfo, finfo);
    render_i(376, y, fbp, vinfo, finfo);
    render_strip(400, y, fbp, vinfo, finfo);
    render_p(604, y, fbp, vinfo, finfo);
    render_a(624, y, fbp, vinfo, finfo);
    render_d(644, y, fbp, vinfo, finfo);
    render_a(664, y, fbp, vinfo, finfo);
    render_n(684, y, fbp, vinfo, finfo);
    render_g(704, y, fbp, vinfo, finfo);
}

void tere(int y,char *fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo){
    render_kotak(80, y, fbp, vinfo, finfo);
    render_t(106, y, fbp, vinfo, finfo);
    render_e(126, y, fbp, vinfo, finfo);
    render_r(146, y, fbp, vinfo, finfo);
    render_e(166, y, fbp, vinfo, finfo);
    render_s(186, y, fbp, vinfo, finfo);
    render_a(206, y, fbp, vinfo, finfo);
    render_strip(520, y, fbp, vinfo, finfo);
    render_p(544, y, fbp, vinfo, finfo);
    render_e(564, y, fbp, vinfo, finfo);
    render_k(584, y, fbp, vinfo, finfo);
    render_a(604, y, fbp, vinfo, finfo);
    render_n(624, y, fbp, vinfo, finfo);
    render_b(644, y, fbp, vinfo, finfo);
    render_a(664, y, fbp, vinfo, finfo);
    render_r(684, y, fbp, vinfo, finfo);
    render_u(704, y, fbp, vinfo, finfo);
}

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

void kevin_f(int y, char *fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo) {

    render_kotak(80, y, fbp, vinfo, finfo);    

    render_k(106, y, fbp, vinfo, finfo);
    render_e(106+25, y, fbp, vinfo, finfo);
    render_v(106+45, y, fbp, vinfo, finfo);
    render_i(106+65, y, fbp, vinfo, finfo);
    render_n(106+75, y, fbp, vinfo, finfo);

    render_f(106+105, y, fbp, vinfo, finfo);
    render_e(106+125, y, fbp, vinfo, finfo);
    render_r(106+145, y, fbp, vinfo, finfo);
    render_n(106+165, y, fbp, vinfo, finfo);
    render_a(106+185, y, fbp, vinfo, finfo);
    render_l(106+205, y, fbp, vinfo, finfo);
    render_d(106+220, y, fbp, vinfo, finfo);
    render_y(106+240, y, fbp, vinfo, finfo);
    

    render_strip(580, y, fbp, vinfo, finfo);

    render_j(600, y, fbp, vinfo, finfo);
    render_a(620, y, fbp, vinfo, finfo);
    render_k(640, y, fbp, vinfo, finfo);
    render_a(665, y, fbp, vinfo, finfo);
    render_r(685, y, fbp, vinfo, finfo);
    render_t(705, y, fbp, vinfo, finfo);
    render_a(720, y, fbp, vinfo, finfo);
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
    clear_screen(fbp,800,600,vinfo,finfo);

    //bella(100, fbp, vinfo, finfo);
    //kevin_a(150, fbp, vinfo, finfo);
    //kevin_f(200, fbp, vinfo, finfo);
    //yora(250,fbp,vinfo,finfo);
    //tere(300,fbp,vinfo,finfo);

    y = 762;
    for (;;){
        clear_screen(fbp,1366,762,vinfo,finfo);
        if(y>=0){nama(y, fbp, vinfo, finfo);}
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

