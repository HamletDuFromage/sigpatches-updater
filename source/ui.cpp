#include "ui.hpp"

void displayList(std::vector<std::string> items, int cursor){
    for (int i = 0; i < (int) items.size(); i++){
        
        if(i == items.size() - 1 ) std::cout << std::endl;
        if(cursor == i) std::cout << prettifyString(">> ", "[1;36m");
        std::cout << "\033[1m" << items[i].substr(0, WIDTH - 4) << "\033[0m" << std::endl;
    }
}

void viewHeader(){
    std::cout << "\033[31m" << "================================================================================" << "\033[0m" << std::endl;
    std::cout << "\033[1;31m" << "Sigpatches Updater v" << VERSION << " by HamletDuFromage" << "\033[0m" <<std::endl;
    std::cout << "\033[31m" << "================================================================================" << "\033[0m" << std::endl;
    std::cout << "Press [+] to quit" << std::endl;
    std::cout << "Hold  [Y] to display the help" << std::endl;
}
//void prettifyString(std::string& s, const char * modifier){
//    s = "\033" + std::string(modifier) + s + "\033[0m";
//}

void viewHelp(){
    std::cout << prettifyString("What are sigpatches?", "[1;36m") << std::endl;
    std::cout << "Sigpatches allow your Switch to install and run unofficial NSP files \
(digital titles that appear on the home menu). \
Note that you must use CFW to launch these applications even after \
installation as sigpatches are always required to do so." << std::endl;
    std::cout << std::endl;
    std::cout << prettifyString("Which sigpatches should you install?", "[1;36m") << std::endl;
    std::cout << "If you're entering Atmosphere by injecting the \"fusee-primary.bin\" payload, \
download the appropriate sigpatches. If you're using Hekatee and \"fss0\", get the Hekate sigpatches." << std::endl;


}

std::string prettifyString(const char * s, const char * modifier){
    return "\033" + std::string(modifier) + std::string(s) + "\033[0m";
}