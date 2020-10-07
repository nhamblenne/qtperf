#include <stdio.h>
#include <stdlib.h>

#include <X11/Xlib.h>

int const gGridSize = 100;

int main() {
    Display *display;
    Window window;
    XEvent event;
    int screen;
    GC background;
    GC foreground;
    unsigned long valuemask = 0;
    XGCValues values;
    Window root_return;
    int x_return, y_return;
    unsigned int width_return, height_return;
    unsigned int border_width_return;
    unsigned int depth_return;
    int done = 0;
    int xpos = 0;
    int ypos = 0;
    
    display = XOpenDisplay(NULL);
    if (display == NULL) {
        fprintf(stderr, "Cannot open display\n");
        exit(1);
    }

    screen = DefaultScreen(display);
    
    window = XCreateSimpleWindow(display, RootWindow(display, screen), 10, 10, 300, 200,
                                 1, BlackPixel(display, screen), WhitePixel(display, screen));

    Atom del_window = XInternAtom(display, "WM_DELETE_WINDOW", 0);
    XSetWMProtocols(display, window, &del_window, 1);

    XSelectInput(display, window, ExposureMask | PointerMotionMask);

    XMapWindow(display, window);

    background = XCreateGC(display, window, valuemask, &values);
    XSetForeground(display, background, WhitePixel(display, screen));
    
    foreground = XCreateGC(display, window, valuemask, &values);
    XSetForeground(display, foreground, BlackPixel(display, screen));
    
    while (!done) {
        XNextEvent(display, &event);
        
        switch (event.type) {
        case ClientMessage:
            done = 1;
            break;
            
        case MotionNotify:
            xpos = event.xmotion.x;
            ypos = event.xmotion.y;
            
            /* FALLTHROU */
            
        case Expose:
            XGetGeometry(display, window, &root_return, &x_return, &y_return, &width_return, 
                         &height_return, &border_width_return, &depth_return);            
            XFillRectangle(display, window, background, 0, 0, width_return, height_return);
            for (int i = xpos % 100; i < width_return; i += 100) {
                XDrawLine(display, window, foreground, i, 0, i, height_return);
            }
            for (int i = ypos % 100; i < height_return; i += 100) {
                XDrawLine(display, window, foreground, 0, i, width_return, i);
            }
            XFillRectangle(display, window, foreground, event.xmotion.x-5, event.xmotion.y-5, 10, 10);
            break;
            
        }
    }
    
    XDestroyWindow(display, window);
    XCloseDisplay(display);
    
    return 0;
}
