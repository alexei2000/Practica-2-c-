#ifndef UI_HPP
#define UI_HPP

#include <iostream>
#include "../eventosDeCuenta/EventosDeCuenta.hpp"
#include "../formatLogs/FormatLogs.hpp"
#include "string.h"
#include "string"

using namespace std;

class UI{
    private:
        static UI* instance;
        EventosDeCuentas *event;
        int option;
        UI();
        void menu();
        void getOption();
        void selectOption();
        void getDate();
        bool validDate(string date);

    public:
        static UI* getInstance();
        void init();

};

UI* UI::instance = NULL;

UI::UI(){
    option = -1;
    event = new EventosDeCuentas;
}

UI* UI::getInstance(){
    if (instance == NULL){
        instance = new UI();
    }
    return instance;
}

void UI::init(){

    getDate();

    if(event->getNumAccounts()==0){
        cout<<"no hay eventos para la fecha dada";
        system("pause");
        return;
    }

    while(option!=0){
        menu();
        getOption();
        selectOption();
    }
}

void UI::menu(){
    system("cls");
    cout<<"\tIngrese la opcion"<<endl;
    cout<<"\t\t1. Mostrar numero de logs"<<endl;
    cout<<"\t\t2. Mostrar numero de eventos recibidos"<<endl;
    cout<<"\t\t3. Mostrar numero de cuentas"<<endl;
    cout<<"\t\t4. Mostrar 10 cuentas con mas eventos"<<endl;
    cout<<"\t\t5. Mostrar eventos enviados por tipo"<<endl;
    cout<<"\t\t6. Generar archivo csv"<<endl;
    cout<<"\t\t0. Salir"<<endl;;
}

void UI::getOption(){
    do{
        cin>>option;
    }while(option<0 || option>6);
}

void UI::selectOption(){
    system("cls");
    switch (option){
        case 1: cout<<"-. "<<event->getNumLogs()<<endl<<endl; break;
        case 2: cout<<"-. "<<event->getNumEvents()<<endl<<endl; break;
        case 3: cout<<"-. "<<event->getNumAccounts()<<endl<<endl; break;
        case 4: event->showFirstTen(); break;
        case 5: event->showEventsAndTypes(); break;
        case 6: event->generateCsv();
    }
    system("pause");
}

void UI::getDate(){
    string date;

    do{
        cout<<"\tIngrese una fecha formato (yyyy-mm-dd): ";
        cin>>date;
        cout<<endl;
    }while(!validDate(date));

    FormatLogs *fL = FormatLogs::getInstance();
    fL->readFileAndInsert("registros/signals.log",*event,date);
}

bool UI::validDate(string date){

    if(
        (date.length() == 10) &&
        isdigit(date[0]) &&
        isdigit(date[1]) &&
        isdigit(date[2]) &&
        isdigit(date[3]) &&
        (date[4] == '-')   &&
        isdigit(date[5]) &&
        isdigit(date[6]) &&
        (date[7] == '-' )  &&
        isdigit(date[8]) &&
        isdigit(date[9])
    )
        return true;
    else
        return false;
}




#endif