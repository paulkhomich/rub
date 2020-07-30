#include "tty.hpp"
#include <sys/ioctl.h>

tty ttySize(void) {
    static winsize win;
    ioctl(0, TIOCGWINSZ, &win);
    
    return { win.ws_col, win.ws_row };
}
