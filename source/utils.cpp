#include "utils.hpp"
#include "download.hpp"
#include <filesystem>
#include <fstream>
#include <switch.h>

std::vector<std::string> htmlProcess(std::string s, std::regex rgx){
    //std::vector<std::regex> rgx = {std::regex(">(?:(?!>).)*?</a>"), std::regex(">(?:(?!>).)*?</a>")};
    std::vector<std::string> res;
    std::smatch match;
    while (std::regex_search(s, match, rgx)){
        res.push_back(match[0].str());
        s = match.suffix();
    }
    return res;
}

void createTree(std::string path){
    std::string delimiter = "/";
    size_t pos = 0;
    std::string token;
    std::string directories("");
    while ((pos = path.find(delimiter)) != std::string::npos) {
        token = path.substr(0, pos);
        directories += token + "/";
        std::filesystem::create_directory(directories);
        path.erase(0, pos + delimiter.length());
    }
}

void clearConsole(){
    consoleClear();
    consoleUpdate(NULL);
}

bool isArchive(const char *){
    std::fstream file;
    std::string fileContent;
    if(std::filesystem::exists(SIGPATCHES_FILENAME)){
        file.open(SIGPATCHES_FILENAME, std::fstream::in);
        file >> fileContent;
        file.close();
    }
    return fileContent.find("DOCTYPE") == std::string::npos;
    
}