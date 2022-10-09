#pragma once
#include <cstdlib>
#include <iostream>
#include <ncurses.h>
#include <ncurses.h> /* ncurses.h includes stdio.h */
#include <string.h>
#include <string>

std::string tui(void);

void install_video(std::string url);
