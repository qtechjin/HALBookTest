KERNELDIR=/usr/src/linux-headers-3.13.0-32-generic
PWD:=$(shell pwd)
CC = gcc

obj-m := word_count.o
modules:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules
clean:
	rm -rf *.o *~core .depend .*.cmd *.ko
