#!/bin/sh
set -e
. ./build.sh
 
mkdir -p isodir
mkdir -p isodir/boot
mkdir -p isodir/boot/grub
 
cp sysroot/boot/blocks.kernel isodir/boot/blocks.kernel
cat > isodir/boot/grub/grub.cfg << EOF
menuentry "blocks" {
	multiboot /boot/blocks.kernel
}
EOF
grub-mkrescue -o blocks.iso isodir