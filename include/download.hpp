#ifndef _DOWNLOAD_H_
#define _DOWNLOAD_H_

#define ON              1
#define OFF             0

#define SIGPATCHES_URL "https://hamletdufromage.github.io/sigpatches-updater/sigpatches.html"
#define DOWNLOAD_PATH "/config/sigpatches-updater/"
#define SIGPATCHES_FILENAME "/config/sigpatches-updater/sigpatches.zip"


#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <math.h>
#include <curl/curl.h>

#include <string>
#include <regex>
#include <iostream>

#include <switch.h>


bool downloadFile(const char *url, const char *output, int api);

std::tuple<std::vector<std::string>, std::vector<std::string>> fetchLinks(const char *url);

#endif