# Cross Compiler Documentation

## Check GCC and Binutils Version

- `gcc --version` 
  - `>= 4.6.0`
  
- `ld --version`
  - `>= 2.22`

---

## Preparing for the build

The GNU Compiler Collection is an advanced piece of software with dependencies. You need the following in order to build GCC:


- A Unix-like environment (Windows users can use the Windows Subsystem for Linux or Cygwin)
- Enough memory and hard disk space (it depends, 256 MiB will not be enough).
- GCC (existing release you wish to replace), or another system C compiler
G++ (if building a version of GCC >= 4.8.0), or another system C++ compiler
- Make
- Bison
- Flex
- GMP
- MPFR
- MPC
- Texinfo
- ISL (optional)
- CLooG (optional)

<img src="./img/1.png" />

---

## GCC Build Commands

- sudo apt update

- sudo apt install build-essential

- sudo apt install bison

- sudo apt install flex

- sudo apt install libgmp3-dev

- sudo apt install libmpc-dev

- sudo apt install libmpfr-dev

- sudo apt install texinfo

- export PREFIX="/usr/local/x86_64elfgcc"

- export TARGET=i686-elf

- export PATH="$PREFIX/bin:$PATH"

- mkdir /tmp/src

- cd /tmp/src

- curl -O http://ftp.gnu.org/gnu/binutils/binutils-2.35.1.tar.gz

- tar xf binutils-2.35.1.tar.gz

- mkdir binutils-build

- cd binutils-build

- ../binutils-2.35.1/configure --target=$TARGET --enable-interwork --enable-multilib --disable-nls --disable-werror --prefix=$PREFIX 2>&1 | tee configure.log

- sudo make all install 2>&1 | tee make.log

- cd /tmp/src

- curl -O https://ftp.gnu.org/gnu/gcc/gcc-10.2.0/gcc-10.2.0.tar.gz

- tar xf gcc-10.2.0.tar.gz

- mkdir gcc-build

- cd gcc-build

- ../gcc-10.2.0/configure --target=$TARGET --prefix="$PREFIX" --disable-nls --disable-libssp --enable-languages=c++ --without-headers

- sudo make all-gcc

- sudo make all-target-libgcc

- sudo make install-gcc

- sudo make install-target-libgcc

---

## References:

- https://wiki.osdev.org/GCC_Cross-Compiler
- https://www.youtube.com/watch?v=-v6uRjpR_0M