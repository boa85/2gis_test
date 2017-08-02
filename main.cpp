#include <iostream>
#include "args_parser/include/argument_parser.hpp"
#include "command_handler/include/command_handler.hpp"
/**
 * Напишите (консольную) программу, принимающую на вход  имя файла и набор параметров.
 * В зависимости от параметров программа должна работать в трёх режимах:
 * 1)      test -f Test.tst -m words -v mother
 * печатает количество слов «mother» в файле «Test.tst»
 * 2)      test -f Test.tst -m checksum
 * печатает 32-битную чексумму, рассчитанную по алгоритму
 * checksum = word1 + word2 + … + wordN (word1..wordN – 32-хбитные слова, представляющие содержимое файла)
 * 3)      test -h
 * печатает информацию о программе и описание параметров.
 *
 */
using namespace word_counter;
using namespace argument_parser;
using namespace command_handler;
int main(int argc, char *argv[]) {
    try {
        auto parser = std::make_shared<ArgumentParser>();
        auto commandHandler = std::make_shared<CommandHandler>();
        parser->count.connect(boost::bind(&CommandHandler::countWords, commandHandler, _1, _2));
        parser->checksum.connect(boost::bind(&CommandHandler::calculateChecksum, commandHandler, _1));
        parser->startParsing(argc, argv);
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }


    return 0;
}