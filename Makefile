### VARIABLES ###

H = ./Headers/
S = ./Sources/
CC = gcc
CFLAGS = -lgraph
EXE = taquin
OFILES = menu.o \
		 preparation.o \
		 deplacements.o \
		 main.o

### BUT PAR DEFAUT ###

but : ${EXE}

### REGLES ESSENTIELLES ###

menu.o : $(S)menu.c $(H)menu.h $(H)preparation.h
	$(CC) $(CFLAGS) -c $(S)menu.c

preparation.o : $(S)preparation.c $(H)menu.h $(H)preparation.h $(H)deplacements.h
	$(CC) $(CFLAGS) -c $(S)preparation.c

deplacements.o : $(S)deplacements.c $(H)menu.h $(H)deplacements.h
	$(CC) $(CFLAGS) -c $(S)deplacements.c

main.o : $(S)main.c $(H)menu.h $(H)preparation.h $(H)deplacements.h
	$(CC) $(CFLAGS) -c $(S)main.c

${EXE} : ${OFILES}
	$(CC) -o ${EXE} ${OFILES} $(CFLAGS)

### REGLES OPTIONNELLES ###

clean :
	 -rm -f ${OFILES}

mrproper : clean but

run :
	./$(EXE)

### BUTS FACTICES ###

.PHONY : but clean mrproper

### FIN ###