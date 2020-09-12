#include <iostream>
#include <filesystem>

#include "unzipper.h"
#include "ui.hpp"
#include "download.hpp"
#include "utils.hpp"
#include "extract.hpp"
#include <switch.h>


void initServices(){
    consoleInit(NULL);
    socketInitializeDefault();
}

void exitServices(){
    socketExit();
    consoleExit(NULL);
}

int main(int argc, char* argv[]){
    initServices();

    viewHeader();
    std::cout << "Loading..." << std::endl;

    createTree(DOWNLOAD_PATH);

    int cursor = 0;
    int menu = 0;
    bool downloaded = false;
    std::string results("");
    auto items = fetchLinks(SIGPATCHES_URL);
    int nbItems = std::get<0>(items).size();
    if(nbItems == 0) menu = -1;
    while (appletMainLoop())
    {
        consoleClear();
        viewHeader();
        hidScanInput();
        u64 kDown = hidKeysDown(CONTROLLER_P1_AUTO);
        u64 kHeld = hidKeysHeld(CONTROLLER_P1_AUTO);
        if (kDown & KEY_PLUS) break;
        if (kHeld & KEY_Y){
            consoleClear();
            viewHelp();
        }
        else if (menu == -1) std::cout << "Couldn't fetch download links, make sure you're connected to the internet.";
        else if(menu == 0){
            std::cout << "Use the D-pad or the thumbstick to select the desired sigpatches" << std::endl;
            std::cout << "Press [A] to confirm your choice" << std::endl << std::endl;;
            downloaded = false;
            displayList(std::get<0>(items), cursor);
            if (kDown & KEY_A) menu = 1;
            if ((kDown & KEY_DOWN) && cursor < nbItems - 1) cursor += 1;
            if ((kDown & KEY_UP) && cursor > 0) cursor -= 1;
        }
        else if(menu == 1){
            std::cout << "Press [A] to install the sigpatches" << std::endl;
            std::cout << "Press [B] go back to the main screen" << std::endl;
            std::cout << std::endl << std::endl;

            std::cout << "The following sigpatches will be downloaded: " << std::endl;
            std::cout << prettifyString("Name:\n", "[1;36m") << std::get<0>(items)[cursor] << std::endl;
            std::cout << std::endl;
            std::cout <<  prettifyString("Download url:\n", "[1;36m")<< std::get<1>(items)[cursor] << std::endl;
            if(kDown & KEY_A) menu = 2;
            if(kDown & KEY_B) menu = 0;
        }
        else if(menu == 2){
            std::cout << "Press [B] go back to the main screen" << std::endl << std::endl;
            if(!downloaded){
                results = "";
                //if(1){
                if(downloadFile(std::get<1>(items)[cursor].c_str(), SIGPATCHES_FILENAME, OFF)){
                    if(isArchive(SIGPATCHES_FILENAME)){
                        if(extract(SIGPATCHES_FILENAME)) results += prettifyString("Successfully downloaded the sigpatches archive and successfully extracted them", "[1;32m");
                        else results += "Could not extract the sigpatches archive.";
                    }
                    else results += "The download link is broken. If the issue persists after a day, leave a comment on the Gbatemp thread or open an issue on github.com/HamletDuFromage/sigpatches-updater";
                }
                else results += "Couldn't download the sigpatches archive";
                downloaded = true;
            }
            std::cout << results << std::endl;
            if(kDown & KEY_B) menu = 0;
        }

        consoleUpdate(NULL);
    }

    
    exitServices();
}