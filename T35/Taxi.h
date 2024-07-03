#pragma once
#include <iostream>
#include <list>
#include <string>

class Taxi {
public:
    int number;
    std::string brand;
    std::string driver;
    bool isFree;

    Taxi(int num, const std::string& br, const std::string& dr, bool free)
        : number(num), brand(br), driver(dr), isFree(free) {}
};

class TaxiList {
    std::list<Taxi> taxis;
public:
    void addTaxi(const Taxi& taxi) {
        taxis.push_front(taxi);
    }

    void addBefore(int number, const Taxi& taxi) {
        for (auto it = taxis.begin(); it != taxis.end(); ++it) {
            if (it->number == number) {
                taxis.insert(it, taxi);
                return;
            }
        }
    }

    void removeTaxi(int number) {
        for (auto it = taxis.begin(); it != taxis.end(); ++it) {
            if (it->number == number) {
                taxis.erase(it);
                return;
            }
        }
    }

    void setOnCall(int number) {
        for (auto& taxi : taxis) {
            if (taxi.number == number) {
                taxi.isFree = false;
                return;
            }
        }
    }

    void setFree(int number) {
        for (auto& taxi : taxis) {
            if (taxi.number == number) {
                taxi.isFree = true;
                return;
            }
        }
    }

    void showFreeTaxis() {
        for (const auto& taxi : taxis) {
            if (taxi.isFree) {
                std::cout << "Taxi number: " << taxi.number << ", Brand: " << taxi.brand << ", Driver: " << taxi.driver << std::endl;
            }
        }
    }

    void showOnCallTaxis() {
        for (const auto& taxi : taxis) {
            if (!taxi.isFree) {
                std::cout << "Taxi number: " << taxi.number << ", Brand: " << taxi.brand << ", Driver: " << taxi.driver << std::endl;
            }
        }
    }

    void show() {
        for (const auto& taxi : taxis) {
            std::cout << "Номер таксі: " << taxi.number
                << ", Марка: " << taxi.brand
                << ", Водій: " << taxi.driver
                << ", Статус: " << (taxi.isFree ? "Вільний" : "На виклику")
                << std::endl;
        }
    }

};
