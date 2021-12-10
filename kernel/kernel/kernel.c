#include <stdio.h>
 
#include <kernel/tty.h>
 
void kernel_main(void) {
	terminal_initialize();
	printf("Hello, VIT Bhopal! Welcome to Blocks OS. Thanks for the Project Review 1.");
}
