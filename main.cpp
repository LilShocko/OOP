#include <iostream>
using namespace std;
class ElectricalDevice{
private:
    int avexp;
public:
    virtual void alert();
};
class Printer: public ElectricalDevice{
private:
    int serial_number;
    int price_toner;
    bool is_toner_out;
public:
    void alert(){
        cout<<"Printer "<<serial_number<<" is out of toner";
    }
};
class Scanner: public ElectricalDevice{
private:
    int price_paper;
    bool is_paper_empty;
public:
    void alert(){
        cout<<"Scanner is out of paper ";
    }
};
class Room{
private:
    ElectricalDevice* rom;
    int current;
public:
    Room(int sizee){
        current=0;
        rom= new ElectricalDevice[sizee];
    }
    void addDevice(ElectricalDevice& added){
        rom[current]=added;
    }


};



int main(){
    Room r1(5);




    return 0;
}
