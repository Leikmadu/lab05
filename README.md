# Laboratory work IV

Данная лабораторная работа посвещена изучению систем непрерывной интеграции на примере сервиса Travis CI
```bash
$ open https://travis-ci.org
```

## Tasks
- 1. Авторизоваться на сервисе Travis CI с использованием GitHub аккаунта
- 2.Cоздать публичный репозиторий с названием lab05 на сервисе GitHub
- 3. Ознакомиться со ссылками учебного материала
- 4. Включить интеграцию сервиса Travis CI с созданным репозиторием
- 5. Получить токен для Travis CLI с правами repo и user
- 6. Получить фрагмент вставки значка сервиса Travis CI в формате Markdown
- 7. Выполнить инструкцию учебного материала
- 8. Составить отчет и отправить ссылку личным сообщением в Slack

## Студент
Малыхин Кирилл Группа: ИУ8-21  
Дата: 04.05.2026  

---

## Tutorial
```bash
$ export GITHUB_USERNAME=<имя_пользователя>
$ export GITHUB_TOKEN=<полученный_токен>
$ cd ${GITHUB_USERNAME}/workspace
$ pushd .
$ source scripts/activate
```


```bash
$ \curl -sSL https://get.rvm.io | bash -s -- --ignore-dotfiles
```

**Вывод**
```
Turning on ignore dotfiles mode.
Downloading https://github.com/rvm/rvm/archive/master.tar.gz
Installing RVM to /home/misha/.rvm/
Installation of RVM in /home/misha/.rvm/ is almost complete:

  * To start using RVM you need to run `source /home/misha/.rvm/scripts/rvm`
    in all your open shell windows, in rare cases you need to reopen all shell windows.
Thanks for installing RVM 🙏
```

```bash
$ echo "source $HOME/.rvm/scripts/rvm" >> scripts/activate
$ . scripts/activate
$ rvm autolibs disable
$ rvm install ruby-2.4.2
```

**Вывод**
```
ruby-2.4.2 - #removing src/ruby-2.4.2..
Installing Ruby from source to: /home/Leikmadur/.rvm/rubies/ruby-2.4.2, this may take a while depending on your cpu(s)...
ruby-2.4.2 - #downloading ruby-2.4.2, this may take a while depending on your connection...
ruby-2.4.2 - #extracting ruby-2.4.2 to /home/Leikmadur/.rvm/src/ruby-2.4.2.....
ruby-2.4.2 - #configuring..................................................................
ruby-2.4.2 - #post-configuration..
ruby-2.4.2 - #compiling......................................................................................................|
ruby-2.4.2 - #installing...........
ruby-2.4.2 - #making binaries executable..
ruby-2.4.2 - #downloading rubygems-3.0.9
  % Total    % Received % Xferd  Average Speed   Time    Time     Time  Current
                                 Dload  Upload   Total   Spent    Left  Speed
100  865k  100  865k    0     0   695k      0  0:00:01  0:00:01 --:--:--  696k
No checksum for downloaded archive, recording checksum in user configuration.
ruby-2.4.2 - #extracting rubygems-3.0.9.....
ruby-2.4.2 - #removing old rubygems........
ruby-2.4.2 - #installing rubygems-3.0.9................................................................
ruby-2.4.2 - #gemset created /home/Leikmadur/.rvm/gems/ruby-2.4.2@global
ruby-2.4.2 - #importing gemset /home/Leikmadur/.rvm/gemsets/global.gems..........................................................
ruby-2.4.2 - #generating global wrappers........
ruby-2.4.2 - #gemset created /home/Leikmadur/.rvm/gems/ruby-2.4.2
ruby-2.4.2 - #importing gemsetfile /home/Leikmadur/.rvm/gemsets/default.gems evaluated to empty gem list
ruby-2.4.2 - #generating default wrappers........
ruby-2.4.2 - #adjusting #shebangs for (gem irb erb ri rdoc testrb rake).
Install of ruby-2.4.2 - #complete
```

```bash
$ rvm use 2.4.2 --default
```
**Вывод**
```
Using /home/Leikmadur/.rvm/gems/ruby-2.4.2
```


```bash
$ git clone https://github.com/${GITHUB_USERNAME}/lab03 projects/lab05
```
**Вывод**
```
Cloning into 'projects/lab05'...
remote: Enumerating objects: 100, done.
remote: Counting objects: 100% (100/100), done.
remote: Compressing objects: 100% (76/76), done.
remote: Total 100 (delta 26), reused 85 (delta 18), pack-reused 0 (from 0)
Receiving objects: 100% (100/100), 29.55 KiB | 1.85 MiB/s, done.
Resolving deltas: 100% (26/26), done.

```

```bash
$ cd projects/lab05
$ git remote remove origin
$ git remote add origin https://github.com/Leikmadu/lab05.git
$ git clone https://github.com/${GITHUB_USERNAME}/lab03 projects/lab05
$ cd projects/lab05
$ git remote remove origin
$ git remote add origin https://github.com/${GITHUB_USERNAME}/lab05
```

```bash 
$ cat > .travis.yml <<EOF
language: cpp
EOF

$ cat >> .travis.yml <<EOF

script:
- cmake -H. -B_build -DCMAKE_INSTALL_PREFIX=_install
- cmake --build _build
- cmake --build _build --target install
EOF

$ cat >> .travis.yml <<EOF

addons:
  apt:
    sources:
      - george-edison55-precise-backports
    packages:
      - cmake
      - cmake-data
EOF
```




## Homework

```bash
$ mkdir -p .github/workflows
```
В файл вставляем такой текст:

```bash
cat > .github/workflows/ci.yml <<'EOF'
name: C++ CI

on:
  push:
    branches: [ master ]
  pull_request:
    branches: [ master ]

jobs:
  build:
    runs-on: ${{ matrix.os }}

    strategy:
      matrix:
        os: [ubuntu-latest, windows-latest]
        compiler: [gcc, clang]

        include:
          - os: ubuntu-latest
            compiler: gcc
            cc: gcc
            cxx: g++

          - os: ubuntu-latest
            compiler: clang
            cc: clang
            cxx: clang++

          - os: windows-latest
            compiler: gcc
            cc: gcc
            cxx: g++

          - os: windows-latest
            compiler: clang
            cc: clang
            cxx: clang++

    steps:
    - name: Checkout repository
      uses: actions/checkout@v3

    - name: Install dependencies (Ubuntu)
      if: matrix.os == 'ubuntu-latest'
      run: |
        sudo apt update
        sudo apt install -y build-essential cmake clang

    - name: Set compiler
      run: |
        echo "CC=${{ matrix.cc }}" >> $GITHUB_ENV
        echo "CXX=${{ matrix.cxx }}" >> $GITHUB_ENV

    - name: Configure CMake
      run: cmake -S . -B build

    - name: Build
      run: cmake --build build --config Release
EOF
```

```bash

echo "" >> README.md
echo "[![C++ CI](https://github.com/Leikmadu/lab05/actions/workflows/ci.yml/badge.svg)](https://github.com/Leikmadu/lab05/actions/workflows/ci.yml)" >> README.md
```

``` bash
$ git add .github/workflows/ci.yml README.md
$ git commit -m "Add CI with GCC and Clang on Linux and Windows"
$ git push origin master
```



