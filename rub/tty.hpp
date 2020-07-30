#ifndef tty_hpp
#define tty_hpp

struct tty {
    unsigned short   width;
    unsigned short   height;
};

tty ttySize(void);

#endif /* tty_hpp */
