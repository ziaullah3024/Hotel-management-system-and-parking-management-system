#include "fileio.h"
#include "utils.h"
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

vector<Room> loadRooms() {
    vector<Room> out;
    ifstream fin("data/rooms.txt");
    string line;
    while (getline(fin, line)) if (!line.empty()) out.push_back(Room::fromCSV(line));
    return out;
}
void saveRooms(const vector<Room> &v) {
    ofstream fout("data/rooms.txt");
    for (auto &x : v) fout << x.toCSV() << '\n';
}

vector<Guest> loadGuests() {
    vector<Guest> out;
    ifstream fin("data/guests.txt"); string line;
    while (getline(fin, line)) if (!line.empty()) out.push_back(Guest::fromCSV(line));
    return out;
}
void saveGuests(const vector<Guest> &v) {
    ofstream fout("data/guests.txt");
    for (auto &x : v) fout << x.toCSV() << '\n';
}

vector<Booking> loadBookings() {
    vector<Booking> out;
    ifstream fin("data/bookings.txt"); string line;
    while (getline(fin, line)) if (!line.empty()) out.push_back(Booking::fromCSV(line));
    return out;
}
void saveBookings(const vector<Booking> &v) {
    ofstream fout("data/bookings.txt");
    for (auto &x : v) fout << x.toCSV() << '\n';
}

vector<ParkingSlot> loadSlots() {
    vector<ParkingSlot> out;
    ifstream fin("data/parking_slots.txt"); string line;
    while (getline(fin, line)) if (!line.empty()) out.push_back(ParkingSlot::fromCSV(line));
    return out;
}
void saveSlots(const vector<ParkingSlot> &v) {
    ofstream fout("data/parking_slots.txt");
    for (auto &x : v) fout << x.toCSV() << '\n';
}

vector<Vehicle> loadVehicles() {
    vector<Vehicle> out;
    ifstream fin("data/vehicle_logs.txt"); string line;
    while (getline(fin, line)) if (!line.empty()) out.push_back(Vehicle::fromCSV(line));
    return out;
}
void saveVehicles(const vector<Vehicle> &v) {
    ofstream fout("data/vehicle_logs.txt");
    for (auto &x : v) fout << x.toCSV() << '\n';
}

vector<Service> loadServices() {
    vector<Service> out;
    ifstream fin("data/services.txt"); string line;
    while (getline(fin, line)) if (!line.empty()) out.push_back(Service::fromCSV(line));
    return out;
}
void saveServices(const vector<Service> &v) {
    ofstream fout("data/services.txt");
    for (auto &x : v) fout << x.toCSV() << '\n';
}

vector<Invoice> loadInvoices() {
    vector<Invoice> out;
    ifstream fin("data/invoices.txt"); string line;
    while (getline(fin, line)) if (!line.empty()) out.push_back(Invoice::fromCSV(line));
    return out;
}
void saveInvoices(const vector<Invoice> &v) {
    ofstream fout("data/invoices.txt");
    for (auto &x : v) fout << x.toCSV() << '\n';
}

void createDefaultFilesIfMissing() {
    ensureDataFolder();

    ifstream f1("data/users.txt");
    if (!f1.good()) {
        ofstream fo("data/users.txt");
        fo << "admin,admin123,admin\n";
        fo << "recept,rec123,receptionist\n";
        fo << "att,att123,attendant\n";
    }

    ifstream f2("data/services.txt");
    if (!f2.good()) {
        ofstream fo("data/services.txt");
        fo << "1,Laundry,5.00\n2,Food,10.00\n3,Internet,2.00\n";
    }

    ifstream f3("data/rooms.txt");
    if (!f3.good()) {
        ofstream fo("data/rooms.txt");
        fo << "101,Single,1,25.00,0\n102,Double,2,40.00,0\n201,Suite,4,80.00,0\n";
    }

    ifstream f4("data/parking_slots.txt");
    if (!f4.good()) {
        ofstream fo("data/parking_slots.txt");
        fo << "1,normal,0\n2,normal,0\n3,vip,0\n";
    }

    vector<string> other = {
        "data/guests.txt","data/bookings.txt",
        "data/vehicle_logs.txt","data/invoices.txt"
    };
    for (auto &fn : other) {
        ifstream t(fn);
        if (!t.good()) ofstream tmp(fn);
    }
}
