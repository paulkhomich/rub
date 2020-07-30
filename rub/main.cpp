#include <string>
#include <ncurses.h>

#define DEFAULT 0
#define always while (true)

int main() {
    initscr();
    curs_set(0);
    keypad(stdscr, true);
    
    std::string menu[] = { "New", "Load", "Settings", "Exit", "Online" };
    char item = DEFAULT;
    char menuSize = (sizeof(menu)/sizeof(std::string));
    
    always {
        clear();
        for (int i = 0; i < menuSize; i++) {
            addch(item == i ? '*' : ' ');
            addch(' ');
            
            printw("%s\n", menu[i].c_str());
        }

        switch (getch()) {
            case KEY_DOWN: { item = (item + 1) % menuSize; break; }
            case KEY_UP: { item = (menuSize + item - 1) % menuSize; break; }
        }
        
        refresh();
    }
    
    endwin();
    return 0;
}
