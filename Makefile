CC?=clang
#CC?=gcc
RM=rm -fv
CFLAGS=$(shell pkg-config --cflags libbsd libmodbus)
LIBS=$(shell pkg-config --libs libbsd libmodbus) -pthread
SRCS=src/*

all: epever

epever: $(SRCS)
	$(CC) -v $(CFLAGS) $(LIBS) -Wall -Werror -O3 -o epever src/*.c

lint:
	clang-format --verbose --Werror -i --style=file $(SRCS)
	clang-tidy --checks='*,-altera-id-dependent-backward-branch,-altera-unroll-loops,-cert-err33-c,-clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling,-llvm-header-guard,-llvmlibc-restrict-system-libc-headers,-readability-function-cognitive-complexity' --format-style=llvm $(SRCS) -- $(CFLAGS)
.PHONY: lint

clean:
	$(RM) epever
