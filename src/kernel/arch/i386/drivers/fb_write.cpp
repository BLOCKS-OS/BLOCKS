/**
 * @brief 
 * Printing of character on the console using driver which
 * writes to the framebuffer memory the desired character,
 * foreground and background colour.
 *
 * The memory of framebuffer is divided into 16 bit cells,
 * where the 16 bits determine both the character, the foreground color and the background color.
 * 
 * Bit:     | 15 14 13 12 11 10 9 8 | 7 6 5 4 | 3 2 1 0 |
 * Content: | ASCII                 | FG      | BG      |
 */

// Treating the address 0x000B8000 as a char pointer
char *fb = (char *) 0x000B8000;

/** fb_write_cell:
 *  Writes a character with the given foreground and background to position i
 *  in the framebuffer.
 *
 *  @param i  The location in the framebuffer
 *  @param c  The character
 *  @param fg The foreground color
 *  @param bg The background color
 */
void fb_write_cell(unsigned int i, char c, unsigned char fg, unsigned char bg){
    fb[i] = c;
    fb[i+1] = ((fg & 0x0F) << 4) | (bg & 0x0F);
}


/* 
---- Sample Usage ----

#define FB_BLACK        0
#define FB_GREEN        2
#define FB_RED          4
#define FB_LIGHT_GREY   7
#define FB_DARK_GREY    8
#define FB_WHITE        15

fb_write_cell(0, 'A', FB_WHITE, FB_DARK_GREY);
*/
