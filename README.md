## Laboratory work V

Данная лабораторная работа посвещена изучению фреймворков для тестирования на примере **GTest**

```sh
$ open https://github.com/google/googletest
```

## Tasks

- [ ] 1. Создать публичный репозиторий с названием **lab05** на сервисе **GitHub**
- [ ] 2. Выполнить инструкцию учебного материала
- [ ] 3. Ознакомиться со ссылками учебного материала
- [ ] 4. Составить отчет и отправить ссылку личным сообщением в **Slack**

## Tutorial

```sh
$ export GITHUB_USERNAME=<имя_пользователя>

$ alias gsed=sed # for *-nix system
```

```sh
$ cd ${GITHUB_USERNAME}/workspace

$ pushd .
```

```sh
~/Desktop/Leikmadur/workspace ~/Desktop/Leikmadur/workspace
```

```sh
$ source scripts/activate
```

```sh
$ git clone https://github.com/Leikmadu/lab04 lab05
```

```sh
Cloning into 'lab05'...
remote: Enumerating objects: 120, done.
remote: Counting objects: 100% (120/120), done.
remote: Compressing objects: 100% (79/79), done.
remote: Total 120 (delta 35), reused 116 (delta 31), pack-reused 0 (from 0)
Receiving objects: 100% (120/120), 35.11 KiB | 653.00 KiB/s, done.
Resolving deltas: 100% (35/35), done.
```

```sh
$ cd projects/lab05

$ git remote remove origin

$ git remote add origin https://github.com/${GITHUB_USERNAME}/lab05
```

```sh
$ mkdir third-party

$ git submodule add https://github.com/google/googletest third-party/gtest
```

```sh
Cloning into '/home/kirill/Desktop/Leikmadur/workspace/lab05/third-party/gtest'...
remote: Enumerating objects: 28637, done.
remote: Counting objects: 100% (73/73), done.
remote: Compressing objects: 100% (52/52), done.
Receiving objects:   1% (287/28637), 76.01 KiB | 102.00 KiBReceiving objects:   2% (573/28637), 124.01 KiB | 93.00 KiBReceiving objects:   2% (725/28637), 220.01 KiB | 111.00 KiReceiving objects:   3% (860/28637), 276.01 KiB | 109.00 KiReceiving objects:   4% (1146/28637), 276.01 KiB | 109.00 KReceiving objects:   4% (1256/28637), 388.01 KiB | 128.00 KReceiving objects:   5% (1432/28637), 388.01 KiB | 128.00 KReceiving objects:   6% (1719/28637), 388.01 KiB | 128.00 KReceiving objects:   7% (2005/28637), 548.01 KiB | 154.00 KReceiving objects:   7% (2205/28637), 692.01 KiB | 161.00 KReceiving objects:   8% (2291/28637), 692.01 KiB | 161.00 KReceiving objects:   9% (2578/28637), 812.01 KiB | 168.00 KReceiving objects:   9% (2617/28637), 812.01 KiB | 168.00 KReceiving objects:  10% (2864/28637), 884.01 KiB | 165.00 KReceiving objects:  10% (3098/28637), 1012.01 KiB | 178.00 Receiving objects:  11% (3151/28637), 1012.01 KiB | 178.00 Receiving objects:  11% (3314/28637), 1.09 MiB | 174.00 KiBReceiving objects:  12% (3437/28637), 1.09 MiB | 174.00 KiBReceiving objects:  12% (3602/28637), 1.12 MiB | 168.00 KiBReceiving objects:  13% (3723/28637), 1.18 MiB | 156.00 KiBReceiving objects:  14% (4010/28637), 1.20 MiB | 131.00 KiBReceiving objects:  14% (4186/28637), 1.20 MiB | 131.00 KiBReceiving objects:  15% (4296/28637), 1.28 MiB | 121.00 KiBReceiving objects:  16% (4582/28637), 1.28 MiB | 121.00 KiBReceiving objects:  16% (4629/28637), 1.37 MiB | 116.00 KiBReceiving objects:  16% (4670/28637), 1.50 MiB | 104.00 KiBReceiving objects:  16% (4735/28637), 1.71 MiB | 127.00 KiBReceiving objects:  16% (4771/28637), 1.80 MiB | 122.00 KiBReceiving objects:  16% (4796/28637), 1.93 MiB | 139.00 KiBReceiving objects:  16% (4850/28637), 2.02 MiB | 138.00 KiBReceiving objects:  17% (4869/28637), 2.08 MiB | 131.00 KiBReceiving objects:  17% (4876/28637), 2.14 MiB | 125.00 KiBReceiving objects:  17% (4946/28637), 2.20 MiB | 125.00 KiBReceiving objects:  17% (5049/28637), 2.47 MiB | 138.00 KiBReceiving objects:  18% (5155/28637), 2.64 MiB | 163.00 KiBReceiving objects:  18% (5177/28637), 2.75 MiB | 164.00 KiBReceiving objects:  18% (5411/28637), 2.89 MiB | 182.00 KiBReceiving objects:  19% (5442/28637), 2.89 MiB | 182.00 KiBReceiving objects:  19% (5726/28637), 3.50 MiB | 284.00 KiBReceiving objects:  20% (5728/28637), 3.50 MiB | 284.00 KiBReceiving objects:  20% (5954/28637), 4.11 MiB | 360.00 KiBReceiving objects:  21% (6014/28637), 4.11 MiB | 360.00 KiBReceiving objects:  22% (6301/28637), 4.35 MiB | 374.00 KiBReceiving objects:  22% (6493/28637), 4.35 MiB | 374.00 KiBReceiving objects:  23% (6587/28637), 4.35 MiB | 374.00 KiBReceiving objects:  24% (6873/28637), 4.35 MiB | 374.00 KiBReceiving objects:  25% (7160/28637), 4.87 MiB | 452.00 KiBReceiving objects:  25% (7216/28637), 5.14 MiB | 484.00 KiBReceiving objects:  26% (7446/28637), 5.14 MiB | 484.00 KiBReceiving objects:  27% (7732/28637), 5.41 MiB | 495.00 KiBReceiving objects:  27% (7753/28637), 5.41 MiB | 495.00 KiBReceiving objects:  28% (8019/28637), 5.81 MiB | 522.00 KiBReceiving objects:  28% (8060/28637), 6.04 MiB | 506.00 KiBReceiving objects:  29% (8305/28637), 6.04 MiB | 506.00 KiBReceiving objects:  30% (8592/28637), 6.33 MiB | 510.00 KiBReceiving objects:  30% (8632/28637), 6.48 MiB | 456.00 KiBReceiving objects:  30% (8798/28637), 6.49 MiB | 444.00 KiBReceiving objects:  31% (8878/28637), 6.49 MiB | 444.00 KiBReceiving objects:  31% (9087/28637), 6.82 MiB | 371.00 KiBReceiving objects:  31% (9144/28637), 6.93 MiB | 302.00 KiBReceiving objects:  32% (9164/28637), 6.93 MiB | 302.00 KiBReceiving objects:  32% (9361/28637), 7.12 MiB | 229.00 KiBReceiving objects:  33% (9451/28637), 7.12 MiB | 229.00 KiBReceiving objects:  34% (9737/28637), 7.34 MiB | 219.00 KiBReceiving objects:  34% (9966/28637), 7.62 MiB | 249.00 KiBReceiving objects:  35% (10023/28637), 7.62 MiB | 249.00 KiReceiving objects:  36% (10310/28637), 7.86 MiB | 299.00 KiReceiving objects:  36% (10482/28637), 7.96 MiB | 270.00 KiReceiving objects:  36% (10519/28637), 8.02 MiB | 251.00 KiReceiving objects:  37% (10596/28637), 8.14 MiB | 247.00 KiReceiving objects:  37% (10630/28637), 8.14 MiB | 247.00 KiReceiving objects:  37% (10795/28637), 8.33 MiB | 246.00 KiReceiving objects:  38% (10883/28637), 8.43 MiB | 221.00 KiReceiving objects:  38% (11111/28637), 8.57 MiB | 191.00 KiReceiving objects:  39% (11169/28637), 8.57 MiB | 191.00 KiReceiving objects:  40% (11455/28637), 8.57 MiB | 191.00 KiReceiving objects:  40% (11612/28637), 8.90 MiB | 192.00 KiReceiving objects:  41% (11742/28637), 8.90 MiB | 192.00 KiReceiving objects:  41% (11954/28637), 9.00 MiB | 201.00 KiReceiving objects:  42% (12028/28637), 9.20 MiB | 234.00 KiReceiving objects:  43% (12314/28637), 9.30 MiB | 241.00 KiReceiving objects:  43% (12358/28637), 9.30 MiB | 241.00 KiReceiving objects:  44% (12601/28637), 9.52 MiB | 271.00 KiReceiving objects:  45% (12887/28637), 9.52 MiB | 271.00 KiReceiving objects:  46% (13174/28637), 9.70 MiB | 281.00 KiReceiving objects:  47% (13460/28637), 9.70 MiB | 281.00 KiReceiving objects:  47% (13581/28637), 9.70 MiB | 281.00 KiReceiving objects:  48% (13746/28637), 9.70 MiB | 281.00 KiReceiving objects:  49% (14033/28637), 9.86 MiB | 285.00 KiReceiving objects:  49% (14088/28637), 10.01 MiB | 278.00 KReceiving objects:  49% (14264/28637), 10.10 MiB | 238.00 KReceiving objects:  50% (14319/28637), 10.10 MiB | 238.00 KReceiving objects:  51% (14605/28637), 10.27 MiB | 268.00 KReceiving objects:  51% (14704/28637), 10.46 MiB | 276.00 KReceiving objects:  51% (14706/28637), 10.89 MiB | 300.00 KReceiving objects:  52% (14892/28637), 10.89 MiB | 300.00 KReceiving objects:  53% (15178/28637), 11.15 MiB | 300.00 KReceiving objects:  53% (15296/28637), 11.15 MiB | 300.00 KReceiving objects:  54% (15464/28637), 11.15 MiB | 300.00 KReceiving objects:  55% (15751/28637), 11.38 MiB | 314.00 KReceiving objects:  55% (16007/28637), 11.50 MiB | 315.00 KReceiving objects:  56% (16037/28637), 11.50 MiB | 315.00 KReceiving objects:  57% (16324/28637), 11.50 MiB | 315.00 KReceiving objects:  58% (16610/28637), 11.69 MiB | 326.00 KReceiving objects:  59% (16896/28637), 11.69 MiB | 326.00 KReceiving objects:  59% (16934/28637), 11.69 MiB | 326.00 KReceiving objects:  60% (17183/28637), 11.69 MiB | 326.00 KReceiving objects:  61% (17469/28637), 11.85 MiB | 344.00 KReceiving objects:  62% (17755/28637), 11.85 MiB | 344.00 KReceiving objects:  63% (18042/28637), 11.85 MiB | 344.00 KReceiving objects:  64% (18328/28637), 11.85 MiB | 344.00 KReceiving objects:  65% (18615/28637), 11.85 MiB | 344.00 KReceiving objects:  66% (18901/28637), 11.85 MiB | 344.00 KReceiving objects:  67% (19187/28637), 12.10 MiB | 361.00 KReceiving objects:  68% (19474/28637), 12.10 MiB | 361.00 KReceiving objects:  69% (19760/28637), 12.10 MiB | 361.00 KReceiving objects:  70% (20046/28637), 12.10 MiB | 361.00 KReceiving objects:  70% (20275/28637), 12.30 MiB | 378.00 KReceiving objects:  71% (20333/28637), 12.30 MiB | 378.00 KReceiving objects:  72% (20619/28637), 12.30 MiB | 378.00 KReceiving objects:  73% (20906/28637), 12.30 MiB | 378.00 KReceiving objects:  74% (21192/28637), 12.30 MiB | 378.00 KReceiving objects:  75% (21478/28637), 12.30 MiB | 378.00 KReceiving objects:  76% (21765/28637), 12.30 MiB | 378.00 KReceiving objects:  77% (22051/28637), 12.30 MiB | 378.00 KReceiving objects:  78% (22337/28637), 12.58 MiB | 406.00 KReceiving objects:  79% (22624/28637), 12.58 MiB | 406.00 KReceiving objects:  80% (22910/28637), 12.58 MiB | 406.00 KReceiving objects:  81% (23196/28637), 12.58 MiB | 406.00 KReceiving objects:  81% (23305/28637), 12.71 MiB | 345.00 KReceiving objects:  82% (23483/28637), 12.71 MiB | 345.00 KReceiving objects:  82% (23535/28637), 12.76 MiB | 296.00 KReceiving objects:  83% (23769/28637), 12.76 MiB | 296.00 KReceiving objects:  83% (24021/28637), 12.87 MiB | 265.00 KReceiving objects:  84% (24056/28637), 12.87 MiB | 265.00 KReceiving objects:  85% (24342/28637), 12.87 MiB | 265.00 KReceiving objects:  86% (24628/28637), 12.97 MiB | 259.00 KReceiving objects:  86% (24691/28637), 12.97 MiB | 259.00 KReceiving objects:  87% (24915/28637), 12.97 MiB | 259.00 KReceiving objects:  88% (25201/28637), 13.04 MiB | 242.00 KReceiving objects:  89% (25487/28637), 13.04 MiB | 242.00 KReceiving objects:  90% (25774/28637), 13.04 MiB | 242.00 KReceiving objects:  91% (26060/28637), 13.14 MiB | 232.00 KReceiving objects:  92% (26347/28637), 13.14 MiB | 232.00 KReceiving objects:  92% (26358/28637), 13.14 MiB | 232.00 KReceiving objects:  93% (26633/28637), 13.14 MiB | 232.00 KReceiving objects:  94% (26919/28637), 13.14 MiB | 232.00 KReceiving objects:  95% (27206/28637), 13.29 MiB | 212.00 KReceiving objects:  96% (27492/28637), 13.29 MiB | 212.00 KReceiving objects:  97% (27778/28637), 13.29 MiB | 212.00 KReceiving objects:  98% (28065/28637), 13.29 MiB | 212.00 KReceiving objects:  99% (28351/28637), 13.29 MiB | 212.00 KReceiving objects:  99% (28614/28637), 13.51 MiB | 210.00 KReceiving objects:  99% (28626/28637), 13.67 MiB | 188.00 Kremote: Total 28637 (delta 37), reused 22 (delta 20), pack-reused 28564 (from 2)
Receiving objects: 100% (28637/28637), 13.73 MiB | 185.00 KReceiving objects: 100% (28637/28637), 13.78 MiB | 250.00 KiB/s, done.
Resolving deltas: 100% (21270/21270), done.
```

```sh
$ cd third-party/gtest && git checkout release-1.8.1 && cd ../..
```

```sh
Note: switching to 'release-1.8.1'.

You are in 'detached HEAD' state. You can look around, make experimental
changes and commit them, and you can discard any commits you make in this
state without impacting any branches by switching back to a branch.

If you want to create a new branch to retain commits you create, you may
do so (now or later) by using -c with the switch command. Example:

  git switch -c <new-branch-name>

Or undo this operation with:

  git switch -

Turn off this advice by setting config variable advice.detachedHead to false

HEAD is now at 2fe3bd99 Merge pull request #1433 from dsacre/fix-clang-warnings
```

```sh
$ git add third-party/gtest

$ git commit -m"added gtest framework"
```
```sh
$ gsed -i '/option(BUILD_EXAMPLES "Build examples" OFF)/a\

option(BUILD_TESTS "Build tests" OFF)

' CMakeLists.txt

$ cat >> CMakeLists.txt <<EOF

if(BUILD_TESTS)
  enable_testing()
  add_subdirectory(third-party/gtest)
  file(GLOB \${PROJECT_NAME}_TEST_SOURCES tests/*.cpp)
  add_executable(check \${\${PROJECT_NAME}_TEST_SOURCES})
  target_link_libraries(check \${PROJECT_NAME} gtest_main)
  add_test(NAME check COMMAND check)
endif()
EOF
```

```sh
$ mkdir tests

$ cat > tests/test1.cpp <<EOF

#include <print.hpp>

#include <gtest/gtest.h>

TEST(Print, InFileStream)
{
  std::string filepath = "file.txt";
  std::string text = "hello";
  std::ofstream out{filepath};

  print(text, out);
  out.close();

  std::string result;
  std::ifstream in{filepath};
  in >> result;

  EXPECT_EQ(result, text);
}
EOF
```

```sh
$ cmake -H. -B_build -DBUILD_TESTS=ON

$ cmake --build _build
```

```sh
[  8%] Building CXX object CMakeFiles/print.dir/sources/print.cpp.o
[ 16%] Linking CXX static library libprint.a
[ 16%] Built target print
[ 25%] Building CXX object _deps/googletest-build/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.o
[ 33%] Linking CXX static library ../../../lib/libgtest.a
[ 33%] Built target gtest
[ 41%] Building CXX object _deps/googletest-build/googletest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o
[ 50%] Linking CXX static library ../../../lib/libgtest_main.a
[ 50%] Built target gtest_main
[ 58%] Building CXX object CMakeFiles/check.dir/tests/test1.cpp.o
[ 66%] Linking CXX executable check
[ 66%] Built target check
[ 75%] Building CXX object _deps/googletest-build/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o
[ 83%] Linking CXX static library ../../../lib/libgmock.a
[ 83%] Built target gmock
[ 91%] Building CXX object _deps/googletest-build/googlemock/CMakeFiles/gmock_main.dir/src/gmock_main.cc.o
[100%] Linking CXX static library ../../../lib/libgmock_main.a
[100%] Built target gmock_main


```
```
$ cmake --build _build --target test
```

```sh
Running tests...
Test project /home/kirill/Desktop/Leikmadur/workspace/lab05/_build
    Start 1: check
1/1 Test #1: check ............................   Passed    0.00 sec

100% tests passed, 0 tests failed out of 1

Total Test time (real) =   0.02 sec
```

```sh
$ _build/check
```

```sh
Running main() from /home/kirill/Desktop/Leikmadur/workspace/lab05/_build/_deps/googletest-src/googletest/src/gtest_main.cc
[==========] Running 1 test from 1 test suite.
[----------] Global test environment set-up.
[----------] 1 test from Print
[ RUN      ] Print.InFileStream
[       OK ] Print.InFileStream (0 ms)
[----------] 1 test from Print (0 ms total)

[----------] Global test environment tear-down
[==========] 1 test from 1 test suite ran. (0 ms total)
[  PASSED  ] 1 test.
```

```
$ cmake --build _build --target test -- ARGS=--verbose
```
```sh
Running tests...
UpdateCTestConfiguration  from :/home/kirill/Desktop/Leikmadur/workspace/lab05/_build/DartConfiguration.tcl
Test project /home/kirill/Desktop/Leikmadur/workspace/lab05/_build
Constructing a list of tests
Done constructing a list of tests
Updating test list for fixtures
Added 0 tests to meet fixture requirements
Checking test dependency graph...
Checking test dependency graph end
test 1
    Start 1: check

1: Test command: /home/kirill/Desktop/Leikmadur/workspace/lab05/_build/check
1: Working Directory: /home/kirill/Desktop/Leikmadur/workspace/lab05/_build
1: Test timeout computed to be: 10000000
1: Running main() from /home/kirill/Desktop/Leikmadur/workspace/lab05/_build/_deps/googletest-src/googletest/src/gtest_main.cc
1: [==========] Running 1 test from 1 test suite.
1: [----------] Global test environment set-up.
1: [----------] 1 test from Print
1: [ RUN      ] Print.InFileStream
1: [       OK ] Print.InFileStream (0 ms)
1: [----------] 1 test from Print (0 ms total)
1: 
1: [----------] Global test environment tear-down
1: [==========] 1 test from 1 test suite ran. (0 ms total)
1: [  PASSED  ] 1 test.
1/1 Test #1: check ............................   Passed    0.00 sec

100% tests passed, 0 tests failed out of 1

Total Test time (real) =   0.01 sec

```
```sh
$ gsed -i 's/lab04/lab05/g' README.md

$ mkdir -p .github/workflows

$ cat > .github/workflows/ci.yml << 'EOF'
name: CI

on:
  push:
    branches: [ master, main ]
  pull_request:
    branches: [ master, main ]

jobs:
  build-and-test:
    runs-on: ubuntu-latest
    
    steps:
    - uses: actions/checkout@v4
      with:
        submodules: recursive
    
    - name: Configure CMake
      run: cmake -B _build -DBUILD_TESTS=ON
    
    - name: Build
      run: cmake --build _build
    
    - name: Run tests
      run: cmake --build _build --target test -- ARGS=--verbose
EOF
```



```sh
$ git add .

$ git commit -m "Update files"

$ git push origin main
```

```sh
$ mkdir artifacts

$ sleep 20s && gnome-screenshot --file artifacts/screenshot.png

```


## Homework

### Задание
1. Создайте `CMakeList.txt` для библиотеки *banking*.
2. Создайте модульные тесты на классы `Transaction` и `Account`.
    * Используйте mock-объекты.
    * Покрытие кода должно составлять 100%.
3. Настройте сборочную процедуру на **TravisCI**.
4. Настройте [Coveralls.io](https://coveralls.io/).

```sh
$ cd banking

$ nano CMakeLists.txt
```

Записываеm:

```sh
cmake_minimum_required(VERSION 3.14)
project(banking)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(banking STATIC
    Account.cpp
    Transaction.cpp
)

target_include_directories(banking PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
```

```sh
$ mkdir tests

$ cd tests

$ mkdir mocks

$ cd mocks

$ nano MockAccount.hpp
```
```sh
#ifndef MOCK_ACCOUNT_HPP
#define MOCK_ACCOUNT_HPP

#include "Account.h"
#include <gmock/gmock.h>

class MockAccount : public Account {
public:
    MockAccount(int id, int balance) : Account(id, balance) {}
    
    // Новый синтаксис MOCK_METHOD для Google Mock 1.12+
    MOCK_METHOD(int, GetBalance, (), (const));
    MOCK_METHOD(void, ChangeBalance, (int diff));
    MOCK_METHOD(void, Lock, ());
    MOCK_METHOD(void, Unlock, ());
};

#endif
```

```sh
$ nano MockTransaction.hpp
```

```sh
#ifndef MOCK_TRANSACTION_HPP
#define MOCK_TRANSACTION_HPP

#include "Transaction.h"
#include <gmock/gmock.h>

class MockTransaction : public Transaction {
public:
    MockTransaction() : Transaction() {}
    
    MOCK_METHOD(void, SaveToDataBase, (Account& from, Account& to, int sum));
};

#endif
```

```sh

$ cd ..

$ nano test_account.cpp
```

```sh
#include <gtest/gtest.h>
#include "Account.h"

TEST(AccountTest, Constructor) {
    Account acc(1, 100);
    EXPECT_EQ(acc.id(), 1);
    EXPECT_EQ(acc.GetBalance(), 100);
}

TEST(AccountTest, LockAndChangeBalance) {
    Account acc(1, 100);
    acc.Lock();
    acc.ChangeBalance(50);
    EXPECT_EQ(acc.GetBalance(), 150);
    acc.Unlock();
}

TEST(AccountTest, ChangeBalanceWithoutLockThrows) {
    Account acc(1, 100);
    EXPECT_THROW(acc.ChangeBalance(50), std::runtime_error);
}

TEST(AccountTest, LockTwiceThrows) {
    Account acc(1, 100);
    acc.Lock();
    EXPECT_THROW(acc.Lock(), std::runtime_error);
}

TEST(AccountTest, UnlockWithoutLockDoesNothing) {
    Account acc(1, 100);
    EXPECT_NO_THROW(acc.Unlock());
    EXPECT_NO_THROW(acc.Lock());
}
```

```sh

$ nano test_transaction.cpp
```

```sh
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Transaction.h"
#include "mocks/MockAccount.hpp"
#include "mocks/MockTransaction.hpp"

using ::testing::_;
using ::testing::Return;
using ::testing::Throw;

// Попытка перевода на тот же счёт
TEST(TransactionTest, SameAccountThrows) {
    MockAccount acc(1, 1000);
    Transaction tx;
    EXPECT_THROW(tx.Make(acc, acc, 200), std::logic_error);
}

// Отрицательная сумма
TEST(TransactionTest, NegativeSumThrows) {
    MockAccount from(1, 1000);
    MockAccount to(2, 500);
    Transaction tx;
    EXPECT_THROW(tx.Make(from, to, -100), std::invalid_argument);
}

// Сумма меньше 100
TEST(TransactionTest, SumTooSmallThrows) {
    MockAccount from(1, 1000);
    MockAccount to(2, 500);
    Transaction tx;
    EXPECT_THROW(tx.Make(from, to, 50), std::logic_error);
}

// Комиссия слишком большая
TEST(TransactionTest, FeeTooLargeReturnsFalse) {
    MockAccount from(1, 1000);
    MockAccount to(2, 500);
    Transaction tx;
    tx.set_fee(100);
    EXPECT_CALL(from, GetBalance()).WillOnce(Return(1000));
    EXPECT_FALSE(tx.Make(from, to, 150));
}

// Успешный перевод
TEST(TransactionTest, SuccessfulTransfer) {
    MockAccount from(1, 1000);
    MockAccount to(2, 500);
    Transaction tx;
    tx.set_fee(1);

    EXPECT_CALL(from, Lock()).Times(1);
    EXPECT_CALL(to, Lock()).Times(1);
    EXPECT_CALL(to, ChangeBalance(200)).Times(1);
    EXPECT_CALL(from, GetBalance()).WillOnce(Return(1000));
    EXPECT_CALL(from, ChangeBalance(-201)).Times(1);
    EXPECT_CALL(from, Unlock()).Times(1);
    EXPECT_CALL(to, Unlock()).Times(1);

    EXPECT_TRUE(tx.Make(from, to, 200));
}

// Недостаточно средств - проверка ДО блокировки
TEST(TransactionTest, InsufficientFunds) {
    MockAccount from(1, 100);
    MockAccount to(2, 500);
    Transaction tx;
    tx.set_fee(1);

    // Ожидаем только вызов GetBalance для проверки
    EXPECT_CALL(from, GetBalance()).WillOnce(Return(100));
    
    // Блокировки и изменения НЕ должны вызываться
    EXPECT_CALL(from, Lock()).Times(0);
    EXPECT_CALL(to, Lock()).Times(0);
    EXPECT_CALL(to, ChangeBalance(_)).Times(0);
    EXPECT_CALL(from, ChangeBalance(_)).Times(0);
    EXPECT_CALL(from, Unlock()).Times(0);
    EXPECT_CALL(to, Unlock()).Times(0);

    EXPECT_FALSE(tx.Make(from, to, 150));
}

// Проверка вызова SaveToDataBase
TEST(TransactionTest, SaveToDataBaseIsCalled) {
    MockAccount from(1, 1000);
    MockAccount to(2, 500);
    MockTransaction tx;
    tx.set_fee(1);

    EXPECT_CALL(from, Lock()).Times(1);
    EXPECT_CALL(to, Lock()).Times(1);
    EXPECT_CALL(to, ChangeBalance(200)).Times(1);
    EXPECT_CALL(from, GetBalance()).WillOnce(Return(1000));
    EXPECT_CALL(from, ChangeBalance(-201)).Times(1);
    EXPECT_CALL(tx, SaveToDataBase(_, _, 200)).Times(1);
    EXPECT_CALL(from, Unlock()).Times(1);
    EXPECT_CALL(to, Unlock()).Times(1);

    EXPECT_TRUE(tx.Make(from, to, 200));
}

// Тест для покрытия catch блока
TEST(TransactionTest, ExceptionDuringChangeBalanceTriggersRollback) {
    MockAccount from(1, 1000);
    MockAccount to(2, 500);
    Transaction tx;
    tx.set_fee(1);

    EXPECT_CALL(from, Lock()).Times(1);
    EXPECT_CALL(to, Lock()).Times(1);
    EXPECT_CALL(to, ChangeBalance(200)).Times(1);
    EXPECT_CALL(from, GetBalance()).WillOnce(Return(1000));
    EXPECT_CALL(from, ChangeBalance(-201)).WillOnce(Throw(std::runtime_error("Test error")));
    EXPECT_CALL(to, ChangeBalance(-200)).Times(1);
    EXPECT_CALL(from, Unlock()).Times(1);
    EXPECT_CALL(to, Unlock()).Times(1);

    EXPECT_THROW(tx.Make(from, to, 200), std::runtime_error);
}
```

```sh
$ nano CMakeLists.txt
```

В корне папки обновим CMakeLists.txt:

```sh
cmake_minimum_required(VERSION 3.14)
project(lab05)

option(BUILD_TESTS "Build tests" OFF)
option(COVERAGE "Enable coverage reporting" OFF)

add_subdirectory(banking)

if(COVERAGE)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage -O0 -g")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} --coverage -O0 -g")
endif()

if(BUILD_TESTS)
    enable_testing()
    
    include(FetchContent)
    FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG release-1.12.1
    )
    FetchContent_MakeAvailable(googletest)
    
    add_executable(banking_tests
        banking/tests/test_account.cpp
        banking/tests/test_transaction.cpp
    )
    
    target_link_libraries(banking_tests banking gtest_main gmock_main)
    target_include_directories(banking_tests PRIVATE banking)
    
    add_test(NAME banking_tests COMMAND banking_tests)
endif()
```

```sh
$ rm -rf _build

$ cmake -H. -B_build -DBUILD_TESTS=ON
```

Вывод:
```sh
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
-- Found Python: /usr/bin/python3 (found version "3.12.3") found components: Interpreter 
-- Performing Test CMAKE_HAVE_LIBC_PTHREAD
-- Performing Test CMAKE_HAVE_LIBC_PTHREAD - Success
-- Found Threads: TRUE  
-- Configuring done (22.4s)
-- Generating done (0.0s)
-- Build files have been written to: /home/kirill/Desktop/Leikmadur/workspace/lab05/_build

```

```sh 
$ cmake --build _build
```
```sh
[  7%] Building CXX object _deps/googletest-build/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.o
[ 14%] Linking CXX static library ../../../lib/libgtest.a
[ 14%] Built target gtest
[ 21%] Building CXX object _deps/googletest-build/googletest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o
[ 28%] Linking CXX static library ../../../lib/libgtest_main.a
[ 28%] Built target gtest_main
[ 35%] Building CXX object _deps/googletest-build/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o
[ 42%] Linking CXX static library ../../../lib/libgmock.a
[ 42%] Built target gmock
[ 50%] Building CXX object _deps/googletest-build/googlemock/CMakeFiles/gmock_main.dir/src/gmock_main.cc.o
[ 57%] Linking CXX static library ../../../lib/libgmock_main.a
[ 57%] Built target gmock_main
[ 64%] Building CXX object banking/CMakeFiles/banking.dir/Account.cpp.o
[ 71%] Building CXX object banking/CMakeFiles/banking.dir/Transaction.cpp.o
[ 78%] Linking CXX static library libbanking.a
[ 78%] Built target banking
[ 85%] Building CXX object CMakeFiles/banking_tests.dir/banking/tests/test_account.cpp.o
[ 92%] Building CXX object CMakeFiles/banking_tests.dir/banking/tests/test_transaction.cpp.o
[100%] Linking CXX executable banking_tests
[100%] Built target banking_tests
```

```sh
$ ./banking_tests

$ cmake --build _build --target test -- ARGS=--verbose
```
```sh
Running tests...
UpdateCTestConfiguration  from :/home/kirill/Desktop/Leikmadur/workspace/lab05/_build/DartConfiguration.tcl
UpdateCTestConfiguration  from :/home/kirill/Desktop/Leikmadur/workspace/lab05/_build/DartConfiguration.tcl
Test project /home/kirill/Desktop/Leikmadur/workspace/lab05/_build
Constructing a list of tests
Done constructing a list of tests
Updating test list for fixtures
Added 0 tests to meet fixture requirements
Checking test dependency graph...
Checking test dependency graph end
test 1
    Start 1: banking_tests

1: Test command: /home/kirill/Desktop/Leikmadur/workspace/lab05/_build/banking_tests
1: Working Directory: /home/kirill/Desktop/Leikmadur/workspace/lab05/_build
1: Test timeout computed to be: 10000000
1: Running main() from /home/kirill/Desktop/Leikmadur/workspace/lab05/_build/_deps/googletest-src/googletest/src/gtest_main.cc
1: [==========] Running 13 tests from 2 test suites.
1: [----------] Global test environment set-up.
1: [----------] 5 tests from AccountTest
1: [ RUN      ] AccountTest.Constructor
1: [       OK ] AccountTest.Constructor (0 ms)
1: [ RUN      ] AccountTest.LockAndChangeBalance
1: [       OK ] AccountTest.LockAndChangeBalance (0 ms)
1: [ RUN      ] AccountTest.ChangeBalanceWithoutLockThrows
1: [       OK ] AccountTest.ChangeBalanceWithoutLockThrows (0 ms)
1: [ RUN      ] AccountTest.LockTwiceThrows
1: [       OK ] AccountTest.LockTwiceThrows (0 ms)
1: [ RUN      ] AccountTest.UnlockWithoutLockDoesNothing
1: [       OK ] AccountTest.UnlockWithoutLockDoesNothing (0 ms)
1: [----------] 5 tests from AccountTest (0 ms total)
1: 
1: [----------] 8 tests from TransactionTest
1: [ RUN      ] TransactionTest.SameAccountThrows
1: [       OK ] TransactionTest.SameAccountThrows (0 ms)
1: [ RUN      ] TransactionTest.NegativeSumThrows
1: [       OK ] TransactionTest.NegativeSumThrows (0 ms)
1: [ RUN      ] TransactionTest.SumTooSmallThrows
1: [       OK ] TransactionTest.SumTooSmallThrows (0 ms)
1: [ RUN      ] TransactionTest.FeeTooLargeReturnsFalse
1: [       OK ] TransactionTest.FeeTooLargeReturnsFalse (0 ms)
1: [ RUN      ] TransactionTest.SuccessfulTransfer
1: Transaction saved: 1 -> 2 200
1: 1 send to 2 $200
1: [       OK ] TransactionTest.SuccessfulTransfer (0 ms)
1: [ RUN      ] TransactionTest.InsufficientFunds
1: [       OK ] TransactionTest.InsufficientFunds (0 ms)
1: [ RUN      ] TransactionTest.SaveToDataBaseIsCalled
1: 1 send to 2 $200
1: [       OK ] TransactionTest.SaveToDataBaseIsCalled (0 ms)
1: [ RUN      ] TransactionTest.ExceptionDuringChangeBalanceTriggersRollback
1: [       OK ] TransactionTest.ExceptionDuringChangeBalanceTriggersRollback (0 ms)
1: [----------] 8 tests from TransactionTest (1 ms total)
1: 
1: [----------] Global test environment tear-down
1: [==========] 13 tests from 2 test suites ran. (2 ms total)
1: [  PASSED  ] 13 tests.
1/1 Test #1: banking_tests ....................   Passed    0.02 sec

100% tests passed, 0 tests failed out of 1

Total Test time (real) =   0.02 sec

```

```sh
$ gcovr -r . --filter '.*banking.*' --exclude '.*tests.*' --exclude '.*mocks.*' --print-summary

```

```sh
(INFO) Reading coverage data...
(INFO) Writing coverage report...
------------------------------------------------------------------------------
                           GCC Code Coverage Report
Directory: .
------------------------------------------------------------------------------
File                                       Lines    Exec  Cover   Missing
------------------------------------------------------------------------------
/home/kirill/Desktop/Leikmadur/workspace/lab05/banking/Account.cpp
                                              18      18   100%
/home/kirill/Desktop/Leikmadur/workspace/lab05/banking/Account.h
                                               1       1   100%
/home/kirill/Desktop/Leikmadur/workspace/lab05/banking/Transaction.cpp
                                              34      34   100%
/home/kirill/Desktop/Leikmadur/workspace/lab05/banking/Transaction.h
                                               1       1   100%
------------------------------------------------------------------------------
TOTAL                                         54      54   100%
------------------------------------------------------------------------------


```

```sh
$ cd .github/workflows

$ nano ci.yml
```

Исправленный ci.yml:
```sh
name: CI

on: [push, pull_request]

jobs:
  build:
    runs-on: ubuntu-latest

    steps:
      - uses: actions/checkout@v4
        with:
          submodules: recursive

      - name: Install dependencies
        run: |
          sudo apt-get update
          sudo apt-get install -y cmake lcov gcovr libgtest-dev libgmock-dev

      - name: Configure CMake with coverage
        run: cmake -B _build -DBUILD_TESTS=ON -DCMAKE_CXX_FLAGS="--coverage -O0 -g -w"

      - name: Build
        run: cmake --build _build

      - name: Run tests
        working-directory: _build
        run: ctest --verbose

      - name: Collect coverage with gcovr
        working-directory: _build
        run: |
          gcovr -r . --filter '.*/banking/.*' \
            --exclude '.*/tests/.*' \
            --exclude '.*/mocks/.*' \
            --xml coverage.xml

      - name: Upload coverage to Coveralls
        uses: coverallsapp/github-action@v2
        with:
          file: _build/coverage.xml
          github-token: ${{ secrets.GITHUB_TOKEN }}
```

```sh
$ git add .

$ git commit -n "Update files"

$ git push origin main
```

