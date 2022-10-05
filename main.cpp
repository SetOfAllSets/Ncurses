#include <unistd.h>
#include <ncurses.h>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
  initscr();
  noecho();
  curs_set(0);
  init_pair(1, COLOR_CYAN, COLOR_GREEN);
  clear();
  refresh();
  //start making a menu window
  int maxy, maxx ;
  getmaxyx(stdscr, maxy, maxx);
  int height = 9;
  int width = 8;
  int starty = maxy/2-0.5*height;
  int startx = maxx/2-0.5*width;
  
  WINDOW *menuwin = newwin(height, width, starty, startx);
  box(menuwin, 0, 0);
  keypad(menuwin, true);
  //end making a menu window
  wrefresh(menuwin);
  //start menu
  string options[4] = {"Slow", "Medium", "Fast", "Custom"};
  bool choice = false;
  int selected = 0;
  
  while(true) {
    for(int i=0;i<4;i++) {
      if(i==selected) {
        wattron(menuwin, A_REVERSE);
      }
      mvwprintw(menuwin, 1+2*i, 1, options[i].c_str());
      wattroff(menuwin, A_REVERSE);
    };
    wrefresh(menuwin);
    switch(wgetch(menuwin)) {
      case KEY_UP:
        selected--;
        break;
      case KEY_DOWN:
        selected++;
        break;
      case 10:
        choice = true;
        break;
      default:
        break;
    };
    switch(selected) {
      case -1:
        selected = 0;
        break;
      case 4:
        selected = 3;
        break;
      default:
        break;
    };
    if(choice) {
      break;
    };
  };
  wclear(menuwin);
  box(menuwin, 0, 0);
  mvwprintw(menuwin, 1, 1, "%d", selected);
  wrefresh(menuwin);
  getch();
  //end menu
  //this (the above) took fucking forever to make lmao
  //just realised that replit auto adds a second one of any grouping thing even in comments and now I'm wondering why other text editors don't do that, like when are you going to but "(" or ")" or even """
  //start custom snake speed menu (doing this later than other code so note to self: re-enable echo so you don't have to print the output of wgetch())
  delwin(menuwin);
  refresh();
  height = maxy-2;
  width = maxx-2;
  starty = maxy/2-0.5*height;
  startx = maxx/2-0.5*width;
  
  WINDOW *snakewin = newwin(height, width, starty, startx);
  /*just realised I put startx as a variable name, that's going to confuse so many people, "X WORKS ON REPLIT NOW?!?!??!" lmao, ncurses does at least
  actually, could you use X in a pygame project due to it having a screen?*/
  box(snakewin,0,0);
  //snake loop start
  //score will be length/time*100000 rounded to be an int
  wrefresh(snakewin);
  vector<string> coordsy;
  vector<string> coordsx;
  vector<string> foodcoordsy;
  vector<string> foodcoordsx;
  vector<string> wallcoordsy;
  vector<string> wallcoordx;
  string direction = ">";
  
  while(true) {
    
  };
  //snake loop end
  getch();
  endwin();
  return 0;
}