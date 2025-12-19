#ifndef MODELS_H
#define MODELS_H
#include <string>

struct Room {
    int number;
    std::string type;
    int capacity;
    double price;
    bool occupied;
};

struct Guest {
    int id;
    std::string name, cnic, phone;
};

struct Booking {
    int id, roomNumber, guestId;
    std::string inDate, outDate;
    bool active;
};

struct ParkingSlot {
    int slotNumber;
    bool occupied;
};

struct Vehicle {
    int id, slotNumber, guestId;
    std::string plate;
    long long entry, exit;
};

struct Invoice {
    int id, bookingId;
    double roomFee, parkingFee;
    long long time;
    double total() const { return roomFee + parkingFee; }
};

#endif
