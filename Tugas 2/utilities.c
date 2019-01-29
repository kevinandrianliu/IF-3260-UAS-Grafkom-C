#include "utilities.h"
// Tugas 1
void render_a(int x, int y, int b, int g, int r, char *fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo){
    long int location;

    //16x20
    for (int j = 0; j < 4; j++) {
        if (j + y >= vinfo.yres)
            break;
        for (int i = 4; i < 12; i++) {
            location = (x+i+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (y+j+vinfo.yoffset) * finfo.line_length;
            pixel_color(fbp, location, b, g, r);
        }
    }
    for (int j = 8; j < 12; j++) {
        if (j + y >= vinfo.yres)
            break;
        for (int i = 4; i < 12; i++) {
            location = (x+i+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (y+j+vinfo.yoffset) * finfo.line_length;
            pixel_color(fbp, location, b, g, r);
        }
    }
    for (int j = 4; j < 20; j++){
        if (j + y >= vinfo.yres)
            break;
        for (int i = 0; i < 4; i++){
            location = (x+i+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (y+j+vinfo.yoffset) * finfo.line_length;
            pixel_color(fbp, location, b, g, r);
        }
    }
    for (int j = 4; j < 20; j++){
        if (j + y >= vinfo.yres)
            break;
        for (int i = 12; i < 16; i++){
            location = (x+i+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (y+j+vinfo.yoffset) * finfo.line_length;
            pixel_color(fbp, location, b, g, r);
        }
    }
}
void render_b(int x, int y, int b, int g, int r, char *fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo){
	    long int location;
    int xx, yy;   
    for (yy = y; yy < y+4; yy++){
        if (yy >= vinfo.yres)
            break;
        for (xx = x; xx < x+16; xx++) {
            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (yy+vinfo.yoffset) * finfo.line_length;
            pixel_color(fbp, location, b, g, r);
	    
        }
    }
    for (yy = y+4; yy < y+8; yy++){
        if (yy >= vinfo.yres)
            break;
        for (xx = x; xx < x+4; xx++) {
            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (yy+vinfo.yoffset) * finfo.line_length;
            pixel_color(fbp, location, b, g, r);
        }
	for (xx = x+16; xx < x+20; xx++) {
        if (yy >= vinfo.yres)
            break;
            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (yy+vinfo.yoffset) * finfo.line_length;
            pixel_color(fbp, location, b, g, r);
        }
    }	
    for (yy = y+8; yy < y+12; yy++){
        if (yy >= vinfo.yres)
            break;
        for (xx = x; xx < x+16; xx++) {
            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (yy+vinfo.yoffset) * finfo.line_length;
            pixel_color(fbp, location, b, g, r);
        }
    }
    for (yy = y+12; yy < y+16; yy++){
        if (yy >= vinfo.yres)
            break;
        for (xx = x; xx < x+4; xx++) {   
            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (yy+vinfo.yoffset) * finfo.line_length;
            pixel_color(fbp, location, b, g, r);
        }
	for (xx = x+16; xx < x+20; xx++) {
        if (yy >= vinfo.yres)
            break;
        location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (yy+vinfo.yoffset) * finfo.line_length;
        pixel_color(fbp, location, b, g, r);
        }
    }
    for (yy = y+16; yy < y+20; yy++){
        if (yy >= vinfo.yres)
            break;
        for (xx = x; xx < x+16; xx++) { 
            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (yy+vinfo.yoffset) * finfo.line_length;
            pixel_color(fbp, location, b, g, r);
        }
    }

}

void render_c(int x, int y, int b, int g, int r, char *fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo){
    long int location;

    for (int j = 0; j < 4; j++){
        if (j + y >= vinfo.yres)
            break;
        for (int i = 4; i < 16; i++){
            location = (x+i+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (y+j+vinfo.yoffset) * finfo.line_length;
            pixel_color(fbp, location, b, g, r);
        }
    }
    for (int j = 4; j < 16; j++){
        if (j + y >= vinfo.yres)
            break;
        for (int i = 0; i < 4; i++){
            location = (x+i+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (y+j+vinfo.yoffset) * finfo.line_length;
            pixel_color(fbp, location, b, g, r);
        }
    }
    for (int j = 16; j < 20; j++){
        if (j + y >= vinfo.yres)
            break;
        for (int i = 4; i < 16; i++){
            location = (x+i+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (y+j+vinfo.yoffset) * finfo.line_length;
            pixel_color(fbp, location, b, g, r);
        }
    }
}

void render_d(int x, int y, int b, int g, int r, char *fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo){
	    long int location;
    int xx,yy;    
    for (yy = y; yy < y+20; yy++){
        if (yy >= vinfo.yres)
            break;
        for (xx = x; xx < x+4; xx++) {
	       location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (yy+vinfo.yoffset) * finfo.line_length;
            pixel_color(fbp, location, b, g, r);
        }
    }
    for (yy = y; yy < y+4; yy++){
        if (yy >= vinfo.yres)
            break;
        for (xx = x; xx < x+12; xx++) {
	       location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (yy+vinfo.yoffset) * finfo.line_length;
            pixel_color(fbp, location, b, g, r);
        }
    }
    for (yy = y+16; yy < y+20; yy++){
        if (yy >= vinfo.yres)
            break;
        for (xx = x; xx < x+12; xx++) {
	       location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (yy+vinfo.yoffset) * finfo.line_length;
            pixel_color(fbp, location, b, g, r);
        }
    }
    for (yy = y+4; yy < y+16; yy++){
        if (yy >= vinfo.yres)
            break;
        for (xx = x+12; xx < x+16; xx++) {
	       location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (yy+vinfo.yoffset) * finfo.line_length;
            pixel_color(fbp, location, b, g, r);
        }
    }
    

}
void render_e(int x, int y, int b, int g, int r, char *fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo){
    long int location;

    for (int j = 0; j < 20; j++){
        if (j + y >= vinfo.yres)
            break;
        for (int i = 0; i < 4; i++){
            location = (x+i+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (y+j+vinfo.yoffset) * finfo.line_length;
            pixel_color(fbp, location, b, g, r);
        }
    }
    for (int i = 4; i < 16; i++){
        for (int j = 0; j < 4; j++){
            if (j + y >= vinfo.yres)
                break;
            location = (x+i+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (y+j+vinfo.yoffset) * finfo.line_length;
            pixel_color(fbp, location, b, g, r);
        }
        for (int j = 16; j < 20; j++){
            if (j + y >= vinfo.yres)
                break;
            location = (x+i+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (y+j+vinfo.yoffset) * finfo.line_length;
            pixel_color(fbp, location, b, g, r);
        }
    }
    for (int j = 8; j < 12; j++){
        if (j + y >= vinfo.yres)
            break;
        for (int i = 4; i < 12; i++){
            location = (x+i+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (y+j+vinfo.yoffset) * finfo.line_length;
            pixel_color(fbp, location, b, g, r);
        }
    }
}
void render_f(int x, int y, int b, int g, int r, char *fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo){
	long int location;
    int xx, yy;

    for (yy = y; yy < y+20; yy++){
        if (yy >= vinfo.yres)
            break;
        for (xx = x; xx < x+4; xx++) {

            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                       (yy+vinfo.yoffset) * finfo.line_length;

            pixel_color(fbp, location, b, g, r);
        }
    }

    for (yy = y; yy < y+4; yy++){
        if (yy >= vinfo.yres)
            break;
        for (xx = x; xx < x+16; xx++) {

            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                       (yy+vinfo.yoffset) * finfo.line_length;

            pixel_color(fbp, location, b, g, r);

        }
    }
    for (yy = y+8; yy < y+12; yy++){
        if (yy >= vinfo.yres)
            break;
        for (xx = x; xx < x+12; xx++) {

            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                       (yy+vinfo.yoffset) * finfo.line_length;

            pixel_color(fbp, location, b, g, r);
        }
    }

}
void render_g(int x, int y, int b, int g, int r, char *fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo){
    long int location;

    for (int j = 0; j < 4; j++){
        if (j + y >= vinfo.yres)
            break;
        for (int i = 4; i < 16; i++){
            location = (x+i+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (y+j+vinfo.yoffset) * finfo.line_length;
            pixel_color(fbp, location, b, g, r);
        }
    }
    for (int j = 4; j < 16; j++){
        if (j + y >= vinfo.yres)
            break;
        for (int i = 0; i < 4; i++){
            location = (x+i+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (y+j+vinfo.yoffset) * finfo.line_length;
            pixel_color(fbp, location, b, g, r);
        }
    }
    for (int j = 16; j < 20; j++){
        if (j + y >= vinfo.yres)
            break;
        for (int i = 4; i < 16; i++){
            location = (x+i+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (y+j+vinfo.yoffset) * finfo.line_length;
            pixel_color(fbp, location, b, g, r);
        }
    }
    for (int j = 8; j < 16; j++){
        if (j + y >= vinfo.yres)
            break;
        for (int i = 12; i < 16; i++){
            location = (x+i+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (y+j+vinfo.yoffset) * finfo.line_length;
            pixel_color(fbp, location, b, g, r);
        }
    }
    for (int j = 8; j < 12; j++){
        if (j + y >= vinfo.yres)
            break;
        for (int i = 8; i < 12; i++){
            location = (x+i+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (y+j+vinfo.yoffset) * finfo.line_length;
            pixel_color(fbp, location, b, g, r);
        }
    }
}

void render_h(int x, int y, int b, int g, int r, char *fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo){
    long int location;
    int xx, yy;

    for (yy = y; yy < y+20; yy++){
        if (yy >= vinfo.yres)
            break;
        for (xx = x; xx < x+4; xx++) {

            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                       (yy+vinfo.yoffset) * finfo.line_length;

            pixel_color(fbp, location, b, g, r);

        }
    }

    for (yy = y; yy < y+20; yy++){
        if (yy >= vinfo.yres)
            break;
        for (xx = x+12; xx < x+16; xx++) {

            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                       (yy+vinfo.yoffset) * finfo.line_length;

            pixel_color(fbp, location, b, g, r);

        }
    }

    for (yy = y+8; yy < y+12; yy++){
        if (yy >= vinfo.yres)
            break;
        for (xx = x+4; xx < x+12; xx++) {

            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                       (yy+vinfo.yoffset) * finfo.line_length;

            pixel_color(fbp, location, b, g, r);

        }
    }
}

void render_i(int x, int y, int b, int g, int r, char *fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo){
	long int location;
    int xx, yy;

    for (yy = y; yy < y+20; yy++){
        if (yy >= vinfo.yres)
            break;
        for (xx = x; xx < x+4; xx++) {

            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                       (yy+vinfo.yoffset) * finfo.line_length;

            pixel_color(fbp, location, b, g, r);

        }
    }

}
void render_j(int x, int y, int b, int g, int r, char *fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo){
    long int location;

    for (int j = 0; j < 16; j++){
        if (j + y >= vinfo.yres)
            break;
        for (int i = 12; i < 16; i++){
            location = (x+i+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (y+j+vinfo.yoffset) * finfo.line_length;
            pixel_color(fbp, location, b, g, r);
        }
    }
    for (int j = 16; j < 20; j++){
        if (j + y >= vinfo.yres)
            break;
        for (int i = 4; i < 12; i++){
            location = (x+i+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (y+j+vinfo.yoffset) * finfo.line_length;
            pixel_color(fbp, location, b, g, r);
        }
    }
    for (int j = 12; j < 16; j++){
        if (j + y >= vinfo.yres)
            break;
        for (int i = 0; i < 4; i++){
            location = (x+i+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (y+j+vinfo.yoffset) * finfo.line_length;
            pixel_color(fbp, location, b, g, r);
        }
    }
}
void render_k(int x, int y, int b, int g, int r, char *fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo){
	    long int location;
    int xx,yy;  
    for (yy = y; yy < y+20; yy++){
        if (yy >= vinfo.yres)
            break;
        for (xx = x; xx < x+4; xx++) {

            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                       (yy+vinfo.yoffset) * finfo.line_length;

            pixel_color(fbp, location, b, g, r);

        } 
    }
    for (yy = y; yy < y+4; yy++){
        if (yy >= vinfo.yres)
            break;
        for (xx = x+12; xx < x+16; xx++) {

            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                       (yy+vinfo.yoffset) * finfo.line_length;

            pixel_color(fbp, location, b, g, r);

        }
    }
    for (yy = y+4; yy < y+8; yy++){
        if (yy >= vinfo.yres)
            break;
        for (xx = x+8; xx < x+12; xx++) {

            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                       (yy+vinfo.yoffset) * finfo.line_length;

            pixel_color(fbp, location, b, g, r);

        }
    }

    for (yy = y+8; yy < y+12; yy++){
        if (yy >= vinfo.yres)
            break;
        for (xx = x; xx < x+8; xx++) {

            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                       (yy+vinfo.yoffset) * finfo.line_length;

            pixel_color(fbp, location, b, g, r);

        }
    }

    for (yy = y+12; yy < y+16; yy++){
        if (yy >= vinfo.yres)
            break;
        for (xx = x+8; xx < x+12; xx++) {

            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                       (yy+vinfo.yoffset) * finfo.line_length;

            pixel_color(fbp, location, b, g, r);

        }
    }
    for (yy = y+16; yy < y+20; yy++){
        if (yy >= vinfo.yres)
            break;
        for (xx = x+12; xx < x+16; xx++) {

            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                       (yy+vinfo.yoffset) * finfo.line_length;

            pixel_color(fbp, location, b, g, r);

        }
    }

 

}
void render_l(int x, int y, int b, int g, int r, char *fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo){
	long int location;
    int xx, yy;

    for (yy = y; yy < y+20; yy++){
        if (yy >= vinfo.yres)
            break;
        for (xx = x; xx < x+4; xx++) {

            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                       (yy+vinfo.yoffset) * finfo.line_length;

            pixel_color(fbp, location, b, g, r);

        }
    }

    for (yy = y+16; yy < y+20; yy++){
        if (yy >= vinfo.yres)
            break;
        for (xx = x; xx < x+12; xx++) {

            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                       (yy+vinfo.yoffset) * finfo.line_length;

            pixel_color(fbp, location, b, g, r);
    
        }
    }

}

void render_m(int x, int y, int b, int g, int r, char *fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo){
	    long int location;
    int xx,yy;    
    for (yy = y; yy < y+20; yy++){
        if (yy >= vinfo.yres)
            break;
        for (xx = x; xx < x+4; xx++) {
            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (yy+vinfo.yoffset) * finfo.line_length;
            pixel_color(fbp, location, b, g, r);
        }
	for (xx = x+17; xx < x+20; xx++) {
        if (yy >= vinfo.yres)
            break;
            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (yy+vinfo.yoffset) * finfo.line_length;
            pixel_color(fbp, location, b, g, r);
        }
    }
    for (yy = y+4; yy < y+8; yy++){
        if (yy >= vinfo.yres)
            break;
        for (xx = x+4; xx < x+8; xx++) {
            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (yy+vinfo.yoffset) * finfo.line_length;
            pixel_color(fbp, location, b, g, r);
        }
	for (xx = x+12; xx < x+16; xx++) {
        if (yy >= vinfo.yres)
            break;
            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (yy+vinfo.yoffset) * finfo.line_length;
            pixel_color(fbp, location, b, g, r);
        }
    }
    for (yy = y+8; yy < y+12; yy++){
        if (yy >= vinfo.yres)
            break;
        for (xx = x+8; xx < x+12; xx++) {
            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (yy+vinfo.yoffset) * finfo.line_length;
            pixel_color(fbp, location, b, g, r);
        }
    }

}
void render_n(int x, int y, int b, int g, int r, char *fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo){
	long int location;
    int xx, yy;

    for (yy = y; yy < y+20; yy++){
        if (yy >= vinfo.yres)
            break;
        for (xx = x; xx < x+4; xx++) {

            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                       (yy+vinfo.yoffset) * finfo.line_length;

            pixel_color(fbp, location, b, g, r);

        }
    }

    for (yy = y; yy < y+20; yy++){
        if (yy >= vinfo.yres)
            break;
        for (xx = x+12; xx < x+16; xx++) {

            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                       (yy+vinfo.yoffset) * finfo.line_length;

            pixel_color(fbp, location, b, g, r);

        }
    }

    for (yy = y+8; yy < y+12; yy++){
        if (yy >= vinfo.yres)
            break;
        for (xx = x+4; xx < x+8; xx++) {

            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                       (yy+vinfo.yoffset) * finfo.line_length;

            pixel_color(fbp, location, b, g, r);

        }
    }
    for (yy = y+12; yy < y+16; yy++){
        if (yy >= vinfo.yres)
            break;
        for (xx = x+8; xx < x+12; xx++) {

            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                       (yy+vinfo.yoffset) * finfo.line_length;

            pixel_color(fbp, location, b, g, r);

        }
    }


}
void render_o(int x, int y, int b, int g, int r, char *fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo){
    long int location;
    int i, j;

    //Mengikuti ukuran karakter 16x20 pixel

    for (i = 4; i < 12; i++) {
        for (j = 0; j < 4; j++) {
            if ((j + y) >= vinfo.yres)
                break;
            location = (x+i+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                               (y+j+vinfo.yoffset) * finfo.line_length;
        pixel_color(fbp, location, b, g, r);
        }
        for (j = 16; j < 20; j++) {
            if ((j + y) >= vinfo.yres)
                break;
            location = (x+i+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                               (y+j+vinfo.yoffset) * finfo.line_length;
        pixel_color(fbp, location, b, g, r);
        }
    }
    for (j=4; j<16; j++) {
        if ((j + y) >= vinfo.yres)
                break;
        for (i = 0; i < 4; i++) {
            location = (x+i+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                               (y+j+vinfo.yoffset) * finfo.line_length;
        pixel_color(fbp, location, b, g, r);
        }
        for (i = 12; i < 16; i++) {
            location = (x+i+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                               (y+j+vinfo.yoffset) * finfo.line_length;
        pixel_color(fbp, location, b, g, r);
        }
    }
}
void render_p(int x, int y, int b, int g, int r, char *fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo){
	    long int location;
    int xx, yy;

    for (yy = y; yy < y+20; yy++){
        if (yy >= vinfo.yres)
            break;
        for (xx = x; xx < x+4; xx++) {

            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                       (yy+vinfo.yoffset) * finfo.line_length;

            pixel_color(fbp, location, b, g, r);

        }
    }

    for (yy = y; yy < y+4; yy++){
        if (yy >= vinfo.yres)
            break;
        for (xx = x; xx < x+12; xx++) {

            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                       (yy+vinfo.yoffset) * finfo.line_length;

            pixel_color(fbp, location, b, g, r);

        }
    }

    for (yy = y+4; yy < y+8; yy++){
        if (yy >= vinfo.yres)
            break;
        for (xx = x+12; xx < x+16; xx++) {

            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                       (yy+vinfo.yoffset) * finfo.line_length;

            pixel_color(fbp, location, b, g, r);

        }
    }
    for (yy = y+8; yy < y+12; yy++){
        if (yy >= vinfo.yres)
            break;
        for (xx = x; xx < x+12; xx++) {

            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                       (yy+vinfo.yoffset) * finfo.line_length;

            pixel_color(fbp, location, b, g, r);

        }
    }

}
void render_r(int x, int y, int b, int g, int r, char *fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo){
	long int location;
    int xx, yy;

    for (yy = y; yy < y+20; yy++){
        if (yy >= vinfo.yres)
            break;
        for (xx = x; xx < x+4; xx++) {

            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                       (yy+vinfo.yoffset) * finfo.line_length;

            pixel_color(fbp, location, b, g, r);

        }
    }

    for (yy = y; yy < y+4; yy++){
        if (yy >= vinfo.yres)
            break;
        for (xx = x; xx < x+12; xx++) {

            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                       (yy+vinfo.yoffset) * finfo.line_length;

            pixel_color(fbp, location, b, g, r);

        }
    }

    for (yy = y+4; yy < y+8; yy++){
        if (yy >= vinfo.yres)
            break;
        for (xx = x+12; xx < x+16; xx++) {

            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                       (yy+vinfo.yoffset) * finfo.line_length;

            pixel_color(fbp, location, b, g, r);

        }
    }
    for (yy = y+8; yy < y+12; yy++){
        if (yy >= vinfo.yres)
            break;
        for (xx = x; xx < x+12; xx++) {

            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                       (yy+vinfo.yoffset) * finfo.line_length;

            pixel_color(fbp, location, b, g, r);

        }
    }
    for (yy = y+12; yy < y+16; yy++){
        if (yy >= vinfo.yres)
            break;
        for (xx = x+8; xx < x+12; xx++) {

            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                       (yy+vinfo.yoffset) * finfo.line_length;

            pixel_color(fbp, location, b, g, r);

        }
    }
    for (yy = y+16; yy < y+20; yy++){
        if (yy >= vinfo.yres)
            break;
        for (xx = x+12; xx < x+16; xx++) {

            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                       (yy+vinfo.yoffset) * finfo.line_length;

            pixel_color(fbp, location, b, g, r);

        }
    }


}
void render_s(int x, int y, int b, int g, int r, char *fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo){
    long int location;
    int i, j;

    //Mengikuti ukuran karakter 16x20 pixel

    for (j = 0; j < 4; j++) {
        if ((j + y) >= vinfo.yres)
            break;
        for (i = 4; i < 16; i++) {
            location = (x+i+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                               (y+j+vinfo.yoffset) * finfo.line_length;
        pixel_color(fbp, location, b, g, r);
        }
    }
    for (j=4; j<8; j++) {
        if ((j + y) >= vinfo.yres)
            break;
        for (i = 0; i < 4; i++) {
            location = (x+i+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                               (y+j+vinfo.yoffset) * finfo.line_length;
        pixel_color(fbp, location, b, g, r);
        }
    }
    for (j=8; j<12; j++) {
        if ((j + y) >= vinfo.yres)
            break;
        for (i = 4; i < 12; i++) {
            location = (x+i+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                               (y+j+vinfo.yoffset) * finfo.line_length;
        pixel_color(fbp, location, b, g, r);
        }
    }
    for (j=12; j<16; j++) {
        if ((j + y) >= vinfo.yres)
            break;
        for (i = 12; i < 16; i++) {
            location = (x+i+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                               (y+j+vinfo.yoffset) * finfo.line_length;
        pixel_color(fbp, location, b, g, r);
        }
    }
    for (j=16; j<20; j++) {
        if ((j + y) >= vinfo.yres)
            break;
        for (i = 0; i < 12; i++) {
            location = (x+i+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                               (y+j+vinfo.yoffset) * finfo.line_length;
        pixel_color(fbp, location, b, g, r);
        }
    }
}
void render_t(int x, int y, int b, int g, int r, char *fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo){
    long int location;
    int i, j;

    //Mengikuti ukuran karakter 16x20 pixel
    for (j = 0; j < 4; j++) {
        if ((j + y) >= vinfo.yres)
            break;
        for (i = 0; i < 12; i++) {
            location = (x+i+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                               (y+j+vinfo.yoffset) * finfo.line_length;
        pixel_color(fbp, location, b, g, r);
        }
    }
    for (j=4; j<20; j++) {
        if ((j + y) >= vinfo.yres)
            break;
        for (i = 4; i < 8; i++) {
            location = (x+i+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                               (y+j+vinfo.yoffset) * finfo.line_length;
        pixel_color(fbp, location, b, g, r);
        }
    }
}
void render_u(int x, int y, int b, int g, int r, char *fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo){
	long int location;
    int xx, yy;

    for (yy = y; yy < y+20; yy++){
        if (yy >= vinfo.yres)
            break;
        for (xx = x; xx < x+4; xx++) {

            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                       (yy+vinfo.yoffset) * finfo.line_length;

            pixel_color(fbp, location, b, g, r);

        }
    }

    for (yy = y; yy < y+20; yy++){
        if (yy >= vinfo.yres)
            break;
        for (xx = x+12; xx < x+16; xx++) {

            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                       (yy+vinfo.yoffset) * finfo.line_length;

            pixel_color(fbp, location, b, g, r);

        }
    }

    for (yy = y+16; yy < y+20; yy++){
        if (yy >= vinfo.yres)
            break;
        for (xx = x; xx < x+16; xx++) {

            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                       (yy+vinfo.yoffset) * finfo.line_length;

            pixel_color(fbp, location, b, g, r);

        }
    }

}
//draw V letter
void render_v(int x, int y, int b, int g, int r, char *fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo) {

    long int location;
    int xx, yy;

    for (yy = y; yy < y+16; yy++){
        if (yy >= vinfo.yres)
            break;
        for (xx = x; xx < x+4; xx++) {

            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                       (yy+vinfo.yoffset) * finfo.line_length;

            pixel_color(fbp, location, b, g, r);

        }
    }

    for (yy = y; yy < y+16; yy++){
        if (yy >= vinfo.yres)
            break;
        for (xx = x+12; xx < x+16; xx++) {

            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                       (yy+vinfo.yoffset) * finfo.line_length;

            pixel_color(fbp, location, b, g, r);

        }
    }

    for (yy = y+12; yy < y+16; yy++){
        if (yy >= vinfo.yres)
            break;
        for (xx = x; xx < x+16; xx++) {

            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                       (yy+vinfo.yoffset) * finfo.line_length;

            pixel_color(fbp, location, b, g, r);

        }
    }
    for (yy = y+16; yy < y+20; yy++){
        if (yy >= vinfo.yres)
            break;
        for (xx = x+4; xx < x+12; xx++) {

            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                       (yy+vinfo.yoffset) * finfo.line_length;

            pixel_color(fbp, location, b, g, r);

        }
    }

}
void render_w(int x, int y, int b, int g, int r, char *fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo){
    long int location;
    int i, j;

    //Mengikuti ukuran karakter 20x20 pixel

    for (j=0; j<16; j++) {
        for (i = 0; i < 4; i++) {
            location = (x+i+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                               (y+j+vinfo.yoffset) * finfo.line_length;
        pixel_color(fbp, location, b, g, r);
        }
        for (i = 16; i < 20; i++) {
            location = (x+i+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                               (y+j+vinfo.yoffset) * finfo.line_length;
        pixel_color(fbp, location, b, g, r);
        }
    }
    for (j = 8; j < 16; j++) {
        for (i = 8; i < 12; i++) {
            location = (x+i+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                               (y+j+vinfo.yoffset) * finfo.line_length;
        pixel_color(fbp, location, b, g, r);
        }
    }
    for (j = 16; j < 20; j++) {
        for (i = 4; i < 8; i++) {
            location = (x+i+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                               (y+j+vinfo.yoffset) * finfo.line_length;
        pixel_color(fbp, location, b, g, r);
        }
    }
    for (j = 16; j < 20; j++) {
        for (i = 12; i < 16; i++) {
            location = (x+i+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                               (y+j+vinfo.yoffset) * finfo.line_length;
        pixel_color(fbp, location, b, g, r);
        }
    }
}
void render_y(int x, int y, int b, int g, int r, char *fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo){
	long int location;
    int xx, yy;

    for (yy = y; yy < y+12; yy++){
        if (yy >= vinfo.yres)
            break;
        for (xx = x; xx < x+4; xx++) {

            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                       (yy+vinfo.yoffset) * finfo.line_length;

            pixel_color(fbp, location, b, g, r);

        }
    }

    for (yy = y; yy < y+12; yy++){
        if (yy >= vinfo.yres)
            break;
        for (xx = x+8; xx < x+12; xx++) {

            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                       (yy+vinfo.yoffset) * finfo.line_length;

            pixel_color(fbp, location, b, g, r);

        }
    }

    for (yy = y+8; yy < y+12; yy++){
        if (yy >= vinfo.yres)
            break;
        for (xx = x; xx < x+12; xx++) {

            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                       (yy+vinfo.yoffset) * finfo.line_length;

            pixel_color(fbp, location, b, g, r);

        }
    }
    for (yy = y+8; yy < y+20; yy++){
        if (yy >= vinfo.yres)
            break;
        for (xx = x+4; xx < x+8; xx++) {

            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                       (yy+vinfo.yoffset) * finfo.line_length;

            pixel_color(fbp, location, b, g, r);

        }
    }

}

void render_kotak(int x, int y, int b, int g, int r, char *fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo){
	long int location;
	int xx, yy;
	for (yy = y+4; yy < y+12; yy++){
        if (yy >= vinfo.yres)
            break;
        for (xx = x+4; xx < x+12; xx++) {

            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                       (yy+vinfo.yoffset) * finfo.line_length;

            pixel_color(fbp, location, b, g, r);

        }
    }
}

void render_strip(int x, int y, int b, int g, int r, char *fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo){
	long int location;
	int xx, yy;
	for (yy = y+8; yy < y+12; yy++){
        if (yy >= vinfo.yres)
            break;
        for (xx = x+4; xx < x+12; xx++) {

            location = (xx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                       (yy+vinfo.yoffset) * finfo.line_length;

            pixel_color(fbp, location, b, g, r);

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

// Tugas 2
void bresenham(int x0, int y0, int x1, int y1, char colorful, char * framebuffer, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo){
    if (x0 > x1){
        int x_temp;
        int y_temp;

        x_temp = x0;
        y_temp = y0;
        x0 = x1;
        y0 = y1;
        x1 = x_temp;
        y1 = y_temp;
    }

    if ((x1 - x0) == 0){
        for (int y = y0; y <= y1; y++){
            long int mem_location = (x1 + vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (y + vinfo.yoffset) * finfo.line_length;

            if (colorful){
                pixel_color(framebuffer,mem_location,(x1 % 255),(y % 255), ((y-x1) % 255));
            } else {
                pixel_color(framebuffer,mem_location,255,255,255);
            }
        }
    } else {
        float gradien = (y1 - y0)/(x1 - x0);
        if ((abs(gradien) >= 0) && (abs(gradien) <= 1)){
            int y = y0;
            int eps = 0;

            if (y1 >= y0){
                int dx = x1 - x0;
                int dy = y1 - y0;
                for (int x = x0; x <= x1; x++){
                    long int mem_location = (x + vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (y + vinfo.yoffset) * finfo.line_length;

                    if (colorful){
                        pixel_color(framebuffer,mem_location,(x % 255),(y % 255), ((y-x) % 255));
                    } else {
                        pixel_color(framebuffer,mem_location,255,255,255);
                    }

                    eps += dy;
                    if ((eps << 1) >= dx){
                        y++;
                        eps -= dx;
                    }
                }
            } else {    //y1 < y0
                int dx = x1 - x0;
                int dy = y0 - y1;
                for (int x = x0; x <= x1; x++){
                    long int mem_location = (x + vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (y + vinfo.yoffset) * finfo.line_length;

                    if (colorful){
                        pixel_color(framebuffer,mem_location,(x % 255),(y % 255), ((y-x) % 255));
                    } else {
                        pixel_color(framebuffer,mem_location,255,255,255);
                    }

                    eps += dy;
                    if ((eps << 1) >= dx){
                        y--;
                        eps -= dx;
                    }
                }
            }
        } else {
            int x = x0;
            int eps = 0;

            if (y1 >= y0){
                int dx = x1 - x0;
                int dy = y1 - y0;

                for (int y = y0; y <= y1; y++){
                    long int mem_location = (x + vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (y + vinfo.yoffset) * finfo.line_length;

                    if (colorful){
                        pixel_color(framebuffer,mem_location,(x % 255),(y % 255), ((y-x) % 255));
                    } else {
                        pixel_color(framebuffer,mem_location,255,255,255);
                    }

                    eps += dx;
                    if ((eps << 1) >= dy){
                        x++;
                        eps -= dy;
                    }
                }
            } else {    //y1 < y0
                int dx = x1 - x0;
                int dy = y0 - y1;

                for (int y = y0; y >= y1; y--){
                    long int mem_location = (x + vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (y + vinfo.yoffset) * finfo.line_length;

                    if (colorful){
                        pixel_color(framebuffer,mem_location,(x % 255),(y % 255), ((y-x) % 255));
                    } else {
                        pixel_color(framebuffer,mem_location,255,255,255);
                    }

                    eps += dx;
                    if ((eps << 1) >= dy){
                        x++;
                        eps -= dy;
                    }
                }
            }
        }
    }
}

char checkIfIntersect(int x01, int y01, int x02, int y02, int x11, int y11, int x12, int y12){
    float delta_x0 = (float)(x01 - x02);
    float delta_x1 = (float)(x11 - x12);
    float delta_y0 = (float)(y01 - y02);
    float delta_y1 = (float)(y11 - y12);

    float c = delta_x0 * delta_y1 - delta_x1 * delta_y0;

    if (abs(c) < 0.01){
        return FALSE;
    } else {
        float a = (float) (x01 * y02 - y01 * x02);
        float b = (float) (x11 * y12 - y11 * x12);

        float x = (a * delta_x1 - b * delta_x0) / c;
        float y = (a * delta_y1 - b * delta_y0) / c;

        if ((x >= (float)min(x11,x12)) && (x <= (float)max(x11,x12)) && (y >= (float)min(y11,y12)) && (y <= (float)max(y11,y12)))
            if ((x >= (float)min(x01,x02)) && (x <= (float)max(x01,x02)) && (y >= (float)min(y01,y02)) && (y <= (float)max(y01,y02)))
            return TRUE;
    }

    return FALSE;
}