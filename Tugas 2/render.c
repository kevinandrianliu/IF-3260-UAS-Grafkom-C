#include <errno.h>
#include <fcntl.h>
#include <linux/input.h>
#include <pthread.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/mman.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include "utilities.h"
#include "lineutil.h"

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
        
        drawCannon(fbp,vinfo,finfo);

        if(checkIfShot(c,r % vinfo.xres,bullet_selection-2)){
            drawBlast((60+r),100,fbp,vinfo,finfo);
            break;
        } else {
            //draw bullet jika telah menembak
            if (flagShoot){
                drawBullets(c,bullet_selection-2,fbp,vinfo,finfo);
                c++;
            }
            drawPlane(40+r,100,90+r,100,fbp,vinfo,finfo);
        }
        r=r+1;

        if (r > vinfo.xres+25)
            r = r % vinfo.xres;

        delay(10000);
    }

    munmap(fbp, screensize);
    close(fbfd);

    while(1);

    fflush(stdout);
    fprintf(stderr, "%s.\n", strerror(errno));
    return 0;
}

