//
//  main.cpp
//  txt_game(test)
//
//  Created by makromant on 14/11/2016.
//  Copyright © 2016 makromant. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <curses.h>
#include "find_txt.h"
using namespace std;

int main()
{
    string ch;
    char ch1,ch2,ch3;
    string str_out;
    char n_char;
    ifstream annot ("/txt/annot.txt");
    //измените на свою директорию
    ifstream start ("/txt/start.txt");
    //измените на свою директорию
    ifstream info  ("/txt/info.txt");
    //измените на свою директорию
    char start_page;
    while (1)
    {
        cout << "играть[s]" << endl;
        cout << "информация[i]";
        cin >> start_page;
        system("clear");
        if (start_page == 's')
            break;
        if (start_page == 'i')
        {
            while(!info.eof())
            {
                info.get(n_char);
                cout << n_char;
            }
            cout << endl << "венуться[b]";
            while (1)
            {
                cin >> start_page;
                system("clear");
                if (start_page=='b')
                    break;
            }
        }
    }
    while (!annot.eof())
    {
        annot.get(n_char);
        cout << n_char;
    }
    cout << endl << endl;
    while (!start.eof())
    {
        start.get(n_char);
        cout << n_char;
    }
    while (1)
    {
        cout << "Введите номер страницы (напрмер 094, 94 страница и тп.)" << endl;
        cin >> ch;
        while (!ch[0] || !ch[1] || !ch[2])
        {
            cout << "Не правильный тип ввода! Попробуйте еще раз" << endl;
            cin >> ch;
        }
        system("clear");
        ch1 = (char)ch[0];
        ch2 = (char)ch[1];
        ch3 = (char)ch[2];
        str_out = find(ch1, ch2, ch3); // take needed page
        if (str_out[1] == '=')
        {
            str_out[1]=' ';
            cout << str_out << endl << endl;
            break;
        }
        else
            cout << str_out << endl;
    }


    return 0;
}
