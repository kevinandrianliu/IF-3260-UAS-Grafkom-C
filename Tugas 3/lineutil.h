#ifndef __LINEUTIL_H__
#define __LINEUTIL_H__

#include <linux/fb.h>

void bresenham(int x0, int y0, int x1, int y1, char colorful, char * framebuffer, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo);
char checkIfIntersect(int x01, int y01, int x02, int y02, int x11, int y11, int x12, int y12);
void putpixel(int x, int y, char * framebuffer, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo);

void drawCircle(int xc, int yc, int x, int y, char * framebuffer, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo);
void halfcircleBres(int xc, int yc, int r, char * framebuffer, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo);

void drawPlane(int x0, int y0, int x1, int y1, char * fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo);
void drawBlast(int x0, int y0, char * fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo);
void drawCannon(char * fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo);
void drawStar(int x0, int y0, char * fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo);
void drawBullets(int offset, char selection, char * fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo);

char checkIfShot(int star_offset, int plane_offset, int selection);

void rasterScan(int x_min, int y_min, int x_max, int y_max, char colorful, char * fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo);
char checkPixelAround(int x, int y, char * fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo);
#endif