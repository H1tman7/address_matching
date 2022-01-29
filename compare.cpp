#include <iostream>
#include <fstream>
#include <windows.h>

using namespace std;

int main(){
    int ad_len = 43, my_addresses = 0, winners = 0, res = 0;

    char *str1 = new char[ad_len];
    ifstream fin1("my addresses.txt");
    while (!fin1.eof()){
        fin1.getline(str1, ad_len);
        my_addresses++;
    }
    cout << "\nCount of your addresses: " << my_addresses << endl; //Выводим количество адресов, которые будем сравнивать

    char *str2 = new char[ad_len];
    ifstream fin2("winners.txt");
    while (!fin2.eof()){
        fin2.getline(str2, ad_len);
            winners++;
    }
    cout << "Count of Winners: " << winners << endl << endl; // Выводим количество адресов, с которыми будем сравнивать

    fin2.clear(); // Возвращаем указатели к началу файлов
    fin1.clear();
    fin2.seekg(0); 
    fin1.seekg(0);

    for(int i = 0; i < my_addresses; ++i){
        fin1.getline(str1, ad_len);       //Считываем адрес из первого файла
        for(int j = 0; j < winners; ++j){
            fin2.getline(str2, ad_len);   // Считываем адрес из второго файла
            if(strcmp(str1, str2) == 0){  // Сравниваем адреса
                cout << res + 1 << ") " << str1 << endl; //Если адреса совпали, выводим совпадение
                res++;
                break;
            }
        }
    }

    fin1.close(); //Закрытие файлов
    fin2.close();

    delete[] str1; //Очистка памяти
    delete[] str2;

    cout << "\nResult = " << res << endl << endl; //Вывод количества совпадений
    
    return 0;
}