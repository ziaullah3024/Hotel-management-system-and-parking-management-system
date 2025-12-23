#include "auth.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

bool userLogin(string &role, string &usernameOut) {
    cout << "=== LOGIN ===\n";
    cout << "Username: ";
    string u; cin >> u;
    cout << "Password: ";
    string p; cin >> p;

    ifstream fin("data/users.txt");
    string line;
    while (getline(fin, line)) {
        stringstream ss(line);
        string un, pw, rl;
        getline(ss, un, ',');
        getline(ss, pw, ',');
        getline(ss, rl, ',');
        if (un == u && pw == p) {
            role = rl;
            usernameOut = un;
            return true;
        }
    }
    return false;
}
