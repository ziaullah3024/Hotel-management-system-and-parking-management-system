#ifndef FILEIO_H
#define FILEIO_H

#include <vector>
#include "models.h"

std::vector<Room> loadRooms();
void saveRooms(const std::vector<Room>&);

std::vector<Guest> loadGuests();
void saveGuests(const std::vector<Guest>&);

std::vector<Booking> loadBookings();
void saveBookings(const std::vector<Booking>&);

std::vector<ParkingSlot> loadSlots();
void saveSlots(const std::vector<ParkingSlot>&);

std::vector<Vehicle> loadVehicles();
void saveVehicles(const std::vector<Vehicle>&);

std::vector<Service> loadServices();
void saveServices(const std::vector<Service>&);

std::vector<Invoice> loadInvoices();
void saveInvoices(const std::vector<Invoice>&);

void createDefaultFilesIfMissing();

#endif
