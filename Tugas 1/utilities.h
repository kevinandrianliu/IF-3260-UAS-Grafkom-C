#ifndef __UTILITIES_H__
#define __UTILITIES_H__

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <linux/fb.h>
#include <sys/mman.h>
#include <sys/ioctl.h>

void render_a(int x, int y, int b, int g, int r, char *fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo);
void render_b(int x, int y, int b, int g, int r, char *fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo);
void render_c(int x, int y, int b, int g, int r, char *fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo);
void render_d(int x, int y, int b, int g, int r, char *fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo);
void render_e(int x, int y, int b, int g, int r, char *fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo);
void render_f(int x, int y, int b, int g, int r, char *fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo);
void render_g(int x, int y, int b, int g, int r, char *fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo);
void render_h(int x, int y, int b, int g, int r, char *fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo);
void render_i(int x, int y, int b, int g, int r, char *fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo);
void render_j(int x, int y, int b, int g, int r, char *fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo);
void render_k(int x, int y, int b, int g, int r, char *fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo);
void render_l(int x, int y, int b, int g, int r, char *fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo);
void render_m(int x, int y, int b, int g, int r, char *fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo);
void render_n(int x, int y, int b, int g, int r, char *fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo);
void render_o(int x, int y, int b, int g, int r, char *fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo);
void render_p(int x, int y, int b, int g, int r, char *fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo);
void render_r(int x, int y, int b, int g, int r, char *fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo);
void render_s(int x, int y, int b, int g, int r, char *fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo);
void render_t(int x, int y, int b, int g, int r, char *fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo);
void render_u(int x, int y, int b, int g, int r, char *fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo);
void render_v(int x, int y, int b, int g, int r, char *fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo);
void render_w(int x, int y, int b, int g, int r, char *fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo);
void render_y(int x, int y, int b, int g, int r, char *fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo);
void render_kotak(int x, int y, int b, int g, int r, char *fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo);
void render_strip(int x, int y, int b, int g, int r, char *fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo);
void pixel_color(char *fbp, long int location, int b, int g, int r);
void clear_screen(char * framebuffer, unsigned int x_size, unsigned int y_size, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo);

#endif
