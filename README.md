# Laboratory work III

Данная лабораторная работа посвещена изучению систем автоматизации сборки проекта на примере CMake
```bash
$ open https://cmake.org/
```

## Tasks
- 1. Создать публичный репозиторий с названием lab03 на сервисе GitHub
- 2. Ознакомиться со ссылками учебного материала
- 3. Выполнить инструкцию учебного материала
- 4. Составить отчет и отправить ссылку личным сообщением в Slack

## Студент
Малыхин Кирилл Группа: ИУ8-21  
Дата: 04.04.2026  

---

## Tutorial
```bash
$ export GITHUB_USERNAME=<имя_пользователя>
$ cd ${GITHUB_USERNAME}/workspace
$ pushd .
```
**Вывод**
```
~/Desktop/Leikmadur/workspace ~/Desktop/Leikmadur/workspace
```

```bash
$ source scripts/activate
```

```bash
$ git clone https://github.com/${GITHUB_USERNAME}/lab02.git projects/lab03
```
**Вывод**
```
Cloning into 'projects/lab03'...
remote: Enumerating objects: 56, done.
remote: Counting objects: 100% (56/56), done.
remote: Compressing objects: 100% (44/44), done.
remote: Total 56 (delta 13), reused 40 (delta 6), pack-reused 0 (from 0)
Receiving objects: 100% (56/56), 14.41 KiB | 421.00 KiB/s, done.
Resolving deltas: 100% (13/13), done.
```

```bash
$ cd projects/lab03
$ git remote remove origin
$ git remote add origin https://github.com/${GITHUB_USERNAME}/lab03.git
```

```bash
$ g++ -std=c++11 -I./include -c sources/print.cpp
$ ls print.o
```

```bash
$ git pull origin main
$ git log
```
**Вывод**
```
print.o
```

```bash
$ nm print.o | grep print
```
**Вывод**
```
0000000000000000 T _Z5printRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEERSo
000000000000002a T _Z5printRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEERSt14basic_ofstreamIcS2_E
```


```bash
$ ar rvs print.a print.o
```
**Вывод**
```
ar: creating print.a
a - print.o
```

```bash
$ file print.a
```

**Вывод**
```
print.a: current ar archive
```

```bash 
$ g++ -std=c++11 -I./include -c examples/example1.cpp
$ ls example1.o
```
**Вывод**
```
example1.o
```

```bash
$ g++ example1.o print.a -o example1
$ ./example1 && echo
```
**Вывод**
```
hello
```

```bash
$ g++ -std=c++11 -I./include -c examples/example2.cpp
$ nm example2.o
```

**Вывод**
```
0000000000000000 V DW.ref.__gxx_personality_v0
                 U __gxx_personality_v0
0000000000000000 T main
                 U __stack_chk_fail
                 U _Unwind_Resume
                 U _Z5printRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEERSt14basic_ofstreamIcS2_E
                 U _ZNSt14basic_ofstreamIcSt11char_traitsIcEEC1EPKcSt13_Ios_Openmode
                 U _ZNSt14basic_ofstreamIcSt11char_traitsIcEED1Ev
0000000000000000 W _ZNSt15__new_allocatorIcED1Ev
0000000000000000 W _ZNSt15__new_allocatorIcED2Ev
0000000000000000 n _ZNSt15__new_allocatorIcED5Ev
                 U _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1EPKcRKS3_
                 U _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev
                 U _ZSt21ios_base_library_initv
0000000000000000 r _ZStL19piecewise_construct
```

```bash
$ g++ example2.o print.a -o example2
$ ./example2
```

```bash
$ cat log.txt && echo
```

**Вывод**
```
hello
```

```bash
$ rm -rf example1.o example2.o print.o
$ rm -rf print.a
$ rm -rf example1 example2
$ rm -rf log.txt
```

```bash
$ cat > CMakeLists.txt <<EOF

cmake_minimum_required(VERSION 3.10)
project(print)
EOF
```

```bash
$ cat >> CMakeLists.txt <<EOF

add_library(print STATIC \${CMAKE_CURRENT_SOURCE_DIR}/sources/print.cpp)
EOF
```

```bash
$ cat >> CMakeLists.txt <<EOF

include_directories(\${CMAKE_CURRENT_SOURCE_DIR}/include)
EOF
```

```bash
$ cat >> CMakeLists.txt <<EOF

include_directories(\${CMAKE_CURRENT_SOURCE_DIR}/include)
EOF
```

```bash
$ cmake -H. -B_build
```
**Вывод**
```
-- The C compiler identification is GNU 13.3.0
-- The CXX compiler identification is GNU 13.3.0
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Check for working C compiler: /usr/bin/cc - skipped
-- Detecting C compile features
-- Detecting C compile features - done
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: /usr/bin/c++ - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Configuring done (0.7s)
-- Generating done (0.0s)
-- Build files have been written to: /home/kirill/Desktop/Leikmadur/workspace/projects/lab03/_build
```

```bash
$ cmake --build _build
```
**Вывод**
```
[ 50%] Building CXX object CMakeFiles/print.dir/sources/print.cpp.o
[100%] Linking CXX static library libprint.a
[100%] Built target print
```

```bash
$ cat >> CMakeLists.txt <<EOF

add_executable(example1 \${CMAKE_CURRENT_SOURCE_DIR}/examples/example1.cpp)
add_executable(example2 \${CMAKE_CURRENT_SOURCE_DIR}/examples/example2.cpp)
EOF
```

```bash
$ cat >> CMakeLists.txt <<EOF

target_link_libraries(example1 print)
target_link_libraries(example2 print)
EOF
```

```bash
$ cmake --build _build
```
**Вывод**
```
-- Configuring done (0.1s)
-- Generating done (0.0s)
-- Build files have been written to: /home/kirill/Desktop/Leikmadur/workspace/projects/lab03/_build
[ 33%] Built target print
[ 50%] Building CXX object CMakeFiles/example1.dir/examples/example1.cpp.o
[ 66%] Linking CXX executable example1
[ 66%] Built target example1
[ 83%] Building CXX object CMakeFiles/example2.dir/examples/example2.cpp.o
[100%] Linking CXX executable example2
[100%] Built target example2
```

```bash
$ cmake --build _build --target print
```
**Вывод**
```
[100%] Built target print
```

```bash
$ cmake --build _build --target example1
```
**Вывод**
```
[ 50%] Built target print
[100%] Built target example1
```

```bash
$ cmake --build _build --target example2
```

**Вывод**
```
[ 50%] Built target print
[100%] Built target example2
```

```bash
$ ls -la _build/libprint.a
```

**Вывод**
```
-rw-rw-r-- 1 kirill kirill 2246 Mar 30 22:44 _build/libprint.a
```

```bash
$ _build/example1 && echo
```

**Вывод**
```
hello
```

```bash
$ _build/example2
$ cat log.txt && echo
```

**Вывод**
```
hello
```

```bash
$ rm -rf log.txt
$ git clone https://github.com/tp-labs/lab03 tmp
```
**Вывод**
```
Cloning into tmp
remote Enumerating objects: 59, done.
remote Counting objects: 100% (59/59), done.
remote Delta compression using up to 2 threads
remote Compressing objects: 100% (40/40), done.
remote Total 59 (delta 14), reused 55 (delta 13), pack-reused 0
Receiving objects: 100% (59/59), 15.13 KiB | 7.57 MiB/s, done.
remote: Resolving deltas: 100% (14/14), done.

```
```bash
$ mv -f tmp/CMakeLists.txt .
$ rm -rf tmp
```

```bash
$ cat CMakeLists.txt
```

**Вывод**
```
cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(BUILD_EXAMPLES "Build examples" OFF)

project(print)

add_library(print STATIC ${CMAKE_CURRENT_SOURCE_DIR}/sources/print.cpp)

target_include_directories(print PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)

if(BUILD_EXAMPLES)
  file(GLOB EXAMPLE_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/examples/*.cpp")
  foreach(EXAMPLE_SOURCE ${EXAMPLE_SOURCES})
    get_filename_component(EXAMPLE_NAME ${EXAMPLE_SOURCE} NAME_WE)
    add_executable(${EXAMPLE_NAME} ${EXAMPLE_SOURCE})
    target_link_libraries(${EXAMPLE_NAME} print)
    install(TARGETS ${EXAMPLE_NAME}
      RUNTIME DESTINATION bin
    )
  endforeach(EXAMPLE_SOURCE ${EXAMPLE_SOURCES})
endif()

install(TARGETS print
    EXPORT print-config
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
)

install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/ DESTINATION include)
install(EXPORT print-config DESTINATION cmake)
```

```bash
$ cmake -H. -B_build -DCMAKE_INSTALL_PREFIX=_install
```
**Вывод**
```
[100%] Built target print
Install the project...
-- Install configuration: ""
-- Installing: /home/kirill/Desktop/Leikmadur/workspace/projects/lab03/_install/lib/libprint.a
-- Installing: /home/kirill/Desktop/Leikmadur/workspace/projects/lab03/_install/include
-- Installing: /home/kirill/Desktop/Leikmadur/workspace/projects/lab03/_install/include/print.hpp
-- Installing: /home/kirill/Desktop/Leikmadur/workspace/projects/lab03/_install/cmake/print-config.cmake
-- Installing: /home/kirill/Desktop/Leikmadur/workspace/projects/lab03/_install/cmake/print-config-noconfig.cmake
```

```bash
$ sudo snap install tree
```
**Вывод**
```
[sudo] password for kirill: 
tree 2.1.3+pkg-5852 from 林博仁 Buo-ren Lin (brlin) installed
```

```bash
$ git add CMakeLists.txt
$ git commit -m"added CMakeLists.txt"
```
**Вывод**
```
[main 7378b9c] added CMakeLists.txt
 1 file changed, 36 insertions(+)
 create mode 100644 CMakeLists.txt
```

```bash
$ git push origin main
```

##Report

```bash
$ popd
$ export LAB_NUMBER=03
$ git clone https://github.com/tp-labs/lab${LAB_NUMBER} tasks/lab${LAB_NUMBER}
$ mkdir reports/lab${LAB_NUMBER}
$ cp tasks/lab${LAB_NUMBER}/README.md reports/lab${LAB_NUMBER}/REPORT.md
$ cd reports/lab${LAB_NUMBER}
$ edit REPORT.md
$ gist REPORT.md
```


## Homework

Представьте, что вы стажер в компании "Formatter Inc.".

### Задание 1

#### Вам поручили перейти на систему автоматизированной сборки CMake. Исходные файлы находятся в директории formatter_lib. В этой директории находятся файлы для статической библиотеки formatter. Создайте CMakeList.txt в директории formatter_lib, с помощью которого можно будет собирать статическую библиотеку formatter.

- 1. Создаем папку formatter_lib:

```bash
$ mkdir formatter_lib
```

- 2. В этой папке cоздаем CMakeLists.txt с этим текстом

```
cmake_minimum_required(VERSION 3.10)
project(formatter)

add_library(formatter STATIC formatter.cpp)

target_include_directories(formatter PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
```
- 3. Создаем formatter.cpp:

```bash
#include "formatter.h"

std::string formatter(const std::string& message)
{
    std::string res;
    res += "-------------------------\n";
    res += message + "\n";
    res += "-------------------------\n";
    return res;
}
```
- 4. Создаем formatter.h:
```bash
#pragma once

#include <string>

std::string formatter(const std::string& message);
```


### Задание 2

#### У компании "Formatter Inc." есть перспективная библиотека, которая является расширением предыдущей библиотеки. Т.к. вы уже овладели навыком созданием CMakeList.txt для статической библиотеки formatter, ваш руководитель поручает заняться созданием CMakeList.txt для библиотеки formatter_ex, которая в свою очередь использует библиотеку formatter.

- 1. Создаем папку formatter_ex.

```bash
$ mkdir formatter_ex
```

- 2. В этой папке cоздаем CMakeLists.txt с этим текстом

```bash
cmake_minimum_required(VERSION 3.10)
project(formatter_ex)

add_library(formatter_ex STATIC formatter_ex.cpp)

target_include_directories(formatter_ex PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(formatter_ex formatter)
```

- 3. Создаем файл formatter_ex.cpp:

```bash
#include "formatter_ex.h"

#include "formatter.h"

std::ostream& formatter(std::ostream& out, const std::string& message)
{
    return out << formatter(message);
}
```

- 4. Создаем файл formatter_ex.h.

```bash
#pragma once

#include <string>
#include <iostream>

std::ostream& formatter(std::ostream& out, const std::string& message);
```


### Задание 3

#### Note: Конечно же ваша компания предоставляет примеры использования своих библиотек. Чтобы продемонстрировать как работать с библиотекой formatter_ex, вам необходимо создать два CMakeList.txt для двух простых приложений: hello_world, которое использует библиотеку formatter_ex; solver, приложение которое испольует статические библиотеки formatter_ex и solver_lib.


- 1. Cоздаем папку hello_world:
```bash
$ mkdir hello_world
```

- 2. В этой папке cоздаем CMakeLists.txt с этим текстом
```bash
cmake_minimum_required(VERSION 3.10)
project(hello_world)

add_executable(hello_world main.cpp)

target_link_libraries(hello_world formatter_ex)
```
- 3. Создаем файл  hello_world.cpp:

```bash
#include <iostream>

#include "formatter_ex.h"

int main()
{
    formatter(std::cout, "hello, world!");
}
```

- 4. Cоздаем папку solver:
```bash
$ mkdir solver
```

- 5. В этой папке cоздаем CMakeLists.txt с этим текстом

```bash
cmake_minimum_required(VERSION 3.10)
project(solver)

add_executable(solver main.cpp)

target_link_libraries(solver formatter_ex solver_lib)
```

- 6. Создаем файл  equation.cpp:
```bash
#include <iostream>

#include "formatter_ex.h"
#include "solver.h"

int main()
{
    float a = 0;
    float b = 0;
    float c = 0;

    std::cin >> a >> b >> c;

    float x1 = 0;
    float x2 = 0;

    try
    {
        solve(a, b, c, x1, x2);

        formatter(std::cout, "x1 = " + std::to_string(x1));
        formatter(std::cout, "x2 = " + std::to_string(x2));
    }
    catch (const std::logic_error& ex)
    {
        formatter(std::cout, ex.what());
    }

    return 0;
}
```

- 7. Cоздаем папку solver_lib:
```bash
$ mkdir solver_lib
```

- 8. В этой папке cоздаем CMakeLists.txt с этим текстом:

```bash
cmake_minimum_required(VERSION 3.10)
project(solver_lib)

add_library(solver_lib STATIC solver.cpp)

target_include_directories(solver_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
```

- 9. Создаем файл solver.cpp:
```bash
#include "solver.h"
#include <cmath>
#include <stdexcept>

void solve(float a, float b, float c, float& x1, float& x2)
{
    float d = (b * b) - (4 * a * c);

    if (d < 0)
    {
        throw std::logic_error{"error: discriminant < 0"};
    }

    x1 = (-b - std::sqrt(d)) / (2 * a);
    x2 = (-b + std::sqrt(d)) / (2 * a);
}
```

- 10. Создаем файл solver.h:

```bash
void solve(float a, float b, float c, float& x1, float& x2);
```
- 11. Cоздаем главный CMakeLists.txt в основной папке lab03 с этим текстом:

```bash
cmake_minimum_required(VERSION 3.10)
project(lab03)

add_subdirectory(formatter_lib)
add_subdirectory(formatter_ex)
add_subdirectory(solver_lib)
add_subdirectory(hello_world)
add_subdirectory(solver)
```

- 12. Cобираем проект в корнe папки lab03:

```bash
$ cmake -H. -B build
```

**Вывод**

```
-- The C compiler identification is GNU 13.3.0
-- The CXX compiler identification is GNU 13.3.0
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Check for working C compiler: /usr/bin/cc - skipped
-- Detecting C compile features
-- Detecting C compile features - done
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: /usr/bin/c++ - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Configuring done (0.5s)
-- Generating done (0.0s)
-- Build files have been written to: /home/kirill/Desktop/Leikmadur/workspace/projects/lab03/build
```

```bash
$ cmake --build build
```

**Вывод**
```
[ 20%] Built target formatter
[ 30%] Building CXX object formatter_ex/CMakeFiles/formatter_ex.dir/formatter_ex.cpp.o
[ 40%] Linking CXX static library libformatter_ex.a
[ 40%] Built target formatter_ex
[ 50%] Building CXX object solver_lib/CMakeFiles/solver_lib.dir/solver.cpp.o
[ 60%] Linking CXX static library libsolver_lib.a
[ 60%] Built target solver_lib
[ 70%] Building CXX object hello_world/CMakeFiles/hello_world.dir/hello_world.cpp.o
[ 80%] Linking CXX executable hello_world
[ 80%] Built target hello_world
[ 90%] Building CXX object solver/CMakeFiles/solver.dir/equation.cpp.o
[100%] Linking CXX executable solver
[100%] Built target solver
```

- 13. Запускеам проекты:

```bash
$ ./build/hello_world/hello_world
```

**Вывод**
```
-------------------------
hello, world!
-------------------------
```

```bash
$ ./build/solver/solver
```

**Вывод**
```
8
2
-14
-------------------------
x1 = -1.453768
-------------------------
-------------------------
x2 = 1.203768
-------------------------
```








[![C++ CI](https://github.com/Leikmadu/lab04/actions/workflows/ci.yml/badge.svg)](https://github.com/Leikmadu/lab04/actions/workflows/ci.yml)

[![C++ CI](https://github.com/Leikmadu/lab04/actions/workflows/ci.yml/badge.svg)](https://github.com/Leikmadu/lab04/actions/workflows/ci.yml)
