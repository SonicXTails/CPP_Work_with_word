#include <iostream>                             // Подключаем библиотеку ввода-вывода
#include <string>                               // Подключаем библиотеку для работы со строками
#include <algorithm>                            // Подключаем библиотеку для работы с алгоритмами
#include <random>                               // Подключаем библиотеку для генерации случайных чисел
#include <locale>                               // Подключаем библиотеку для работы с локализацией
#include <io.h>                                 // Подключаем библиотеку для работы с консолью
#include <numeric>                              // Подключаем библиотеку для работы с числовыми операциями

using namespace std;                            

class Methods {                                 
public: 

    wstring Reverse(wstring word) { 
        reverse(word.begin(), word.end());      // Разворачиваем строку с помощью Linq-запроса reverse (учитывая начало и конец)
        return word;                            // Возвращаем развернутую строку
    }


    wstring removeVowels(const wstring& str) {
        wstring result;                    
        const wstring vowels = L"йцкнгшщзхфвпрлджчсмтбЙЦКНГШЩЗХФВПРЛДЖЧСМТБ"; 

        for (wchar_t c : str) { 
            if (vowels.find(c) != wstring::npos) { 
                result += c;
            }
        }

        return result;
    }

    wstring removeConsonants(const wstring& str) {
        wstring result;
        const wstring consonants = L"аеёиоуыэюяАЕЁИОУЫЭЮЯ";

        for (wchar_t c : str) {                 
            if (consonants.find(c) != wstring::npos) { 
                result += c;
            }
        }

        return result;
    }

    wstring Shuffle(wstring word) {             // Метод для перемешивания символов в строке
        random_device rd;                       // Генератор случайных чисел
        mt19937 g(rd());                        // Мерсенский твистер
        shuffle(word.begin(), word.end(), g);   // Перемешиваем символы в строке
        return word;                            // Возвращаем перемешанную строку
    }
};

int main() {                                    
    Methods Method;     

    setlocale(LC_ALL, "RUS");                   // Устанавливаем локаль для русского языка
    system("chcp 1251 > nul");                  // Устанавливаем кодировку консоли в cp1251

    wstring word;                               
    wcout << L"Введите слово: "; 
    getline(wcin, word); 

    int choice; 
    wcout << L"Выберите действие:\n"; 
    wcout << L"1. Слово задом наперед\n"; 
    wcout << L"2. Вывести слово без гласных\n"; 
    wcout << L"3. Вывести слово без согласных\n"; 
    wcout << L"4. Рандомно раскидать буквы в слове\n"; 
    wcin >> choice; 

    wstring result;                             
    switch (choice) {                           
    case 1:                                     
        result = Method.Reverse(word);          
        break;                                  
    case 2:                                     
        result = Method.removeVowels(word);     
        break;                                  
    case 3:                                     
        result = Method.removeConsonants(word); 
        break;                                  
    case 4:                                     
        result = Method.Shuffle(word);          
        break;                                  
    default:                                    
        wcout << L"Некорректный выбор." << endl;
        return 0; 
    }

    wcout << result << endl; 

    return 0; 
}
