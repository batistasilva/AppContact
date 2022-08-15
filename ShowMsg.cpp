/* 
 * File:   ShowMsg.cpp
 * Author: batista
 * 
 * Created on 8 de Mar�o de 2013, 20:45
 */

#include "ShowMsg.h"

ShowMsg::ShowMsg() {
}

ShowMsg::~ShowMsg() {
}

void ShowMsg::ShowMessage(string message, int first_color, int second_color) {
    int lenght_msg, lenght, i;
    //char colors[][20] = {"\033[01;30m\033[22;47m", "\033[01;31m\033[22;47m", "\033[01;32m\033[22;47m", "\033[01;33m\033[22;47m", "\033[01;34m\033[22;47m", "\033[01;35m\033[22;47m", "\033[01;36m\033[22;47m", "\033[01;37m\033[43m", "\033[0m"};

    char colors[][20] = {"\033[02;30m", "\033[02;31m", "\033[02;32m", "\033[02;33m", "\033[02;34m", "\033[02;35m", "\033[02;36m", "\033[02;37m", "\033[0m"};
    lenght_msg = message.length() + 6; //tamanho da mensagem
    lenght = message.length(); //tamanho da mensagem

    for (i = 0; i < lenght_msg; i++)
        cout << colors[first_color] << '*';

    cout << "\n*  ";
    for (i = 0; i < lenght; i++)
        cout << " ";
    cout << "  *" << endl;
    cout << endl;
    // cout << colors[second_color] << "[" << __FILE__ << ":" << __LINE__ << "] " << colors[first_color] << endl;
    //
    cout << "   " << colors[second_color] << message << colors[first_color] << endl;

    cout << "\n*  ";
    for (i = 0; i < lenght; i++)
        cout << " ";
    cout << "  *" << endl;

    for (i = 0; i < lenght_msg; i++)
        cout << '*';

    cout << colors[8] << "\n\n";
}


