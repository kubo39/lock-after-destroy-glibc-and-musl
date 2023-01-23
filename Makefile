.PHONY: all
all: glibc musl

.PHONY: glibc
glibc:
	gcc -o glibc_bin app.c -lpthread
	./glibc_bin

.PHONY: musl
musl:
	musl-gcc -static -o musl_bin app.c
	./musl_bin

.PHONY: clean
clean:
	-$(RM) glibc_bin musl_bin
