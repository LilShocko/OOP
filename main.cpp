#include <iostream>
#include<cstring>
#include<vector>
using namespace std;
class worker{
private:
    string name;
    int worktime;
public:
    worker(string _name, int _worktime){
        name=_name;
        worktime=_worktime;
    }
    void print(){
        cout<<"Name: "<<name<<endl;
        cout<<"Works from "<<worktime<<" years"<<endl;
    }
};
class programmer:public worker{
private:
    bool doescplus;
    bool doesc;
public:
    programmer(string _name, int _worktime, bool _doescplus, bool _doesc):worker(_name, _worktime){
        //worker(_name, _worktime);
        doescplus=_doescplus;
        doesc=_doesc;
    }
    void print(){
        worker::print();
        cout<<"Does cplusplus = "<<doescplus<<endl;
        cout<<"Does c = "<<doesc<<endl<<endl;
    }
};
class manager:public worker{
private:
    int control;
public:
    manager(string _name, int _worktime, int _control): worker(_name, _worktime){
        control=_control;
    }
    void print(){
        worker::print();
        cout<<"And controls "<<this->control<<" people"<<endl;
    }
};
class pr{
private:
    vector <worker*> lista;
public:
    void addworker(worker* added){
        lista.push_back(added);
    }
    void printroom(){
        for(int i=0; i< lista.size(); i++){
            lista[i]->worker::print();
        }
    }
};


int main(){
    manager m1("goshko", 1, 10);
    programmer p1("toshko", 5, 0, 0);
    pr rom1;
    rom1.addworker(&m1);
    rom1.addworker(&p1);
    rom1.printroom();

    return 0;
}
