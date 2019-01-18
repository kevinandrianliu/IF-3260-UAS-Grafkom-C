#include "utilities.h"

void render_a(int x, int y, char *fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo){

}
void render_b(int x, int y, char *fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo){

}
void render_d(int x, int y, char *fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo){

}
void render_e(int x, int y, char *fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo){

}
void render_f(int x, int y, char *fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo){

}
void render_g(int x, int y, char *fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo){

}
void render_i(int x, int y, char *fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo){

}
void render_j(int x, int y, char *fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo){

}
void render_k(int x, int y, char *fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo){

}
void render_l(int x, int y, char *fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo){

}
void render_m(int x, int y, char *fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo){

}
void render_n(int x, int y, char *fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo){

}
void render_o(int x, int y, char *fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo){

}
void render_p(int x, int y, char *fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo){

}
void render_r(int x, int y, char *fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo){

}
void render_s(int x, int y, char *fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo){

}
void render_t(int x, int y, char *fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo){

}
void render_u(int x, int y, char *fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo){

}
void render_w(int x, int y, char *fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo){

}
void render_y(int x, int y, char *fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo){

}
void pixel_color(char *fbp, long int location, int b, int g, int r){
    *(fbp + location) = b;         // blue
    *(fbp + location + 1) = g;     // green
    *(fbp + location + 2) = r;     // red
    *(fbp + location + 3) = 0;
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