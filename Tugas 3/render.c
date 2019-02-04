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
#include "name.h"

#define CHARWIDTH 16
#define CHARHEIGHT 20

struct input_event ev;
ssize_t n;
int fd;
pthread_t thread0;
int flagShoot = 0;
unsigned short bullet_selection;

pthread_t thread_list[5];
char thread_avail_flag[5];
char plane_shot_down = FALSE;
int r = 0;


void delay(unsigned int ms){
    clock_t goal = ms + clock();
    while (goal > clock());
}

char getAvailableThread(){
    for (int i = 0; i < 5; i++){
        if (thread_avail_flag[i]){
            return i;
        }
    }

    return -1;
}

void *thread_run(void * thread_bullet_info){
    struct thread_bullet_param tbp;

    tbp = *(struct thread_bullet_param *) thread_bullet_info;
    
    int c = 0;

    //printf("Thread %d running.\n", tbp.thread_number);
    for(;;){
        if (plane_shot_down){
            break;
        }

        if (checkIfShot(c, r % tbp.vinfo.xres, tbp.turret_number)){
            plane_shot_down = TRUE;
            break;
        }

        if (350 - c > 0){
            drawBullets(c, tbp.turret_number, tbp.framebuffer, tbp.vinfo, tbp.finfo);
            c++;
        } else {
            break;
        }

        delay(20000);
    }

    thread_avail_flag[tbp.thread_number] = TRUE;
    //printf("Thread %d done.\n", tbp.thread_number);
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
    
    //start user input thread
    pthread_create(&thread0, NULL, userInput, NULL);

    clear_screen(fbp,800,600,vinfo,finfo);

    int y = 600;
    for (;;){
        break;

        clear_screen(fbp,800,600,vinfo,finfo);
        if ((y>=0) && (y<600))
            nama(y,fbp, vinfo, finfo);
        if ((y+50>=0) && (y+50<600))
            bella(y+50, fbp, vinfo, finfo);
        if ((y+100>=0) && (y+100<600))
            yora(y+100,fbp,vinfo, finfo);
        if ((y+150>=0) && (y+150<600))
            kevin_a(y+150, fbp, vinfo, finfo);
        if ((y+200>=0) && (y+200<600))
            kevin_f(y+200, fbp, vinfo, finfo);
        if ((y+250>=0) && (y+250<600))
            tere(y+250, fbp, vinfo, finfo);
        if ((y+300>=0) && (y+300<600))
            fildah(y+300, fbp, vinfo, finfo);
        if ((y+350>=0) && (y+350<600))
            richard(y+350, fbp, vinfo, finfo);

        y -= 3;
        delay(50000);

        if (y < -400)
            break;
    }

    int count = 0;
    for (int i = 0; i < 5; i++){
        thread_avail_flag[i] = TRUE;
    }
    char available_thread = 0;

    while (1) {
        if (plane_shot_down){
            clear_screen(fbp,800,600,vinfo,finfo);
            drawCannon(fbp,vinfo,finfo);
            drawBlast((60 + r), 100, fbp, vinfo, finfo);
            break;
        } else {
            clear_screen(fbp,800,600,vinfo,finfo);

            if (350-c <= 0 ) {
                c = 0;
                flagShoot = 0;
                bullet_selection = 0;
            }
            
            drawCannon(fbp,vinfo,finfo);
            // if ((available_thread = getAvailableThread()) != -1){
            //     thread_avail_flag[available_thread] = FALSE;

            //     printf("THREAD %d RUNNING.\n", available_thread);
            //     pthread_create(&(thread_list[available_thread]), NULL, thread_run, (void *) &available_thread);
            // } else {
            //     printf("THREAD NOT AVAILABLE. WAITING FOR 5s.\n");
            //     sleep(2);
            // }

            if (flagShoot){
                if ((available_thread = getAvailableThread()) != -1){
                    thread_avail_flag[available_thread] = FALSE;

                    struct thread_bullet_param thread_bullet_info;

                    thread_bullet_info.thread_number = available_thread;
                    thread_bullet_info.turret_number = bullet_selection-2;
                    thread_bullet_info.framebuffer = fbp;
                    thread_bullet_info.vinfo = vinfo;
                    thread_bullet_info.finfo = finfo;

                    pthread_create(&(thread_list[available_thread]), NULL, thread_run, (void *) &thread_bullet_info);

                    flagShoot = FALSE;
                }
            }

            // if(checkIfShot(c,r % vinfo.xres,bullet_selection-2)){
            //     drawBlast((60+r),100,fbp,vinfo,finfo);
            //     break;
            // } else {
            //     //draw bullet jika telah menembak
            //     if (flagShoot){
            //         drawBullets(c,bullet_selection-2,fbp,vinfo,finfo);
            //         c++;
            //     }
            //     drawPlane(40+r,100,90+r,100,fbp,vinfo,finfo);
            // }
            drawPlane(40+r,100,90+r,100,fbp,vinfo,finfo);
            r=r+1;

            if (r > vinfo.xres+25)
                r = r % vinfo.xres;

            delay(10000);
        }
    }

    munmap(fbp, screensize);
    close(fbfd);

    for (int i = 0; i < 5; i++){
        pthread_join(thread_list[i],NULL);
    }

    while(1);

    fflush(stdout);
    fprintf(stderr, "%s.\n", strerror(errno));

    return 0;
}

