#include <iostream>
#include <string>
#include <vector>
#include <switch.h>

#define VERSION "0.2"

#define WIDTH 80 // The width of the console
#define HEIGHT 45 // Height of the console

void displayList(std::vector<std::string> items, int cursor);
void viewHeader();
void viewHelp();
std::string prettifyString(const char * s, const char * modifier);