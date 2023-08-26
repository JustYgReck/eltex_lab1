# eltex_lab1

## П.1
Задача: реализовать внешние функции (у меня - деление нацело и по модулю);

Используемые файлы: 
f1.c, f2.c, main.c

Сборка: 
$ gcc -c main.c f1.c f2.c
$ gcc main.o f1.o f2.o -o rezult

Запуск:
./rezult <делимое> <делитель>

Вывод:
- Первая ф-ия - деление нацело;
- Вторая ф-ия - деление по модулю.

## П.2
Задача: переоформить ф-ии в виде статической библиотеки;

Используемые файлы: 
f1.c, f2.c, main.c

Сборка:
$ gcc -c main.c f1.c f2.c
$ ar rc liblab1.a f1.o f2.o
$ ranlib liblab1.a
$ gcc main.o -L. -llab1 -o rezultStatic

Запуск:
./rezultStatic <делимое> <делитель>

Вывод:
- Первая ф-ия - деление нацело;
- Вторая ф-ия - деление по модулю.

## П.3
Задача: переоформить программу с использованием динамической библиотеки, подгружаем при компиляции;

Используемые файлы:
f1.c, f2.c, main.c

Сборка:
$ gcc -c main.c
$ gcc -fPIC -c f1.c -o f1PIC.o
$ gcc -fPIC -c f2.c -o f2PIC.o
$ gcc -shared -o liblab1dyn.so f1PIC.o f2PIC.o
$ gcc main.o -L. -llab1dyn -o rezultDyn

(!!) Дополнительно добавляем директорию проекта в переменную LD_LIBRARY_PATH:
    $ LD_LIBRARY_PATH=$(pwd)
    $ export LD_LIBRARY_PATH

Использование:
./rezultDyn <делимое> <делитель>

## П.4
Задача: изменить программу для динамической загрузки ф-ий из библиотеки;

Используемые файлы:
f1.c, f2.c, mainDL.c

Сборка:
$ gcc -fPIC -c f1.c -o f1PIC.o
$ gcc -fPIC -c f2.c -o f2PIC.o
$ gcc -shared -o libdivide.so f1PIC.o f2PIC.o
$ gcc mainDL.c -ldl -o rezultDL

Использование:
./rezultDL <идентификатор ф-ии> <делимое> <делитель>

(пример: ./rezultDL f1 100 3)
(f1 - деление нацело, ответ д.б. равен 30)
