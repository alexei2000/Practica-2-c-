#ifndef EVENTOSDECUENTA_HPP
#define EVENTOSDECUENTA_HPP

#include <map>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

class EventosDeCuentas{

    private:
        map<string,map<string,long>> colection;
        long numEvents;
        long numLogs;
    public:
        EventosDeCuentas();
        void insert(string account, string event);
        void setNumLogs(long n);
        long getNumLogs();
        long getNumAccounts();
        long getNumEvents();
        void generateCsv();
        void showFirstTen();
        void showEventsAndTypes();

};

EventosDeCuentas::EventosDeCuentas(){
    numEvents = 0;
    numLogs = 0;
}


void EventosDeCuentas::setNumLogs(long n ){
    numLogs = n;
}

long EventosDeCuentas::getNumLogs(){
    return numLogs;
}

long EventosDeCuentas::getNumAccounts(){

    return colection.size();
}


long EventosDeCuentas::getNumEvents(){

    return numEvents;
}

void EventosDeCuentas::generateCsv(){
    long count=0;
    multimap<long,string> eventsAccounts;

    for (auto const &account: colection){
        for(auto const &eventType: account.second){
            count+=eventType.second;
        }
        eventsAccounts.insert(pair <long,string>(count,account.first));
        count=0;
    }

    ofstream csv;
    csv.open("csv/logs.csv");
    for(auto const &it: eventsAccounts){
        csv<<it.second<<";"<<it.first<<"\n";
    }
    csv.close();

    cout<<"archivo creado en la ruta csv/logs.csv";
}

void EventosDeCuentas::showFirstTen(){

    long count=0;
    multimap<long,string> eventsAccounts;

    for (auto const &account: colection){
        for(auto const &eventType: account.second){
            count-=eventType.second;
        }
        eventsAccounts.insert(pair <long,string>(count,account.first));
        count=0;
    }

    int i=0;
    for(auto const &it : eventsAccounts){
        cout<<it.second<<": "<<it.first*(-1)<<endl;
        i++;
        if(i>=10){
            break;
        }
    }

}

void EventosDeCuentas::showEventsAndTypes(){
    map <string,long> totalEvents;
    multimap <long, string> totalEventsOrganized;

    for (auto const &account: colection){
        for(auto const &eventType: account.second){
            totalEvents[eventType.first]+=eventType.second;
        }
    }

    for(auto const &event: totalEvents){
        totalEventsOrganized.insert(pair <long,string>(-event.second,event.first));
    }

    for(auto const &it : totalEventsOrganized){
        cout<<it.second<<": "<<it.first*(-1)<<endl;
    }


}

void EventosDeCuentas::insert(string account, string event){
    numEvents++;
    colection[account][event]++;
}


#endif