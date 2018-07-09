TARGET=dft_main
TARGET1=$(addsuffix _O0, $(TARGET))
TARGET2=$(addsuffix _O1, $(TARGET))
TARGET3=$(addsuffix _O2, $(TARGET))
TARGET4=$(addsuffix _O3, $(TARGET))
TARGET5=$(addsuffix _Os, $(TARGET))
DEPS=dft_main dft
DEPS:=$(addsuffix .c, $(DEPS))

CC=gcc
LIB=/usr/lib/x86_64-linux-gnu/libsndfile.so.1.0.28 -lm
CFLAGS1=-O0
CFLAGS2=-O1
CFLAGS3=-O2
CFLAGS4=-O3
CFLAGS5=-Os

.PHONY: clean

all:	$(TARGET1) $(TARGET2) $(TARGET3) $(TARGET4) $(TARGET5)

$(TARGET1): $(DEPS)
	$(CC) $(CFLAGS1) $(DEPS) -o $@ $(LIB)

$(TARGET2): $(DEPS)
	$(CC) $(CFLAGS2) $(DEPS) -o $@ $(LIB)

$(TARGET3): $(DEPS)
	$(CC) $(CFLAGS3) $(DEPS) -o $@ $(LIB)

$(TARGET4): $(DEPS)
	$(CC) $(CFLAGS4) $(DEPS) -o $@ $(LIB)

$(TARGET5): $(DEPS)
	$(CC) $(CFLAGS5) $(DEPS) -o $@ $(LIB)

clean:
	@echo Tidying things up...
	-rm -f *.o $(TARGET1) $(TARGET2) $(TARGET3) $(TARGET4) $(TARGET5)
	-rm -f *.txt *.png

	


