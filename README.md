# 2gis_test

## 2GIS тестовое задание

Напишите (консольную) программу, принимающую на вход  имя файла и набор параметров. 
В зависимости от параметров программа должна работать в трёх режимах:

1) посчитать количество слов «mother» в файле «Test.tst»
2) посчитать 32-битную чексумму, рассчитанную по алгоритму checksum = word1 + word2 + … + wordN (word1..wordN – 32-хбитные слова, представляющие содержимое файла)
3) вывод информации о программе и описание параметров.

## Сборка и запуск:
### Зависимости для сборки:
* git
* build-essential
* cmake
* libboost-all-dev
* libboost-filesystem версии не ниже 1.58.0
* libboost-program-options версии не ниже 1.58.0
### Пример установки зависимостей для ubuntu 16.04
      sudo apt install git build-essential cmake  libboost-all-dev libboost-filesystem1.58.0 libboost-program-options1.58.0
### Сборка проекта

* Клонирование из репозитория в локальный каталог

      git clone https://github.com/boa85/2gis_test.git
* Переход в каталог с исходным кодом

      cd ${project_source_dir}
* Создание дирректории для работы cmake и переход в неё

      mkdir cmake-build-debug && cd ./cmake-build-debug/
* Запуск cmake для генерации Makefile

      cmake ..
* Сборка проекта 

      make

###  Запуск

* Отобразить справку

      ./2gis_test --help
* Посчитать количество вхождений слова в текст

      ./2gis_test -m word -f test.tst -w mother
* Вычислить чексумму.

      ./2gis_test -m checksum -f test.tst
