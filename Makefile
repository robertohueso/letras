SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c

all: $(BIN)/testdiccionario $(BIN)/cantidad_letras

$(BIN)/testdiccionario: $(OBJ)/Diccionario.o $(SRC)/testdiccionario.cpp
	$(CXX) -g -Wall -I$(INC) $(SRC)/testdiccionario.cpp $(OBJ)/Diccionario.o -o $(BIN)/testdiccionario

$(BIN)/cantidad_letras: $(OBJ)/ConjuntoLetras.o $(SRC)/cantidad_letras.cpp
	$(CXX) -g -Wall -I$(INC) $(SRC)/cantidad_letras.cpp $(OBJ)/Letra.o $(OBJ)/ConjuntoLetras.o -o $(BIN)/cantidad_letras

$(OBJ)/Diccionario.o: $(SRC)/Diccionario.cpp $(INC)/Diccionario.h $(INC)/ArbolGeneral.cpp $(INC)/ArbolGeneral.h
		$(CXX) $(CPPFLAGS) $(SRC)/Diccionario.cpp -o $(OBJ)/Diccionario.o

$(OBJ)/Letra.o: $(SRC)/Letra.cpp $(INC)/Letra.h
		$(CXX) $(CPPFLAGS) $(SRC)/Letra.cpp -o $(OBJ)/Letra.o

$(OBJ)/ConjuntoLetras.o: $(SRC)/ConjuntoLetras.cpp $(OBJ)/Letra.o $(INC)/ConjuntoLetras.h
		$(CXX) $(CPPFLAGS) $(SRC)/ConjuntoLetras.cpp  -o $(OBJ)/ConjuntoLetras.o

$(OBJ)/BolsaLetras.o: $(OBJ)/ConjuntoLetras.o $(INC)/BolsaLetras.h $(SRC)/BolsaLetras.cpp
		$(CXX) $(CPPFLAGS) $(SRC)/BolsaLetras.cpp  -o $(OBJ)/BolsaLetras.o
# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile


# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/* doc/doxygen_sqlite3.db
