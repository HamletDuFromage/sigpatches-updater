#include "extract.hpp"

bool extract(std::string filename){
    chdir("/");
    zipper::Unzipper unzipper(filename);
    bool res = unzipper.extract();
    unzipper.close();
    return res;
}