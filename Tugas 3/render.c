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

int flagShoot = 0;              // Stores the info if user has invoked an attack command
unsigned short bullet_selection;// Stores the attack selection user inputs

pthread_t thread_list[5];       // Lists the thread available for each shots
char thread_avail_flag[5];      // Stores the thread info, whether it's available to use or not
char plane_shot_down = FALSE;   // Stores the plane info if it has been shot down by one of the shots
int plane_offset = 0;           // Stores the plane offset from the initial point

char getAvailableThread(){
// Checks if there's an available thread to use
// Returns 0 to 4 as the thread number, -1 if no thread is available
    for (int i = 0; i < 5; i++){
        if (thread_avail_flag[i]){
            return i;
        }
    }

    return -1;
}

void *render_bullet_thread(void * thread_bullet_info){
// Function for rendering the bullets in thread
    struct thread_bullet_param tbp;

    tbp = *(struct thread_bullet_param *) thread_bullet_info;
    
    int bullet_offset = 0;
    struct timespec delay;
    delay.tv_sec = 0;
    delay.tv_nsec = 10000000;

    for(;;){
        if (plane_shot_down){
            break;
        }

        if (checkIfShot(bullet_offset, plane_offset % tbp.vinfo.xres, tbp.turret_number)){
            plane_shot_down = TRUE;
            break;
        }

        if (350 - bullet_offset > 0){
            drawBullets(bullet_offset, tbp.turret_number, tbp.framebuffer, tbp.vinfo, tbp.finfo);
            bullet_offset++;
        } else {
            break;
        }

        nanosleep(&delay,NULL);
    }

    thread_avail_flag[tbp.thread_number] = TRUE;
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

    // Input keyboard
    const char *dev = "/dev/input/event4";
    fd = open(dev, O_RDONLY);
    if (fd == -1) {
        fprintf(stderr, "Cannot open %s: %s.\n", dev, strerror(errno));
        return EXIT_FAILURE;
    }
    
    //start user input thread
    pthread_create(&thread0, NULL, userInput, NULL);

    struct timespec delay;
    delay.tv_sec = 0;
    delay.tv_nsec = 50000000;

    // -------- Printing Credits --------
    int vertical_offset = 600;
    for (;;){
        break;

        clear_screen(fbp,800,600,vinfo,finfo);
        if ((vertical_offset>=0) && (vertical_offset<600))
            nama(vertical_offset,fbp, vinfo, finfo);
        if ((vertical_offset+50>=0) && (vertical_offset+50<600))
            bella(vertical_offset+50, fbp, vinfo, finfo);
        if ((vertical_offset+100>=0) && (vertical_offset+100<600))
            yora(vertical_offset+100,fbp,vinfo, finfo);
        if ((vertical_offset+150>=0) && (vertical_offset+150<600))
            kevin_a(vertical_offset+150, fbp, vinfo, finfo);
        if ((vertical_offset+200>=0) && (vertical_offset+200<600))
            kevin_f(vertical_offset+200, fbp, vinfo, finfo);
        if ((vertical_offset+250>=0) && (vertical_offset+250<600))
            tere(vertical_offset+250, fbp, vinfo, finfo);
        if ((vertical_offset+300>=0) && (vertical_offset+300<600))
            fildah(vertical_offset+300, fbp, vinfo, finfo);
        if ((vertical_offset+350>=0) && (vertical_offset+350<600))
            richard(vertical_offset+350, fbp, vinfo, finfo);

        vertical_offset -= 3;
        nanosleep(&delay,NULL);

        if (vertical_offset < -400)
            break;
    }

    // -------- Printing Game Sequence --------
    // ---- Initialize thread flags
    for (int i = 0; i < 5; i++){
        thread_avail_flag[i] = TRUE;
    }

    char available_thread = 0;
    delay.tv_nsec /= 5;

    // ---- Infinite loop of framebuffer drawing
    while (1) {
        // ---- Checks if the plane already shot down
        if (plane_shot_down){   // If yes, break out of the loop
            clear_screen(fbp,800,600,vinfo,finfo);
            drawCannon(fbp,vinfo,finfo);
            drawBlast((60 + plane_offset), 100, fbp, vinfo, finfo);
            break;
        } else {    // If not, continue the loop
            // ---- Clear the screen
            clear_screen(fbp,800,600,vinfo,finfo);
            
            // ---- Draw the cannon
            drawCannon(fbp,vinfo,finfo);

            // ---- Checks whether the user has inputted an attack command (1-5)
            if (flagShoot){

                // ---- Checks if there's a thread available to use
                if ((available_thread = getAvailableThread()) != -1){
                    // ---- Set the thread to in use
                    thread_avail_flag[available_thread] = FALSE;

                    struct thread_bullet_param thread_bullet_info;

                    thread_bullet_info.thread_number = available_thread;
                    thread_bullet_info.turret_number = bullet_selection-2;
                    thread_bullet_info.framebuffer = fbp;
                    thread_bullet_info.vinfo = vinfo;
                    thread_bullet_info.finfo = finfo;

                    pthread_create(&(thread_list[available_thread]), NULL, render_bullet_thread, (void *) &thread_bullet_info);

                    // ---- Reset the flagShoot so user can input another attack command
                    flagShoot = FALSE;
                }
            }

            // ---- Draw the plane
            drawPlane(40+plane_offset,100,90+plane_offset,100,fbp,vinfo,finfo);
            plane_offset++;

            // ---- Reset the y position of plane
            if (plane_offset > vinfo.xres+25)
                plane_offset = plane_offset % vinfo.xres;

            nanosleep(&delay,NULL);
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

