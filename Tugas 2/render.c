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
    bresenham(335,445,353,463,0,fbp,vinfo,finfo);
    bresenham(345,435,367,457,0,fbp,vinfo,finfo);
    bresenham(335,445,345,435,0,fbp,vinfo,finfo);
    
    //bresenham(370-c2,430-c2*2,360-c2,410-c2*2,TRUE,fbp,vinfo,finfo);
    bresenham(322,502,326,506,0,fbp,vinfo,finfo);
    //bresenham(375,445,367,437,0,fbp,vinfo,finfo);
    //bresenham(375,425,365,435,0,fbp,vinfo,finfo);

    //bresenham(400+c3,460-c3*3,410+c3,430-c3*3,TRUE,fbp,vinfo,finfo);
    /*bresenham(395,465,403,433,0,fbp,vinfo,finfo);
    bresenham(405,455,417,427,0,fbp,vinfo,finfo);
    bresenham(405,455,395,465,0,fbp,vinfo,finfo);*/
		
    //bresenham(430+c2,430-c2*2,440+c2,410-c2*2,TRUE,fbp,vinfo,finfo);
    /*bresenham(425,435,433,413,0,fbp,vinfo,finfo);
    bresenham(435,425,447,407,0,fbp,vinfo,finfo);
    bresenham(425,435,435,425,0,fbp,vinfo,finfo);*/

    //bresenham(450+c,450-c,440+c,460-c,TRUE,fbp,vinfo,finfo);
    /*bresenham(445,455,433,463,0,fbp,vinfo,finfo);
    bresenham(455,445,447,457,0,fbp,vinfo,finfo);
    bresenham(445,455,455,445,0,fbp,vinfo,finfo);*/
    halfcircleBres(400,530,80,fbp,vinfo,finfo);
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

    int c = 0;
    int c2 = 0; 
    int c3 = 0;
    int r = 0;

    while (1) {

		clear_screen(fbp,800,600,vinfo,finfo);

		if (350-c <= 0) {
			c = 0;
		}
		if (410-c2*2 <= 0) {
			c2 = 0;
		}
		if (430-c3*3 <= 0) {
			c3 = 0;
		}
		
		drawPlane(40+r,100,90+r,100,fbp,vinfo,finfo);
		drawBlast(200+r,100,fbp,vinfo,finfo);


		bresenham(350-c,450-c,360-c,460-c,TRUE,fbp,vinfo,finfo);
		bresenham(450+c,450-c,440+c,460-c,TRUE,fbp,vinfo,finfo);

		bresenham(370-c2,430-c2*2,360-c2,410-c2*2,TRUE,fbp,vinfo,finfo);
		bresenham(430+c2,430-c2*2,440+c2,410-c2*2,TRUE,fbp,vinfo,finfo);

		bresenham(400+c3,460-c3*3,410+c3,430-c3*3,TRUE,fbp,vinfo,finfo);

		drawCannon(fbp,vinfo,finfo);
		c++; c2++; c3++;
		r=r+1;
		delay(10000);
    }

    munmap(fbp, screensize);
    close(fbfd);

    return 0;
}

