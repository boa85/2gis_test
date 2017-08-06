# 2gis_test

## 2GIS тестовое задание

Напишите (консольную) программу, принимающую на вход  имя файла и набор параметров. 
В зависимости от параметров программа должна работать в трёх режимах:

1)      test -f Test.tst -m words -v mother

печатает количество слов «mother» в файле «Test.tst»

2)      test -f Test.tst -m checksum

печатает 32-битную чексумму, рассчитанную по алгоритму 
checksum = word1 + word2 + … + wordN (word1..wordN – 32-хбитные слова, представляющие содержимое файла)

3)      test -h

печатает информацию о программе и описание параметров.

## Сборка и запуск:
### Установка зависимостей для сборки на Ubuntu 16.04:
*      sudo apt install git build-essential cmake  libboost-all-dev libboost-filesystem1.58.0 libboost-program-options1.58.0
### Сборка проекта

*      git clone https://github.com/boa85/2gis_test.git
*      cd ${project_source_dir}
*      mkdir cmake-build-debug
*      cd cmake-build-debug/
*      cmake ..
*      make

###  Запуск
*      ./2gis_test --help #Показать справку
*      ./2gis_test -m word -f test.tst -w mother #Посчитать количество вхождений слова в текс
*      ./2gis_test -m checksum -f test.tst #Вычислить чексумму.
