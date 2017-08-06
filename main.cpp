#include <iostream>

#include "args_parser/include/argument_parser.hpp"
#include "command_handler/include/command_handler.hpp"
#include "args_parser/include/args_parse_exception.hpp"
#include "command_handler/include/invoker.hpp"
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
using namespace two_gis_test;
using namespace argument_parser;
using namespace command_handler;
int main(int argc, char *argv[]) {
    try {
        auto parser = std::make_shared<ArgumentParser>();
        auto invoker = std::make_shared<Invoker>();
        auto commandHandler = std::make_shared<CommandHandler>();
        parser->countOccurrencesWord.connect(boost::bind(&Invoker::countOccurrencesWord, invoker, _1, _2));
        parser->calculateChecksum.connect(boost::bind(&Invoker::calculateCheckSum, invoker, _1));
        invoker->start.connect(boost::bind(&CommandHandler::start, commandHandler, _1));
        parser->startParsing(argc, argv);
    }
    catch (ArgsParseException &e) {
        std::cerr << e.what() << std::endl;
    }
    catch (std::exception &exception) {
        std::cerr << exception.what() << std::endl;
    }
    return 0;
}