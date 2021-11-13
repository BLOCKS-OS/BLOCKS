# About BLOCKS OS

## GNU Compiler Collection - System V ABI

The System V ABI (as used by i686-elf-gcc, x86_64-elf-gcc, and other ELF platforms) specifies use of five different object files that together handle program initialization.

These are traditionally called crt0.o, crti.o, crtbegin.o, crtend.o, and crtn.
o. Together these object files implement two special functions: 

* **_init** which runs the global constructors and other initialization tasks
* **_fini** that runs the global destructors and other termination tasks.

**ELF Platform used: i686-elf-gcc**