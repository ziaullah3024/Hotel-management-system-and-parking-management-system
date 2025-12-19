#include "utils.h"
#include <iostream>
#include <ctime>
#include <limits>
#include <cstdlib>

using namespace std;

void ensureDataFolder() {
#ifdef _WIN32
    system("if not exist data mkdir data");
#else
    system("mkdir -p data");
#endif
}

void pauseScreen() {
    cout << "\nPress ENTER...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

long long nowEpoch() {
    return (long long)time(nullptr);
}

string epochToString(long long e) {
    if (e <= 0) return "";
    time_t t = (time_t)e;
    char buf[32];
    strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", localtime(&t));
    return buf;
}
