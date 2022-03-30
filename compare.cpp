#include <iostream>
#include <fstream>
#include <windows.h>

using namespace std;

int main(){
    unsigned int ad_len, my_addresses = 0, winners = 0, res = 0;
    string address;
    char *str1 = new char[ad_len];

    ifstream fin1("my addresses.txt");  //Открываем файл с моими адресами
    fin1 >> address;                    //считываем первую строку(адрес)
    ad_len = address.size() + 1;        //получаем длину адреса

    cout << "\nLength of the address: " << ad_len - 1 << endl; //Выводим длину адреса

    while (!fin1.eof()){                //Считаем количество адресов, которые будем сравнивать
        fin1.getline(str1, ad_len);
        my_addresses++;
    }
    
    cout << "Count of your addresses: " << my_addresses << endl; //Выводим количество адресов, которые будем сравнивать
    cout << "\nCount of your addresses: " << my_addresses << endl; // Выводим количество адресов, которые будем сравнивать

    char *str2 = new char[ad_len];
    ifstream fin2("winners.txt");
    while (!fin2.eof()){
        fin2.getline(str2, ad_len);
            winners++;
    }
    cout << "Count of Winners: " << winners << endl << endl; // Выводим количество адресов, с которыми будем сравнивать

    fin1.clear(); // Возвращаем указатели к началу файлов
    fin1.seekg(0);
    fin2.clear();
    fin2.seekg(0);

    for(int i = 0; i < my_addresses; ++i){
        fin1.getline(str1, ad_len);       // Считываем адрес из первого файла
        for(int j = 0; j < winners; ++j){
            fin2.getline(str2, ad_len);   // Считываем адрес из второго файла
            if(strcmp(str1, str2) == 0){                 // Сравниваем адреса
                cout << res + 1 << ") " << str1 << endl; // Если адреса совпали, выводим совпадение
                res++;
                fin2.seekg(0);
                break;
            }
        }
    }
    cout << endl;

    delete[] str1; // Очистка памяти
    delete[] str2;

    cout << "\nResult = " << res << endl << endl; // Вывод количества совпадений

    return 0;
}