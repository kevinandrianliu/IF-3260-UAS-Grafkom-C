#include <stdlib.h>
#include <time.h>
#include "lineutil.h"
#include "utilities.h"

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
    //rasterScan(x0-30,y0-15,x1+25,y1+41,TRUE,fbp,vinfo,finfo);
    //rasterScan(x0-15,y1-10,x1-10,y1+13,TRUE,fbp,vinfo,finfo);
}

void drawPlanePiece1(int x0, int y0, int x1, int y1, char * fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo){
    
    bresenham(x0+35,y0,x1,y1,0,fbp,vinfo,finfo);//lurus atas
    bresenham(x0+50,y0+26,x1   ,y1+26,0,fbp,vinfo,finfo);//lurus bawah
    bresenham(x0+52,y0+11,x1+23,y1+11,0,fbp,vinfo,finfo);//lurus tengah
    bresenham(x0+52,y0+11,x1-15,y1   ,0,fbp,vinfo,finfo);//runcing
    bresenham(x0+50,y0+26,x1+25,y1+13,0,fbp,vinfo,finfo);//runcing
    bresenham(x0+50,y0   ,x1+25,y1+13,0,fbp,vinfo,finfo);//runcing
    bresenham(x0+50,y0+30,x0+35,y0,0,fbp,vinfo,finfo);//runcing
    
}

void drawPlanePiece2(int x0, int y0, int x1, int y1, char * fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo){
    bresenham(x0,y0,x1,y1,0,fbp,vinfo,finfo);//lurus atas
    bresenham(x0-9 ,y0+26,x1-47,y1+26,0,fbp,vinfo,finfo);//lurus bawah
    bresenham(x0+25,y0+26,x1   ,y1+26,0,fbp,vinfo,finfo);//lurus bawah
    bresenham(x0,y0,x0-9,y0+26,0,fbp,vinfo,finfo);//
    bresenham(x1,y1,x1,y1+26,0,fbp,vinfo,finfo);//
    bresenham(x0+10,y0+15,x1-10,y1+15,0,fbp,vinfo,finfo);//tambahan bawah
    bresenham(x0+9,y0+15,x1-50,y1+41,0,fbp,vinfo,finfo);//sayap
    bresenham(x0+40,y0+15,x1-50,y1+41,0,fbp,vinfo,finfo);//sayap
}
void drawPlanePiece3(int x0, int y0, int x1, int y1, char * fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo){
    bresenham(x0   ,y0   ,x0-10,y0+25,0,fbp,vinfo,finfo);//ekor
    bresenham(x0   ,y0   ,x1-80,y1-15,0,fbp,vinfo,finfo);//ekor
    bresenham(x0-10,y0+25,x1-80,y1-15,0,fbp,vinfo,finfo);//ekor
}

void drawBlast(int x0, int y0, int r, char * fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo){

	int outert = 51;
	int outerd = 39;
	int outerx = 35;
	int innerl = 21;
	int inners = 8;
	int i;
	for (i = 0; i <= r; i++) {
		int ott = i;
		int otd = outerd*i/outert;
		int otx = outerx*i/outert;
		int inl = innerl*i/outert;
		int ins = inners*i/outert;

		bresenham(x0 - ins, y0 - inl, x0, y0 - ott, TRUE, fbp, vinfo, finfo); //Atas
		bresenham(x0 + ins, y0 - inl, x0, y0 - ott, TRUE, fbp, vinfo, finfo);

		bresenham(x0 - ins, y0 - inl, x0 - otx, y0 - otd, TRUE, fbp, vinfo, finfo); //Barat Laut
		bresenham(x0 - inl, y0 - ins, x0 - otx, y0 - otd, TRUE, fbp, vinfo, finfo);

		bresenham(x0 - inl, y0 - ins, x0 - ott, y0, TRUE, fbp, vinfo, finfo); //Barat
		bresenham(x0 - inl, y0 + ins, x0 - ott, y0, TRUE, fbp, vinfo, finfo);

		bresenham(x0 - inl, y0 + ins, x0 - otx, y0 + otd, TRUE, fbp, vinfo, finfo); //Barat Daya
		bresenham(x0 - ins, y0 + inl, x0 - otx, y0 + otd, TRUE, fbp, vinfo, finfo);

		bresenham(x0 - ins, y0 + inl, x0, y0 + ott, TRUE, fbp, vinfo, finfo); //Selatan
		bresenham(x0 + ins, y0 + inl, x0, y0 + ott, TRUE, fbp, vinfo, finfo);

		bresenham(x0 + ins, y0 - inl, x0 + otx, y0 - otd, TRUE, fbp, vinfo, finfo); //Timur Laut
		bresenham(x0 + inl, y0 - ins, x0 + otx, y0 - otd, TRUE, fbp, vinfo, finfo);

		bresenham(x0 + inl, y0 - ins, x0 + ott, y0, TRUE, fbp, vinfo, finfo); //Timur
		bresenham(x0 + inl, y0 + ins, x0 + ott, y0, TRUE, fbp, vinfo, finfo);

		bresenham(x0 + inl, y0 + ins, x0 + otx, y0 + otd, TRUE, fbp, vinfo, finfo); //Tenggara
		bresenham(x0 + ins, y0 + inl, x0 + otx, y0 + otd, TRUE, fbp, vinfo, finfo);

	}
    //rasterScan(x0-ott,y0-ott,x0+ott,y0+ott,FALSE,fbp,vinfo,finfo);


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
    // bresenham(x0-8,y0-8,x0,y0,TRUE,fbp,vinfo,finfo);
    // bresenham(x0+5,y0-10,x0,y0,TRUE,fbp,vinfo,finfo);
    // bresenham(x0+11,y0,x0,y0,TRUE,fbp,vinfo,finfo);
    // bresenham(x0+5,y0+10,x0,y0,TRUE,fbp,vinfo,finfo);
    // bresenham(x0-10,y0+6,x0,y0,TRUE,fbp,vinfo,finfo);
    bresenham(x0-7,y0,x0,y0-7,TRUE,fbp,vinfo,finfo);
    bresenham(x0,y0-7,x0+7,y0,TRUE,fbp,vinfo,finfo);
    bresenham(x0+7,y0,x0,y0+7,TRUE,fbp,vinfo,finfo);
    bresenham(x0,y0+7,x0-7,y0,TRUE,fbp,vinfo,finfo);

    rasterScan(x0-7,y0-7,x0+7,y0+7,TRUE,fbp,vinfo,finfo);
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

    int x_min_star_box = min(x_star-7, min(x_star, x_star+7));
    int y_min_star_box = min(y_star-7, min(y_star, y_star+7));
    int x_max_star_box = max(x_star-7, max(x_star, x_star+7));
    int y_max_star_box = max(y_star-7, max(y_star, y_star+7));
    
    int x0_plane_coordinates[6] = {
        40+plane_offset-9,
        40+plane_offset+25,
        40+plane_offset+50,
        40+plane_offset+9,
        40+plane_offset+40,
        40+plane_offset-10
    };
    int y0_plane_coordinates[6] = {
        100+26,
        100+26,
        100+26,
        100+15,
        100+15,
        100+25
    };
    int x1_plane_coordinates[6] = {
        90+plane_offset-47,
        90+plane_offset,
        90+plane_offset+25,
        90+plane_offset-50,
        90+plane_offset-50,
        90+plane_offset-80
    };
    int y1_plane_coordinates[6] = {
        100+26,
        100+26,
        100+13,
        100+41,
        100+41,
        100-15
    };
    for (int i = 0; i < 6; i++){
        if (checkIfIntersect(x_min_star_box,y_min_star_box,x_min_star_box,y_max_star_box,x0_plane_coordinates[i],y0_plane_coordinates[i],x1_plane_coordinates[i],y1_plane_coordinates[i]))
            return TRUE;
        if (checkIfIntersect(x_min_star_box,y_max_star_box,x_max_star_box,y_max_star_box,x0_plane_coordinates[i],y0_plane_coordinates[i],x1_plane_coordinates[i],y1_plane_coordinates[i]))
            return TRUE;
        if (checkIfIntersect(x_max_star_box,y_max_star_box,x_max_star_box,y_min_star_box,x0_plane_coordinates[i],y0_plane_coordinates[i],x1_plane_coordinates[i],y1_plane_coordinates[i]))
            return TRUE;
        if (checkIfIntersect(x_max_star_box,y_min_star_box,x_min_star_box,y_min_star_box,x0_plane_coordinates[i],y0_plane_coordinates[i],x1_plane_coordinates[i],y1_plane_coordinates[i]))
            return TRUE;
    }

    return FALSE;
}

char checkPixelAround(int x, int y, char * fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo){
    long int mem_location;
    int max_x;

    char pixel_up = FALSE;
    char pixel_down = FALSE;

    for (int i = x-1; i < x + 2; i++){
        if (!(pixel_up)){
            mem_location = (i + vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (y - 1 + vinfo.yoffset) * finfo.line_length;
            if ((*(fbp + mem_location) || *(fbp + mem_location + 1) || *(fbp + mem_location + 2)) > 0x00){
                pixel_up = TRUE;
            }
        }
        if (!(pixel_down)){
            mem_location = (i + vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (y + 1 + vinfo.yoffset) * finfo.line_length;
            if ((*(fbp + mem_location) || *(fbp + mem_location + 1) || *(fbp + mem_location + 2)) > 0x00){
                pixel_down = TRUE;
            }
        }
    }

    return (pixel_up && pixel_down);
}

void rasterScan(int x_min, int y_min, int x_max, int y_max, char colorful, char * fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo){
    char fill_flag = 0;  // 0 = Don't fill, 1 = Fill
    long int mem_location;

    // Assumes x is not filled from the top or bottom of screen
    for (int j = y_min; j <= y_max; j++){
        for (int i = x_min; i <= x_max; i++){
            mem_location = (i + vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (j + vinfo.yoffset) * finfo.line_length;

            if ((*(fbp + mem_location) || *(fbp + mem_location + 1) || *(fbp + mem_location + 2)) == 0x00){
                if (fill_flag){
                    if (colorful){
                        pixel_color(fbp,mem_location,(i % 255),(j % 255), ((j-i) % 255));
                    } else {
                        pixel_color(fbp,mem_location,255,255,255);
                    }
                }
            } else {
                if (checkPixelAround(i, j, fbp, vinfo, finfo)){
                    if (fill_flag) {
                        if (colorful){
                            pixel_color(fbp,mem_location,(i % 255),(j % 255), ((j-i) % 255));
                        } else {
                            pixel_color(fbp,mem_location,255,255,255);
                        }
                    }

                    fill_flag = !(fill_flag);
                }
            }
        }
    }
}

void randomBullet(int x, int y, char * fbp, struct fb_var_screeninfo vinfo, struct fb_fix_screeninfo finfo){
    drawStar(x,y,fbp,vinfo,finfo);
}
