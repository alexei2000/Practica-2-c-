#ifndef FORMATLOGS_HPP
#define FORMATLOGS_HPP

#include <fstream>
#include <iostream>
#include "../eventosDeCuenta/EventosDeCuenta.hpp"


using namespace std;

class FormatLogs{

    private:
        static FormatLogs *instance;
        fstream fe;
        FormatLogs(){}
        string extractWord(string line);

    public:
        static FormatLogs *getInstance();
        void readFileAndInsert(string url, EventosDeCuentas &events, string date);

};

FormatLogs* FormatLogs::instance = NULL;


FormatLogs* FormatLogs::getInstance(){
    if (instance == NULL){
        instance = new FormatLogs();
    }
    return instance;
}

void FormatLogs::readFileAndInsert(string url, EventosDeCuentas &events, string date){

    fstream fe(url);
    int numLine = 0, contentPos=0;
    string line,type,account;
    const string typeFind="'event_type': '",accountFind="'account': '";

    if(! fe.is_open()){
        cout<<"Archivo no encontrado"<<endl;
        return;
    }
    else{
        while(!fe.eof()){
            getline(fe,line);
            numLine++;

            if(line.find(date) != string::npos){
                if(line.find("SIGNALHANDLER") != string::npos){
                    line = line.substr(line.find(typeFind) + typeFind.size());
                    type = extractWord(line);

                    line = line.substr(line.find(accountFind) + accountFind.size());
                    account = extractWord(line);

                    events.insert(account,type);
                }
            }
            line.clear();
        }

        fe.close();
    }

    events.setNumLogs(numLine);

}

string FormatLogs::extractWord(string line){
    string word;
    bool band = true;

    for(int i=0; band ; i++){
        if(line[i] != '\''){
            word.push_back(line[i]);
        }
        else{
            band = false;
        }
    }

    return word;
}

#endif