
## Staring Your Operating System after making changes
*ps: basic setup(described in **1-setting-cross-compiler.md**) is required for this to work*

**You can then assemble boot.s using:**
- i686-elf-as boot.s -o boot.o

**Compile using:**

*For C*
- i686-elf-gcc -c kernel.c -o kernel.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra

*or, for C++*
- i686-elf-g++ -c kernel.c++ -o kernel.o -ffreestanding -O2 -Wall -Wextra -fno-exceptions -fno-rtti

**You can then link your kernel using:**
- i686-elf-gcc -T linker.ld -o blocks.bin -ffreestanding -O2 -nostdlib boot.o kernel.o -lgcc


**Verifying Multiboot**
- grub-file --is-x86-multiboot blocks.bin

**Create a bootable image of your operating system**
- grub-mkrescue -o blocks.iso isodir

**Command to start your new operating system**
- qemu-system-i386 -kernel blocks.bin