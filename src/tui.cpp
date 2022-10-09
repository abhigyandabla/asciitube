#include "tui.hpp"

std ::string tui(void) {
  char mesg[] = " \n/$$$$$$  | \n$$ |__$$ | \n$$    $$ | "
                "\n$$$$$$$$ | \n$$ |  $$ | \n$$ |  $$ | \n$$/   $$/ scii Tube";
  char *str = (char *)(malloc(40));

  int row, col;               /* to store the number of rows and *
                               * the number of colums of the screen */
  initscr();                  /* start the curses mode */
  getmaxyx(stdscr, row, col); /* get the number of rows and columns */
  mvprintw(row / 3, (col - strlen(mesg)) / 3, "%s", mesg);
  /* print the message at the center of the screen */
  getstr(str);
  endwin();
  return str;
}

void install_video(std::string url) {

  std::string com = "youtube-dl -o './video/video.mp4' ";
  com = com + "'" + url + "'";
  std::cout << "executing command : " << com << '\n';
  std::system(com.c_str());
}

// int main() { install_video(tui()); }
