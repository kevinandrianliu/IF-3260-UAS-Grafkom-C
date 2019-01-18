#include "utilities.h"

void render_a(int x, int y, char *fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo){
    long int location;

    //16x20
    for (int j = 0; j < 4; j++) {
        for (int i = 4; i < 12; i++) {
            location = (x+i+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (y+j+vinfo.yoffset) * finfo.line_length;
            pixel_color(fbp, location, 255, 255, 255);
        }
    }
    for (int j = 8; j < 12; j++) {
        for (int i = 4; i < 12; i++) {
            location = (x+i+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (y+j+vinfo.yoffset) * finfo.line_length;
            pixel_color(fbp, location, 255, 255, 255);
        }
    }
    for (int i = 0; i < 4; i++){
        for (int j = 4; j < 20; j++){
            location = (x+i+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (y+j+vinfo.yoffset) * finfo.line_length;
            pixel_color(fbp, location, 255, 255, 255);
        }
    }
    for (int i = 12; i < 16; i++){
        for (int j = 4; j < 20; j++){
            location = (x+i+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (y+j+vinfo.yoffset) * finfo.line_length;
            pixel_color(fbp, location, 255, 255, 255);
        }
    }
}
void render_b(int x, int y, char *fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo){
	    long int location;
    int xx, yy;   
    for (yy = y; yy < y+4; yy++){
        for (xx = x; xx < x+15; xx++) {
            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (yy+vinfo.yoffset) * finfo.line_length;
            pixel_color(fbp, location, 255, 255, 255);
	    
        }
    }
    for (yy = y+4; yy < y+8; yy++){
        for (xx = x; xx < x+5; xx++) {
            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (yy+vinfo.yoffset) * finfo.line_length;
            pixel_color(fbp, location, 255, 255, 255);
        }
	for (xx = x+16; xx < x+20; xx++) {
            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (yy+vinfo.yoffset) * finfo.line_length;
            pixel_color(fbp, location, 255, 255, 255);
        }
    }	
    for (yy = y+8; yy < y+12; yy++){
        for (xx = x; xx < x+15; xx++) {
            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (yy+vinfo.yoffset) * finfo.line_length;
            pixel_color(fbp, location, 255, 255, 255);
        }
    }
    for (yy = y+12; yy < y+16; yy++){
        for (xx = x; xx < x+5; xx++) {   
            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (yy+vinfo.yoffset) * finfo.line_length;
            pixel_color(fbp, location, 255, 255, 255);
        }
	for (xx = x+16; xx < x+20; xx++) {
            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (yy+vinfo.yoffset) * finfo.line_length;
            pixel_color(fbp, location, 255, 255, 255);
        }
    }
    for (yy = y+16; yy < y+20; yy++){
        for (xx = x; xx < x+15; xx++) { 
            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (yy+vinfo.yoffset) * finfo.line_length;
            pixel_color(fbp, location, 255, 255, 255);
        }
    }

}
void render_d(int x, int y, char *fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo){
	    long int location;
    int xx,yy;    
    for (yy = y; yy < y+4; yy++){
        for (xx = x; xx < x+15; xx++) {
	       location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (yy+vinfo.yoffset) * finfo.line_length;
            pixel_color(fbp, location, 255, 255, 255);
        }
    }
    for (yy = y+4; yy < y+8; yy++){
        for (xx = x; xx < x+5; xx++) {
            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (yy+vinfo.yoffset) * finfo.line_length;
            pixel_color(fbp, location, 255, 255, 255);
        }
	for (xx = x+16; xx < x+20; xx++) {
            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (yy+vinfo.yoffset) * finfo.line_length;
            pixel_color(fbp, location, 255, 255, 255);
        }
    }	
    for (yy = y+8; yy < y+12; yy++){
        for (xx = x; xx < x+5; xx++) {
            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (yy+vinfo.yoffset) * finfo.line_length;
            pixel_color(fbp, location, 255, 255, 255);
        }
	for (xx = x+16; xx < x+20; xx++) {
            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (yy+vinfo.yoffset) * finfo.line_length;
            pixel_color(fbp, location, 255, 255, 255);
        }
    }
    for (yy = y+12; yy < y+16; yy++){
        for (xx = x; xx < x+5; xx++) {   
            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (yy+vinfo.yoffset) * finfo.line_length;
            pixel_color(fbp, location, 255, 255, 255);
        }
	for (xx = x+16; xx < x+20; xx++) {
            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (yy+vinfo.yoffset) * finfo.line_length;
            pixel_color(fbp, location, 255, 255, 255);
        }
    }
    for (yy = y+16; yy < y+20; yy++){
        for (xx = x; xx < x+15; xx++) { 
            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (yy+vinfo.yoffset) * finfo.line_length;
            pixel_color(fbp, location, 255, 255, 255);
        }
    }

}
void render_e(int x, int y, char *fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo){
    long int location;

    for (int j = 0; j < 20; j++){
        for (int i = 0; i < 4; i++){
            location = (x+i+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (y+j+vinfo.yoffset) * finfo.line_length;
            pixel_color(fbp, location, 255, 255, 255);
        }
    }
    for (int i = 4; i < 16; i++){
        for (int j = 0; j < 4; j++){
            location = (x+i+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (y+j+vinfo.yoffset) * finfo.line_length;
            pixel_color(fbp, location, 255, 255, 255);
        }
        for (int j = 16; j < 20; j++){
            location = (x+i+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (y+j+vinfo.yoffset) * finfo.line_length;
            pixel_color(fbp, location, 255, 255, 255);
        }
    }
    for (int i = 4; i < 12; i++){
        for (int j = 8; j < 12; j++){
            location = (x+i+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (y+j+vinfo.yoffset) * finfo.line_length;
            pixel_color(fbp, location, 255, 255, 255);
        }
    }
}
void render_f(int x, int y, char *fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo){
	long int location;
    int xx, yy;

    for (yy = y; yy < y+20; yy++)
        for (xx = x; xx < x+4; xx++) {

            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                       (yy+vinfo.yoffset) * finfo.line_length;

            pixel_color(fbp, location, 255, 255, 255);
        }

    for (yy = y; yy < y+4; yy++)
        for (xx = x; xx < x+16; xx++) {

            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                       (yy+vinfo.yoffset) * finfo.line_length;

            pixel_color(fbp, location, 255, 255, 255);

        }
    for (yy = y+8; yy < y+12; yy++)
        for (xx = x; xx < x+12; xx++) {

            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                       (yy+vinfo.yoffset) * finfo.line_length;

            pixel_color(fbp, location, 255, 255, 255);
        }

}
void render_g(int x, int y, char *fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo){
    long int location;

    for (int j = 0; j < 4; j++){
        for (int i = 4; i < 16; i++){
            location = (x+i+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (y+j+vinfo.yoffset) * finfo.line_length;
            pixel_color(fbp, location, 255, 255, 255);
        }
    }
    for (int j = 4; j < 16; j++){
        for (int i = 0; i < 4; i++){
            location = (x+i+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (y+j+vinfo.yoffset) * finfo.line_length;
            pixel_color(fbp, location, 255, 255, 255);
        }
    }
    for (int j = 16; j < 20; j++){
        for (int i = 4; i < 16; i++){
            location = (x+i+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (y+j+vinfo.yoffset) * finfo.line_length;
            pixel_color(fbp, location, 255, 255, 255);
        }
    }
    for (int j = 8; j < 16; j++){
        for (int i = 12; i < 16; i++){
            location = (x+i+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (y+j+vinfo.yoffset) * finfo.line_length;
            pixel_color(fbp, location, 255, 255, 255);
        }
    }
    for (int j = 8; j < 12; j++){
        for (int i = 8; i < 12; i++){
            location = (x+i+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (y+j+vinfo.yoffset) * finfo.line_length;
            pixel_color(fbp, location, 255, 255, 255);
        }
    }
}
void render_i(int x, int y, char *fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo){
	long int location;
    int xx, yy;

    for (yy = y; yy < y+20; yy++)
        for (xx = x; xx < x+4; xx++) {

            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                       (yy+vinfo.yoffset) * finfo.line_length;

            pixel_color(fbp, location, 255, 255, 255);

        }

}
void render_j(int x, int y, char *fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo){
    long int location;

    for (int j = 0; j < 16; j++){
        for (int i = 12; i < 16; i++){
            location = (x+i+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (y+j+vinfo.yoffset) * finfo.line_length;
            pixel_color(fbp, location, 255, 255, 255);
        }
    }
    for (int j = 16; j < 20; j++){
        for (int i = 4; i < 12; i++){
            location = (x+i+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (y+j+vinfo.yoffset) * finfo.line_length;
            pixel_color(fbp, location, 255, 255, 255);
        }
    }
    for (int j = 12; j < 16; j++){
        for (int i = 0; i < 4; i++){
            location = (x+i+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (y+j+vinfo.yoffset) * finfo.line_length;
            pixel_color(fbp, location, 255, 255, 255);
        }
    }
}
void render_k(int x, int y, char *fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo){
	    long int location;
    int xx,yy;    
    for (yy = y; yy < y+4; yy++){
        for (xx = x; xx < x+5; xx++) {
            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (yy+vinfo.yoffset) * finfo.line_length;
            pixel_color(fbp, location, 255, 255, 255);
        }
	for (xx = x+16; xx < x+20; xx++) {
            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (yy+vinfo.yoffset) * finfo.line_length;
            pixel_color(fbp, location, 255, 255, 255);
        }
    }
    for (yy = y+4; yy < y+8; yy++){
        for (xx = x; xx < x+5; xx++) {
            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (yy+vinfo.yoffset) * finfo.line_length;
            pixel_color(fbp, location, 255, 255, 255);
        }
	for (xx = x+12; xx < x+16; xx++) {
            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (yy+vinfo.yoffset) * finfo.line_length;
            pixel_color(fbp, location, 255, 255, 255);
        }
    }	
    for (yy = y+8; yy < y+12; yy++){
        for (xx = x; xx < x+10; xx++) {
            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (yy+vinfo.yoffset) * finfo.line_length;
            pixel_color(fbp, location, 255, 255, 255);
        }
    }
    for (yy = y+12; yy < y+16; yy++){
        for (xx = x; xx < x+5; xx++) {
            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (yy+vinfo.yoffset) * finfo.line_length;
            pixel_color(fbp, location, 255, 255, 255);
        }
	for (xx = x+12; xx < x+16; xx++) {
            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (yy+vinfo.yoffset) * finfo.line_length;
            pixel_color(fbp, location, 255, 255, 255);
        }
    }
    for (yy = y+16; yy < y+20; yy++){
        for (xx = x; xx < x+5; xx++) {
            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (yy+vinfo.yoffset) * finfo.line_length;
            pixel_color(fbp, location, 255, 255, 255);
        }
	for (xx = x+16; xx < x+20; xx++) {
            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (yy+vinfo.yoffset) * finfo.line_length;
            pixel_color(fbp, location, 255, 255, 255);
        }
    }

}
void render_l(int x, int y, char *fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo){
	long int location;
    int xx, yy;

    for (yy = y; yy < y+20; yy++)
        for (xx = x; xx < x+4; xx++) {

            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                       (yy+vinfo.yoffset) * finfo.line_length;

            pixel_color(fbp, location, 255, 255, 255);

        }

    for (yy = y+16; yy < y+20; yy++)
        for (xx = x; xx < x+12; xx++) {

            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                       (yy+vinfo.yoffset) * finfo.line_length;

            pixel_color(fbp, location, 255, 255, 255);
    
        }

}

void render_m(int x, int y, char *fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo){
	    long int location;
    int xx,yy;    
    for (yy = y; yy < y+20; yy++){
        for (xx = x; xx < x+4; xx++) {
            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (yy+vinfo.yoffset) * finfo.line_length;
            pixel_color(fbp, location, 255, 255, 255);
        }
	for (xx = x+17; xx < x+20; xx++) {
            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (yy+vinfo.yoffset) * finfo.line_length;
            pixel_color(fbp, location, 255, 255, 255);
        }
    }
    for (yy = y+4; yy < y+8; yy++){
        for (xx = x+4; xx < x+8; xx++) {
            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (yy+vinfo.yoffset) * finfo.line_length;
            pixel_color(fbp, location, 255, 255, 255);
        }
	for (xx = x+12; xx < x+16; xx++) {
            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (yy+vinfo.yoffset) * finfo.line_length;
            pixel_color(fbp, location, 255, 255, 255);
        }
    }
    for (yy = y+8; yy < y+12; yy++){
        for (xx = x+8; xx < x+12; xx++) {
            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (yy+vinfo.yoffset) * finfo.line_length;
            pixel_color(fbp, location, 255, 255, 255);
        }
    }

}
void render_n(int x, int y, char *fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo){
	long int location;
    int xx, yy;

    for (yy = y; yy < y+20; yy++)
        for (xx = x; xx < x+4; xx++) {

            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                       (yy+vinfo.yoffset) * finfo.line_length;

            pixel_color(fbp, location, 255, 255, 255);

        }

    for (yy = y; yy < y+20; yy++)
        for (xx = x+12; xx < x+16; xx++) {

            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                       (yy+vinfo.yoffset) * finfo.line_length;

            pixel_color(fbp, location, 255, 255, 255);

        }

    for (yy = y+8; yy < y+12; yy++){
        for (xx = x+4; xx < x+8; xx++) {

            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                       (yy+vinfo.yoffset) * finfo.line_length;

            pixel_color(fbp, location, 255, 255, 255);

        }
    }
    for (yy = y+12; yy < y+16; yy++){
        for (xx = x+8; xx < x+12; xx++) {

            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                       (yy+vinfo.yoffset) * finfo.line_length;

            pixel_color(fbp, location, 255, 255, 255);

        }
    }


}
void render_o(int x, int y, char *fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo){

}
void render_p(int x, int y, char *fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo){
	    long int location;
    int xx, yy;

    for (yy = y; yy < y+20; yy++)
        for (xx = x; xx < x+4; xx++) {

            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                       (yy+vinfo.yoffset) * finfo.line_length;

            pixel_color(fbp, location, 255, 255, 255);

        }

    for (yy = y; yy < y+4; yy++)
        for (xx = x; xx < x+12; xx++) {

            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                       (yy+vinfo.yoffset) * finfo.line_length;

            pixel_color(fbp, location, 255, 255, 255);

        }

    for (yy = y+4; yy < y+8; yy++){
        for (xx = x+12; xx < x+16; xx++) {

            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                       (yy+vinfo.yoffset) * finfo.line_length;

            pixel_color(fbp, location, 255, 255, 255);

        }
    }
    for (yy = y+8; yy < y+12; yy++){
        for (xx = x; xx < x+12; xx++) {

            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                       (yy+vinfo.yoffset) * finfo.line_length;

            pixel_color(fbp, location, 255, 255, 255);

        }
    }

}
void render_r(int x, int y, char *fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo){
	long int location;
    int xx, yy;

    for (yy = y; yy < y+20; yy++)
        for (xx = x; xx < x+4; xx++) {

            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                       (yy+vinfo.yoffset) * finfo.line_length;

            pixel_color(fbp, location, 255, 255, 255);

        }

    for (yy = y; yy < y+4; yy++)
        for (xx = x; xx < x+12; xx++) {

            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                       (yy+vinfo.yoffset) * finfo.line_length;

            pixel_color(fbp, location, 255, 255, 255);

        }

    for (yy = y+4; yy < y+8; yy++){
        for (xx = x+12; xx < x+16; xx++) {

            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                       (yy+vinfo.yoffset) * finfo.line_length;

            pixel_color(fbp, location, 255, 255, 255);

        }
    }
    for (yy = y+8; yy < y+12; yy++){
        for (xx = x; xx < x+12; xx++) {

            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                       (yy+vinfo.yoffset) * finfo.line_length;

            pixel_color(fbp, location, 255, 255, 255);

        }
    }
    for (yy = y+12; yy < y+16; yy++){
        for (xx = x+8; xx < x+12; xx++) {

            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                       (yy+vinfo.yoffset) * finfo.line_length;

            pixel_color(fbp, location, 255, 255, 255);

        }
    }
    for (yy = y+16; yy < y+20; yy++){
        for (xx = x+12; xx < x+16; xx++) {

            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                       (yy+vinfo.yoffset) * finfo.line_length;

            pixel_color(fbp, location, 255, 255, 255);

        }
    }


}
void render_s(int x, int y, char *fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo){

}
void render_t(int x, int y, char *fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo){

}
void render_u(int x, int y, char *fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo){
	long int location;
    int xx, yy;

    for (yy = y; yy < y+20; yy++)
        for (xx = x; xx < x+4; xx++) {

            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                       (yy+vinfo.yoffset) * finfo.line_length;

            pixel_color(fbp, location, 255, 255, 255);

        }

    for (yy = y; yy < y+20; yy++)
        for (xx = x+12; xx < x+16; xx++) {

            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                       (yy+vinfo.yoffset) * finfo.line_length;

            pixel_color(fbp, location, 255, 255, 255);

        }

    for (yy = y+16; yy < y+20; yy++)
        for (xx = x; xx < x+16; xx++) {

            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                       (yy+vinfo.yoffset) * finfo.line_length;

            pixel_color(fbp, location, 255, 255, 255);

        }

}
//draw V letter
void render_v(int x, int y, char *fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo) {

    long int location;
    int xx, yy;

    for (yy = y; yy < y+16; yy++)
        for (xx = x; xx < x+4; xx++) {

            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                       (yy+vinfo.yoffset) * finfo.line_length;

            pixel_color(fbp, location, 255, 255, 255);

        }

    for (yy = y; yy < y+16; yy++)
        for (xx = x+12; xx < x+16; xx++) {

            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                       (yy+vinfo.yoffset) * finfo.line_length;

            pixel_color(fbp, location, 255, 255, 255);

        }

    for (yy = y+12; yy < y+16; yy++){
        for (xx = x; xx < x+16; xx++) {

            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                       (yy+vinfo.yoffset) * finfo.line_length;

            pixel_color(fbp, location, 255, 255, 255);

        }
    }
    for (yy = y+16; yy < y+20; yy++){
        for (xx = x+4; xx < x+12; xx++) {

            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                       (yy+vinfo.yoffset) * finfo.line_length;

            pixel_color(fbp, location, 255, 255, 255);

        }
    }

}
void render_w(int x, int y, char *fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo){

}
void render_y(int x, int y, char *fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo){
	long int location;
    int xx, yy;

    for (yy = y; yy < y+12; yy++)
        for (xx = x; xx < x+4; xx++) {

            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                       (yy+vinfo.yoffset) * finfo.line_length;

            pixel_color(fbp, location, 255, 255, 255);

        }

    for (yy = y; yy < y+12; yy++)
        for (xx = x+8; xx < x+12; xx++) {

            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                       (yy+vinfo.yoffset) * finfo.line_length;

            pixel_color(fbp, location, 255, 255, 255);

        }

    for (yy = y+8; yy < y+12; yy++){
        for (xx = x; xx < x+12; xx++) {

            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                       (yy+vinfo.yoffset) * finfo.line_length;

            pixel_color(fbp, location, 255, 255, 255);

        }
    }
    for (yy = y+8; yy < y+20; yy++){
        for (xx = x+4; xx < x+8; xx++) {

            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                       (yy+vinfo.yoffset) * finfo.line_length;

            pixel_color(fbp, location, 255, 255, 255);

        }
    }

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