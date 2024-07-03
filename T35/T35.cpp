#include <iostream>
#include "DNode.h"
#include "Taxi.h"

 int main() {
       
        DList<int> list;
        list.push_back(1);
        list.push_back(2);
        list.push_front(0);
        list.insertBefore(2, 1);
        list.insertAfter(1, 2);
        list.show();
        list.erase(1);
        list.show();

        std::cout << std::endl;
        std::cout << std::endl;

        TaxiList taxiList;
        taxiList.addTaxi(Taxi(1, "Toyota", "Biba", true));
        taxiList.addTaxi(Taxi(2, "Nissan", "Boba", true));
        taxiList.addBefore(1, Taxi(3, "Hyundai", "Abeme", true));

        taxiList.removeTaxi(2);
        taxiList.setOnCall(1);
        taxiList.setFree(3);
        taxiList.show();

        return 0;
    }


