/*

- Да что они могут, эти утки! Только крякать! - сказал один из братьев Гавс.

- Ну и вы крякните, - сказала Мамаша Гавс, - крякните программу (assets/victim-1), чтобы она принимала любой другой
ключ, и продавайте её!

К сожалению, братья Гавс не слушали лекций Дмитрия Станиславовича и не ходили на семинары по информатике. Зато они
поймали Вас и потребовали написать программу, которая изменяет исполняемый файл программы так, чтобы она принимала любой
ключ, кроме правильного. И поторопитесь: паяльник уже нагревается, а ни припоя, ни канифоли нигде не видно....

*/

#include <iostream>
#include <fstream>

#define INPUT "source"
#define OUTPUT "cracked"
#define BUFFSIZE 12 * 1024

int main() {
    std::ifstream fin(INPUT, std::ios::in | std::ios::binary);
    char buffer[BUFFSIZE];
    fin.read(buffer, BUFFSIZE);
    std::streamsize read = fin.gcount();
    buffer[0x4b0] = 0x74;
    std::ofstream fout(OUTPUT, std::ios::out | std::ios::binary);
    fout.write(buffer, read);

    return 0;
}