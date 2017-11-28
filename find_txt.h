//
//  find_txt.h
//  txt_game(test)
//
//  Created by makromant on 14/11/2016.
//  Copyright © 2016 makromant. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
using namespace std;

string find(char ch1, char ch2, char ch3) {
    setlocale(LC_ALL, "Russian");
    ifstream txt ("/txt/text.txt");
    //измените на свою директорию
    char str;
    bool stop=false;
    string all_string="";
    while(!txt.eof())
    {
        txt.get(str);
        if (str == '[')
        {
            txt.get(str);
        }
        if (str == ch1)
        {
            txt.get(str);
            if (str == ch2)
            {
                txt.get(str);
                if (str == ch3)
                {
                    stop=true;
                    break;
                }

            }

        }

    }
    if (stop)
    {
    while(!txt.eof())
    {
        txt.get(str);
        if (str == '=')
        {
            all_string += "=";
            txt.get(str);
        }
        if (str == '+')
            break;
        all_string += (char) str;
    }
    }
    if (all_string=="")
    {
        all_string="Не существует такой страницы!";
    }
    return all_string;
}
