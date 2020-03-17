#include <map>
#include <string>
#include <iostream>
#include "../ui/UI.hpp"

using namespace std;


int main(){

    UI *ui = UI::getInstance();
    ui->init();

    return 0;
}

