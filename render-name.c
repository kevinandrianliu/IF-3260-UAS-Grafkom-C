#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <linux/fb.h>
#include <sys/mman.h>
#include <sys/ioctl.h>
#include "utilities.h"
#include <time.h>
#define CHARWIDTH 16
#define CHARHEIGHT 20

void delay(unsigned int ms)
{
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
    
    render_y(206, y, fbp, vinfo, finfo);
    render_o(222, y, fbp, vinfo, finfo);
    render_r(242, y, fbp, vinfo, finfo);
    render_a(262, y, fbp, vinfo, finfo);
    
    render_i(292, y, fbp, vinfo, finfo);
    render_s(300, y, fbp, vinfo, finfo);
    render_l(320, y, fbp, vinfo, finfo);
    render_a(336, y, fbp, vinfo, finfo);
    render_m(356, y, fbp, vinfo, finfo);
    render_i(380, y, fbp, vinfo, finfo);
    //render_strip(400, y, fbp, vinfo, finfo);
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
    render_e(122, y, fbp, vinfo, finfo);
    render_r(142, y, fbp, vinfo, finfo);
    render_e(162, y, fbp, vinfo, finfo);
    render_s(182, y, fbp, vinfo, finfo);
    render_a(202, y, fbp, vinfo, finfo);
    //render_strip(520, y, fbp, vinfo, finfo);
    render_p(540, y, fbp, vinfo, finfo);
    render_e(560, y, fbp, vinfo, finfo);
    render_k(580, y, fbp, vinfo, finfo);
    render_a(600, y, fbp, vinfo, finfo);
    render_n(620, y, fbp, vinfo, finfo);
    render_b(640, y, fbp, vinfo, finfo);
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

    //render_strip(580, y, fbp, vinfo, finfo);

    render_j(588, y, fbp, vinfo, finfo);
    render_a(608, y, fbp, vinfo, finfo);
    render_k(628, y, fbp, vinfo, finfo);
    render_a(648, y, fbp, vinfo, finfo);
    render_r(668, y, fbp, vinfo, finfo);
    render_t(684, y, fbp, vinfo, finfo);
    render_a(704, y, fbp, vinfo, finfo);
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

    //render_strip(540, y, fbp, vinfo, finfo);

    render_t(544, y, fbp, vinfo, finfo);
    render_a(564, y, fbp, vinfo, finfo);
    render_n(584, y, fbp, vinfo, finfo);
    render_g(604, y, fbp, vinfo, finfo);
    render_e(624, y, fbp, vinfo, finfo);
    render_r(644, y, fbp, vinfo, finfo);
    render_a(664, y, fbp, vinfo, finfo);
    render_n(684, y, fbp, vinfo, finfo);
    render_g(704, y, fbp, vinfo, finfo);
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
    

    //render_strip(580, y, fbp, vinfo, finfo);

    render_j(588, y, fbp, vinfo, finfo);
    render_a(608, y, fbp, vinfo, finfo);
    render_k(628, y, fbp, vinfo, finfo);
    render_a(648, y, fbp, vinfo, finfo);
    render_r(668, y, fbp, vinfo, finfo);
    render_t(684, y, fbp, vinfo, finfo);
    render_a(704, y, fbp, vinfo, finfo);
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
    
    while(y>=-500){
        clear_screen(fbp,800,600,vinfo,finfo);
        if(y+250>=0){nama(y+250, fbp, vinfo, finfo);}
        if(y+300>=0){bella(y+300, fbp, vinfo, finfo);}
        if(y+350>=0){yora(y+350,fbp,vinfo, finfo);}
        if(y+400>=0){kevin_a(y+400, fbp, vinfo, finfo);}
        if(y+450>0){kevin_f(y+450, fbp, vinfo, finfo);}
        if(y+500>0){tere(y+500, fbp, vinfo, finfo);}
        y=y-1;
        delay(25000);
    }
    /*
    while(y>=-950){
        clear_screen(fbp,800,600,vinfo,finfo);
        if(y+600>=0){nama(y+600, fbp, vinfo, finfo);}
        if(y+650>=0){bella(y+650, fbp, vinfo, finfo);}
        if(y+700>=0){yora(y+700,fbp,vinfo, finfo);}
        if(y+750>=0){kevin_a(y+850, fbp, vinfo, finfo);}
        if(y+800>0){kevin_f(y+900, fbp, vinfo, finfo);}
        if(y+950>0){tere(y+950, fbp, vinfo, finfo);}
        y=y-1;
        delay(25000);
    }*/


    munmap(fbp, screensize);
    close(fbfd);
    return 0;
}

