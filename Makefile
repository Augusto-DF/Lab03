#Makefile

#Compilador : g++
CC=g++

#Variáveis de diretórios:
INC_DIR=./include
SRC_DIR=./src
OBJ_DIR=./build
DOC_DIR=./doc
BIN_DIR=./bin
LIB_DIR=./lib
TEST_DIR=./test

#Váriavel de compilação:
CFLAGS=-Wall -pedantic -ansi -std=c++11 -I. -I$(INC_DIR)/q01
#CFLAGS2=-Wall -pedantic -ansi -std=c++11 -I. -I$(INC_DIR)/q02
#CFLAGS3=-Wall -pedantic -ansi -std=c++11 -I.

.PHONY: all clean doxy debug doc

#Remove os arquivos .o:
all: questao01 #questao02 questao03

debug: CFLAGS += -g -O0
#debug: CFLAGS2 += -g -O0
#debug: CFLAGS3 += -g -O0
debug: questao01 #questao02 questao03

#Criação do executavel: questao01
questao01: $(OBJ_DIR)/produto.o $(OBJ_DIR)/fruta.o $(OBJ_DIR)/bebida.o $(OBJ_DIR)/roupa.o $(OBJ_DIR)/main1.o
	@echo	"======================"
	@echo	"Carregando o alvo $@"
	@echo	"======================"
	$(CC) $(CFLAGS) -o $(BIN_DIR)/$@ $^
	@echo	"++++ [Executavel questao01 criado em $(BIN_DIR)] ++++"
	@echo	"  =============================================    "

#Criação dos arquivos .o:

#produto.o
$(OBJ_DIR)/produto.o: $(SRC_DIR)/q01/produto.cpp $(INC_DIR)/q01/produto.h
	$(CC) -c $(CFLAGS) -o $@ $<

#fruta.o
$(OBJ_DIR)/fruta.o: $(SRC_DIR)/q01/fruta.cpp $(INC_DIR)/q01/fruta.h
	$(CC) -c $(CFLAGS) -o $@ $<

#bebida.o
$(OBJ_DIR)/bebida.o: $(SRC_DIR)/q01/bebida.cpp $(INC_DIR)/q01/bebida.h
	$(CC) -c $(CFLAGS) -o $@ $<

#roupa.o
$(OBJ_DIR)/roupa.o: $(SRC_DIR)/q01/roupa.cpp $(INC_DIR)/q01/roupa.h
	$(CC) -c $(CFLAGS) -o $@ $<

#main.o
$(OBJ_DIR)/main1.o: $(SRC_DIR)/q01/main.cpp
	$(CC) -c $(CFLAGS) -o $@ $<

doxy:
	rm -rf $(DOC_DIR)/*
	doxygen Doxyfile

clean:
	rm -rf $(BIN_DIR)/*
	rm -rf $(OBJ_DIR)/*