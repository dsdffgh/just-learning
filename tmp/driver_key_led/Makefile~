
# To build modules outside of the kernel tree, we run "make"
# in the kernel source tree; the Makefile these then includes this
# Makefile once again.
# This conditional selects whether we are being included from the
# kernel Makefile or not.

TARGET = button
CROSS_COMPILE = arm-linux-

CC              = $(CROSS_COMPILE)gcc
STRIP           = $(CROSS_COMPILE)strip
#CFLAGS          = -O2


ifeq ($(KERNELRELEASE),)

    # Assume the source tree is where the running kernel was built
    # You should set KERNELDIR in the environment if it's elsewhere
    KERNELDIR ?= /home/kernel/linux-2.6.38
    #KERNELDIR ?= /usr/src/kernels/2.6.35.14-106.fc14.i686/
    
    # The current directory is passed to sub-makes as argument
    PWD := $(shell pwd)

all:	$(TARGET) modules

$(TARGET):
	$(CC) -o $(TARGET) $(TARGET).c

modules:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules

modules_install:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules_install

clean:
	rm -rf *.o *~ core .depend .*.cmd *.ko *.mod.c .tmp_versions $(TARGET)

.PHONY: modules modules_install clean

else
    # called from kernel build system: just declare what our modules are
    obj-m := my210button.o

endif


