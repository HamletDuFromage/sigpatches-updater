#include <regex>
#include <iostream>

std::vector<std::string> htmlProcess(std::string s, std::regex rgx);
void createTree(std::string path);
void clearConsole();
bool isArchive(const char *);
