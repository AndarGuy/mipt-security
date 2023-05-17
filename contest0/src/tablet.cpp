/*

Кряк!

- Да что они могут, эти Гавс! Даже крякать толком не умеют! - сказал Флинтхарт Гломгольд. - Правильный-то код программа
не принимает! Вот я крякну, как самый лучший селезень мира! Так, что программа будет принимать любой код! Я продам
программу из предыдущего эпизода (assets/victim-1) и стану самым богатым селезнем в мире!

Флинтхарт Гломгольд не читал лекции на сайте и не решал контесты. Зато он знает, что Вы работали на Гавс, и грозится
сдать Вас полиции, если Вы не напишете для него программу, которая изменяет исполняемый файл программы так, чтобы она
принимала любой ключ, даже если в него внесут доработки, изменяющие положение кода, проверяющего ключ.

*/

#include <iostream>
#include <fstream>

#define INPUT "source"
#define OUTPUT "cracked"
#define BUFFSIZE 12 * 1024

int main() {
    std::ifstream fin(INPUT, std::ios::in | std::ios::binary);
    unsigned char buffer[BUFFSIZE];
    fin.read((char*)buffer, BUFFSIZE);
    std::streamsize read = fin.gcount();
    unsigned char pattern[] = {0x75, 0x11, 0x68, 0x2b, 0xa0, 0x04, 0x08, 0xe8};
    for (size_t i = 0; i < BUFFSIZE; i++) {
        bool matched = true;
        for (size_t j = 0; j < sizeof(pattern) && matched; j++) {
            if (pattern[j] != buffer[i + j]) {
                matched = false;
            }
        }
        if (matched) {
            buffer[i] = 0x90;
            buffer[i + 1] = 0x90;
        }
    }
    std::ofstream fout(OUTPUT, std::ios::out | std::ios::binary);
    fout.write((char*)buffer, read);

    return 0;
}