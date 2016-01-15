SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c

all: $(BIN)/testdiccionario

$(BIN)/testdiccionario: $(OBJ)/Diccionario.o $(SRC)/testdiccionario.cpp
	$(CXX) -g -Wall -I$(INC) $(SRC)/testdiccionario.cpp $(OBJ)/Diccionario.o -o $(BIN)/testdiccionario

$(OBJ)/Diccionario.o: $(SRC)/Diccionario.cpp $(INC)/Diccionario.h $(INC)/ArbolGeneral.cpp $(INC)/ArbolGeneral.h
		$(CXX) $(CPPFLAGS) $(SRC)/Diccionario.cpp -o $(OBJ)/Diccionario.o
# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile


# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/* doc/doxygen_sqlite3.db
