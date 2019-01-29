#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <linux/input.h>
#include <linux/fb.h>
#include <sys/mman.h>
#include <sys/ioctl.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <pthread.h>
#include "utilities.h"

#define CHARWIDTH 16
#define CHARHEIGHT 20

struct input_event ev;
ssize_t n;
int fd;
pthread_t thread0;
int flagShoot = 0;
unsigned short bullet_selection;

void delay(unsigned int ms){
    clock_t goal = ms + clock();
    while (goal > clock());
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
    putpixel(xc+x, yc-y, framebuffer, vinfo, finfo); 
    putpixel(xc-x, yc-y, framebuffer, vinfo, finfo); 
    putpixel(xc+y, yc-x, framebuffer, vinfo, finfo); 
    putpixel(xc-y, yc-x, framebuffer, vinfo, finfo);
}
  
// Function for circle-generation 
// using Bresenham's algorithm 
void halfcircleBres(int xc, int yc, int r, char * framebuffer, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo) 
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

void drawPlane(int x0, int y0, int x1, int y1, char * fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo){
    bresenham(x0,y0,x1,y1,0,fbp,vinfo,finfo);//lurus atas
    bresenham(x0-9 ,y0+26,x1-47,y1+26,0,fbp,vinfo,finfo);//lurus bawah
    bresenham(x0+25,y0+26,x1   ,y1+26,0,fbp,vinfo,finfo);//lurus bawah
    bresenham(x0+52,y0+11,x1+23,y1+11,0,fbp,vinfo,finfo);//lurus tengah
    bresenham(x0+52,y0+11,x1-15,y1   ,0,fbp,vinfo,finfo);//runcing
    bresenham(x0+50,y0+26,x1+25,y1+13,0,fbp,vinfo,finfo);//runcing
    bresenham(x0+50,y0   ,x1+25,y1+13,0,fbp,vinfo,finfo);//runcing
    bresenham(x0+10,y0+15,x1-10,y1+15,0,fbp,vinfo,finfo);//tambahan bawah
    bresenham(x0+9,y0+15,x1-50,y1+41,0,fbp,vinfo,finfo);//sayap
    bresenham(x0+40,y0+15,x1-50,y1+41,0,fbp,vinfo,finfo);//sayap
    bresenham(x0   ,y0   ,x1-80,y1-15,0,fbp,vinfo,finfo);//ekor
    bresenham(x0-10,y0+25,x1-80,y1-15,0,fbp,vinfo,finfo);//ekor
}

void drawBlast(int x0, int y0, char * fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo){
    bresenham(x0,y0,x0-8,y0 + 30,0,fbp,vinfo,finfo); //Atas
    bresenham(x0,y0,x0+8,y0 + 30,0,fbp,vinfo,finfo);

    bresenham(x0-8,y0 + 30,x0-35,y0+12,0,fbp,vinfo,finfo); //Barat Laut
    bresenham(x0-21,y0 + 43,x0-35,y0+12,0,fbp,vinfo,finfo);

    bresenham(x0-21,y0 + 43,x0-51,y0 + 51,0,fbp,vinfo,finfo); //Barat
    bresenham(x0-21,y0 + 59,x0-51,y0 + 51,0,fbp,vinfo,finfo);

    bresenham(x0-21,y0 + 59,x0-35,y0+88,0,fbp,vinfo,finfo); //Barat Daya
    bresenham(x0-8,y0 + 72,x0-35,y0+88,0,fbp,vinfo,finfo);

    bresenham(x0-8,y0 + 72,x0,y0 + 102,0,fbp,vinfo,finfo); //Selatan
    bresenham(x0+8,y0 + 72,x0,y0 + 102,0,fbp,vinfo,finfo);

    bresenham(x0+8,y0 + 30,x0+35,y0+12,0,fbp,vinfo,finfo); //Timur Laut
    bresenham(x0+21,y0 + 43,x0+35,y0+12,0,fbp,vinfo,finfo);

    bresenham(x0+21,y0 + 43,x0+51,y0 + 51,0,fbp,vinfo,finfo); //Timur
    bresenham(x0+21,y0 + 59,x0+51,y0 + 51,0,fbp,vinfo,finfo);

    bresenham(x0+8,y0 + 72,x0+35,y0+88,0,fbp,vinfo,finfo); //Tenggara
    bresenham(x0+21,y0 + 59,x0+35,y0+88,0,fbp,vinfo,finfo);


}
void drawCannon(char * fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo){
    //bresenham(340-c,440-c,360-c,460-c,TRUE,fbp,vinfo,finfo);
    bresenham(307,450,335,495,0,fbp,vinfo,finfo);
    bresenham(298,462,307,450,0,fbp,vinfo,finfo);
    bresenham(298,462,327,510,0,fbp,vinfo,finfo);

    bresenham(352,424,365,460,0,fbp,vinfo,finfo);
    bresenham(337,430,352,424,0,fbp,vinfo,finfo);
    bresenham(337,430,352,468,0,fbp,vinfo,finfo);
    
    
    bresenham(392,415,392,450,0,fbp,vinfo,finfo);
    bresenham(392,415,407,415,0,fbp,vinfo,finfo);
    bresenham(407,415,407,450,0,fbp,vinfo,finfo);

    bresenham(448,424,435,460,0,fbp,vinfo,finfo);
    bresenham(463,430,448,424,0,fbp,vinfo,finfo);
    bresenham(463,430,448,468,0,fbp,vinfo,finfo);

    bresenham(493,450,465,479,0,fbp,vinfo,finfo);
    bresenham(503,469,493,450,0,fbp,vinfo,finfo);
    bresenham(502,462,473,493,0,fbp,vinfo,finfo);


    halfcircleBres(400,530,80,fbp,vinfo,finfo);
    bresenham(320,530,480,530,0,fbp,vinfo,finfo);

}

void drawStar(int x0, int y0, char * fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo){
    bresenham(x0-8,y0-8,x0,y0,TRUE,fbp,vinfo,finfo);
    bresenham(x0+5,y0-10,x0,y0,TRUE,fbp,vinfo,finfo);
    bresenham(x0+11,y0,x0,y0,TRUE,fbp,vinfo,finfo);
    bresenham(x0+5,y0+10,x0,y0,TRUE,fbp,vinfo,finfo);
    bresenham(x0-10,y0+6,x0,y0,TRUE,fbp,vinfo,finfo);
}

void drawBullets(int offset, char selection, char * fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo){
    switch (selection){
        case 0:
            drawStar(302-offset/1.5,456-offset,fbp,vinfo,finfo);
            break;
        case 1:
            drawStar(344-offset/2,427-offset,fbp,vinfo,finfo);
            break;
        case 2:
            drawStar(400,415-offset,fbp,vinfo,finfo);
            break;
        case 3:
            drawStar(455+offset/2,427-offset,fbp,vinfo,finfo);
            break;
        case 4:
            drawStar(498+offset/1.5,460-offset,fbp,vinfo,finfo);
            break;
    }

}

void *userInput(){
    while(1){
        n = read(fd, &ev, sizeof ev);
        if (n == (ssize_t)-1) {
            if (errno == EINTR)
                continue;
            else
                break;
        } else if (n != sizeof ev) {
            errno = EIO;
            break;
        }
        if (ev.type == EV_KEY && ev.value >= 0 && ev.value <= 2){
            if((ev.value == 1) && (!(flagShoot)) && (ev.code > 1) && (ev.code < 7)){
                flagShoot = 1;
                bullet_selection = ev.code;
            }
        }
    }
}

char checkIfShot(int star_offset, int plane_offset, int selection){
    int x_star;
    int y_star;

    switch (selection){
        case 0:
            x_star = 302-star_offset/1.5;
            y_star = 456-star_offset;
            break;
        case 1:
            x_star = 344-star_offset/2;
            y_star = 427-star_offset;
            break;
        case 2:
            x_star = 400;
            y_star = 415-star_offset;
            break;
        case 3:
            x_star = 455+star_offset/2;
            y_star = 427-star_offset;
            break;
        case 4:
            x_star = 498+star_offset/1.5;
            y_star = 460-star_offset;
            break;
    }

    int x_star_coordinates[5] = {x_star-8, x_star+5,  x_star+11, x_star+5,  x_star-10};
    int y_star_coordinates[5] = {y_star-8, y_star-10, y_star,    y_star+10, y_star+6};

    // for (int i = 0; i < 5; i++){
    //     if (checkIfIntersect(x_star_coordinates[i],y_star_coordinates[i],x_star,y_star,))
    //         return TRUE

    //     plane_offset-9,
    //     drawPlane(40+r,100,90+r,100,fbp,vinfo,finfo);
    //     bresenham(x0-9 ,y0+26,x1-47,y1+26,0,fbp,vinfo,finfo);//lurus bawah
    //     bresenham(x0+25,y0+26,x1   ,y1+26,0,fbp,vinfo,finfo);//lurus bawah
    //     bresenham(x0+10,y0+15,x1-10,y1+15,0,fbp,vinfo,finfo);//tambahan bawah

    // }
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

    //input keyboard
    const char *dev = "/dev/input/event4";
    fd = open(dev, O_RDONLY);
    if (fd == -1) {
        fprintf(stderr, "Cannot open %s: %s.\n", dev, strerror(errno));
        return EXIT_FAILURE;
    }

    int c = 0;
    int c2 = 0; 
    int c3 = 0;
    int r = 0;
    
    //start user input thread
    pthread_create(&thread0, NULL, userInput, NULL);

    while (1) {
        clear_screen(fbp,800,600,vinfo,finfo);

        if (350-c <= 0 ) {
            c = 0;
            flagShoot = 0;
            bullet_selection = 0;
        }
        
        drawPlane(40+r,100,90+r,100,fbp,vinfo,finfo);
        drawBlast(200+r,100,fbp,vinfo,finfo);
        
        drawCannon(fbp,vinfo,finfo);

        //draw bullet jika telah menembak
        if (flagShoot){
            drawBullets(c,bullet_selection-2,fbp,vinfo,finfo);
            c++;
        }

        // if(450-c == 100 && (40+r)%800 == 350-c){
        //     drawBlast((60+r)%800,100,fbp,vinfo,finfo);
        // }
        r=r+1;
        delay(10000);

        //NOTE: Belom semua sisi pesawat di cek
        
    }

    munmap(fbp, screensize);
    close(fbfd);

    while(1);

    fflush(stdout);
    fprintf(stderr, "%s.\n", strerror(errno));
    return 0;
}

