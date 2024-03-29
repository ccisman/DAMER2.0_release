﻿# DAMER 2.0

an aotumatic tool for modeling and slicing multiple-thread c programs(PThread programs).

This project is a tool for building a PDNet model of c program, and alleviate the state space with slicing.
The c program must satisfy ANSI-C grammar.


## Environment
- Ubuntu or Deepin

## installation

Since our tool use Graphviz and tcmalloc. You should make sure they are installed in your computer.

### install Graphviz.

if you have not installed Graphviz yet, use the following command-line to install Graphviz

$ sudo apt-get install graphviz

### install tcmalloc.(tcmalloc的安装如果出现任何问题，可以使用mac版本进行测试，mac版本中去掉了tcmalloc的相关使用)

There are two ways to install tcmalloc

#### 1.

Use our script to install tcmalloc automatically. You can use the following command-lines in this directory.

$ cd tcmalloc \
$ chmod +x install.sh \
$ sudo ./install.sh

It will takes a few minutes if everything goes well.

#### 2.

if you have not installed tcmalloc yet, use the following command-lines to install tcmalloc

First, you should install m4

$ wget http://mirrors.kernel.org/gnu/m4/m4-1.4.13.tar.gz \
$ tar -xzvf m4-1.4.13.tar.gz \
$ cd m4-1.4.13 \
$ ./configure --prefix=/usr/local

$ sudo make && sudo make install \
$ cd ..

if there is an error occured, use the following commands:

$ sed -i 's/IO_ftrylockfile/IO_EOF_SEEN/' lib/*.c \
$ echo "#define _IO_IN_BACKUP 0x100" >> lib/stdio-impl.h \
$ sudo make install \
$ cd ..

Second, you should install autoconf

$ wget http://mirrors.kernel.org/gnu/autoconf/autoconf-2.65.tar.gz \
$ tar -xzvf autoconf-2.65.tar.gz \
$ cd autoconf-2.65 \
$ ./configure --prefix=/usr/local

$ sudo make && sudo make install \
$ cd ..

Third, you should install automake

$ wget http://mirrors.kernel.org/gnu/automake/automake-1.11.1.tar.gz \
$ tar xzvf automake-1.11.1.tar.gz \
$ cd automake-1.11.1 \
$ ./configure --prefix=/usr/local

$ sudo make && sudo make install \
$ cd ..

Forth, you should install libtool

$ wget http://mirrors.kernel.org/gnu/libtool/libtool-2.2.6b.tar.gz \
$ tar xzvf libtool-2.2.6b.tar.gz \
$ cd libtool-2.2.6b \
$ ./configure --prefix=/usr/local

$ sudo make && sudo make install \
$ cd ..

Fifth, you should install libunwind

$ wget http://download.savannah.gnu.org/releases/libunwind/libunwind-1.1.tar.gz \
$ tar -zxvf libunwind-1.1.tar.gz \
$ cd libunwind-1.1 \
$ ./configure --prefix=/usr/local

$ sudo make && sudo make install \
$ cd ..

Finally, you can install google-perftools

get the newest google-perftools-2.x.tar.gz from https://github.com/gperftools/gperftools/releases , then do:

$ tar -zxvf gperftools-2.x.tar.gz \
$ cd gperftools-2.x \
$ ./configure --prefix=/usr/local

$ sudo make && sudo make install \
$ su \
$ echo "/usr/local/lib" > /etc/ld.so.conf

## Usage

- The 'test_program' folder is where you put the test files. Those *.c files is the original program files.


To run DAMER, type the following command in 'exe' directory:

$ ./PDNet2_0 [-showtree] [-showcpn][-heu][-PDNetSlice][-TraditionalSlice][-CIA][-property filename] (filename)

Tips: The contents in parentheses are required

for example:

$ ./PDNet2_0 -compare ../test_programs/fib_bench-1.c

More command can be seen with:

$ ./exe/PDNet2_0 -help

## Script
可以将run.sh脚本放在可执行文件对应目录下运行来批量处理测试文件。
